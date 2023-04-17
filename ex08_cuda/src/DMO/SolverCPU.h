#pragma once

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "thrust/host_vector.h"
#include "thrust/device_vector.h"

#include <type_traits>
#include <vector>

#include "math_constants.h"

#include "DmoParams.h"
#include "Vertex.h"
#include "DmoMesh.h"
#include "Metrics.h"

namespace DMO
{
	// CPU kernel
	template<typename MetricT>
	void dmoCPU( std::vector<float2>& points, DmoMesh<false>& dmoMesh1_, const MetricT& metric );

	template<typename MeshT, typename MetricT, typename Metric2T = DMO::Metrics::NoMetric>
	class SolverCPU
	{
		MeshT& mesh_;
		MetricT* metric1_;
		Metric2T* metric2_;

		std::vector<float2> points_;

		DmoMesh<false>* dmoMesh1_;
		DmoMesh<false>* dmoMesh2_;

	public:
		SolverCPU<MeshT, MetricT, Metric2T>( MeshT& mesh, MetricT* metric1, DmoMesh<false>* dmoMesh1, Metric2T* metric2 = nullptr, DmoMesh<false>* dmoMesh2 = nullptr );

		void solve( int nIterations = 100 );
	};


	/*
	*		========================
	*		Implementation of Solver
	*		========================
	*/

	template<typename MeshT, typename MetricT, typename Metric2T>
	SolverCPU<MeshT, MetricT, Metric2T>::SolverCPU( MeshT& mesh, MetricT* metric1, DmoMesh<false>* dmoMesh1, Metric2T* metric2, DmoMesh<false>* dmoMesh2 )
		: mesh_( mesh ), metric1_( metric1 ), metric2_( metric2 ), dmoMesh1_(dmoMesh1), dmoMesh2_( dmoMesh2 )
	{
		// copy points
		points_.resize( mesh_.n_vertices() );
		for( auto vh : mesh_.vertices() ) {
			auto p = mesh_.point( vh );
			points_[vh.idx()] = { p[0],p[1] };
		}

	}

	template<typename MeshT, typename MetricT, typename Metric2T>
	void SolverCPU<MeshT, MetricT, Metric2T>::solve( int nIterations ) {
		for( int i = 0; i < nIterations; ++i ) {
			dmoCPU<MetricT>( points_, *dmoMesh1_, *metric1_ );
			if constexpr( !std::is_same<Metric2T, DMO::Metrics::NoMetric>::value ) {
				dmoCPU<Metric2T>( points_, *dmoMesh2_, *metric2_ );
			}
		}

		for( const auto& vh : mesh_.vertices() ) {
			int idx = vh.idx();
			TriMesh::Point p = { points_[idx].x, points_[idx].y, 0.f };
			mesh_.set_point( vh, p );
		}
	}

}

#include "SolverCPU_impl.h"
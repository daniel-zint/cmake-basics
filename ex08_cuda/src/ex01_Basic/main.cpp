/*
* DMO Example 01 - Basics
*
* Usage of DMO with predefined metrics
* 
* !!! Your project must contain the file registerDMO.cu !!!
*/

#include <experimental/filesystem>
#include <iostream>
#include "baseDirectory.h"

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
typedef OpenMesh::TriMesh_ArrayKernelT<> TriMesh;

#include "DMO/Solver.h"


namespace fs = std::experimental::filesystem;

int main( int argc, char* argv[] )
{
	fs::current_path( BASE_DIRECTORY );

	fs::path meshPath = "examples/transition4to1.off";

	TriMesh mesh;
	OpenMesh::IO::read_mesh( mesh, meshPath.string() );

	/* Define a set of vertices that should be optimized.
	* Predefined sets are: Inner, Boundary, All
	* Sets can also be created by passing a vector of vertex handles.
	*/
	DMO::DmoMesh<true> dmoMeshInner = DMO::DmoMesh<true>::create<TriMesh, DMO::Set::Inner>( mesh );

	//std::vector<OpenMesh::SmartVertexHandle> set;
	//set.reserve( mesh.n_vertices() );
	//for( const auto& v : mesh.vertices() ) {
	//	set.push_back( v );
	//}
	//DMO::DmoMesh dmoMeshAll( set );

	std::cout << "Start solver" << std::endl;
	// Optimize vertex set with the mean ratio metric for 100 iterations
        auto t = DMO::Metrics::Tri::MeanRatio();
	DMO::Solver( mesh, &t, &dmoMeshInner ).solve( 100 );
	std::cout << "Finish solver" << std::endl;

	OpenMesh::IO::write_mesh( mesh, "examples/out.off" );

        system("diff examples/out.off examples/out1.off");
}
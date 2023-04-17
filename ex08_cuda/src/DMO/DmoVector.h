#pragma once

#include "thrust/host_vector.h"
#include "thrust/device_vector.h"
#include <vector>
#include <type_traits>

namespace DMO
{

	template <typename T>
	class DmoVectorGPU
	{
		thrust::host_vector<T> h_;
		thrust::device_vector<T> d_;
	public:
		const auto& h() const { return h_; }
		auto& h() { return h_; }
		const auto& d() const { return d_; }
		auto& d() { return d_; }

		void copyHostToDevice() {
			d_ = h_;
		}

		void copyDeviceToHost() {
			h_ = d_;
		}
	};

	template <typename T>
	class DmoVectorCPU
	{
		std::vector<T> h_;
	public:
		const auto& h() const { return h_; }
		auto& h() { return h_; }
	};

	template<typename T, bool useGPU = true> using DmoVector = typename std::conditional<useGPU, DmoVectorGPU<T>, DmoVectorCPU<T>>::type;
		
}
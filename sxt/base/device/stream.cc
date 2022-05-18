#include "sxt/base/device/stream.h"

#include <cstdlib>
#include <iostream>

#include <cuda_runtime.h>

namespace sxt::basdv {
//--------------------------------------------------------------------------------------------------
// constructor
//--------------------------------------------------------------------------------------------------
stream::stream() noexcept {
  auto rcode = cudaStreamCreate(&stream_);
  if (rcode != cudaSuccess) {
    std::cerr << "cudaStreamCreate failed: " << cudaGetErrorString(rcode)
              << "\n";
    std::abort();
  }
}

//--------------------------------------------------------------------------------------------------
// destructor
//--------------------------------------------------------------------------------------------------
stream::~stream() noexcept {
  auto rcode = cudaStreamDestroy(stream_);
  if (rcode != cudaSuccess) {
    std::cerr << "cudaStreamDestroy failed: " << cudaGetErrorString(rcode)
              << "\n";
    std::abort();
  }
}
}  // namespace sxt::basdv
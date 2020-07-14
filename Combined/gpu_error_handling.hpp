#pragma once

#include <cuda_runtime.h>

#include <cstdlib>
#include <iostream>

namespace rhgt {

#define RCHECKCUDAERROR(error) rhgt::CudaErrorHandler(error, __FILE__, __LINE__)

inline void CudaErrorHandler(const cudaError_t &err, const std::string &file, const size_t line){
  if (err!=cudaSuccess) {
    std::cerr<<"[GASAL CUDA ERROR:] " << cudaGetErrorString(err)
             <<" (CUDA error no.="<<err<<")"
             <<" in "<<file<<":"<<line<<std::endl;
    exit(EXIT_FAILURE);
  }
}

}
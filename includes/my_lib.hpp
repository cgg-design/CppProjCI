#pragma once
#include "linalg.h"

/**
 * @brief Method printing Hehho world
 * 
 * @return std::string 
 */
std::string print_hello_world();

/**
 * @brief method returning 3D vectors linalg is use hier, muss be link in the CMakeLists on my_lib.cpp
 * 
 * @return linalg::aliases::float3 
 */
linalg::aliases::float3 print_linalg_vector();

/**
 * @brief print a Boost version and return true if succes
 * 
 * @return true 
 */
bool print_boost_version();
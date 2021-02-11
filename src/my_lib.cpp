#include<iostream>
#include<string.h>
#include "linalg.h"
#include "boost/version.hpp"
#include "my_lib.hpp"


std::string print_hello_world(){
	// LOG_F(INFO, "We are starting to print Hello world!");
	return "Hello World";
}

linalg::aliases::float3 print_linalg_vector(){
	int result;
	linalg::aliases::float3 v {1, 2, 3};
		std::cout <<"Vec: " << v[0]<< ","<< v[2]  << std::endl; // Prints {1,2,3}
	return v;//result
}


bool print_boost_version(){
	std::cout << "Boost version: " << BOOST_VERSION << std::endl;
	return true;
}
#include<iostream>
#include <my_lib.hpp>
#include "calc_add.hpp"
#include "calc_sub.hpp"
#include "calc_mul.hpp"
#include "calc_square.hpp"
#include "loguru.hpp"  

/* Hier sind funktionen aus der bibliotheke verwendet */


/**
 * @brief Main method
 * 
 * @return int 
 */

// int main(){
int main(int argc, char **argv){
	//loguru::init(argc, argv);
    //in der CMake datei einen option definieren
	std::cout << "Print: " << print_hello_world() << std::endl;
	std::cout << "Add: " << add_values(4,6) << std::endl;
	std::cout << "Sub: " << sub_values(6,4) << std::endl;
	std::cout << "Mul: " << mul_values(4,6) << std::endl;
	std::cout << "Sqr: " << square_values(13) << std::endl;

	print_linalg_vector();

	print_boost_version();

	loguru::init(argc, argv);
	loguru::add_file("everything.log", loguru::Append, loguru::Verbosity_MAX);
    loguru::add_file("info.log", loguru::Append, loguru::Verbosity_INFO);
    loguru::add_file("warning.log", loguru::Append, loguru::Verbosity_WARNING);
    loguru::add_file("error.log", loguru::Append, loguru::Verbosity_ERROR);

    LOG_F(INFO, "Hello this is an info!");
    LOG_F(WARNING, "Hello this is a warning!");
    LOG_F(ERROR, "Hello this is an error!");



    return 0;
}
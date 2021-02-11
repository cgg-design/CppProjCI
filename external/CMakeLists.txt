##  Bibliotheque  ##
##################### linalg CMakeLists.txt  #####################
# library external
# library mit nur .h datein sollen als interface gekenzeichnet
##################################################################
# add_library(${LIBRARY_LINALG} OBJECT ${LIBRARY_SOURCES})  # fur alle source .cpp dateien

# linalg only .hpp
set(LIB_INCL_LINALG_HPP "linalg/")
add_library(${LIBRARY_LINALG} INTERFACE) # fur nur .h dateien
target_include_directories(${LIBRARY_LINALG} INTERFACE ${LIB_INCL_LINALG_HPP}) # "linalg" name der library


# logguru: .cpp and .hpp
set(LIB_INCL_LOGURU_CPP "loguru/loguru.cpp")
set(LIB_INCL_LOGURU_HPP "loguru/loguru.hpp")
set(LIB_INCL_LOGURU "loguru/")#include
add_library(loguru ${LIB_INCL_LOGURU_CPP} ${LIB_INCL_LOGURU_HPP})
target_include_directories(loguru PUBLIC ${LIB_INCL_LOGURU}) # "linalg" name der library

find_package(Threads)# threading bibliotheke
target_link_libraries(loguru ${CMAKE_THREAD_LIBS_INIT}) # For pthreads
if(NOT WIN32)
    target_link_libraries(loguru dl) # For ldl
endif()

# Celero
# if(USE_BENCHMARKS)
#     add_subdirectory(Celero)
#     add_library("${PROJECT}_celero" ALIAS celero)
# endif()
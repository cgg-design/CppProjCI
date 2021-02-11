###############################
###     calc_sub library    ###
###############################

set(LIBRARY_SOURCES "calc_mul.cpp")
set(LIBRARY_HEADERS "${PROJECT_SOURCE_DIR}/includes/calc_mul.hpp")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/includes/")

# Option for generating/building: target
add_library(${LIBRARY_MUL} OBJECT ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_MUL} PUBLIC ${LIBRARY_INCLUDES})
target_compile_features(${LIBRARY_MUL} PUBLIC cxx_std_17)



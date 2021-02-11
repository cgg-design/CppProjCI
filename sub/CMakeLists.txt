######### Bibliotheque ########
##     calc_sub library      ##
###############################

set(LIBRARY_SOURCES "calc_sub.cpp")
set(LIBRARY_HEADERS "${PROJECT_SOURCE_DIR}/includes/calc_sub.hpp")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/includes/")

# Option for generating/building: target
add_library(${LIBRARY_SUB} OBJECT ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_SUB} PUBLIC ${LIBRARY_INCLUDES})
target_compile_features(${LIBRARY_SUB} PUBLIC cxx_std_17)

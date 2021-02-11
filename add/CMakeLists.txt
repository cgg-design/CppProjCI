##  Bibliotheque  ##
# add

set(LIBRARY_SOURCES "calc_add.cpp") 
set(LIBRARY_HEADERS "${PROJECT_SOURCE_DIR}/includes/calc_add.hpp")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/includes/")

# Option for generating/building: target
add_library(${LIBRARY_ADD} OBJECT ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
# Wo liegt die header file
target_include_directories(${LIBRARY_ADD} PUBLIC ${LIBRARY_INCLUDES})
target_compile_features(${LIBRARY_ADD} PUBLIC cxx_std_17)


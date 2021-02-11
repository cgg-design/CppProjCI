### Bibliotheque ###
# calc_square library

set(LIBRARY_SOURCES "calc_square.cpp")
set(LIBRARY_HEADERS "${PROJECT_SOURCE_DIR}/includes/calc_square.hpp")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/includes/")

# Option for generating/building: target
add_library(${LIBRARY_SQR} OBJECT ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_SQR} PUBLIC ${LIBRARY_INCLUDES})
target_compile_features(${LIBRARY_SQR} PUBLIC cxx_std_17)

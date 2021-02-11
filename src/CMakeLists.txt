### Bibliotheque ###
# MyLib library

set(LIBRARY_SOURCES "my_lib.cpp")
set(LIBRARY_HEADERS "${PROJECT_SOURCE_DIR}/includes/my_lib.hpp")
set(LIBRARY_INCLUDES "${PROJECT_SOURCE_DIR}/includes/")

# Option for generating/building: target
add_library(${LIBRARY_SRC} OBJECT ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
# Wo liegt die header file
target_include_directories(${LIBRARY_SRC} PUBLIC ${LIBRARY_INCLUDES})
# linalg function shall be used in library my_lib.cpp
target_link_libraries(${LIBRARY_SRC} PUBLIC ${LIBRARY_LINALG})
target_link_libraries(${LIBRARY_SRC} PUBLIC loguru)
# optional
target_compile_features(${LIBRARY_SRC} PUBLIC cxx_std_17)

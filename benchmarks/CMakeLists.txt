#############################################
# Performance testing, Check
# Um Ausführungszeitberechnen z.B. 
# vom Bibliotheke, es soll dort wor man verwenden 
# will gelinkt werden
#############################################

# Sources
set(BENCHMARK_SOURCES "main.cpp")
# Target
add_executable(${BENCHMARK_MAIN} ${BENCHMARK_SOURCES})
# Benchmark mit lib my_lib.cpp linken (auch andere lib z.B add.cpp)
target_link_libraries(${BENCHMARK_MAIN} PUBLIC ${LIBRARY_SRC}) # ${LIBRARY_NAME}
# CONAN_LIBS_CELERO in build -> conanbuildinfo.cmake zu finden
target_link_libraries(${BENCHMARK_MAIN} PUBLIC ${CONAN_LIBS_CELERO})
# Settings
target_compile_features(${BENCHMARK_MAIN} PUBLIC cxx_std_17)

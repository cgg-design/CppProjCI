########### Main Application  ############
# Main executable
# Externe Library werden hier gelinkt
##########################################

# add the executabl, it's in same dir
add_executable(${MAIN} "main.cpp")
# Executable lirary: ${PROJECT}_Executable
# main mit my_lib.h linken fuer alle .cpp file
target_link_libraries(${MAIN} PUBLIC ${LIBRARY_SRC} ${LIBRARY_ADD} ${LIBRARY_SUB} ${LIBRARY_MUL} ${LIBRARY_SQR})
# Wo liegt diese header file
target_include_directories(${MAIN} PUBLIC ${PROJECT_BINARY_DIR} )
# features von den module, die  gelinkt sind (bauen) setzen
target_compile_features(${LIBRARY_SRC} PUBLIC cxx_std_17) # linalg is bereits hier
target_compile_features(${LIBRARY_ADD} PUBLIC cxx_std_17)
target_compile_features(${LIBRARY_SUB} PUBLIC cxx_std_17) 
target_compile_features(${LIBRARY_MUL} PUBLIC cxx_std_17)
target_compile_features(${LIBRARY_SQR} PUBLIC cxx_std_17)



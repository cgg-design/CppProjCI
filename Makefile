install:
	@sudo apt-get install gcovr lcov


install_doc:
	@pip install jinja2 Pygments
	@pip apt-get install doxygen


setup:
	@pip install conan
	@conan user	

prepare:
	@rm -rf build
	@mkdir build
	@cd build && conan install .. && cd ..

#include "cube.h"
cube::cube(std::string name) :name(name) {
	std::cout << "constructor of cube " << name << std::endl;
}
cube::~cube() {
	std::cout << "destructor of cube"<< std::endl;
}

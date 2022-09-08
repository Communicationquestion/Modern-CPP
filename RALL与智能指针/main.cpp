#include "cube.h"

#include<memory>
int main() {
	
	cube c2("as");
	/*auto pointer = std::make_shared< cube>(c2);
	pointer->out();*/
	std::unique_ptr<cube> pointer = std::make_unique<cube>(c2);
	//pointer->out();
	std::unique_ptr<cube> p2(std::move(pointer));
	p2->out();
}
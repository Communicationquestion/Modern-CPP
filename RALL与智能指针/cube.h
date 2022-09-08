#pragma once
#include<iostream>
#include<string>
class cube
{
public:
	cube(std::string name);
	cube() = default;
	~cube();
	void out() const {
		std::cout << "cube name " <<name<< std::endl;
	}
	std::string getname() const {
		return name;
	}
	std::string setname(const std::string& name) {
		this->name = name;
	}
private:
	std::string name{ "Mimi" };

};


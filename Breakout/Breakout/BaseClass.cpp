// BaseClass.cpp

#include <iostream>
#include "BaseClass.h"

BaseClass::BaseClass() {
	std::cout << "BaseClass::BaseClass" << std::endl;
};

BaseClass::~BaseClass() {
	std::cout << "BaseClass::~BaseClass" << std::endl;
};

DerivedClass::DerivedClass() {
	std::cout << "DerivedClass::DerivedClass" << std::endl;
};

DerivedClass::~DerivedClass() {
	std::cout << "DerivedClass::~DerivedClass" << std::endl;
};

void DerivedClass::Method() {
	//m_some_data = 0;
	m_some_more_data = 0;
};

SuperClass::SuperClass() {
	std::cout << "SuperClass::SuperClass" << std::endl;
};

SuperClass::~SuperClass() {
	std::cout << "SuperClass::~SuperClass" << std::endl;
};

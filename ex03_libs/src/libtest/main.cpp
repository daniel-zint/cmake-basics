#include <iostream>

#include <StaticLib/StaticLibClass.h>
#include <SharedLib/SharedLibClass.h>

int main() {
	std::cout << "Hello World!" << std::endl;
	StaticLibClass();
	SharedLibClass();
}

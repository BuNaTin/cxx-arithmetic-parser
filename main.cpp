
#include "source/Expression/Expression.h"

#include <string>
#include <iostream>


// Test file
int main() {
    std::cout<<"Input: ";
    std::string buffer;
    getline(std::cin,buffer);
    Expression alfa(buffer);
    std::cout<<"Output: "<<alfa.Calc()<<'\n';
	return 0;
}

#include "source/Expression/Expression.h"
#include <iostream>

int main() {
	std::cout<<"Input:";
	std::string alfa;
	getline(std::cin,alfa);
	Expression expr(alfa);
	std::cout<<"Output:"<<expr.Calc()<<'\n';
	return 0;
}
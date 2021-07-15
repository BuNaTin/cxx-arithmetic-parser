
#include "OperationList.h"

#include <cmath>

std::map<char, double (*)(double,double) > OperationList::_data = {
	std::pair<char, double (*)(double,double)> ('+',[](double l,double r) {return l+r;}),
	std::pair<char, double (*)(double,double)> ('-',[](double l,double r) {return l-r;}),
	std::pair<char, double (*)(double,double)> ('*',[](double l,double r) {return l*r;}),
	std::pair<char, double (*)(double,double)> ('/',[](double l,double r) {return l/r;}),
	std::pair<char, double (*)(double,double)> ('^',[](double l,double r) {return pow(l,r);})
};

std::initializer_list<char> OperationList::_one = {'+','-'};
std::initializer_list<char> OperationList::_two = {'*','/'};
std::initializer_list<char> OperationList::_three = {'^'};

std::initializer_list<char> OperationList::_all = {'+','-','*','/','^'};

std::initializer_list<char> OperationList::GetOperations(int operationLvl = 0) {
	switch(operationLvl) {
		case 0:
			return _all;
		case 1:
			return _one;
		case 2:
			return _two;
		case 3:
			return _three;
		default:
			return {};
	}
}
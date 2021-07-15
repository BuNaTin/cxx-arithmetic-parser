
#include "FunctionList.h"

#include <cmath>

std::map<std::string, double (*)(double) > FunctionList::_data = {
	std::pair<std::string, double(*)(double)>("sin",[](double arg){return sin(arg);}),
	std::pair<std::string, double(*)(double)>("cos",[](double arg){return cos(arg);}),
	std::pair<std::string, double(*)(double)>("tan",[](double arg){return tan(arg);}),
	std::pair<std::string, double(*)(double)>("sqrt",[](double arg){return sqrt(arg);})
};

std::initializer_list<std::string> FunctionList::_list = {
	"sin",
	"cos",
	"tan",
	"sqrt"
};

std::initializer_list<std::string> FunctionList::GetFunctions() {
	return _list;
}
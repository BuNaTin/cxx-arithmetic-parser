
#pragma once

#include <map>
#include <initializer_list>
	
class OperationList {
public:
	double (*ForDeclType)(double,double);
public:
	static auto GetOperation(char operation )
				->decltype( ForDeclType ) {
		return _data[ operation ];
	}
	static std::initializer_list<char> GetOperations(int);
private:
	static std::initializer_list<char> _one;
	static std::initializer_list<char> _two;
	static std::initializer_list<char> _three;
	static std::initializer_list<char> _all;
	static std::map<char, double (*)(double,double) > _data;
};
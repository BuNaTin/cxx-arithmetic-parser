
#pragma once

#include <map>
#include <initializer_list>

class FunctionList {
public:
	double (*ForDeclType)(double);
public:
	static auto GetFunction( std::string func_name)
							-> decltype( ForDeclType ) {
		return _data[ func_name ];
	}
	static std::initializer_list<std::string> GetFunctions();
private:
	static std::map<std::string, double (*)(double) > _data;
	static std::initializer_list<std::string> _list;
};
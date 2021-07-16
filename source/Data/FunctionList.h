
#pragma once

#include <map>
#include <initializer_list>
    
/* 
    class FunctionList is singleton look like microservice with all static members.
    To add new operations use FunctionList.cpp
*/
class FunctionList {
public:
    // for GetFunction() method
	double (*ForDeclType)(double);
public:
// API methods
	static auto GetFunction( std::string func_name)
							-> decltype( ForDeclType ) {
		return _data[ func_name ];
	}
	static std::initializer_list<std::string> GetFunctions();
private:
	static std::map<std::string, double (*)(double) > _data;
	static std::initializer_list<std::string> _list;
};

#pragma once

#include <map>
#include <initializer_list>
    
/* 
    class Operation is singleton look like microservice with all static members.
    To add new operations use OperationList.cpp
*/
class OperationList {
public:
    double (*ForDeclType)(double,double);
public:
    static auto GetOperation(char operation )
                ->decltype( ForDeclType ) {
        return _data[ operation ];
    }
    static std::initializer_list<char> GetOperations(int);
    static int GetMaxOperationLvl();
private:
    static std::initializer_list<char> _one;
    static std::initializer_list<char> _two;
    static std::initializer_list<char> _three;
    static std::initializer_list<char> _all;
    static std::map<char, double (*)(double,double) > _data;
    static int _maxOperationLvl;
};
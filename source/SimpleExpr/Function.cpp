
#include "Function.h"

#include <iostream>

// For realization
#include "../Data/FunctionList.h"
#include "../Factory/Factory.h"
#include "../Parser/Parser.h"

Function::Function() {
    
}
Function::~Function() {
    
}

Function::Function(const std::string& buffer) {
    _buildSuccessfully = true;
    _name = Parser::GetFuncName(buffer);
    _body_up = Factory::MakeExpr( Parser::GetFuncBody(buffer) );
    if(_name == "" || _body_up == nullptr) {
        _buildSuccessfully = false;
    }
}

double Function::Calc() const {
    if(!_buildSuccessfully) {
        std::cerr<<"Calc() for unsuccess build function\n";
    }
    auto func = FunctionList::GetFunction(_name);
    return func( _body_up->Calc() );
}

bool Function::BuildSuccessfully() const {
    return (_buildSuccessfully && 
            _body_up->BuildSuccessfully()
    );
}
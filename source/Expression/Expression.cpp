
#include "Expression.h"

#include <iostream>

// For realisation
#include "../Factory/Factory.h"

Expression::Expression(const std::string& buffer)
{
	_rep_up = Factory::MakeExpr(buffer);
	if( _rep_up == nullptr or not _rep_up->BuildSuccessfully() ) {
		std::cerr<<"Wrong expression\n";
		_result = 0.0;
	} else {
		_result = _rep_up->Calc();
	}
}

double Expression::Calc() const {
	return _result;
}
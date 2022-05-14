
#include "Expression.h"

#include <iostream>

// For realisation
#include "../Factory/Factory.h"

Expression::Expression(const std::string &buffer)
{
	_rep_up = Factory::MakeExpr(buffer);
	if (_rep_up == nullptr || !_rep_up->BuildSuccessfully())
	{
		valid = false;
		_result = 0.0;
	}
	else
	{
		_result = _rep_up->Calc();
	}
}

std::pair<double, bool> Expression::Calc() const
{
	return {_result, valid};
}
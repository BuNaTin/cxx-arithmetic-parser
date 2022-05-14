
#include "Expression.h"

#include <iostream>

// For realisation
#include "../Factory/Factory.h"

Expression::Expression(const std::string &buffer)
{
	if (!checkBrackets(buffer))
	{
		valid = false;
		_result = 0.0;
		return;
	}
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

bool Expression::checkBrackets(const std::string &buffer)
{
	int n = 0;
	for (auto symb : buffer)
	{
		if (symb == '(')
			++n;
		if (symb == ')')
			--n;
		if (n < 0)
			return false;
	}
	return n == 0;
}

std::pair<double, bool> Expression::Calc() const
{
	return {_result, valid};
}
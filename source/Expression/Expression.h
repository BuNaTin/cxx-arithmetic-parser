
#pragma once

#include <string>
#include <memory>

// For interface
#include "../SimpleExpr/virtualExpr.h"

/*
	class Expression is non-copyable because of _rep_up (which is unique_ptr)
	It is a safe wrapper above all microservices
*/
class Expression
{
public:
	// API
	Expression(const std::string &buffer);
	std::pair<double, bool> Calc() const;

public:
	// Non-copyable
	Expression(const Expression &other) = delete;
	Expression &operator=(const Expression &other) = delete;

private:
	bool checkBrackets(const std::string &);

private:
	bool valid = true;
	double _result;
	std::unique_ptr<virtualExpr> _rep_up;
};
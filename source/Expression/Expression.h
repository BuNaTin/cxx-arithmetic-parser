
#pragma once

#include <string>
#include <memory>

// For interface
#include "../SimpleExpr/virtualExpr.h"

class Expression {
public:
	Expression(const std::string& buffer);
	double Calc() const;
public:
	Expression(const Expression& other) = delete;
	Expression& operator=(const Expression& other) = delete;
private:
	double _result;
	std::unique_ptr<virtualExpr> _rep_up;
};
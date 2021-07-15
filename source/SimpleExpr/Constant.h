
#pragma once

#include <string>

// For interface
#include "virtualExpr.h"

class Constant : public virtualExpr {
public:
	Constant();
	Constant(double res);
	Constant(const std::string&);
	~Constant();
public:
	double Calc() const override;
	bool BuildSuccessfully() const override;
public:
	Constant(const Constant& other) = delete;
	Constant& operator=(const Constant& other) = delete;
private:
	double _result;
	bool _buildSuccessfully;
};
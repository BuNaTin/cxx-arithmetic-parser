
#pragma once

class virtualExpr {
public:
	virtual double Calc() const = 0;
	virtual bool BuildSuccessfully() const = 0;
	virtual ~virtualExpr() {};
};
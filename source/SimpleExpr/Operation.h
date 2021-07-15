
#pragma once

#include <string>
#include <memory>

// For interface
#include "virtualExpr.h"

class Operation : public virtualExpr {
public:
	Operation();
	Operation(const std::string&);
	~Operation();
public:
	double Calc() const override;
	bool BuildSuccessfully() const override;
public:
	Operation(const Operation& other) = delete;
	Operation& operator=(const Operation& other) = delete;
private:
	using upvirtualExpr = std::unique_ptr<virtualExpr>;
	bool _buildSuccessfully;
	char _operation;
	upvirtualExpr _left;
	upvirtualExpr _right;
};
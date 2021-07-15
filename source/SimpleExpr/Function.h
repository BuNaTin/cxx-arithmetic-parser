
#pragma once

#include <string>
#include <memory>

// For interface
#include "virtualExpr.h"

class Function : public virtualExpr {
public:
	Function();
	Function(const std::string& buffer);
	~Function();
public:
	double Calc() const override;
	bool BuildSuccessfully() const override;
public:
	Function(const Function& other) = delete;
	Function& operator=(const Function& other) = delete;
private:
	std::string _name;
	std::unique_ptr<virtualExpr> _body_up; // body as Unique Ptr
	bool _buildSuccessfully;
};
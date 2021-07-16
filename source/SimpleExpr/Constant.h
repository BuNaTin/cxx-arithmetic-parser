
#pragma once

#include <string>

// For interface
#include "virtualExpr.h"

/*
    Copyable class Constant.
    Makes double value from string or double and safe him.

*/
class Constant : public virtualExpr {
public:
// Initializing methods + constructors
    Constant();
    Constant(double res);
    Constant(const std::string&);
    Constant(const Constant& other);
    ~Constant();
public:
// API methods
    double Calc() const override;
    bool BuildSuccessfully() const override;
public:
// Copyable
    Constant& operator=(const Constant& other);
private:
    double _result;
    bool _buildSuccessfully;
};
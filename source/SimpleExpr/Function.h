
#pragma once

#include <string>
#include <memory>

// For interface
#include "virtualExpr.h"


/* 
    Non-copyable (because of body, which are unique_ptr) class Function.
    class Operation takes lower operation from expression
    and build left and right operands by Factory
*/
class Function : public virtualExpr {
public:
// Initialize methods + constructors
    Function();
    Function(const std::string& buffer);
    ~Function();
public:
// API methods
    double Calc() const override;
    bool BuildSuccessfully() const override;
public:
// Non-copyable
    Function(const Function& other) = delete;
    Function& operator=(const Function& other) = delete;
private:
    std::string _name;
    std::unique_ptr<virtualExpr> _body_up;
    bool _buildSuccessfully;
};
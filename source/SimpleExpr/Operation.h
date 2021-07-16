
#pragma once

#include <string>
#include <memory>

// For interface
#include "virtualExpr.h"


/* 
    Non-copyable (because of operands, which are unique_ptr) class Operation.
    class Operation takes lower operation from expression
    and build left and right operands by Factory
*/
class Operation : public virtualExpr {
public:
// Initializing methods + constructors
    Operation();
    Operation(const std::string&);
    ~Operation();
public:
// API methods
    double Calc() const override;
    bool BuildSuccessfully() const override;
public:
// Non-copyable
    Operation(const Operation& other) = delete;
    Operation& operator=(const Operation& other) = delete;
private:
    using upvirtualExpr = std::unique_ptr<virtualExpr>;
    bool _buildSuccessfully;
    char _operation;
    upvirtualExpr _left_up;
    upvirtualExpr _right_up;
};
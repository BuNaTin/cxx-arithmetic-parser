
#pragma once

/*
    Parent of Constant, Operation and Function classes.
    Member of pattern Composite.
*/
class virtualExpr {
public:
    virtual double Calc() const = 0;
    virtual bool BuildSuccessfully() const = 0;
    virtual ~virtualExpr() {};
};
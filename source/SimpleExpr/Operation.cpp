
#include "Operation.h"

#include <iostream>
#include <algorithm>

// For realisation
#include "../Parser/Parser.h"
#include "../Factory/Factory.h"
#include "../Data/OperationList.h"

Operation::Operation() : _operation(0), _buildSuccessfully(false),
                         _left_up(nullptr), _right_up(nullptr)
{
}

Operation::Operation(const std::string &res)
{
    std::string buf = Parser::ClearGarbage(res);
    auto operationSymb_iter = Parser::FindLowerOperation(buf);
    if (operationSymb_iter != buf.end())
    {
        _buildSuccessfully = true;
    }
    else
    {
        _buildSuccessfully = false;
        return;
    }
    _operation = *operationSymb_iter;
    std::string left, right;
    // Build string for left operand
    for (auto symb_iter = buf.begin(); symb_iter != operationSymb_iter; ++symb_iter)
    {
        left += *symb_iter;
    }
    // Build string for right operand
    for (auto symb_iter = ++operationSymb_iter; symb_iter != buf.end(); ++symb_iter)
    {
        right += *symb_iter;
    }
    // Init operands
    _left_up = Factory::MakeExpr(left);
    _right_up = Factory::MakeExpr(right);
    if (_left_up == nullptr or _right_up == nullptr)
    {
        _buildSuccessfully = false;
    }
}

Operation::~Operation()
{
}

double Operation::Calc() const
{
    if (_buildSuccessfully == false)
    {
        std::cerr << "Calc() for unsuccess build operation\n";
        return 0.0;
    }
    if (_left_up == nullptr or _right_up == nullptr)
    {
        std::cerr << "Operation with not initialise\n";
        return 0.0;
    }
    auto operation = OperationList::GetOperation(_operation);
    return operation(_left_up->Calc(), _right_up->Calc());
}

bool Operation::BuildSuccessfully() const
{
    if (_buildSuccessfully)
    {
        return _left_up->BuildSuccessfully() and _right_up->BuildSuccessfully();
    }
    return _buildSuccessfully; // false
}

#include "Factory.h"

#include <iostream>

// For realisation
#include "../SimpleExpr/Constant.h"
#include "../SimpleExpr/Operation.h"
#include "../SimpleExpr/Function.h"
#include "../Parser/Parser.h"

auto Factory::MakeExpr(const std::string &buffer)
    -> decltype(std::unique_ptr<virtualExpr>(nullptr))
{
    std::cout << "Try to make expr: " << buffer << '\n';
    if (Parser::HadOperation(buffer))
    {
        return std::make_unique<Operation>(buffer);
    }
    if (Parser::HadFunction(buffer))
    {
        return std::make_unique<Function>(buffer);
    }
    if (Parser::HadConstant(buffer))
    {
        return std::make_unique<Constant>(buffer);
    }
    // wrong string input
    return nullptr;
}
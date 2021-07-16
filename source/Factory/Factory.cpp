
#include "Factory.h"

#include <iostream>

// For realisation 
#include "../SimpleExpr/Constant.h"
#include "../SimpleExpr/Operation.h"
#include "../SimpleExpr/Function.h"
#include "../Parser/Parser.h"

auto Factory::MakeExpr(const std::string& buffer)
						-> decltype(std::unique_ptr<virtualExpr>(nullptr)) {
	if(Parser::HadOperation(buffer)) {
		return std::make_unique<Operation>(buffer);
	}
	if(Parser::HadFunction(buffer)) {
		return std::make_unique<Function>(buffer);
	}
	if(Parser::HadConstant(buffer)) {
		return std::make_unique<Constant>(buffer);
	}
	// Couldn't find current expression in buffer
	// Can use this for log
	// std::cerr<<"Error Expr:"<<buffer<<'\n'; 
	return nullptr;
}
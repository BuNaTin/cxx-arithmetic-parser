
#include "Operation.h"

#include <iostream>

// For realisation
#include "../Parser/Parser.h"
#include "../Factory/Factory.h"
#include "../Data/OperationList.h"

Operation::Operation():_operation(0),_buildSuccessfully(false) {

}

Operation::Operation(const std::string& res) {
	std::string buf = Parser::ClearGarbage(res);
	auto operationSymb_iter = Parser::FindLowerOperation(buf);
	if( operationSymb_iter != buf.end() ) {
		_buildSuccessfully = true;
	} else {
		_buildSuccessfully = false;
	}
	_operation = *operationSymb_iter;
	std::string left, right;
	for(auto symb_iter = buf.begin(); symb_iter != operationSymb_iter; ++symb_iter) {
		left += *symb_iter;
	}
	for(auto symb_iter = ++operationSymb_iter; symb_iter != buf.end(); ++symb_iter) {
		right += *symb_iter;
	}
	_left = Factory::MakeExpr(left);
	_right = Factory::MakeExpr(right);
	if(_left == nullptr or _right == nullptr) {
		_buildSuccessfully = false;
	}
}

Operation::~Operation() {

}

double Operation::Calc() const {
	if(_buildSuccessfully == false) {
		std::cerr<<"Calc() for unsuccess build operation\n";
		return 0.0;
	}
	if(_left == nullptr or _right == nullptr) {
		std::cerr<<"Operation with not initialise\n";
		return 0.0;
	}
	auto operation = OperationList::GetOperation(_operation);
	return operation(_left->Calc(),_right->Calc());
}

bool Operation::BuildSuccessfully() const {
	if(_buildSuccessfully) {
		return _left->BuildSuccessfully() and _right->BuildSuccessfully();
	} else {
		return _buildSuccessfully;
	}
}
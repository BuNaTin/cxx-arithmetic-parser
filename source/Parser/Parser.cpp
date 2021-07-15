
#include "Parser.h"

#include <iostream>
// For realisation
#include <algorithm>
#include <vector>

#include "../Data/OperationList.h"
#include "../Data/FunctionList.h"

char Parser::_openBracket = '(';
char Parser::_closeBracket = ')';

bool Parser::HadOperation(const std::string& buffer) {
	std::vector<char> operationList = OperationList::GetOperations(0);
	std::string newbuffer = ClearGarbage(buffer);
	int bracketsCnt = 0;
	for(auto symb : newbuffer) {
		if(symb == _openBracket)
			++bracketsCnt;
		if(symb == _closeBracket)
			--bracketsCnt;
		// Try to find out of brackets
		if(bracketsCnt == 0) {
			for(auto operation : operationList) {
				if( symb == operation ) {
					return true;
				}
			}	
		}
	}
	return false;
}

bool Parser::HadConstant(const std::string& buffer) {
	std::string newbuffer = ClearGarbage(buffer);
	bool ans = true;
	for(auto symb : newbuffer) {
		if( not( ('0' <= symb and symb <= '9') or symb == '.') ) {
			ans = false;
		}
	}
	return ans;
}

bool Parser::HadFunction(const std::string& buffer) {
	std::string newbuffer = ClearGarbage(buffer);
	auto symb_iter = newbuffer.begin();
	std::string _name;
	while(*symb_iter != _openBracket and symb_iter != newbuffer.end()) {
		_name+=*symb_iter;
		++symb_iter;
	}
	for( auto names : FunctionList::GetFunctions() ) {
		if( _name == names ) {
			return true;
		}
	}
	return false;
}

auto Parser::GetFuncName(const std::string& buffer)
						-> decltype(std::string()) {
	std::string newbuffer = ClearGarbage(buffer);
	std::string name;
	for(auto symb : newbuffer) {
		if( symb == _openBracket) {
			break;
		}
		name += symb;
	}
	return name;
}

auto Parser::GetFuncBody(const std::string& buffer) 
						-> decltype(std::string()) {
	auto symb_iter = buffer.begin();
	std::string body;
	int bracketsCnt = 1;
	// skip name
	while(*symb_iter != _openBracket) {
		++symb_iter;
	}
	// to skip openBracket
	++symb_iter; 
	while(symb_iter != buffer.end() ) {
		if(*symb_iter == _openBracket) 
			++bracketsCnt;
		if(*symb_iter == _closeBracket)
			--bracketsCnt;
		if(bracketsCnt < 1) 
			break;
		body += (*symb_iter);
		++symb_iter;
	}
	return body;
}

auto Parser::FindLowerOperation(const std::string& buffer) 
								-> decltype( buffer.begin() ){
	auto ans_iter = buffer.end();
	int operationLvl = 1;
	while(ans_iter == buffer.end() and operationLvl <= 3) {
		ans_iter = FindOneOfList(buffer, OperationList::GetOperations(operationLvl));
		++operationLvl;
	}
	if(ans_iter == buffer.end() ) {
		std::cerr<<"Couldn't find operation: "<<buffer<<'\n';
	}
	return ans_iter;
}

std::string Parser::ClearGarbage(const std::string& buffer) {
	std::string result = ClearSpace(buffer);
	result = ClearExtremeBrackets(result);
	return result;
}

std::string Parser::ClearSpace(const std::string& buffer) {
	std::string result;
	std::copy_if(buffer.begin(),buffer.end(),
				std::back_inserter(result),
				[](char symb) {
					return symb != ' ';
				}
	);
	return result;
}

std::string Parser::ClearExtremeBrackets(const std::string& buffer) {
	if(buffer.size() <= 1) {
		return buffer;
	}
	int bracketsCnt = 0;
	for(auto symb : buffer) {
		if( symb == _openBracket )
			++bracketsCnt;
		if( symb == _closeBracket )
			--bracketsCnt;			//	 last symbol |
		//								 			 v
		if( bracketsCnt == 0 and symb != *(--buffer.end() ) ){
			// Has no extreme brackets
			return buffer;
		}
	}
	std::string result;
	// from second to pre-last one
	std::copy(++buffer.begin(), --buffer.end(), 
			std::back_inserter(result)
	);
	return result;
}

auto Parser::FindOneOfList(const std::string& buffer, 
				const std::initializer_list<char>& operations) 
				-> decltype( buffer.end() ){
	//   last symbol
	auto symb_iter = --( buffer.end() );
	int bracketsCnt = 0;
	while( symb_iter != --buffer.begin() ) {
		if( *symb_iter == _openBracket )
			++bracketsCnt;
		if( *symb_iter == _closeBracket )
			--bracketsCnt;
		// Try to find out of brackets: 
		if( bracketsCnt == 0 ) {
			for( auto operation : operations) {
				if( *symb_iter == operation ) {
					return symb_iter;
				}
			}
		}

		--symb_iter;
	}
	// If couldn't find
	return buffer.end();
}
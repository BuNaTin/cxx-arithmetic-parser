
#pragma once

#include <string>
#include <initializer_list>

class Parser {
public:
	static bool HadOperation(const std::string& buffer);
	static bool HadConstant(const std::string& buffer);
	static bool HadFunction(const std::string& buffer);
	static auto GetFuncName(const std::string& buffer)
							-> decltype(std::string());
	static auto GetFuncBody(const std::string& buffer)
							-> decltype(std::string());
	static auto FindLowerOperation(const std::string& buffer)
								-> decltype( buffer.begin() );
	static std::string ClearGarbage(const std::string& buffer);
private:
	static char _openBracket;
	static char _closeBracket;
	static std::string ClearSpace(const std::string& buffer);
	static std::string ClearExtremeBrackets(const std::string& buffer);
	static auto FindOneOfList(const std::string& buffer, 
							const std::initializer_list<char>& operations)
							-> decltype( buffer.end() );
};
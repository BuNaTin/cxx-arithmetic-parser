
#pragma once

#include <string>
#include <initializer_list>


/* 
    class Parser is singleton look like microservice with all static members.
    
*/
class Parser {
public:
// API:
    // for Constant:
    static bool HadConstant(const std::string& buffer);
    // for Operation:
    static bool HadOperation(const std::string& buffer);
    static auto FindLowerOperation(const std::string& buffer)
                                -> decltype( buffer.begin() );
    // for Function:
    static bool HadFunction(const std::string& buffer);
    static auto GetFuncName(const std::string& buffer)
                            -> decltype(std::string());
    static auto GetFuncBody(const std::string& buffer)
                            -> decltype(std::string());
    // Clears all spaces and extreme brackets
    static std::string ClearGarbage(const std::string& buffer);
private:
    // like macros
    static char _openBracket;
    static char _closeBracket;
    static std::string ClearSpace(const std::string& buffer);
    static std::string ClearExtremeBrackets(const std::string& buffer);
    static auto FindOneOfList(const std::string& buffer, 
                            const std::initializer_list<char>& operations)
                            -> decltype( buffer.end() );
};
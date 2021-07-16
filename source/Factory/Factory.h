
#include <memory>
#include <string>

// For interface
#include "../SimpleExpr/virtualExpr.h"
    
/* 
    class Factory is singleton look like microservice with all static members.
    It builds all SimpleExpr types (Constant, Operation, Function)
*/
class Factory {
public:
	static auto MakeExpr(const std::string& buffer) 
				-> decltype(std::unique_ptr<virtualExpr>(nullptr));
};
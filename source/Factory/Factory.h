
#include <memory>
#include <string>

// For interface
#include "../SimpleExpr/virtualExpr.h"

class Factory {
public:
	static auto MakeExpr(const std::string& buffer) 
				-> decltype(std::unique_ptr<virtualExpr>(nullptr));
};
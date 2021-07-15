
#include "Constant.h"

Constant::Constant():_result(0),_buildSuccessfully(true) {

}

Constant::Constant(double res):_result(res),_buildSuccessfully(true) {

}

Constant::Constant(const std::string& res):_buildSuccessfully(true) {
	std::string buf;
	for( auto symb : res ) {
		if( ('0' <= symb and symb <= '9') or (symb == '.')) {
			buf+=symb;
		}
	}
	_result = atof( buf.c_str() );
}

Constant::~Constant() {

}

double Constant::Calc() const {
	return _result;
}

bool Constant::BuildSuccessfully() const {
	return _buildSuccessfully;
}

#include "Constant.h"

#include <algorithm>
#include <iterator>

Constant::Constant():_result(0),_buildSuccessfully(true) {

}

Constant::Constant(double res):_result(res),_buildSuccessfully(true) {

}

Constant::Constant(const std::string& res):_buildSuccessfully(true) {
	std::string buf;
    std::copy_if(res.begin(),res.end(),std::back_inserter(buf),
        [](char symb) {
            //       if in 0, 1, ..., 9
            return (('0' <= symb && symb <= '9') || (symb == '.'));
        }
    );
	_result = atof( buf.c_str() );
}

Constant::Constant(const Constant& other) {
    _result = other._result;
    _buildSuccessfully = other._result;
}

Constant::~Constant() {

}

double Constant::Calc() const {
	return _result;
}

bool Constant::BuildSuccessfully() const {
	return _buildSuccessfully;
}
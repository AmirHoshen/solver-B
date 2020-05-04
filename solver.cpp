

#include <iostream>
#include <math.h>
#include "solver.hpp"



using namespace solver;

bool solver::isZero(double x){
    return (x <= EPS && x >= -EPS);
}

/*********RealVariable*********/

const RealVariable& RealVariable::operator==(double x){
    return *this - x;
}

const RealVariable& RealVariable::operator==(RealVariable &x){
    return *this - x;
}

const RealVariable& RealVariable::operator+(double x){
    return RealVariable(this->_a, this->_b, this->_c + x);
}

const RealVariable& RealVariable::operator+(RealVariable &x){
    return RealVariable(this->_a + x._a, this->_b + x._b, this->_c + x._c);
}

const RealVariable& RealVariable::operator-(double x){
    return RealVariable(this->_a, this->_b, this->_c - x);
}

const RealVariable& RealVariable::operator-(RealVariable &x){
    return RealVariable(this->_a - x._a, this->_b - x._b, this->_c - x._c);
}

const RealVariable& RealVariable::operator*(double x){
    return RealVariable(this->_a * x, this->_b * x, this->_c * x);
}

const RealVariable& RealVariable::operator*(RealVariable &x){
    if(this->_a != 0 && (x._a != 0 || x._b != 0))throw runtime_error ("canot handle");
    if(x._a != 0 && (this->_a != 0 || this->_b != 0))throw runtime_error ("canot handle");
    return RealVariable(this->_a * x._a, this->_b * x._b, this->_c * x._c);
    
}

const RealVariable& RealVariable::operator^(double x){
    if(x == 0) return RealVariable(0, 0, 1);
    else if(x == 1) return *this;
    else if(x == 2) return RealVariable(_a * _a + _a * _b + _a * _c, 
                                        _a * _b + _b * _b + _b * _c,
                                        _a * _c + _b * _c + _c * _c);
    else throw runtime_error("cannot handle power greater then 2");
}

const RealVariable& RealVariable::operator/(double x){
    if(isZero(x)) throw runtime_error("can not divide by zero");
    return RealVariable(_a / x, _b / x, _c / x);
}

const RealVariable& RealVariable::operator/(RealVariable &x){
    if(isZero(x._a) && isZero(x._b) && isZero(x._c)) throw runtime_error("can not divide by zero");
    return RealVariable (_a / x._a, _b / x._a, _c / x._a);
}

const RealVariable& solver::operator==(double x, RealVariable &y){
    return y == x;
}

const RealVariable& solver::operator+(double x, RealVariable &y){
    return y + x;
}

const RealVariable& solver::operator-(double x, RealVariable &y){
    return RealVariable(-y._a, -y._b, -y._c + x);
}

const RealVariable& solver::operator*(double x, RealVariable &y){
    return y * x;
}

const RealVariable& solver::operator/(double x, RealVariable &y){
    return y;
}

const double solver::solve(RealVariable& x){
    return 0;
}


/*********complex*********/

const ComplexVariable& ComplexVariable::operator+(std::complex<double> x){
    return *this;
}
const ComplexVariable& ComplexVariable::operator==(std::complex<double> x){
    return *this;
}

const ComplexVariable& ComplexVariable::operator+(ComplexVariable &x){
    return *this;
}
const ComplexVariable& ComplexVariable::operator==(ComplexVariable &x){
    return *this;
}

const ComplexVariable& ComplexVariable::operator-(std::complex<double> x){
    return *this;
}

const ComplexVariable& ComplexVariable::operator-(ComplexVariable &x){
    return *this;
}

const ComplexVariable& ComplexVariable::operator*(std::complex<double> x){
    return *this;
}

const ComplexVariable& ComplexVariable::operator*(ComplexVariable &x){
    return *this;
}

const ComplexVariable& ComplexVariable::operator^(std::complex<double> x){
    return *this;
}

const ComplexVariable& ComplexVariable::operator^(ComplexVariable &x){
    return *this;
}

const ComplexVariable& ComplexVariable::operator/(std::complex<double> x){
    return *this;
}

const ComplexVariable& ComplexVariable::operator/(ComplexVariable &x){
    return *this;
}

const ComplexVariable& solver::operator==(std::complex<double> x, ComplexVariable &y){
    return y;
}

const ComplexVariable& solver::operator+(std::complex<double> x, ComplexVariable &y){
    return y;
}

const ComplexVariable& solver::operator-(std::complex<double> x, ComplexVariable &y){
    return y;
}

const ComplexVariable& solver::operator*(std::complex<double> x, ComplexVariable &y){
    return y;
}

const ComplexVariable& solver::operator/(std::complex<double> x, ComplexVariable &y){
    return y;
}

const std::complex<double> solver::solve(ComplexVariable& x){
    return 0;
}

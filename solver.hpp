#include <iostream>
#include <complex>
#define EPS .0001
using namespace std;
namespace solver {

    bool isZero (double x);
    class RealVariable {
    public:
        double _a = 0;
        double _b = 1;
        double _c = 0;
        RealVariable(){}
        RealVariable(double a, double b, double c){
            this->_a = a;
            this->_b = b;
            this->_c = c;
        }
       
        const RealVariable& operator==(double x);

        const RealVariable& operator==(RealVariable &x);

        const RealVariable& operator+(double x);

        const RealVariable& operator+(RealVariable &x);

        const RealVariable& operator-(double x);

        const RealVariable& operator-(RealVariable &x);

        const RealVariable& operator*(double x);

        const RealVariable& operator*(RealVariable &x);

        const RealVariable& operator^(double x);

        const RealVariable& operator/(double x);

        const RealVariable& operator/(RealVariable &x);

    };

    const RealVariable& operator==(double x, RealVariable &y);

    const RealVariable& operator+(double x, RealVariable &y);

    const RealVariable& operator-(double x, RealVariable &y);

    const RealVariable& operator*(double x, RealVariable &y);

    const RealVariable& operator/(double x, RealVariable &y);


    class ComplexVariable {
    public:
        std::complex<double> coff = 1;
        std::complex<double> power = 1;
        
        const ComplexVariable& operator+(std::complex<double> x);

        const ComplexVariable& operator==(std::complex<double> x);

        const ComplexVariable& operator+(ComplexVariable &x);
        
        const ComplexVariable& operator==(ComplexVariable &x);

        const ComplexVariable& operator-(std::complex<double> x);

        const ComplexVariable& operator-(ComplexVariable &x);

        const ComplexVariable& operator*(std::complex<double> x);

        const ComplexVariable& operator*(ComplexVariable &x);

        const ComplexVariable& operator^(std::complex<double> x);

        const ComplexVariable& operator^(ComplexVariable &x);

        const ComplexVariable& operator/(std::complex<double> x);

        const ComplexVariable& operator/(ComplexVariable &x);
    };
    
    const ComplexVariable& operator==(std::complex<double> x, ComplexVariable &y);

    const ComplexVariable& operator+(std::complex<double> x, ComplexVariable &y);

    const ComplexVariable& operator-(std::complex<double> x, ComplexVariable &y);

    const ComplexVariable& operator*(std::complex<double> x, ComplexVariable &y);

    const ComplexVariable& operator/(std::complex<double> x, ComplexVariable &y);

    const double solve(RealVariable& x);

    const ::complex<double> solve(ComplexVariable& x);

};
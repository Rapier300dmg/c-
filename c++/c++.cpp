#include <iostream>
#include <stdexcept>
#include <numeric> 

class Fraction {
private:
    int numerator;   
    int denominator; 

    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    void input() {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    void print() const {
        if (denominator == 1) {
            std::cout << numerator;
        }
        else {
            std::cout << numerator << "/" << denominator;
        }
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }


    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        if (fraction.denominator == 1) {
            os << fraction.numerator;
        }
        else {
            os << fraction.numerator << "/" << fraction.denominator;
        }
        return os;
    }

  
    friend std::istream& operator>>(std::istream& is, Fraction& fraction) {
        is >> fraction.numerator >> fraction.denominator;
        if (fraction.denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        fraction.simplify();
        return is;
    }
};

int main() {
    try {
        Fraction f1, f2;

        std::cout << "Enter first fraction (numerator and denominator): ";
        std::cin >> f1;

        std::cout << "Enter second fraction (numerator and denominator): ";
        std::cin >> f2;

        std::cout << "First fraction: " << f1 << std::endl;
        std::cout << "Second fraction: " << f2 << std::endl;

        std::cout << "Sum: " << f1 + f2 << std::endl;
        std::cout << "Difference: " << f1 - f2 << std::endl;
        std::cout << "Product: " << f1 * f2 << std::endl;
        std::cout << "Quotient: " << f1 / f2 << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

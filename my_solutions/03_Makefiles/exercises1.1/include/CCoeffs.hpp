#pragma once
class CCoeffs{
public:
    double a, b, c;
    CCoeffs();
    void print_coeffs() const;
    void input_coeffs();
};

void solve_quadratic_equation(const CCoeffs& coefficients);

#include <iostream>
#include <symengine/expression.h>
#include <symengine/mul.h>
#include <symengine/pow.h>
#include <symengine/symengine_exception.h>

using SymEngine::Expression;
using SymEngine::pow;
using SymEngine::symbol;
using SymEngine::expand;

int main() {
    int n, m;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    std::cout << "Enter the value of m: ";
    std::cin >> m;

    Expression x(symbol("x"));
    Expression expr = 0;

    // Construct the expression (x^0 + x^1 + ... + x^n)
    for (int i = 0; i <= n; ++i) {
        expr = expr + pow(x, i);
    }

    // Raise the expression to the power of m
    Expression expanded = pow(expr, m);

    // Expand the expression
    expanded = expand(expanded);

    // Print the expanded expression
    std::cout << "Expanded expression: " << expanded << std::endl;

    return 0;
}

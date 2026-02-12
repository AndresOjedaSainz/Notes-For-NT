#include <iostream>
#include <cmath>


int main(void)
{
    double a,b,c;

    std::cout << "Enter Side A: ";
    std::cin >> a;

    std::cout << "Enter Side B: ";
    std::cin >> b;

    a = pow(a, 2);
    b = pow(b, 2);
    c = sqrt(a + b);

    std::cout << "Side C: " << c;

    return 0;
}
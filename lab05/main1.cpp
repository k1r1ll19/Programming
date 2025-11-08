#include <iostream>

void Midpoint(double left, double right) {
    std::cout << "\nИспользуется функция вычисления середины интервала..." << std::endl;

    double midpoint = (left + right) / 2.0;
    std::cout << "Середина интервала [" << left << "; " << right << "] равна: " << midpoint << std::endl;
}
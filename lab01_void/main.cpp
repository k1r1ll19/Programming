#include <iostream>

void Midpoint(double left, double right) {
    std::cout << "Исп. функция вычисления середины интервала" << std::endl;
    
    double midpoint = (left + right) / 2.0;
    std::cout << "Середина интервала [" << left << "; " << right << "] равна: " << midpoint << std::endl;
}

int main() {
    double a, b;
    
    std::cout << "Введите левый край интервала (a): ";
    std::cin >> a;
    
    std::cout << "Введите правый край интервала (b): ";
    std::cin >> b;
    
    if (a >= b) {
        std::cout << "Ошибка: левый край интервала должен быть меньше правого!" << std::endl;
        return 1;
    }
    
    Midpoint(a, b);
    
    return 0;
}

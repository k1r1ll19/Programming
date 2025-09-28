#include <iostream>
#include <cmath>

int main(){

    // double, т.к ось действительных сиел и для широкого диапазона 0.00000000000000000
    double left, right;

    std::cout << "Введите левый конец интервала: ";
    std::cin >> left;
    std::cout << "Введите правый конец интервала: ";
    std::cin >> right;

    double middle = (left + right) / 2.0; // считаем середину интервала

    std::cout << "\nСередина интервала: " << middle << std::endl;

    /*
    std::cout << "\nТип данных: double" << std::endl;
    int bits = sizeof(double) * 8;
    int minValue = -pow(2, bits - 1);
    int maxValue = pow(2, bits - 1) - 1;
    
    std::cout << "Минимальное значение double: " << minValue << std::endl;
    std::cout << "Максимальное значение double: " << maxValue << std::endl;
    */
    return 0;
}
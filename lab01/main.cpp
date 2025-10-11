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

    std::cout << "double занимает: " << sizeof(double) * 8 << "бит(а)" << std::endl;
    std::cout << "примерный диапазон = от -1.7e308 до 1.7e308" << std::endl;
    return 0;
}
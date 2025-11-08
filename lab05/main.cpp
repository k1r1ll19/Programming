#include <iostream>

void Midpoint(double left, double right);

double calculate(int c) {
    std::cout << "Используется функция для одного числа (обратное значение)" << std::endl;
    if (c == 0) {
        std::cout << "Ошибка: нельзя делить на ноль!" << std::endl;
        return 0.0;
    }
    return 1.0 / c;
}

int calculate(int a, int b) {
    std::cout << "Используется функция суммы квадратов (a*a + 2*a*b + b*b)" << std::endl;
    return a * a + 2 * a * b + b * b;
}

int main() {
    int choice;
    std::cout << "Введите номер пункта (1 - обратное число, 2 - квадрат суммы): ";
    std::cin >> choice;

    if (choice == 1) {
        int x;
        std::cout << "Введите одно целое число: ";
        std::cin >> x;
        double result = calculate(x);
        std::cout << "Результат: " << result << std::endl;
    }
    else if (choice == 2) {
        int a, b;
        std::cout << "Введите два целых числа через пробел: ";
        std::cin >> a >> b;
        int result = calculate(a, b);
        std::cout << "Результат: " << result << std::endl;
    }
    else {
        std::cout << "Ошибка: неправильный выбор!" << std::endl;
        return 1;
    }

    double left, right;
    std::cout << "Теперь вычислим середину интервала" << std::endl;
    std::cout << "Введите левый край интервала (a): ";
    std::cin >> left;
    std::cout << "Введите правый край интервала (b): ";
    std::cin >> right;

    if (left >= right) {
        std::cout << "Ошибка: левый край интервала должен быть меньше правого!" << std::endl;
        return 1;
    }

    Midpoint(left, right);

    return 0;
}
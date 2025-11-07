#include <iostream>

// Функция для одного числа
double oneNumber(int a) {
    std::cout << "Используется функция для одного числа (обратное значение)" << std::endl;
    if (a == 0) {
        std::cout << "Ошибка: нельзя делить на ноль!" << std::endl;
        return 0;
    }
    return 1.0 / a; // возвращаем обратное значение числа
}

// Функция для двух чисел
int twoNumbers(int a, int b) {
    std::cout << "Используется функция суммы квадратов (a*a + 2*a*b + b*b)" << std::endl;
    return a * a + 2 * a * b + b * b;
}

int main() {
    int choice;
    std::cout << "Введите номер пункта (1 - обратное число, 2 - квадрат суммы): ";
    std::cin >> choice;

    if (choice == 1) {
        // Если выбран пункт 1 — вводим одно число
        int x;
        std::cout << "Введите одно целое число: ";
        std::cin >> x;

        double result = oneNumber(x); // вызываем функцию для одного числа
        std::cout << "Результат: " << result << std::endl;
    }
    else if (choice == 2) {
        // Если выбран пункт 2 — вводим два числа
        int a, b;
        std::cout << "Введите два целых числа через пробел: ";
        std::cin >> a >> b;

        int result = twoNumbers(a, b); // вызываем функцию для двух чисел
        std::cout << "Результат: " << result << std::endl;
    }
    else {
        // Если введён неправильный пункт
        std::cout << "Ошибка: такого пункта нет!" << std::endl;
    }

    return 0; // конец программы
}
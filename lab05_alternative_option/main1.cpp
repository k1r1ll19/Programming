#include <iostream>

double processOneNumber(int a) {
    std::cout << "Исп. функция обратного значения числа" << std::endl;
    if (a == 0) {
        std::cout << "Ошибка: деление на ноль!" << std::endl;
        return 0.0; // Условное значение при ошибке
    }
    return 1.0 / a;
}


double processTwoNumbers(int a, int b) {
    std::cout << "Исп. функция вычисления a*a + 2*a*b + b*b" << std::endl;
    return a * a + 2 * a * b + b * b;
}

int main() {
    int choice;
    int num1 = 0, num2 = 0, num3 = 0;
    double result = 0.0;

    std::cout << "Выберите пункт (1 или 2): ";
    std::cin >> choice;

    if (choice != 1 && choice != 2) {
        std::cout << "Неверный выбор! Должен быть 1 или 2." << std::endl;
        return 1;
    }

    std::cout << "Введите три числа (если число = 0, оно не учитывается): ";
    std::cin >> num1 >> num2 >> num3;

    // Подсчёт количества ненулевых чисел
    int count = 0;
    if (num1 != 0) count++;
    if (num2 != 0) count++;
    if (num3 != 0) count++;

    if (choice == 1) {
        if (count == 1) {
            int value = (num1 != 0) ? num1 : (num2 != 0 ? num2 : num3);
            result = processOneNumber(value);
        }
        else {
            std::cout << "Для пункта 1 нужно ровно одно ненулевое число!" << std::endl;
            return 1;
        }
    }
    else if (choice == 2) { // choice == 2
        if (count == 2) {
            // Получаем два ненулевых числа
            int a = (num1 != 0) ? num1 : num2;
            int b = (num2 != 0 && num1 != 0) ? num2 : 
                    (num2 != 0) ? num2 : num3;
            result = processTwoNumbers(a, b);
        }
        else {
            std::cout << "Для пункта 2 нужно ровно два ненулевых числа!" << std::endl;
            return 1;
        }
    }

    // Вывод результата
    std::cout << "Результат: " << result << std::endl;

    return 0;
}
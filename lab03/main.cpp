#include <iostream>


int main() {
    // ---------- ЗАДАНИЕ 1 ----------
    int N; // количество чисел
    std::cout << "Введите количество чисел в последовательности: ";
    std::cin >> N;

    double number;              // текущее число
    double sum = 0;             // сумма чисел, не превышающих 10.12
    double minValue = 0;        // наименьшее подходящее число
    int minIndex = -1;          // его номер в последовательности (начинаем с 1)
    bool found = false;         // было ли найдено хоть одно подходящее число

    for (int i = 1; i <= N; i++) {
        std::cout << "Введите число #" << i << ": ";
        std::cin >> number;

        if (number > 10.12) {
            continue; // пропускаем числа, которые больше 10.12
        }

        // если число подходит
        sum += number;

        if (!found) {
            // первое подходящее число
            minValue = number;
            minIndex = i;
            found = true;
        } else if (number < minValue) {
            // обновляем минимум
            minValue = number;
            minIndex = i;
        }
    }

    if (found) {
        std::cout << "\nСумма всех чисел, не превышающих 10.12 = " << sum << std::endl;
        std::cout << "Наименьшее из них = " << minValue << std::endl;
        std::cout << "Его номер в последовательности = " << minIndex << std::endl;
    } else {
        std::cout << "\nНет чисел, не превышающих 10.12.\n";
    }

    return 0;
}

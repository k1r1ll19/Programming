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

// ---------- ЗАДАНИЕ 2 ----------

    int X; // переменная для числа
    std::cout << "Введите целое число X (|X| < 1000): " << std::endl;
    std::cin >> X;

    // Проверяем условие |X| < 1000
    if (X <= -1000 || X >= 1000) {
        std::cout << "Ошибка: число должно быть в диапазоне -999 ... 999" << std::endl;
        return 0;
    }

    int temp = X; // временная копия числа
    if (temp < 0) temp = -temp; // убираем минус, если число отрицательное

    int index = 0;// позиция цифры (справа налево)
    int lastIndex = -1;// запоминаем индекс последней найденной 3
    int position = 0;// счётчик цифр

    while (temp > 0) {
        int digit = temp % 10; // берём последнюю цифру
        position++;
        if (digit == 3) {
            lastIndex = position; // сохраняем позицию последней 3
        }
        temp /= 10; // убираем последнюю цифру
    }

    if (lastIndex == -1) {
        std::cout << "Цифры 3 нет." << std::endl;
    } else {
        int totalDigits = position;// сколько всего цифр
        int indexFromLeft = totalDigits - lastIndex + 1;// считаем индекс слева
        std::cout << "Индекс последней цифры 3: " << indexFromLeft << std::endl;
    }

    return 0;
}

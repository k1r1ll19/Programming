#include <iostream>
#include <bitset>
#include <cmath>


int main() {
    // ======== ПУНКТ 1 ========
    short A;
    int i;

    std::cout << "Введите число A (тип short): ";
    std::cin >> A;

    std::cout << "Введите номер бита i (от 0 до 7): ";
    std::cin >> i;

    // Проверка правильности ввода i
    if (i < 0 || i > 7) {
        std::cout << "Ошибка: номер бита должен быть от 0 до 7." << std::endl;
        return 0;
    }
    std::cout << "Число A до изменений: " << A << " = " << std::bitset<8>(A) << std::endl;
    int bit_i = (A >> i) & 1;//извлекаем i-й бит
    int bit0 = A & 1;

    
    std::cout << "i-й бит (" << i << ") равен: " << bit_i << std::endl;



    if (bit_i == 0) {
        std::cout << "i-й бит равен 0 → выполняем обмен 0-го и i-го битов." << std::endl;

        // Если биты разные — меняем их местами
        if (bit0 != bit_i) {
            // Устанавливаем i-й бит в значение 0-го бита
            if (bit0 == 1)
                A |= (1 << i);   
            else
                A &= ~(1 << i);

            // Устанавливаем 0-й бит в значение i-го бита
            if (bit_i == 1)
                A |= 1;
            else
                A &= ~1;
        }

        std::cout << "Результат: A = " << A << " = " << std::bitset<8>(A) << std::endl;
    }
    else {
        std::cout << "i-й бит равен 1 → обмен не выполняется." << std::endl;
        // Если i-й бит равен 1 — работаем с тремя числами
        int x, y, z;
        std::cout << "Введите три целых числа: ";
        std::cin >> x >> y >> z;

        int ax = abs(x);
        int ay = abs(y);
        int az = abs(z);

        // Проверяем равенство модулей
        if (ax == ay || ay == az || ax == az) {
            std::cout << "Код 0. Вычисление невозможно." << std::endl;
        } 
        else {
            // Находим среднее по модулю
            int maxAbs = ax;
            if (ay > maxAbs)
                maxAbs = ay;
            if (az > maxAbs)
                maxAbs = az;

            int minAbs = ax;
            if (ay < minAbs)
                minAbs = ay;
            if (az < minAbs)
                minAbs = az;

            int middle;

            if ((ax != maxAbs) && (ax != minAbs))
                middle = x;
            else if ((ay != maxAbs) && (ay != minAbs)) 
                middle = y;
            else
                middle = z;

            std::cout << "Среднее по модулю число: " << middle << std::endl;
        }
    }

    // ======== ПУНКТ 2 ========
    int N;
    std::cout << "\nВведите номер региона: ";
    std::cin >> N;

    switch (N) {
        case 102: 
        case 116: 
        case 716:
            std::cout << "Республика Татарстан" << std::endl; break;
        case 11: std::cout << "Республика Коми" << std::endl; break;
        case 13: std::cout << "Республики Мордовия" << std::endl; break;
        case 15: std::cout << "Республика Северная Осетия" << std::endl; break;
        
        default: std::cout << "Информация временно недоступна." << std::endl; break;
        
    }

    return 0;
}

//102, 11, 13, 15, 116, 716.
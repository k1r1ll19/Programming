#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>


// ПУНКТ 1: Функции для vector

// Просмотр массива
void printVector(const std::vector<int>& v) {
    std::cout << "[ ";
    for (int x : v) std::cout << x << " ";
    std::cout << "]";
}

// Добавить в начало
void addToStart(std::vector<int>& v, int value) {
    v.insert(v.begin(), value);
}

// Добавить в конец
void addToEnd(std::vector<int>& v, int value) {
    v.push_back(value);
}

// Очистить массив
void clearVector(std::vector<int>& v) {
    v.clear();
}

// Поиск всех индексов элемента
std::vector<int> searchElement(const std::vector<int>& v, int value) {
    std::vector<int> indexes;
    for (int i = 0; i < v.size(); i++)
        if (v[i] == value) indexes.push_back(i);
    return indexes;
}

// ВАРИАНТ 5

void variant5(std::vector<int>& v) {
    int K;
    std::cout << "Введите K: ";
    std::cin >> K;

    int sum = 0, n = 0;
    while (sum < K) {
        n++;
        sum += n;
    }

    std::cout << "Массив ДО: ";
    printVector(v);
    std::cout << std::endl;

    if (sum == K) {
        std::cout << "K можно представить как сумму 1+2+...+" << n << std::endl;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
    } 
    else {
        std::cout << "K нельзя представить такой суммой, дублирую элементы на чётных позициях...\n";

        std::vector<int> temp;
        for (int i = 0; i < v.size(); i++) {
            temp.push_back(v[i]);
            if (i % 2 == 0) temp.push_back(v[i]);
        }
        v = temp;
    }

    std::cout << "Массив ПОСЛЕ: ";
    printVector(v);
    std::cout << std::endl;
}

// ПУНКТ 2: Работа с std::array

const int N = 10;

// сортировка пузырьком 
void Sort_byValue(std::array<int, N> arr) {  
    bool swapped = true;  
    int start = 0, end = N - 1;  
  
    while (swapped) {  
        swapped = false;  
  
        for (int i = start; i < end; i++)  
            if (arr[i] > arr[i+1]) { 
                std::swap(arr[i], arr[i+1]);  
                swapped = true; 
            }
  
        if (!swapped) break;  
        swapped = false;  
        end--;  
  
        for (int i = end; i > start; i--)  
            if (arr[i] < arr[i-1]) { 
                std::swap(arr[i], arr[i-1]);  
                swapped = true; 
            }
  
        start++;  
    }  

    std::cout << "СОРТИРОВКА ПО ЗНАЧЕНИЮ (исходный не меняется):\n";
    std::cout << "[ ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "]\n";
}

void Sort_byReference(std::array<int, N>& arr) {
    bool swapped = true;
    int start = 0;
    int end = N - 1;

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;

        swapped = false;
        end--;

        // Проход справа налево
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }

        start++;
    }
}

// Пункт 1

int main() {

    std::vector<int> v = {1, 3, 2, 4};
    int choice;

    do {
        std::cout << "\n--- М Е Н Ю ---\n";
        std::cout << "0. Выход\n";
        std::cout << "1. Просмотр массива\n";
        std::cout << "2. Добавить элемент в начало\n";
        std::cout << "3. Добавить элемент в конец\n";
        std::cout << "4. Очистить массив\n";
        std::cout << "5. Поиск элемента в массиве\n";
        std::cout << "6. Вариант 5\n";
        std::cout << "7. Пункт 2 (array)\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            printVector(v);
            std::cout << std::endl;
            break;

        case 2: {
            int x;
            std::cout << "Введите число: ";
            std::cin >> x;
            addToStart(v, x);
            break;
        }

case 3: {
            int x;
            std::cout << "Введите число: ";
            std::cin >> x;
            addToEnd(v, x);
            break;
        }

        case 4:
            clearVector(v);
            std::cout << "Массив очищен.\n";
            break;

        case 5: {
            int x;
            std::cout << "Введите число: ";
            std::cin >> x;
            std::vector<int> idx = searchElement(v, x);

            if (idx.empty())
                std::cout << "Элемент не найден.\n";
            else {
                std::cout << "Найдено на индексах: [ ";
                for (int i : idx) std::cout << i << " ";
                std::cout << "]\n";
            }
            break;
        }

        case 6:
            variant5(v);
            break;

        case 7: {
            std::cout << "ПУНКТ 2 (array):\n";
            std::array<int, N> arr;

            std::srand(std::time(0));
            for (int& x : arr)
                x = std::rand() % 21 - 10;

            std::cout << "Исходный массив:\n[ ";
            for (int x : arr) std::cout << x << " ";
            std::cout << "]\n";

            Sort_byValue(arr);

            Sort_byReference(arr);

            std::cout << "ПОСЛЕ сортировки по ссылке:\n[ ";
            for (int x : arr) std::cout << x << " ";
            std::cout << "]\n";
            break;
        }
	
	default:
            std::cout << "Неверный пункт меню!\n";
            break;

        }

    } while (choice != 0);

    std::cout << "Выход из программы...\n";

    return 0;
}
#include <iostream>
#include <cstdlib>

// Функция для поиска столбцов с нулевыми значениями
int* findZeroColumns(int** matrix, int rows, int cols, int& zeroCount) {
    // Создаем временный массив для хранения индексов столбцов с нулями
    int* tempZeroCols = (int*)malloc(cols * sizeof(int));
    zeroCount = 0;
    
    for (int j = 0; j < cols; j++) {
        bool hasZero = false;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            tempZeroCols[zeroCount] = j;
            zeroCount++;
        }
    }
    
    // Создаем финальный массив нужного размера
    int* result = (int*)malloc(zeroCount * sizeof(int));
    for (int i = 0; i < zeroCount; i++) {
        result[i] = tempZeroCols[i];
    }
    free(tempZeroCols);  // Освобождаем временный массив
    
    return result;
}

int main() {
    // ---ЗАДАЧА 1: ДВУМЕРНЫЙ ДИНАМИЧЕСКИЙ МАССИВ---
    
    // Создаем начальную матрицу 2x2
    int** matrix = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)malloc(2 * sizeof(int));
    }
    
    int A, B, C, D;
    
    // Ввод и проверка начальных значений
    std::cout << "Введите 4 целых числа для матрицы 2x2 (A, B, C, D):" << std::endl;
    
    // Ввод A с проверкой
    do {
        std::cout << "A = ";
        std::cin >> A;
        if (A < 0) {
            std::cout << "Ошибка! A не может быть отрицательным. Повторите ввод." << std::endl;
        }
    } while (A < 0);
    
    // Ввод B с проверкой
    do {
        std::cout << "B = ";
        std::cin >> B;
        if (B < 0) {
            std::cout << "Ошибка! B не может быть отрицательным. Повторите ввод." << std::endl;
        }
    } while (B < 0);
    
    std::cout << "C = ";
    std::cin >> C;
    std::cout << "D = ";
    std::cin >> D;
    
    // Заполняем начальную матрицу
    matrix[0][0] = A;
    matrix[0][1] = B;
    matrix[1][0] = C;
    matrix[1][1] = D;
    
    std::cout << "\nНачальная матрица:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    // Увеличиваем матрицу: добавляем A строк снизу и B столбцов справа
    int newRows = 2 + A;
    int newCols = 2 + B;
    
    // Перераспределяем память для новых строк
    matrix = (int**)realloc(matrix, newRows * sizeof(int*));
    // Выделяем память для новых строк
    for (int i = 2; i < newRows; i++) {
        matrix[i] = (int*)malloc(newCols * sizeof(int));
    }
    // Перераспределяем память для существующих строк (увеличиваем столбцы)
    for (int i = 0; i < newRows; i++) {
        matrix[i] = (int*)realloc(matrix[i], newCols * sizeof(int));
    }
    
    // Заполняем расширенную матрицу по формуле
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            if (i < 2 && j < 2) {
                // Оставляем исходные значения для начальной матрицы
                continue;
            } else {
                // Заполняем по формуле: (i-1)*C + (j-1)*D
                matrix[i][j] = (i - 1) * C + (j - 1) * D;
            }
        }
    }
    
    std::cout << "\nРасширенная матрица:" << std::endl;
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    // Вызываем функцию для поиска столбцов с нулями
    int zeroCount;
    int* zeroColumns = findZeroColumns(matrix, newRows, newCols, zeroCount);
    
    std::cout << "\nСтолбцы с нулевыми значениями: ";
    for (int i = 0; i < zeroCount; i++) {
        std::cout << zeroColumns[i] << " ";
    }
    std::cout << std::endl;
    
    // Удаляем столбцы с нулями
    if (zeroCount > 0) {
        int finalCols = newCols - zeroCount;
        
        // Создаем новую матрицу без нулевых столбцов
        int** finalMatrix = (int**)malloc(newRows * sizeof(int*));
        for (int i = 0; i < newRows; i++) {
            finalMatrix[i] = (int*)malloc(finalCols * sizeof(int));
            int newJ = 0;
            for (int j = 0; j < newCols; j++) {
                // Проверяем, не является ли текущий столбец нулевым
                bool isZeroCol = false;
                for (int k = 0; k < zeroCount; k++) {
                    if (j == zeroColumns[k]) {
                        isZeroCol = true;
                        break;
                    }
                }
                // Если столбец не нулевой, копируем его
                if (!isZeroCol) {
                    finalMatrix[i][newJ] = matrix[i][j];
                    newJ++;
                }
            }
        }
        
        // Освобождаем старую матрицу
        for (int i = 0; i < newRows; i++) {
            free(matrix[i]);
        }
        free(matrix);
        
        std::cout << "\nФинальная матрица после удаления столбцов с нулями:" << std::endl;
        for (int i = 0; i < newRows; i++) {
            for (int j = 0; j < finalCols; j++) {
                std::cout << finalMatrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        
        // Освобождаем финальную матрицу
        for (int i = 0; i < newRows; i++) {
            free(finalMatrix[i]);
        }
        free(finalMatrix);
    } else {
        std::cout << "\nНет столбцов с нулевыми значениями для удаления." << std::endl;
        // Освобождаем исходную матрицу
        for (int i = 0; i < newRows; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
    
    // Освобождаем память
    free(zeroColumns);
    
    // ---ЗАДАЧА 2: УКАЗАТЕЛИ И АДРЕСА---
    
    std::cout << "\n=== ЗАДАЧА 2: УКАЗАТЕЛИ И АДРЕСА ===" << std::endl;
    
    double a, b;
    std::cout << "Введите два вещественных числа a и b:" << std::endl;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    
    std::cout << "Исходные значения: a = " << a << ", b = " << b << std::endl;
    
    // Создаем указатели и направляем их на переменные
    double* ptrA = &a;  // ptrA хранит адрес переменной a
    double* ptrB = &b;  // ptrB хранит адрес переменной b
    
    std::cout << "Адрес a: " << ptrA << ", значение: " << *ptrA << std::endl;
    std::cout << "Адрес b: " << ptrB << ", значение: " << *ptrB << std::endl;
    
    // Увеличиваем значение a в 3 раза через указатель
    *ptrA = *ptrA * 3;  // Меняем значение по адресу, на который указывает ptrA
    std::cout << "После увеличения a в 3 раза: a = " << a << std::endl;
    
    // Меняем местами значения через указатели
    double temp = *ptrA;  // Временная переменная для обмена
    *ptrA = *ptrB;        // Значению по адресу ptrA присваиваем значение по адресу ptrB
    *ptrB = temp;         // Значению по адресу ptrB присваиваем сохраненное значение
    
    std::cout << "После обмена: a = " << a << ", b = " << b << std::endl; 
    
    return 0;
    
}
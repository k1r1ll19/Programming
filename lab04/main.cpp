#include <iostream> 

int main() {
    // ======== ПУНКТ 1 ========
    const int size = 8;// размер массива (номер варианта + 3 = 8)
    int arr[size];// создаем массив из 8 элементов
    int count25 = 0;// переменная для подсчета количества чисел 25

    std::cout << "Введите 8 чисел для массива: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];// вводим элементы массива
        if (arr[i] == 25)// если элемент равен 25
            count25++;// увеличиваем счетчик
    }

    // если число 25 встречается больше двух раз
    if (count25 > 2) {
        // сортировка массива по возрастанию
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        std::cout << "\nЧисло 25 встречается больше двух раз.\n";
        std::cout << "Отсортированный массив: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
    } else {
        std::cout << "\nЧисло 25 встречается " << count25 << " раз(а), сортировка не выполняется.";
    }

    std::cout << "\n\n";

    // ======== ПУНКТ 2 ========
    const int rows = 3;// количество строк
    const int cols = 4;// количество столбцов
    int matrix[rows][cols];// создаем матрицу 3x4

    std::cout << "Введите элементы матрицы 3x4:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];  // ввод каждого элемента
        }
    }

    int maxZeros = -1;
    int rowIndex = -1;

    // поиск строки с максимальным количеством нулей
    for (int i = 0; i < rows; i++) {
        int zeroCount = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0)
                zeroCount++;
        }

        if (zeroCount > maxZeros) {
            maxZeros = zeroCount;
            rowIndex = i;
        }
    }

    // если есть хотя бы один ноль
    if (rowIndex != -1 && maxZeros > 0) {
        for (int j = 0; j < cols; j++) {
            if (matrix[rowIndex][j] == 0)
                matrix[rowIndex][j] = 888;// заменяем нули на 888
        }
    }

    std::cout << "\nИзмененная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";// вывод элементов
        }
        std::cout << std::endl;
    }

    return 0;
}
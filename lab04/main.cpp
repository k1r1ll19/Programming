#include <iostream> 

int main() {
    const int size = 8;
    int arr[size];
    int count25 = 0;

    std::cout << "Введите 8 чисел для массива: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
        if (arr[i] == 25)
            count25++;
    }

    if (count25 > 2) {
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

    const int rows = 3;
    const int cols = 4;
    int matrix[rows][cols];

    std::cout << "Введите элементы матрицы 3x4:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int maxZeros = -1;
    int rowIndex = -1;

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

    if (rowIndex != -1 && maxZeros > 0) {
        for (int j = 0; j < cols; j++) {
            if (matrix[rowIndex][j] == 0)
                matrix[rowIndex][j] = 888;
        }
    }

    std::cout << "\nИзмененная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
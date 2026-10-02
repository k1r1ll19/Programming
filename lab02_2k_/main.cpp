#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstddef>

class ZubchatyiMassiv {
private:
    std::vector<std::vector<std::string>> data;

public:
       bool load_from_file(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        data.clear();
        std::string line;

        while (std::getline(file, line)) {
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }

            if (line.empty()) {
                continue;
            }

            std::vector<std::string> row;
            std::size_t start = 0;

            while (true) {
                std::size_t separator = line.find(';', start);

                if (separator == std::string::npos) {
                    row.push_back(line.substr(start));
                    break;
                }

                row.push_back(line.substr(start, separator - start));
                start = separator + 1;
            }

            data.push_back(row);
        }

        return true;
    }

    std::vector<std::string>& operator[](std::size_t i) {
        return data.at(i);
    }

    const std::vector<std::string>& operator[](std::size_t i) const {
        return data.at(i);
    }

    std::size_t row_count() const {
        return data.size();
    }

    bool delete_element(std::size_t i, std::size_t j) {
        if (i >= data.size() || j >= data[i].size()) {
            return false;
        }

        data[i].erase(data[i].begin() + j);
        return true;
    }

    bool delete_element(const std::string& item) {
        for (std::size_t i = 0; i < data.size(); ++i) {
            for (std::size_t j = 0; j < data[i].size(); ++j) {
                if (data[i][j] == item) {
                    data[i].erase(data[i].begin() + j);
                    return true;
                }
            }
        }

        return false;
    }

    bool add_endline(std::size_t k, const std::string& item) {
        if (k >= data.size()) {
            return false;
        }

        data[k].push_back(item);
        return true;
    }

    ZubchatyiMassiv operator+(const ZubchatyiMassiv& other) const {
        ZubchatyiMassiv result;
        std::size_t rows = std::min(data.size(), other.data.size());

        for (std::size_t i = 0; i < rows; ++i) {
            std::vector<std::string> row;
            std::size_t columns = std::min(data[i].size(), other.data[i].size());

            for (std::size_t j = 0; j < columns; ++j) {
                row.push_back(data[i][j] + other.data[i][j]);
            }

            result.data.push_back(row);
        }

        return result;
    }

    ZubchatyiMassiv& operator++() {
        for (std::size_t i = 0; i < data.size(); ++i) {
            for (std::size_t j = 0; j < data[i].size(); ++j) {
                std::string& item = data[i][j];

                if (!item.empty()) {
                    char first = item[0];

                    if ((first >= 'A' && first <= 'Z') ||
                        (first >= 'a' && first <= 'z')) {
                        item[0] = static_cast<char>(first + 1);
                    }
                }
            }
        }

        return *this;
    }

    ZubchatyiMassiv operator++(int) {
        ZubchatyiMassiv old = *this;
        ++(*this);
        return old;
    }

    void sort_rows() {
        for (std::size_t i = 0; i < data.size(); ++i) {
            std::sort(data[i].begin(), data[i].end());
        }
    }

    void print() const {
        const char* colors[] = {
            "\033[31m", // красный
            "\033[32m", // зелёный
            "\033[33m", // жёлтый
            "\033[34m", // синий
            "\033[35m", // пурпурный
            "\033[36m"  // голубой
        };
        const char* reset = "\033[0m";
        const std::size_t color_count = sizeof(colors) / sizeof(colors[0]);

        for (std::size_t i = 0; i < data.size(); ++i) {
            std::cout << colors[i % color_count];
            std::cout << "Строка " << i << ": ";

            for (std::size_t j = 0; j < data[i].size(); ++j) {
                if (j > 0) {
                    std::cout << " | ";
                }

                if (data[i][j].empty()) {
                    std::cout << "\"\"";
                } else {
                    std::cout << data[i][j];
                }
            }

            std::cout << reset << '\n';
        }
    }
};

int main() {
    ZubchatyiMassiv A;

    if (!A.load_from_file("data.txt")) {
        std::cerr << "Не удалось открыть data.txt. Положите файл рядом с программой "
                     "и запустите программу из этой папки.\n";
        return 1;
    }

    std::cout << "Исходный массив:\n";
    A.print();

    std::cout << "\nОбращение к элементу A[0][0]: " << A[0][0] << "\n";

    ZubchatyiMassiv B = A;
    if (B.row_count() > 1 && B[1].size() > 1) {
        B[1][1] = "hello";
    }

    ZubchatyiMassiv sum = A + B;
    std::cout << "\nРезультат A + B:\n";
    sum.print();

    ZubchatyiMassiv incremented = A;
    ++incremented;
    std::cout << "\nПосле ++: первый символ каждого элемента сдвинут на 1:\n";
    incremented.print();

    ZubchatyiMassiv added = A;
    if (added.add_endline(0, "new")) {
        std::cout << "\nПосле add_endline(0, \"new\"):\n";
        added.print();
    }

    ZubchatyiMassiv deleted_by_index = A;
    if (deleted_by_index.delete_element(0, 1)) {
        std::cout << "\nПосле delete_element(0, 1):\n";
        deleted_by_index.print();
    }

    ZubchatyiMassiv deleted_by_value = A;
    if (deleted_by_value.delete_element("cat")) {
        std::cout << "\nПосле delete_element(\"cat\"):\n";
        deleted_by_value.print();
    } else {
        std::cout << "\nЭлемент cat не найден.\n";
    }

    ZubchatyiMassiv sorted = A;
    sorted.sort_rows();
    std::cout << "\nПосле сортировки элементов внутри строк:\n";
    sorted.print();

    return 0;
}

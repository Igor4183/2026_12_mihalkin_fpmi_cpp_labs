// 5. Преобразовать массив целых чисел, удалив из него те элементы, модуль которых равен заданному числу T (вводится пользователем с клавиатуры). Освободившиеся элементы в конце массива заполнить нулями.
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <random>

void read(int& val) {
    if (!(std::cin >> val)) {
        std::cout << "Input error\n";
        std::exit(1);
    }
}

void scanArray(int*& arr, int& n) {
    std::cout << "Введите размер массива\n";
    if (!(std::cin >> n)) {
        std::cout << "Ошибка ввода\n";
        exit(1);
    } else if (n <= 0) {
        std::cout << "Некорректный размер массива\n";
        exit(1);
    }
    arr = new int[n];

    std::cout << "Введите способ ввода массива:\n1.C клавиатуры\n2.Рандомно\n";
    int t;
    if (!(std::cin >> t) or (t != 1 and t != 2)) {
        std::cout << "Input error\n";
        exit(1);
    }
    if (t == 1) {
        std::cout << "Введите массив\n";
        for (int i = 0; i < n; i++) {
            if (!(std::cin >> arr[i])) {
                std::cout << "Ошибка ввода массива\n";
                exit(1);
            }
        }
    } else {
        int a, b;
        std::cout << "Введите границы элементов массива [a, b]\n";
        if (!(std::cin >> a)) {
            std::cout << "Input error\n";
            exit(1);
        }
        if (!(std::cin >> b)) {
            std::cout << "Input error\n";
            exit(1);
        }
        if (a > b) {
            std::cout << "Incorrect [a, b]\n";
            exit(1);
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(a, b);
        for (int i = 0; i < n; i++) {
            arr[i] = dis(gen);
        }
        std::cout << "Массив заполнен:\n";
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    int* arr = nullptr;
    setlocale(LC_ALL, ".utf8");

    scanArray(arr, n);

    std::cout << "Введите t\n";
    int t;
    read(t);

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (std::abs(arr[i]) != t) arr[idx++] = arr[i];
    }
    for (int i = idx; i < n; i++) {
        arr[i] = 0;
    }

    std::cout << "Итоговый массив чисел:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

    delete[] arr;
    return 0;
}
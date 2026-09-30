// 5. Преобразовать массив целых чисел, удалив из него те элементы, модуль которых равен заданному числу T (вводится пользователем с клавиатуры). Освободившиеся элементы в конце массива заполнить нулями.
#include <clocale>
#include <cstdlib>
#include <iostream>

void read(int& val) {
    if (!(std::cin >> val)) {
        std::cout << "Input error\n";
        std::exit(1);
    }
}

int main() {
    int n;
    setlocale(LC_ALL, ".utf8");
    std::cout << "Введите размер массива\n";
    read(n);
    if (n <= 0) {
        std::cout << "Input error\n";
        return 1;
    }

    int* arr = new int[n];
    std::cout << "Введите элементы массива\n";
    for (int i = 0; i < n; i++) read(arr[i]);

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

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

    delete[] arr;
    return 0;
}
// 3. В одномерном массиве, состоящем из n вещественных элементов, вычислить номер такого элемента, что сумма элементов до него менее всего отличается от суммы элементов, стоящих после него.
#include <clocale>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <utility>

const int MAXN = 1'000'000;

void printArray(double* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void generateArray(double* arr, int n, int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    const int deg = 100; // 2 знака после запятой
    std::uniform_int_distribution<int> dis(a * deg, b * deg);
    for (int i = 0; i < n; i++) {
        arr[i] = static_cast<double>(dis(gen)) / deg;
    }
}

void scanArray(double* arr, int& n) {
    std::cout << "Введите размер массива\n";
    if (!(std::cin >> n)) {
        std::cout << "Ошибка ввода\n";
        exit(1);
    } else if (n <= 0 || n > MAXN) {
        std::cout << "Некорректный размер массива\n";
        exit(1);
    }

    std::cout << "Введите способ ввода массива:\n1.С клавиатуры\n2.Рандомно\n";
    int t;
    if (!(std::cin >> t) || (t != 1 && t != 2)) {
        std::cout << "Ошибка ввода\n";
        exit(1);
    }
    if (t == 1) {
        std::cout << "Введите массив\n";
        for (int i = 0; i < n; i++) {
            if (!(std::cin >> arr[i])) {
                std::cout << "Ошибка ввода\n";
                exit(1);
            }
        }
    } else {
        int a, b;
        std::cout << "Введите границы элементов массива [a, b]\n";
        if (!(std::cin >> a >> b)) {
            std::cout << "Ошибка ввода\n";
            exit(1);
        }
        if (a > b) {
            std::cout << "Неправильный промежуток [a, b]\n";
            exit(1);
        }
        generateArray(arr, n, a, b);
    }
}

int solution(double* arr, int n) {
    double lsum = 0, rsum = 0;
    for (int i = 1; i < n; i++) rsum += arr[i];
    std::pair<double, int> ans = std::make_pair(fabs(rsum - lsum), 0); //{val, idx}
    lsum += arr[0];
    for (int i = 1; i < n; i++) {
        rsum -= arr[i];
        if (ans.first > fabs(rsum - lsum)) {
            ans = std::make_pair(fabs(rsum - lsum), i);
        }
        lsum += arr[i];
    }
    return ans.second + 1;
}

int main() {
    setlocale(LC_ALL, ".utf8");
    static double arr[MAXN];

    int n;
    scanArray(arr, n);

    std::cout << "Исходный массив:\n";
    printArray(arr, n);

    int ans = solution(arr, n);

    std::cout << "Номер элемента, что сумма элементов до него менее всего отличается от суммы элементов, стоящих после него:\n"
              << ans; // idx + 1
    return 0;
}
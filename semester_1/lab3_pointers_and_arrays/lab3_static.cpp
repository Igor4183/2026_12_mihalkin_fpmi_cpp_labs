// 3. В одномерном массиве, состоящем из n вещественных элементов, вычислить номер такого элемента, что сумма элементов до него менее всего отличается от суммы элементов, стоящих после него.
#include <clocale>
#include <cmath>
#include <iostream>
#include <random>
#include <utility>
#include <cstdlib>

const int MAXN = 1'000'000;

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
        if (a > b){
            std::cout << "Incorrect [a, b]\n";
            exit(1);
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        const int deg = 100;
        std::uniform_int_distribution<int> dis(a * deg, b * deg);
        for (int i = 0; i < n; i++) {
            arr[i] = static_cast<double>(dis(gen)) / deg;
        }
        std::cout << "Массив заполнен:\n";
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, ".utf8");
    static double arr[MAXN];

    int n;
    scanArray(arr, n);

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

    std::cout << "Номер элемента, что сумма элементов до него менее всего отличается от суммы элементов, стоящих после него:\n" << ans.second + 1; // idx + 1
    return 0;
}
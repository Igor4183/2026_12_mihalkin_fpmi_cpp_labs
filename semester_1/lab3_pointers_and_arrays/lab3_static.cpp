//3. В одномерном массиве, состоящем из n вещественных элементов, вычислить номер такого элемента, что сумма элементов до него менее всего отличается от суммы элементов, стоящих после него.
#include <clocale>
#include <cmath>
#include <iostream>
#include <utility>

const int MAXN = 1'000'000;

int main() {
    setlocale(LC_ALL, ".utf8");
    static double arr[MAXN];

    std::cout << "Введите размер массива\n";
    int n;
    if (!(std::cin >> n)) {
        std::cout << "Ошибка ввода\n";
        return 1;
    } else if (n <= 0 || n > MAXN) {
        std::cout << "Некорректный размер массива\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (!(std::cin >> arr[i])) {
            std::cout << "Ошибка ввода массива\n";
            return 1;
        }
    }

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

    std::cout << ans.second;
    return 0;
}
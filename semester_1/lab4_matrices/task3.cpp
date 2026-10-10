// 3. Сформировать новую матрицу $B_{n \times m}$, где каждый элемент $b_{ij}$ равен сумме всех элементов исходной матрицы $A_{n \times m}$, находящихся в окрестности $a_{ij}$ (не включая сам элемент $a_{ij}$). Вывести матрицы $A$ и $B$ на экран.
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <clocale>

void printMatrix(int** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(8) << mat[i][j];
        }
        std::cout << std::endl;
    }
}

void allocateMatrix(int**& mat, int n, int m) {
    mat = new int*[n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int[m];
    }
}

void generateMatrix(int** mat, int n, int m, int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(a, b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = dis(gen);
        }
    }
}

void scanMatrix(int**& mat, int& n, int& m) {
    if (mat) {
        std::cout << "Указатель на матрицу не nullptr\n";
        exit(1);
    }

    std::cout << "Введите размер матрицы:\n";

    if (!(std::cin >> n >> m)) {
        std::cout << "Ошибка ввода\n";
        exit(1);
    } else if (n <= 0 || m <= 0) {
        std::cout << "Некорректный размер матрицы\n";
        exit(1);
    }

    allocateMatrix(mat, n, m);

    std::cout << "Введите способ ввода матрицы:\n1.C клавиатуры\n2.Рандомно\n";
    int t;
    if (!(std::cin >> t) || (t != 1 && t != 2)) {
        std::cout << "Ошибка ввода\n";
        exit(1);
    }
    if (t == 1) {
        std::cout << "Введите матрицу:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!(std::cin >> mat[i][j])) {
                    std::cout << "Ошибка ввода матрицы\n";
                    exit(1);
                }
            }
        }
    } else {
        int a, b;
        std::cout << "Введите границы элементов массива [a, b]\n";
        if (!(std::cin >> a >> b) || a > b) {
            std::cout << "Ошибка ввода\n";
            exit(1);
        }
        generateMatrix(mat, n, m, a, b);
    }
}

void destroyMatrix(int**& mat, int n) {
    for (int i = 0; i < n; i++) delete[] mat[i];
    delete[] mat;
    mat = nullptr;
}

void solution(int** A, int ** B, int n, int m){
    const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < 8; k++) { // окрестность включает элементы по диагонали
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m) sum += A[x][y];
            }
            B[i][j] = sum;
        }
    }
}

int main() {
    setlocale(LC_ALL, ".utf8");

    int** A = nullptr;
    int** B = nullptr;
    int n, m;

    scanMatrix(A, n, m);
    std::cout << "Исходная матрица А:\n";
    printMatrix(A,n,m);

    allocateMatrix(B, n, m);
    solution(A, B, n, m);

    std::cout << "Итоговая матрица B:\n";
    printMatrix(B, n, m);
    destroyMatrix(A, n);
    destroyMatrix(B, n);
    return 0;
}
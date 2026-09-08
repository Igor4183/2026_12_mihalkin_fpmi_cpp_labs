#include <iostream>

int main(){
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= std::max(n, m); i++)
        if (n % i == 0 and m % i == 0)
            std::cout << i << '\n';
}
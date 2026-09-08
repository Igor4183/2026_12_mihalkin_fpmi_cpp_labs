#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> f(std::max(n, 2));
    f[0] = 0;
    f[1] = 1;
    if (n > 0) std::cout << f[0] << '\n';
    if (n > 1) std::cout << f[1] << '\n';
    for (int i = 2; i < n; i++){
        f[i] = f[i - 1] + f[i - 2];
        std::cout << f[i] << '\n';
    }
}
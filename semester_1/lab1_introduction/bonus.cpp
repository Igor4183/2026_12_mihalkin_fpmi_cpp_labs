#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

int main(){
    int n, k;
    std::cin >> n >> k;
    int len_k = std::to_string(k).size();
    for (int i = 1; i < n; i++) 
        std::cout << std::string(len_k + 1, ' ');
    int row = n;
    for (int day = 1; day <= k; day++){
        std::cout << std::setw(len_k + 1) << day;
        if (row == 7) std::cout << '\n';
        row = row % 7 + 1;
    }
}
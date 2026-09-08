#include <iostream>

int main(){
    int n;
    std::cin >> n;
    if (n / 1000 == n % 10 and n / 100 % 10 == n / 10 % 10) std::cout << "palindrome";
    else std::cout << "not palindrome";
}
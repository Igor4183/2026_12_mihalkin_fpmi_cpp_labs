#include <iostream>

int main(){
    std::string str;
    std::cin >> str;
    int left_sum = 0, right_sum = 0;
    for (int i = 0; i<3; i++) left_sum += str[i] - '0';
    for (int i = 3; i<6; i++) right_sum += str[i] - '0';
    if (left_sum == right_sum) std::cout << "lucky";
    else std::cout << "not lucky";
}
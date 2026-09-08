//3. С клавиатуры вводится натуральное число n. Добавить слева и справа от этого числа его наименьшую отличную от нуля цифру.
#include <iostream>
#include <cassert>

int main(){
    int n;
    std::cin >> n;
    if (n <= 0) return 0;

    int mn = 10, temp = n, deg = 10;
    while (temp > 0){
        if (temp % 10 != 0) mn = std::min(mn, temp % 10);
        temp /= 10;
        deg *= 10;
    }

    assert(mn > 0 && mn < 10);
    n = mn * deg + n * 10 + mn;
    std::cout << n;
}
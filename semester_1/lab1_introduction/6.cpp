#include <iostream>

int main(){
    int a, b, d;
    std::cin >> a >> b >> d;
    for (int now = a; now <= b; now+=d)
        if (now % 3 == 0) std:: cout << now << ' ';
}
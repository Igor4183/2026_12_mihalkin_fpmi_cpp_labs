// 3.Пользователь должен ввести номер своего мобильного телефона, соответствующий формату белорусского номера: +375 (25/29/33/44) XXX-XX-XX. На это у него есть 5 попыток. При неудачной попытке программа просит ввести номер заново. Неудачной попыткой считается любое отклонение от формата (лишний пробел, другие скобки и т.п.). Если все 5 попыток окажутся неудачными, то программа должна завершиться с соответствующим сообщением об ошибке. Если же номер введён верно, то вывести на экран сам номер и сумму его цифр.
// +375 (29) 123-45-67 correct format

#include <algorithm>
#include <clocale>
#include <iostream>
#include <string>
#include <vector>

const std::vector<std::string> phone_codes = {"25", "29", "33", "44"};

bool is_digit(char c) {
    return c >= '0' and c <= '9';
}

bool is_valid_phone(const std::string& phone) {
    if (phone.size() != 19) return false;
    if (phone.substr(0, 6) != "+375 (") return false;
    if (std::find(phone_codes.begin(), phone_codes.end(), phone.substr(6, 2)) == phone_codes.end()) return false;
    if (phone.substr(8, 2) != ") ") return false;
    for (size_t idx = 10; idx < 19; idx++) { // phone[13], phone[16] == '-'
        if (idx == 13 || idx == 16) {
            if (phone[idx] != '-') return false;
        } else if (!is_digit(phone[idx]))
            return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, ".utf8");

    std::string phone;
    int attempt = 0;
    std::cout << "Введите свой номер телефона в формате: \"+375 (25/29/33/44) XXX-XX-XX\"\n";
    do {
        if (attempt != 0) std::cout << "Неверный формат номера. ";
        std::cout << "Осталось попыток: " << 5 - attempt << '\n';
        attempt++;
        if (!getline(std::cin, phone)){
            std::cout << "Не удалось считать номер телефона\n";
            return 1;
        }
    } while (attempt < 5 && !is_valid_phone(phone));
    if (!is_valid_phone(phone)) {
        std::cout << "У вас закончились попытки\n";
        return 1;
    } else {
        std::cout << "Вы ввели корректный номер телефона: " << phone << '\n';

        int sum = 0;
        for (auto c : phone) {
            if (is_digit(c)) sum += c - '0';
        }
        std::cout << "Сумма его цифр равна: " << sum << '\n';
    }

    return 0;
}
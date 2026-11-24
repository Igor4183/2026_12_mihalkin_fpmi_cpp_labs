#include <algorithm>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

const std::string input = "input.txt";
const std::string output = "output.txt";
const std::string log = "log.txt";

std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(std::time_t time, bool is_utc_format) {
    return is_utc_format
               ? std::put_time(std::gmtime(&time), "%d.%m.%Y %X")
               : std::put_time(std::localtime(&time), "%d.%m.%Y %X");
}

void clear_files(const std::string& output_file,
                 const std::string& log_file) {

    std::ofstream output_stream(output_file);
    if (!output_stream) throw std::runtime_error("can't open output file");
    std::ofstream log_stream(log_file);
    if (!log_stream) throw std::runtime_error("can't open log file");
}

void write_log(const std::string& filename, const std::string& text) {
    std::ofstream out(filename, std::ios::app);
    if (!out) throw std::runtime_error("can't open log file");

    out << FormatTime(Now(), false) << " | " << text << '\n';
    if (!out) {
        throw std::runtime_error("can't write to log file");
    }
}

void write_in_file(const std::string& filename, const std::string& line) {
    write_log(log, "writing line \"" + line + "\" to \"" + filename + "\"");

    std::ofstream out(filename, std::ios::app);
    if (!out) throw std::runtime_error("can't open \"" + filename + "\"");

    out << line << '\n';
    if (!out) throw std::runtime_error("can't write to \"" + filename + "\"");
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

std::vector<std::string> split_numbers(const std::string& line) {
    std::vector<std::string> numbers;
    std::size_t start = 0;

    while (true) {
        const std::size_t separator = line.find(';', start);
        if (separator == std::string::npos) {
            numbers.push_back(line.substr(start));
            break;
        }
        numbers.push_back(line.substr(start, separator - start));
        start = separator + 1;
    }

    return numbers;
}

bool is_valid_phone(const std::string& phone) {
    write_log(log, "validating " + phone);
    const std::vector<std::string> phone_codes = {"25", "29", "33", "44"};
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
    try {
        clear_files(output, log);
        write_log(log, "opening file \"" + input + "\"");

        std::ifstream in(input);
        if (!in) throw std::runtime_error("can't open \"" + input + "\"");

        write_log(log, "file \"" + input + "\" has been opened successfully");
        write_log(log, "reading lines from \"" + input + "\"");

        std::string line;
        std::size_t line_number = 0;
        while (std::getline(in, line)) {
            line_number++;
            write_log(log, "got line: \"" + line + "\"");
            const std::vector<std::string> numbers = split_numbers(line);
            if (numbers.size() != 5) {
                throw std::runtime_error("line " + std::to_string(line_number) + " does not contain 5 phone numbers");
            }

            std::string result;
            for (const std::string& phone : numbers) {
                if (is_valid_phone(phone)) {
                    if (!result.empty()) {
                        result += "\n";
                    }
                    result += phone;
                }
            }
            if (result.empty()) {
                result = "no valid numbers";
            }
            write_in_file(output, result);
        }
        write_log(log, "program has ended with code 0");
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
}
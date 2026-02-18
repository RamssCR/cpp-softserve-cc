#include <algorithm>
#include <string>
#include <cctype>
#include <array>
#include <cmath>
#include <format>
#include <stdexcept>
#include <functional>
#include <unordered_map>
#include <iostream>

constexpr std::array units{'F', 'C', 'K'};
using ConversionFunc = std::function<double(double)>;

char sanitize_unit(const char unit) {
    if (unit == '\0') throw std::invalid_argument("temperature unit must not be empty");
    const char upperUnit = static_cast<char>(std::toupper(static_cast<unsigned char>(unit)));

    if (!std::ranges::any_of(units, [upperUnit](const char& c) { return c == upperUnit; }))
        throw std::invalid_argument("provided temperature unit is invalid");

    return upperUnit;
}

int temperature_conversion(const double temperature, const char unit_in, const char unit_out) {
    if (unit_in == unit_out) return static_cast<int>(temperature);
    const std::string conversion = {unit_in, unit_out};
    constexpr double KELVIN_CONSTANT = 273.15;

    static const std::unordered_map<std::string, ConversionFunc> formulas{
        {"FC", [](const double value) { return 5 * (value - 32) / 9; }},
        {"FK", [](const double value) { return 5 * (value - 32) / 9 + KELVIN_CONSTANT; }},
        {"CF", [](const double value) { return 9 * value / 5 + 32; }},
        {"CK", [](const double value) { return value + KELVIN_CONSTANT; }},
        {"KF", [](const double value) { return 9 * (value - KELVIN_CONSTANT) / 5; }},
        {"KC", [](const double value) { return value - KELVIN_CONSTANT; }}
    };

    try {
        return static_cast<int>(round(formulas.at(conversion)(temperature)));
    } catch (std::invalid_argument&) {
        throw std::invalid_argument("Conversion formula not found");
    }
}

// To check the exercise works correctly, replace it on the main.cpp file.
int main() {
    double temperature;
    char unit_in;
    char unit_out;

    std::cout << "Enter temperature value:\n";
    std::cin >> temperature;

    std::cout << "Enter input unit (C, F, K):\n";
    std::cin >> unit_in;

    std::cout << "Enter output unit (C, F, K)\n";
    std::cin >> unit_out;

    try {
        unit_in = sanitize_unit(unit_in);
        unit_out = sanitize_unit(unit_out);

        const auto result = temperature_conversion(temperature, unit_in, unit_out);
        std::cout << std::format("{}{} => {}{}", temperature, unit_in, result, unit_out);
    } catch (std::invalid_argument& e) {
        std::cerr << e.what() << "\n";
    }

}
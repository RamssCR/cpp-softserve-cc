#include <iostream>

double calculate_salary(const double hourly_wage, const int hours_worked) {
    return hourly_wage * hours_worked;
}

// To check the exercise works correctly, replace it on the main.cpp file.
int main() {
    double hourly_wage;
    int hours_worked;

    std::cout << "Input hourly wage: " << "\n";
    std::cin >> hourly_wage;

    std::cout << "Input worked hours: " << "\n";
    std::cin >> hours_worked;

    const auto salary = calculate_salary(hourly_wage, hours_worked);

    std::cout << "Weekly salary: " << salary << "\n";
}
#include <iostream>

void print_volume(const int& volume) {
    std::cout << "Volume: " << volume << "\n";
}

bool set_volume(int& volume, const int new_volume) {
    if (new_volume < 0 || new_volume > 100) return false;
    if (volume == new_volume) return false;

    volume = new_volume;
    return true;
}

void mute(int& volume) { volume = 0; }

void max_volume(int& volume) { volume = 100; }

// To check the exercise works correctly, replace it on the main.cpp file.
int main() {
    int volume;
    int input_volume;
    int command;

    std::cout << "Establish volume (1-100): " << "\n";
    std::cin >> input_volume;

    if (!set_volume(volume, input_volume))
        throw std::runtime_error("Failed to set volume!");

    print_volume(volume);

    std::cout << "Does user want to mute or increase to max volume? Choose either 1 or 2" << "\n";
    std::cin >> command;

    switch (command) {
        case 1:
            mute(volume);
            print_volume(volume);
            break;
        case 2:
            max_volume(volume);
            print_volume(volume);
            break;
        default:
            std::cout << "Invalid command!\n";
            break;
    }
}
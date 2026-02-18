void swap(int* x, int* y) {
    const int temp = *x;
    *x = *y;
    *y = temp;
}

void bet(int& x, int& y) {
    if (x > y)
        x = x * 2;
    else
        y = y * 2;
}

// To check the exercise works correctly, replace it on the main.cpp file.
// Check by using C++ debugger.
int main() {
    int x{20}, y{50};

    bet(x, y);
    swap(&x, &y);
}
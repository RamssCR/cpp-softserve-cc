void exercise1() {
    int local_var;                    // Stack
    int* ptr = new int;               // ptr: Stack, *ptr: Heap
    static int static_var;            // Static Region (uninitialized)
    int arr[10];                      // Stack
    int* dynamic_array = new int[10]; // dynamic_array: Stack, *dynamic_array: Heap
}

void exercise2_leaky() {
    int* ptr1 = new int(10);
    int* ptr2 = new int(20);

    ptr1 = ptr2;  // Memory leak! Original ptr1 memory is lost

    delete ptr1;
    // What's wrong here?
    // Answer: ptr1's value is still on the heap, only the
    // memory address of ptr1 was overwritten.
}

void exercise2_fixed() {
    int* ptr1 = new int(10);
    int* ptr2 = new int(20);

    delete ptr1;
    ptr1 = nullptr;

    ptr1 = ptr2;
    ptr2 = nullptr;

    delete ptr1;
    ptr1 = nullptr;
}
int Factorial(int num) {
    int i = 1;
    int factorial = 1;

    while (num > i++) {
        factorial = factorial * i;
    }

    return factorial;
}

#include <iostream>
#include <limits>

void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task8();
void task9();

int fibonacci(int);
int fastSquareIterative(int, int);

int main() {
//    task0();
//    task1();
//    task2();
//    task3();
//    task4();
//    task5();
//    task6();
//    task8();
//    task9();

    return 0;
}

void task0() {
    int n, product = 1;
    std::cin >> n;

    for(int i = 1; i <= n; i++) {
        product *= i;
    }

    std::cout << product << std::endl;
}

void task1() {
    int n;
    std::cin >> n;

    for(int i = 1; i <= n; ++i) {
        std::cout << i * i + 3 * i << std::endl;
    }
}

void task2() {
    int n;
    std::cin >> n;
    int biggestNegative = std::numeric_limits<int>::min();

    for(int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;

        if(num < 0 && num > biggestNegative) {
            biggestNegative = num;
        }
    }

    std::cout << biggestNegative << std::endl;
}

void task3() {
    int n;
    std::cin >> n;

    std::cout << fibonacci(n) << std::endl;
}

void task4() {
    int sum = 0;
    while(true) {
        int n;
        std::cin >> n;

        sum += n;

        if(n == 0) {
            break;
        }
    }

    std::cout << sum << std::endl;
}

void task5() {
    int n, digitSum = 0;
    std::cin >> n;

    for(;n > 0; n /= 10) {
        digitSum += n % 10;
    }

    std::cout << digitSum << std::endl;
}

void task6() {
    int n, pow;
    std::cin >> n >> pow;

    std::cout << fastSquareIterative(n, pow) << std::endl;
}

void task8() {
    for(int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        if(!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
            std::cout << c << std::endl;
        }
    }
}

void task9() {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            std::cout << "-";
        }
        std::cout << "0";
        for(int j = i; j < n - 1; ++j) {
            std::cout << "+";
        }

        std::cout << std::endl;
    }
}

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    }

    int a = 0, b = 1;
    for(int i = 2; i <= n; ++i) {
        b += a;
        a = b - a;
    }

    return b;
}

int fastSquareIterative(int x, int n) {
    if(n < 0) {
        x = 1 / x;
        n = -n;
    }

    if(n == 0)
        return 1;

    int y = 1;
    while(n > 1) {
        if(n % 2 == 1) {
            y = x * y;
            n--;
        }
        x *= x;
        n /= 2;
    }

    return x * y;
}

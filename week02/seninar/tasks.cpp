#include <iostream>
#include <limits>
#include <cmath>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();
void task11();
void task12();
void task13();

int fastSquareRecursive(int, int);
int fastSquareIterative(int, int);
int fibonacci(int);

int main() {
//    task1();
//    task2();
//    task3();
//    task4();
//    task5();
//    task6();
//    task7();
//    task8();
//    task9();
//    task10();
//    task11();
//    task12();
//    task13();

    return 0;
}

void task1() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    int sum = 0;

    for(int i = a; i <= b; ++i) {
        sum += i;
    }

    std::cout << "Sum of numbers between " << a << " and " << b << " is " << sum << std::endl;
}

void task2() {
    int n, max = std::numeric_limits<int>::min();
    std::cin >> n;
    int number;

    std::cin >> max;

    for(int i = 1; i < n; ++i) {
        std::cin >> number;
        if(number > max) {
            max = number;
        }
    }

    std::cout << "Max number is: " << max << std::endl;
}

void task3() {
    int n, i, product = 1;
    std::cin >> n;

    if(n % 2 == 0) {
        i = 2;
    } else {
        i = 1;
    }

    for(; i <= n; i+=2) {
        product *= i;
    }

    std::cout << "Product of odd numbers is: " << product << std::endl;
}

void task4() {
    int x, n;
    std::cout << "Enter number and power: ";
    std::cin >> x >> n;

    std::cout << "Result of "
              << x
              << " to the power of "
              << n
              << " is "
              << fastSquareIterative(x, n)
              << std::endl;
}

void task5() {
    int n;
    std::cin >> n;

    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            std::cout << "Number is not prime" << std::endl;
            return;
        }
    }

    std::cout << "Number is prime" << std::endl;
}

void task6() {
    int n;
    std::cin >> n;

    std::cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << std::endl;
}

void task7() {
    int n, sum = 0;
    std::cin >> n;

    for(int i = 1; i < n; ++i) {
        if(n % i == 0) {
            std::cout << i << " ";
            sum += i;
        }
    }

    sum += n;

    std::cout << "Sum of divisors is: " << sum << std::endl;
}

void task8() {
    int n;
    std::cin >> n;

    for(int i = 0; i < n/2 + 1; ++i) {
        for(int j = i; j < n/2; ++j) {
            std::cout << " ";
        }
        for(int j = 0; j < 1 + 2*i; ++j) {
            std::cout << "*";
        }
        for(int j = i; j < n/2; ++j) {
            std::cout << " ";
        }

        std::cout << std::endl;
    }

    for(int i = 0; i < n; ++i) {
        if(i == n/2) {
            std::cout << "|";
        } else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void task9() {
    int n, digits = 0;
    std::cin >> n;

    for(; n > 0; n/=10) {
        digits++;
    }

    std::cout << "Number has " << digits << " digits" << std::endl;
}

void task10() {
    int n, sum = 0;
    std::cin >> n;

    for(; n > 0; n/=10) {
        sum += n % 10;
    }

    std::cout << "Sum of digits is: " << sum << std::endl;
}

void task11() {
    int a, b, maxDivisor = 1;
    std::cin >> a >> b;

    for(int i = 2; i <= (a > b ? b : a); ++i) {
        if(a % i == 0 && b % i == 0) {
            maxDivisor = i;
        }
    }

    std::cout << "Max common divisor is: " << maxDivisor << std::endl;
}

void task12() {
    int n, divisor = 2;
    std::cin >> n;

    while(n != 1) {
        if (n % divisor == 0) {
            std::cout << divisor << " ";
            n /= divisor;
        } else {
            divisor++;
        }
    }

    std::cout << std::endl;
}

void task13() {
    int n, prev;
    int count = 0;
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        int number;
        std::cin >> number;
        std::cout << count << " ";
        if(count == 0) {
            prev = number;
            count = 1;
        } else if(prev == number) {
            count++;
        } else {
            count--;
        }
    }

    std::cout << "Supermajority: " << prev << std::endl;
}

int fastSquareRecursive(int x, int n) {
    if(n < 0) {
        return fastSquareRecursive(1 / x, n);
    } else if(n == 0) {
        return 1;
    } else if(n % 2 == 0) {
        return fastSquareRecursive(x * x, n / 2);
    } else {
        return x * fastSquareRecursive(x * x, (n - 1) / 2);
    }
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

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    }

    int a = 0, b = 1;
    for(int i = 2; i < n; ++i) {
        b += a;
        a = b - a;
    }

    return b;
}

#include <iostream>
#include <cmath>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();

int to_binary(int);
void cubes(unsigned);
void sequence(unsigned);
void primes(unsigned);
bool isPrime(unsigned);
double combinations(unsigned, unsigned);
bool is_magic(unsigned);
int biggest_digit_sum(unsigned);
void print_satisfying_predicates(unsigned);

int main() {
//    task1();
//    task2();
//    task3();
//    task4();
//    task5();
//    task6();
//    task7();
//    task8();

    return 0;
}

void task1() {
    std::cout << to_binary(13) << std::endl;
}

int to_binary(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 2 + 10 * to_binary(n / 2);
}

void task2() {
    cubes(900);
}

void cubes(unsigned n) {
    unsigned i = 1;
    while(true) {
        unsigned cube = i * i * i;
        if(cube < n) {
            std::cout << cube << " ";
        } else {
            break;
        }
        i++;
    }
    std::cout << std::endl;
}

void task3() {
    sequence(6);
}

void sequence(unsigned n) {
    for(unsigned i = 1; i <= n; ++i) {
        std::cout << 2*i*i*i + 3*i << ' ';
    }

    std::cout << std::endl;
}

void task4() {
    primes(5);
}

void primes(unsigned n) {
    int primeCount = 0;
    unsigned num = 2;
    while(primeCount < n) {
        if(isPrime(num)) {
            std::cout << num << ' ';
            primeCount++;
        }

        num++;
    }

    std::cout << std::endl;
}

bool isPrime(unsigned num) {
    for(unsigned i = 2; i <= sqrt(num); ++i) {
        if(num % i == 0) {
            return false;
        }
    }

    return true;
}

void task5() {
    std::cout << combinations(10, 4) << std::endl;
    std::cout << combinations(5, 0) << std::endl;
}

double combinations(unsigned n, unsigned k) {
    double divisor = 1, topProduct = 1;

    if(k == 0) {
        return 1;
    }

    for(int i = 1; i <= n - k; ++i) {
        divisor *= i;
    }
    for(unsigned i = k + 1; i <= n; ++i) {
        topProduct *= i;
    }

    return topProduct / divisor;
}

void task6() {
    std::cout << std::boolalpha << is_magic(28) << '\n'; // -> true
    std::cout << std::boolalpha << is_magic(12) << '\n'; // -> false
}

bool is_magic(unsigned n) {
    unsigned sum = 0;
    for(unsigned i = 1; i <= n / 2; ++i) {
        if(n % i == 0) {
            sum += i;
        }
    }

    return sum == n;
}

void task7() {
    int n;
    std::cin >> n;

    std::cout << biggest_digit_sum(n) << std::endl;
}

int biggest_digit_sum(unsigned n) {
    int biggestDigitSum = 0;
    int biggestNumber = 0;
    int currentNumber;

    for(int i = 0; i < n; ++i) {
        std::cin >> currentNumber;
        int currentDigitSum = 0;
        int currentNumberCopy = currentNumber;
        while(currentNumber > 0) {
            currentDigitSum += currentNumber % 10;
            currentNumber /= 10;
        }

        if(currentDigitSum >= biggestDigitSum) {
            biggestDigitSum = currentDigitSum;
            biggestNumber = currentNumberCopy;
        }
    }

    return biggestNumber;
}

void task8() {
    print_satisfying_predicates(7);
}

void print_satisfying_predicates(unsigned n) {
    int satisfyingCount = 0;
    int num = 10;

    while(satisfyingCount < n) {
        short biggestDigit = std::numeric_limits<short>::min();
        short smallestDigit = std::numeric_limits<short>::max();
        int digitSum = 0;
        int numCopy = num;

        while(numCopy > 0) {
            short currentDigit = static_cast<short>(numCopy % 10);
            digitSum += currentDigit;
            if(currentDigit > biggestDigit) {
                biggestDigit = currentDigit;
            }
            if(currentDigit < smallestDigit) {
                smallestDigit = currentDigit;
            }
            numCopy /= 10;
        }

        if(biggestDigit - smallestDigit == 3 && isPrime(digitSum)) {
            std::cout << num << ' ';
            satisfyingCount++;
        }

        num++;
    }

    std::cout << std::endl;
}

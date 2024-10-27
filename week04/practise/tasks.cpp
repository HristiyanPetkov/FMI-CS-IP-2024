#include <iostream>

void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();

void swap(int&, int&);
bool isEven(int);
double Pow(double, unsigned);
double Min(double, double);
double Max(double, double);
double minOf3(double, double, double);
double maxOf3(double, double, double);
bool isAlpha(char);
bool isDigit(char);
void diagonalMatrix(unsigned, unsigned);
void pow2(double);
void deposit(unsigned);
void withdraw(unsigned);
unsigned checkBalance();
unsigned digitRepetition(unsigned, unsigned);
bool ascendingTwo(double, double);
bool ascendingThree(double, double, double);
bool ascendingFour(double, double, double, double);
bool ascendingFive(double, double, double, double, double);

unsigned balance = 0;

int main() {
//    task0();
//    task1();
//    task2();
//    task3();
//    task4();
//    task5();
//    task6();
//    task7();
//    task8();
}

void task0() {
    int a = 5, b = 10;
    std::cout << "Original: " << a << " " << b << std::endl;
    swap(a, b);
    std::cout << "Swapped: " << a << " " << b << std::endl;
}

void swap(int& a, int & b) {
    a += b;
    b = a - b;
    a -= b;
}

void task1() {
    std::cout << std::boolalpha;
    std::cout << "Even with 4: " << isEven(4) << std::endl;
    std::cout << "Even with 5: " << isEven(5) << std::endl;
}

bool isEven(int a) {
    return a % 2 == 0;
}

void task2() {
    std::cout << "Pow 2^3: " << Pow(2, 3) << std::endl;
    std::cout << "Min 7, 9: " << Min(7, 9) << std::endl;
    std::cout << "Max 7, 9: " << Max(7, 9) << std::endl;
    std::cout << "minOf3 7, 9, 2: " << minOf3(7, 9, 2) << std::endl;
    std::cout << "maxOf3 7, 9, 2: " << maxOf3(7, 9, 2) << std::endl;
    std::cout << std::boolalpha;
    std::cout << "isAlpha A: " << isAlpha('A') << std::endl;
    std::cout << "isAlpha a: " << isAlpha('a') << std::endl;
    std::cout << "isAlpha _: " << isAlpha('_') << std::endl;
    std::cout << "isDigit 6: " << isDigit('6') << std::endl;
    std::cout << "isDigit ?: " << isDigit('?') << std::endl;
}

double Pow(double x, unsigned int n) {
    if(n == 0) {
        return 1;
    }

    double product = 1;
    for(int i = 0; i < n; ++i) {
        product *= x;
    }

    return product;
}

double Min(double a, double b) {
    return a < b ? a : b;
}

double Max(double a, double b) {
    return a > b ? a : b;
}

double minOf3(double a, double b, double c) {
    double firstMin = Min(a, b);
    return firstMin < c ? firstMin : c;
}

double maxOf3(double a, double b, double c) {
    double firstMax = Max(a, b);
    return firstMax > c ? firstMax : c;
}

bool isAlpha(char c) {
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

bool isDigit(char c) {
    return c >= 48 && c <= 57;
}

void task3() {
    std::cout << "Diagonal matrix 5x5" << std::endl;
    diagonalMatrix(5, 5);
}

void diagonalMatrix(unsigned int n, unsigned int m) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            std::cout << i * j << " ";
        }

        std::cout << i << " ";

        for(int j = i + 1; j <= m; ++j) {
            std::cout << j - i << " ";
        }

        std::cout << std::endl;
    }
}

void task4() {
    pow2(5);
}

void pow2(double x) {
    std::cout << "Pow2 " << x << ": " << Pow(x, 2) << std::endl;
}

void task5() {
    std::cout << "Task5 minOf3 8, 2, 4: " << minOf3(8, 2, 4) << std::endl;
}

void task6() {
    std::cout << "Starting balance: " << checkBalance() << std::endl;
    std::cout << "Depositing 1250" << std::endl;
    deposit(1250);
    std::cout << "Balance: " << checkBalance() << std::endl;
    std::cout << "Withdrawing 700" << std::endl;
    withdraw(700);
    std::cout << "Balance: " << checkBalance() << std::endl;
    std::cout << "Withdrawing 1000" << std::endl;
    withdraw(1000);
}

void deposit(unsigned int amount) {
    balance += amount;
}

void withdraw(unsigned int amount) {
    if(balance < amount) {
        std::cout << "Not enough balance!" << std::endl;
        return;
    }

    balance -= amount;
}

unsigned checkBalance() {
    return balance;
}

void task7() {
    std::cout << "Repetitions of 3 in 12334567: " << digitRepetition(12334567, 3) << std::endl;
}

unsigned digitRepetition(unsigned int num, unsigned int digit) {
    unsigned repetitions = 0;
    while(num > 0) {
        if(num % 10 == digit) {
            repetitions++;
        }
        num /= 10;
    }

    return repetitions;
}

void task8() {
    std::cout << std::boolalpha;
    std::cout << "Ascending 4, 5: " << ascendingTwo(4, 5) << std::endl;
    std::cout << "Ascending 5, 4: " << ascendingTwo(5, 4) << std::endl;
    std::cout << "Ascending 4, 5, 6: " << ascendingThree(4, 5, 6) << std::endl;
    std::cout << "Ascending 5, 4, 3: " << ascendingThree(5, 4, 3) << std::endl;
    std::cout << "Ascending 4, 5, 6, 7: " << ascendingFour(4, 5, 6, 7) << std::endl;
    std::cout << "Ascending 5, 4, 3, 2: " << ascendingFour(5, 4, 3, 2) << std::endl;
    std::cout << "Ascending 4, 5, 6, 7, 8: " << ascendingFive(4, 5, 6, 7, 8) << std::endl;
    std::cout << "Ascending 5, 4, 3, 2, 1: " << ascendingFive(5, 4, 3, 2, 1) << std::endl;
}

bool ascendingTwo(double a, double b) {
    return a < b;
}

bool ascendingThree(double a, double b, double c) {
    return ascendingTwo(a, b) && b < c;
}

bool ascendingFour(double a, double b, double c, double d) {
    return ascendingThree(a, b, c) && c < d;
}

bool ascendingFive(double a, double b , double c, double d, double f) {
    return ascendingFour(a, b, c, d) && d < f;
}

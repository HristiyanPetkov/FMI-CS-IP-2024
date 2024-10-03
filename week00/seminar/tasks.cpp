#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();

int digitCount(int);
int reverseNumber(int);
bool leapYear(int);

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();

    return 0;
}

void task1() {
    std::cout << "Hello, World!" << std::endl;
}

void task2() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    std::cout << "Sum: " << a + b << std::endl;
}

void task3() {
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    b += a;
    a = b - a;
    b = b - a;

    std::cout << "Switched: " << a << " " << b << std::endl;
}

void task4() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int result = reverseNumber(num);

    std::cout << "Reversed: " << result << std::endl;
}

void task5() {
    char a;
    std::cout << "Enter a lowercase letter: ";
    std::cin >> a;

    std::cout << (char)(a - 32) << std::endl;
}

// S = (1/2)*|x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|
void task6() {
    Point A{}, B{}, C{};
    std::cout << "Enter 3 point coordinates: ";
    std::cin >> A.x >> A.y;
    std::cin >> B.x >> B.y;
    std::cin >> C.x >> C.y;

    double area = ((double)abs(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y)) / 2);

    std::cout << "Area: " << area << std::endl;
}

void task7() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    std::cout << (leapYear(year) ? "true" : "false") << std::endl;
}

int digitCount(int num) {
    int count = 0;
    while(num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int reverseNumber(int num) {
    int result = 0;
    int length = digitCount(num);
    for(int i = 0; i < length; ++i) {
        int digit = (int)(num / (pow(10, i))) % 10;
        result += (int)(digit * pow(10, length-i-1));
    }

    return result;
}

bool leapYear(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

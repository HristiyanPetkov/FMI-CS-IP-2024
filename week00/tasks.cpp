#include <iostream>

using namespace std;

void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();

int min(int, int);
int max(int, int);

int main() {
    task0();
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();

    return 0;
}

void task0() {
    cout << "Program for coffee!" << endl;
}

void task1() {
    int number;
    cout << "Enter a three digit number: " << endl;
    cin >> number;
    cin.clear();

    int digits[3] = {number % 100, (number / 10) % 10, number % 10};
    cout << "First digit: " << digits[0] << endl;
    cout << "Second digit: " << digits[1] << endl;
    cout << "Third digit: " << digits[2] << endl;

    cout << "Sum: " << digits[0] + digits[1] + digits[2] << endl;
}

void task2() {
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    cin.clear();

    a += b;
    b = a - b;
    a = a - b;

    cout << "a: " << a << " b: " << b << endl;
}

void task3() {
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    cin.clear();

    cout << "num1 = " << a << " num2 = " << b << " => " << (b % a == 0 ? 1 : 0) << endl;
}

void task4() {
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    cin.clear();

    int product = a * b;
    cout << product << ", " << product % 10 << " - " << (product % 2 == 0 ? 1 : 0) << endl;
}


void task5() {
    int a, b, c;
    cout << "Enter three numbers: " << endl;
    cin >> a >> b >> c;
    cin.clear();

    cout << (((a + b > c) && (a + c > b) && (b + c > a)) == 1 ? "true" : "false") << endl;
}

void task6() {
    int a, b, c;
    cout << "Enter three numbers: " << endl;
    cin >> a >> b >> c;
    cin.clear();

    int maxVal = max(max(a, b), c);
    int minVal = min(min(a, b), c);

    cout << maxVal << ", " << minVal << endl;
}

void task7() {
    int a, intervalStart, intervalEnd;
    cout << "Enter three numbers: " << endl;
    cin >> a >> intervalStart >> intervalEnd;
    cin.clear();

    cout << (((a > intervalStart) && (a < intervalEnd)) == 1 ? "true" : "false") << endl;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

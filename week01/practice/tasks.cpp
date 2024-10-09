#include <iostream>

void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6(int, int, int, bool);
void task7();
void bonus0(int, int, int, int, int, int);

bool leapYear(int);
bool checkCanMake(int, int, int, int, int, int);

int main() {
    task0();
    task1();
    task2();
    task3();
    task4();
    task5();
    task6(1250, 3, 8, true);
    task7();
    bonus0(1, 2, 4, 3, 3, 150);
    
    return 0;
}

void task0() {
    int a, b;
    char operation;
    std::cout << "Enter two numbers and an operation: ";
    std::cin >> a >> b >> operation;

    switch (operation) {
        case '+':
            std::cout << a + b << std::endl;
            break;
        case '-':
            std::cout << a - b << std::endl;
            break;
        case '*':
            std::cout << a * b << std::endl;
            break;
        case '/':
            std::cout << a / b << std::endl;
            break;
        default:
            std::cout << "Unsupported operation" << std::endl;
    }
}

void task1() {
    short year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    std::cout << year << (leapYear(year) ? "is a leap year." : "is not a leap year") << std::endl;
}

void task2() {
    char character;
    std::cout << "Enter a character: ";
    std::cin >> character;
    if(character >= 65 && character <= 90) {
        std::cout << "The lower case character corresponding to is " << (char)(character + 32) << std::endl;
    } else if(character >= 97 && character <= 122) {
        std::cout << "The upper case character corresponding to is " << (char)(character - 32) << std::endl;
    } else {
        std::cout << character << " is not a letter." << std::endl;
    }
}

void task3() {
    short month;
    std::cout << "Enter a month: ";
    std::cin >> month;

    switch (month % 12) {
        case 0:
        case 1:
        case 2:
            std::cout << "Winter" << std::endl;
            break;

        case 3:
        case 4:
        case 5:
            std::cout << "Spring" << std::endl;
            break;

        case 6:
        case 7:
        case 8:
            std::cout << "Summer" << std::endl;
            break;

        case 9:
        case 10:
        case 11:
            std::cout << "Fall" << std::endl;
            break;

        default:
            std::cout << "Not valid" << std::endl;
    }
}

void task4() {
    int a, b;
    std::cout << "Enter coef a and b: ";
    std::cin >> a >> b;

    if(a == 0) {
        if(b != 0) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "INF" << std::endl;
        }
    } else if(b % a == 0) {
        std::cout << b / a << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

void task5() {
    short month, year;
    std::cout << "Enter a month and year: ";
    std::cin >> month >> year;

    switch (month % 12) {
        case 0:
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            std::cout << "31" << std::endl;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            std::cout << "30" << std::endl;
            break;

        case 2:
            std::cout << (leapYear(year) ? "29" : "28") << std::endl;

        default:
            std::cout << "Not valid" << std::endl;
    }
}

void task6(int price, int usbPorts, int gbRam, bool ssd) {

    bool willBuy = ((usbPorts >= 3 && (gbRam >= 8) && ssd && (price >= 1000 && price <= 1500)) || ((gbRam < 8 || !ssd) && (price <= 800)));

    if(willBuy) {
        std::cout << "Traico will buy the laptop" << std::endl;
    } else {
        std::cout << "Traico won't buy the laptop" << std::endl;
    }
}

void task7() {
    int num;
    std::cout << "Enter four digit number: ";
    std::cin >> num;
    int firstDigit = num/1000;

    if((firstDigit % 2 == 1) &&
        (std::max(std::max(firstDigit, num/100 % 10),
                  std::max(num/10 % 10, num % 10)) == firstDigit)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}

void bonus0(int tomatoes, int peppers, int carrots, int olives, int potatoes, int flavoringMils) {
    if(checkCanMake(tomatoes, peppers, carrots, olives, potatoes, flavoringMils)) {
        std::cout << "Traico will eat!" << std::endl;
    } else {
        std::cout << "Traico won't eat!" << std::endl;
    }
}

bool leapYear(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

bool checkCanMake(int tomatoes, int peppers, int carrots, int olives, int potatoes, int flavoringMils) {
    return (tomatoes >= 1 && peppers >= 2 && carrots >= 4 && olives >= 3 && potatoes >= 3 && flavoringMils >= 150);
}

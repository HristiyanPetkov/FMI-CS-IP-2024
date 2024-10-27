#include <iostream>
#include <cmath>

void task0();
void task1();
void task2();
void task3();
void task4();
void task5();

bool validTime(unsigned);
bool willBuy(bool, bool, unsigned, unsigned, unsigned);

int main() {
//    task0();
//    task1();
//    task2();
//    task3();
//    task4();
//    task5();
}

void task0() {
    unsigned num;
    std::cout << "Enter a num: ";
    std::cin >> num;

    while(num > 0) {
        if(num % 10 == 1) {
            std::cout << "YES" << std::endl;
            return;
        }
        num /= 10;
    }

    std::cout << "NO" << std::endl;
}

void task1() {
    unsigned timeOne, timeTwo, diff;
    std::cin >> timeOne >> timeTwo;
    if(!validTime(timeOne) || !validTime(timeTwo)) {
        std::cout << "Invalid" << std::endl;
        return;
    }
    if(timeOne > timeTwo)
        timeTwo += 2400;

    if(timeTwo % 100 < timeOne % 100) {
        timeTwo -= 100;
        timeTwo += 60;
    }

    diff = timeTwo - timeOne;
    if(!validTime(diff)) {
        diff += 100;
        diff -= 60;
    }
    std::cout << diff << std::endl;
}

bool validTime(unsigned timeOne) {
    return (timeOne % 100 < 60) && (timeOne / 100 < 24);
}

void task2() {
    unsigned a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    for(int i = 2; i <= a; ++i) {
        if(a % i == 0 && b % (i*i) == 0) {
            std::cout << "Yes" << std::endl;
            return;
        }
    }

    std::cout << "No" << std::endl;
}

void task3() {
    std::cout << willBuy(true, true, 100000, 70, 5000) << std::endl;
    std::cout << willBuy(true, false, 200000, 80, 5000) << std::endl;
}

bool willBuy(bool secondHand, bool hasConditioner, unsigned int mileage, unsigned int horsePower, unsigned int price) {
    return ((secondHand && (
                (hasConditioner && mileage < 115000 && horsePower >= 70 && price <= 6000) ||
                (!hasConditioner && mileage < 180000 && horsePower >= 60 && price <= 2500)
            )) || (!secondHand && (horsePower >= 70 && horsePower <= 90) && price <= 25000));
}

void task4() {
    unsigned people;
    double ticketPrice;
    std::cout << "Enter number of people and ticket price: ";
    std::cin >> people >> ticketPrice;

    double discount = 1.0;
    if(people >= 5 && people <= 10) {
        discount = 0.95;
    } else if(people >= 11 && people <= 20) {
        discount = 0.9;
    } else if(people > 20) {
        discount = 0.85;
    }

    std::cout << "Total price: " << people * (ticketPrice * discount) << std::endl;
}

void task5() {
    unsigned n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    unsigned printedNums = 0, currentNum = 1;
    while(printedNums < n) {
        for(int i = 0; i < currentNum; ++i) {
            std::cout << currentNum << " ";
            printedNums++;
            if(printedNums == n) {
                std::cout << std::endl;
                return;
            }
        }

        currentNum++;
    }
}

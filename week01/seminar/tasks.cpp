#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

struct Circle {
    int r;
    int x;
    int y;
};

struct Piece {
    char type;
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
void task8();

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();

    return 0;
}

void task1() {
    short num, digit;
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> num >> digit;

    while(num != 0) {
        if(num % 10 == digit) {
            std::cout << "Number contains digit" << std::endl;
            return;
        }
        num /= 10;
    }

    std::cout << "Number doesn't contain digit" << std::endl;
}

void task2() {
    short num;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num;

    if(num/1000 + ((num/100) % 10) == ((num/10) % 10) + (num % 10)) {
        std::cout << "Magic number" << std::endl;
    } else {
        std::cout << "Not a magic number" << std::endl;
    }
}

void task3() {
    char character;
    std::cout << "Enter a character: " << std::endl;
    std::cin >> character;

    if((character >= 65 && character <= 90) ||(character >= 97 && character <= 122)) {
        std::cout << "Letter" << std::endl;
    } else if(character >= 48 && character <= 57) {
        std::cout << "Digit" << std::endl;
    } else {
        std::cout << "Special character" << std::endl;
    }
}

void task4() {
    Point point{};
    Circle circle{};
    std::cout << "Enter point coordinates followed by circle info: " << std::endl;
    std::cin >> point.x >> point.y >> circle.x >> circle.y >> circle.r;

    double distance = sqrt(pow(abs(point.x - circle.x), 2) + pow(abs(point.y - circle.y), 2));

    if(distance > circle.r) {
        std::cout << "Outside" << std::endl;
    } else if(distance < circle.r) {
        std::cout << "Inside" << std::endl;
    } else {
        std::cout << "On" << std::endl;
    }
}

void task5() {
    short age;
    std::cout << "Enter age: ";
    std::cin >> age;

    std::cout << (age > 18 ? "You are good to go" : "You are underage") << std::endl;
}

void task6() {
    int a, b , c;
    std::cout << "Enter three numbers: ";
    std::cin >> a >> b >> c;

    (a > b ?
        (a > c ?
            (b > c ? std::cout << a << " " << b << " " << c << std::endl
                : std::cout << a << " " << c << " " << b << std::endl)
            : std::cout << c << " " << a << " " << b << std::endl)
        : (b > c ?
           (a > c ? std::cout << b << " " << a << " " << c << std::endl
                : std::cout << b << " " << c << " " << a << std::endl)
            : std::cout << c << " " << b << " " << a << std::endl)
    );
}

void task7() {
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

void task8() {
    Piece piece{};
    Point point{};
    std::cout << "Enter piece info followed by point info: " << std::endl;
    std::cin >> piece.type >> piece.x >> piece.y >> point.x >> point.y;

    switch (piece.type) {
        case 'r': // rook
            std::cout << ((piece.y == point.y || piece.x == point.x) ? "Yes" : "No") << std::endl;
            break;
        case 'b': // bishop
            std::cout << ((abs(piece.x - point.x) == abs(piece.y - point.y)) ? "Yes" : "No") << std::endl;
            break;
        case 'q': // queen
            std::cout << ((piece.y == point.y ||
                           piece.x == point.x ||
                           abs(piece.x - point.x) == abs(piece.y - point.y))
                           ? "Yes" : "No") << std::endl;
            break;
        case 'h': // knight
            std::cout << ((abs((piece.x - point.x) * (piece.y - point.y)) == 2) ? "Yes" : "No") << std::endl;
            break;
        default:
            std::cout << "Unsupported piece" << std::endl;
    }
}

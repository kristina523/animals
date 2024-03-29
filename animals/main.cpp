#include <iostream>
#include <string>
#include <ctime>

class Animal {
protected:
    std::string name;

public:
    Animal(std::string _name) : name(_name) {}
};

class Pet {
public:
    virtual void feed(int foodAmount) = 0;
};

class Dog : public Animal, public Pet {
public:
    Dog(std::string _name) : Animal(_name) {}

    void feed(int foodAmount) override {
        if (rand() % 100 >= foodAmount - 10 && rand() % 100 <= foodAmount + 10) {
            std::cout << name << " ест и счастлив!\n";
        } else {
            std::cout << name << " голоден и печален.\n";
        }
    }
};

class Cat : public Animal, public Pet {
public:
    Cat(std::string _name) : Animal(_name) {}

    void feed(int foodAmount) override {
        if (rand() % 100 >= foodAmount - 10 && rand() % 100 <= foodAmount + 10) {
            std::cout << name << " ест и доволен!\n";
        } else {
            std::cout << name << " мяукает, требуя еще еды.\n";
        }
    }
};

int main() {
    srand(time(0));

    int foodAmount;
    std::cout << "Введите количество корма для кормления животных (от 0 до 100): ";
    std::cin >> foodAmount;

    std::string dogName, catName;
    std::cout << "Введите имя собаки: ";
    std::cin >> dogName;
    std::cout << "Введите имя кошки: ";
    std::cin >> catName;

    Dog dog(dogName);
    Cat cat(catName);

    dog.feed(foodAmount);
    cat.feed(foodAmount);

    return 0;
}

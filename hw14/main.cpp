//
//  main.cpp
//  hw14
//
//  Created by Valeria Dudinova on 14.11.2024.
//

#include <iostream>
using namespace std;

class Pet
{
protected:
    string name;

public:
    Pet(const string& pet_name) : name(pet_name) {}

    // Віртуальна функція для видачі звуку тварини
    virtual void Sound() const = 0;

    // Віртуальна функція для відображення імені
    virtual void Show() const
    {
        cout << "The name of the animal: " << name << endl;
    }

    // Віртуальна функція для відображення підвиду
    virtual void Type() const = 0;

    // Деструктор
    virtual ~Pet() {}
};

// Виробний клас "Собака"
class Dog : public Pet {
public:
    Dog(const string& dog_name) : Pet(dog_name) {}

    // Реалізація звуку для собаки
    void Sound() const override {
        cout << "Haw-haw!" << endl;
    }

    // Відображення підвиду
    void Type() const override {
        cout << "Subspecies: Dog" << endl;
    }
};

// Виробний клас "Кішка"
class Cat : public Pet {
public:
    Cat(const string& cat_name) : Pet(cat_name) {}

    // Реалізація звуку для кішки
    void Sound() const override {
        cout << "Meow!" << endl;
    }

    // Відображення підвиду
    void Type() const override {
        cout << "Subspecies: Cat" << endl;
    }
};

// Виробний клас "Попугай"
class Parrot : public Pet {
public:
    Parrot(const string& parrot_name) : Pet(parrot_name) {}

    // Реалізація звуку для попугая
    void Sound() const override {
        cout << "Chirik-chirik!" << endl;
    }

    // Відображення підвиду
    void Type() const override {
        cout << "Subspecies: Parrot" << endl;
    }
};

// Виробний клас "Хом'як"
class Hamster : public Pet {
public:
    Hamster(const string& hamster_name) : Pet(hamster_name) {}

    // Реалізація звуку для хом'яка
    void Sound() const override {
        cout << "Squeal!" << endl;
    }

    // Відображення підвиду
    void Type() const override {
        cout << "Subspecies: Hamster" << endl;
    }
};

int main() {
    // Створення масиву вказівників на базовий клас Pet
    Pet* pets[4];

    // Додавання об'єктів різних тварин у масив
    pets[0] = new Dog("Sherlock");
    pets[1] = new Cat("Murka");
    pets[2] = new Parrot("Cash");
    pets[3] = new Hamster("Chip");

    // Виведення інформації про кожну тварину
    for (int i = 0; i < 4; ++i) {
        pets[i]->Show();  // Вивести ім'я тварини
        pets[i]->Sound(); // Вивести звук тварини
        pets[i]->Type();  // Вивести підвид тварини
        cout << "------------------------" << endl;
    }

    // Звільнення пам'яті
    for (int i = 0; i < 4; ++i) {
        delete pets[i];  // Видаляємо кожен об'єкт
    }

    return 0;
}

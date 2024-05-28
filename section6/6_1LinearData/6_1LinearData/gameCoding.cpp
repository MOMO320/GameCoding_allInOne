#include <iostream>
using namespace std;

class Animal
{
public:
	Animal() { cout << "Animal()" << endl; }
	virtual ~Animal() { cout << "~Animal()" << endl; }

	virtual void PrintShout() { cout << "Animal" << endl; }
};

class Dog : public Animal
{
public:
	Dog() { cout << "Dog()" << endl; }
	virtual ~Dog() override { cout << "~Dog()" << endl; }

    virtual void PrintShout() override { cout << "�۸�!! �۸�!!" << endl; }
	void onlyDog() { cout << "�ȳ��ϼ���?" << endl; }
};

class Cat : public Animal
{
public:
	Cat() { cout << "Cat()" << endl; }
	virtual ~Cat() override { cout << "~Cat()" << endl; }

	virtual void PrintShout() override { cout << "�߿�~~ �߿�~~" << endl; }

	void onlyCat() { cout << "Ű�߿�!!!" << endl; }
};

void main2()
{
	Dog * dog = new Dog();
	Cat * cat = new Cat();

	Animal* animal = cat;

	dog = static_cast<Dog*>(animal);

	dog->PrintShout();
	dog->onlyDog();
}

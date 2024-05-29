#include<iostream>
#include "string"
using namespace std;


class Animal
{
public:
	Animal(): age(0), name("���ٿ�~?") { /*cout << "Animal()" << endl;*/ }
	virtual ~Animal() {/* cout << "~Animal()" << endl;*/ }

	virtual void PrintShout() { cout << "=============== ���� �Ұ� ================" << endl; }

	void PrintOnly() { cout << "Animal Only : ����� ¢��� ����?" << endl; }
public:
	int age;
	string name;
};

class Dog : public Animal
{
public:
	Dog() { /*cout << "Dog()" << endl;*/ }
	virtual ~Dog() { /*cout << "~Dog()" << endl;*/ }

 	virtual void PrintShout() override 
	{
		// �θ��� PrintShou �Լ� ȣ��
		Animal::PrintShout();

		cout << "�۸�!!!�۸�!!" << endl;
		cout << "���� : " << age << endl;
		cout << "�̸� : " << name << endl;
	}

	void PrintDogOnly() { cout << "��!! ��!! ��!!" << endl; }
};

class Cat : public Animal
{
public : 
	Cat() { /*cout << "Cat()" << endl; */}
	virtual ~Cat() {/* cout << "~Cat()" << endl;*/ }

	virtual void PrintShout() override
	{
		cout << "�̾߿�~~ �̾߿�~~" << endl;
		cout << "���� : " << age << endl;
		cout << "�̸� : " << name << endl;
	}

	void PrintCatOnly() { cout << "Ű�߿�!!!!! Ű�߿�!!!" << endl; }
};

int main2()
{
	Animal * animal = new Animal;
	
	Dog* dog = new Dog();
	dog->age = 3;
	dog->name = "�ູ��";

	Cat* cat = new Cat();
	cat->age = 10;
	cat->name = "����";

	Animal* aniArr[2];

	// ---------------------- ��ĳ���� ---------------------------
	aniArr[0] = static_cast<Animal*>(dog);
	aniArr[1] = static_cast<Animal*>(cat);

	cout << "  ----------------------------------------" << endl;
	for (int i = 0; i < 2; i++)
	{
		// �ڽ��� �Լ� ȣ�� �Ұ�
		aniArr[i]->PrintShout();	
		aniArr[i]->PrintOnly();	
	}
	cout << " ----------------------------------------" << endl;
	// ---------------------- ��ĳ���� ---------------------------

	// ---------------------- �ٿ� ĳ���� ---------------------------
	Dog* testDog = new Dog();
	testDog = nullptr;

	Cat* testCat = new Cat();
	testCat = nullptr;

	// ---------------------- �ٿ� ĳ���� ---------------------------
	for (int i = 0; i < 2; i++)
	{
		testDog = dynamic_cast<Dog*>(aniArr[i]);
		testCat = dynamic_cast<Cat*>(aniArr[i]);

		if (testDog != nullptr)
		{
			testDog->PrintShout();
			testDog->PrintDogOnly();
			testDog->PrintOnly(); // �θ��� �Լ� ȣ�� ����
		}
			

		if (testCat != nullptr)
		{
			testCat->PrintShout();
			testCat->PrintCatOnly();
			testCat->PrintOnly();	// �θ��� �Լ� ȣ�� ����
		}
			
	}
	// ---------------------- �ٿ� ĳ���� ---------------------------
	cout << " ----------------------------------------" << endl;

	return 0;
}
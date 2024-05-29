#include<iostream>
#include "string"
using namespace std;


class Animal
{
public:
	Animal(): age(0), name("난다용~?") { /*cout << "Animal()" << endl;*/ }
	virtual ~Animal() {/* cout << "~Animal()" << endl;*/ }

	virtual void PrintShout() { cout << "=============== 동물 소개 ================" << endl; }

	void PrintOnly() { cout << "Animal Only : 뭐라고 짖어야 하지?" << endl; }
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
		// 부모의 PrintShou 함수 호출
		Animal::PrintShout();

		cout << "멍멍!!!멍멍!!" << endl;
		cout << "나이 : " << age << endl;
		cout << "이름 : " << name << endl;
	}

	void PrintDogOnly() { cout << "왈!! 왈!! 왈!!" << endl; }
};

class Cat : public Animal
{
public : 
	Cat() { /*cout << "Cat()" << endl; */}
	virtual ~Cat() {/* cout << "~Cat()" << endl;*/ }

	virtual void PrintShout() override
	{
		cout << "미야옹~~ 미야옹~~" << endl;
		cout << "나이 : " << age << endl;
		cout << "이름 : " << name << endl;
	}

	void PrintCatOnly() { cout << "키야옹!!!!! 키야옹!!!" << endl; }
};

int main2()
{
	Animal * animal = new Animal;
	
	Dog* dog = new Dog();
	dog->age = 3;
	dog->name = "행복이";

	Cat* cat = new Cat();
	cat->age = 10;
	cat->name = "나비";

	Animal* aniArr[2];

	// ---------------------- 업캐스팅 ---------------------------
	aniArr[0] = static_cast<Animal*>(dog);
	aniArr[1] = static_cast<Animal*>(cat);

	cout << "  ----------------------------------------" << endl;
	for (int i = 0; i < 2; i++)
	{
		// 자식의 함수 호출 불가
		aniArr[i]->PrintShout();	
		aniArr[i]->PrintOnly();	
	}
	cout << " ----------------------------------------" << endl;
	// ---------------------- 업캐스팅 ---------------------------

	// ---------------------- 다운 캐스팅 ---------------------------
	Dog* testDog = new Dog();
	testDog = nullptr;

	Cat* testCat = new Cat();
	testCat = nullptr;

	// ---------------------- 다운 캐스팅 ---------------------------
	for (int i = 0; i < 2; i++)
	{
		testDog = dynamic_cast<Dog*>(aniArr[i]);
		testCat = dynamic_cast<Cat*>(aniArr[i]);

		if (testDog != nullptr)
		{
			testDog->PrintShout();
			testDog->PrintDogOnly();
			testDog->PrintOnly(); // 부모의 함수 호출 가능
		}
			

		if (testCat != nullptr)
		{
			testCat->PrintShout();
			testCat->PrintCatOnly();
			testCat->PrintOnly();	// 부모의 함수 호출 가능
		}
			
	}
	// ---------------------- 다운 캐스팅 ---------------------------
	cout << " ----------------------------------------" << endl;

	return 0;
}
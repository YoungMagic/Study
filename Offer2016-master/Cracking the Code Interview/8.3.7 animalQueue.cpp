/*
* ������8.3.7 �мҶ���������ֻ��è�͹������ϸ����ء��Ƚ��ȳ���ԭ�򡱡�
* ���������������Ķ���ʱ��ֻ��ѡ�����ϵģ����ݽ���ʱ�䳤�̣������ߣ�
* ������ѡè�򹷣����ϵģ���
* ������ݽṹ��ʵ�ָ��ֲ�������������enqueue��dequeueAny��dequeueDog
* dequeueCat�ȡ�
*/

#include <iostream>
#include <cstdlib>
#include <queue>
#include <string>

using namespace std;

class Animal{
public:
	Animal(string name) :name(name){}

	void setOrder(int ord)
	{
		this->order = ord;
	}

	int getOrder()
	{
		return this->order;
	}

	bool isOlderThan(Animal a)
	{
		return this->order < a.getOrder();
	}
private:
	int order;
	string name;
};

class Dog : Animal{
public:
	Dog(string n) :Animal(n){}
};

class Cat :Animal{
public:
	Cat(string n) :Animal(n){}
};

class AnimalQueue{
public:
	queue<Dog> dogs;
	queue<Cat> cats;

	void enqueue(Animal a)
	{
		a.setOrder(order);
		++order;

		if (a instanceof Dog)
			dogs.push((Dog)a);
		else if (a instanceof Cat)
			cats.push((Cat)a);
	}

	Animal dequeueAny()
	{
		if (dogs.empty())
			return dequeueCats();
		else if (cats.empty())
			return dequeueDogs();

		Dog dog = dogs.front();
		Cat cat = cats.front();
		if (dog.isOlderThan(cat))
			return dequeueDogs();
		else
			return dequeueCats();
	}

	Dog dequeueDogs()
	{
		Dog dog = dogs.front();
		dogs.pop();
		return dog;
	}

	Cat dequeueCats()
	{
		Cat cat = cats.front();
		cats.pop();
		return cat;
	}

private:
	int order = 0;
};
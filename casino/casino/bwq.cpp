#include <iostream>
#include <string>
#include <vector>

class Animals
{
protected : 
// has to be prtotected 
	double weight = 0;
	std::string name;
public:
	Animals(std::string N, double W)
		:name(N), weight(W)
	{
		// nothing here...
	}
	virtual bool Overweight() = 0; // Pure virtual, cant take any argsz

	friend std::ostream& operator << (std::ostream& out, Animals& A)
	{
		std::cout << "Name: " << A.name << "\n";
		std::cout << "Weight: " << A.weight << "\n";
		
		return out;

	}
};

class Dog : public Animals
{

public:
	Dog(std::string N, double W) : Animals(N,W)
	{
		//Noting here...
	}
	virtual bool Overweight()  
	{
		return this->weight > 45;
	}

};

class Cat : public Animals
{

public:
	Cat(std::string N, double W) : Animals(N, W)
	{
		//Noting here...
	}
	virtual bool Overweight() 
	{
		return this->weight > 15;
	}

};

int main() {

	std::vector<Animals*> V =
	{new Cat ("MAsd", 77),new Dog ("std", 99),new Cat("hjio", 53),new Dog("guuy", 65),new Cat("qiou", 11),new Dog("iouytt", 34),new Cat("opiu", 16) };
	std::cout << "Vector Size: " << V.size()<<'\n';
	std::cout << "\n";
	std::cout << "Overweight CATS" << "\n";
	std::cout << "\n";

	for (auto C : V)
	{
		if (dynamic_cast<Cat*>(C)&& C->Overweight())
		{
			std::cout << *C<<"\n";
		}
	}
	std::cout << "\n";
	std::cout << "Overweight DOGS" << "\n";
	std::cout << "\n";


	for (Animals* C : V)
	{
		if (dynamic_cast<Dog*>(C) && C->Overweight())
		{
			std::cout << *C << "\n";
		}
	}

	return 0;
}
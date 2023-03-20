#include<iostream>
#include<string>
#include<windows.h>

class Figure
{
protected:
	std::string name = "Фигура";
	int sum = 0;
public:
	virtual void Sides()
	{

	}
	virtual void Angles()
	{
	
	}
	virtual void NumSides()
	{

	}
	virtual bool Check()
	{
		return true;
	}
	bool correct = Check();
	Figure(int sum)
	{
		this->sum = sum;
	}
	virtual void print()
	{
		std::cout << name <<":" << std::endl;
		if (correct)
		{
			std::cout << "Правильная"<<std::endl;
		}
		else std::cout << "Неправильная"<<std::endl;
		std::cout << "Колличество сторон: " << sum << std::endl;

	}
};
class Triangle :public Figure
{
protected:
	int a, b, c;
	int A, B, C;
	int sum;
	std::string name = "Треугольник";
public:
	Triangle(int sum, int a, int b, int c, int A, int B, int C) :Figure(sum)
	{
		this->sum = sum;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;

	}
	void NumSides() override
	{
		std::cout << "Колличество сторон: " << sum << std::endl;
	}
	void Sides() override
	{
		std::cout << "Стороны: " << "a = " << a << " b = " << b << " c = " << c << std::endl;
	}
	void Angles() override
	{
		std::cout << "Углы: " << "A = " << A << " B = " << B << " C = " << C << std::endl;
	}
	int* ammount = &sum;
	int* FirstAngle = &A;
	int* SecondAngle = &B;
	int* ThirdAngle = &C;
	bool Check() override
	{
		if ((*ammount < 3 || *ammount>3) || (*FirstAngle + *SecondAngle + *ThirdAngle != 180))
		{
			return false;
		}
		else 
		{
			 return true;
		}
	}
	bool correct = Check();
	
	
	void print() override
	{
		std::cout << name << ":" << std::endl;
		if (correct == true)
		{
			std::cout << "Правильная" << std::endl;
		}
		else std::cout << "Неправильная" << std::endl;
		std::cout << "Колличество сторон: " << sum << std::endl;
		Sides();
		Angles();
	}
};
class Quadrangle :public Figure
{

};
void print(Figure* figure)
{
	figure->print();
}



int main(int argc, char** argv)
{
	system("chcp 1251");
	Figure figure(0);
	print(&figure);
	Triangle triangle(3, 10, 20, 30, 50, 60, 70);
	print(&triangle);

	
	return 0;
}



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
	virtual std::string GetName()
	{
		return name;
	}
	virtual bool Check()
	{
		return true;
	}
	Figure(int sum)
	{
		this->sum = sum;
	}
	virtual void print()
	{
		std::cout << GetName() <<":" << std::endl;
		if (Check()==true)
		{
			std::cout << "Правильная" << std::endl;
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
	std::string name = "Треугольник";
public:
	Triangle( int a, int b, int c, int A, int B, int C) :Figure(3)
	{
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
	 std::string GetName() override
	{
		return name;
	}
	bool Check() override
	{
		if ((A + B + C) != 180)
		{
			return false;
		}
		else return true;
	}
	
	
	void print() override
	{
		std::cout << GetName() << ":" << std::endl;
		if (Check() == true)
		{
			std::cout << "Правильная" << std::endl;
		}
		else std::cout << "Неправильная" << std::endl;
		std::cout << "Колличество сторон: " << sum << std::endl;
		Sides();
		Angles();
	}
};
class Triangle90 :public Triangle
{
protected:
	std::string name = "Прямоугольный треугольник";
public:
	Triangle90(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, 90)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}
	 std::string GetName() override
	{
		return name;
	}
	bool Check() override
	{
		if (!Triangle::Check() || C != 90) return false;
		else return true;
	}
};
class Isoscelestriangle :public Triangle
{
protected:
	std::string name = "Равнобедренный треугольник";
public:
	Isoscelestriangle(int a, int b, int A, int B) :Triangle(a, b, a, A, B, A)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}
	std::string GetName() override
	{
		return name;
	}
	bool Check() override
	{
		if (!Triangle::Check() || (a != c && A != C))
		{
			return false;
		}
		else return true;
	}
	
};
class Triangle60 :public Triangle
{
protected:
	std::string name = "Равносторонний треугольник";
public:
	Triangle60(int a) :Triangle(a, a, a, 60, 60, 60)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}
	std::string GetName() override
	{
		return name;
	}
	bool Check() override
	{
		if (!Triangle::Check() || (a != b || b != c || a != c || A != B || A != C || B != C)) return false;
		else return true;
	}
};
class Quadrangle :public Figure
{
protected:
	int a, b, c, d;
	int A, B, C, D;
	std::string name = "Четырёхугольник";
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) :Figure(4)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	 std::string GetName() override
	{
		return name;
	}
	 bool Check() override
	 {
		 if (A + B + C + D != 360) return false;
		 else return true;
	 }
	 void NumSides() override
	 {
		 std::cout << "Колличество сторон: " << sum << std::endl;
	 }
	 void Sides() override
	 {
		 std::cout << "Стороны: " << "a = " << a << " b = " << b << " c = " << c <<" d = "<<d<< std::endl;
	 }
	 void Angles() override
	 {
		 std::cout << "Углы: " << "A = " << A << " B = " << B << " C = " << C <<" D = "<<D<< std::endl;
	 }
	 void print() override
	 {
		 std::cout << GetName() << ":" << std::endl;
		 if (Check() == true)
		 {
			 std::cout << "Правильная" << std::endl;
		 }
		 else std::cout << "Неправильная" << std::endl;
		 std::cout << "Колличество сторон: " << sum << std::endl;
		 Sides();
		 Angles();
	 }
};
class Paralelogramm : public Quadrangle
{
protected:
	std::string name = "Параллелограмм";
public:
	Paralelogramm(int a, int b, int A, int B) :Quadrangle(a, b, a, b, A, B, A, B)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	std::string GetName() override
	{
		return name;
	}
	bool Check() override
	{
		if (!Quadrangle::Check() || a != c || b != d || A != C || B != D) return false;
		else return true;
	}
};
class Recangle :public Paralelogramm
{
protected:
	std::string name = "Прямоугольник";
public:
	Recangle(int a, int b) :Paralelogramm(a,b,90,90)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	std::string GetName() override
	{
		return name;
	}
	bool Check() override
	{
		if (!Quadrangle::Check() || a != c || b != d || A != 90 || B != 90 || C != 90 || D != 90) return false;
		else return true;
	}

};
class Rhomb :public Paralelogramm
{
protected:
	std::string name = "Ромб";
public:
	Rhomb(int a, int A, int B) :Paralelogramm(a, a, A, B)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	std::string GetName() override
	{
		return name;
	}
	bool Check() override
	{
		if (!Quadrangle::Check() || a != c || a != b || a != d || b != c || b != d || c != d || A != C || B != D) return false;
		else return true;
	}
};
class Square :public Rhomb
{
protected:
	std::string name = "Квадрат";
public:
	Square(int a) :Rhomb(a,  90, 90)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	std::string GetName() override
	{
		return name;
	}
	bool Check() override
	{
		if (!Quadrangle::Check() || a != c || a != b || a != d || b != c || b != d || c != d || A != 90 || B != 90 || C != 90 || D != 90) return false;
		else return true;
	}
};
void print(Figure* figure)
{
	figure->print();
	std::cout << std::endl;
}



int main(int argc, char** argv)
{
	system("chcp 1251");
	Figure figure(0);
	print(&figure);
	Triangle triangle( 10, 20, 30, 50, 60, 70);
	print(&triangle);
	Triangle90 triangle90(10, 20, 30, 50, 60);
	print(&triangle90);
	Isoscelestriangle isoscelestriangle(10, 20, 50, 60);
	print(&isoscelestriangle);
	Triangle60 triangle60(30);
	print(&triangle60);
	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	print(&quadrangle);
	Recangle rectangle(10, 20);
	print(&rectangle);
	Square square(20);
	print(&square);
	Paralelogramm paralelogramm(20, 30, 30, 40);
	print(&paralelogramm);
	Rhomb rhomb(30, 40, 30);
	print(&rhomb);
	return 0;
}



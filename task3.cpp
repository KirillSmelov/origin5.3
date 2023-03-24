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
	int sum;
	std::string name = "Треугольник";
public:
	Triangle( int a, int b, int c, int A, int B, int C) :Figure(sum)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		sum = 3;
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
	int a, b, c;
	int A, B, C;
public:
	Triangle90(int a, int b, int c, int A, int B, int C) :Triangle(a, b, c, A, B, C)
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
		if ((A + B + C) != 180 || C != 90) return false;
		else return true;
	}
};
class Isoscelestriangle :public Triangle
{
protected:
	std::string name = "Равнобедренный треугольник";
	int a, b, c;
	int A, B, C;
public:
	Isoscelestriangle(int a, int b, int c, int A, int B, int C) :Triangle(a, b, c, A, B, C)
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
		if ((A + B + C) != 180 || (a != c && A != C))
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
	int a, b, c, A, B, C;
public:
	Triangle60(int a, int b, int c, int A, int B, int C) :Triangle(a, b, c, A, B, C)
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
		if ((A + B + C != 180) || (a != b || b != c || a != c || A != B || A != C || B != C)) return false;
		else return true;
	}
};
class Quadrangle :public Figure
{
protected:
	int a, b, c, d;
	int A, B, C, D;
	std::string name = "Четырёхугольник";
	int sum = 4;
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) :Figure(a)
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
class Recangle :public Quadrangle
{
protected:
	int a, b, c, d;
	int A, B, C, D;
	std::string name = "Прямоугольник";
public:
	Recangle(int a, int b, int c, int d, int A, int B, int C, int D) :Quadrangle(a,b,c,d,A,B,C,D)
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
		if (A + B + C + D != 360||a!=c||b!=d||A!=90||B!=90||C!=90||D!=90) return false;
		else return true;
	}

};
class Square :public Quadrangle
{
protected:
	int a, b, c, d;
	int A, B, C, D;
	std::string name = "Квадрат";
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) :Quadrangle(a, b, c, d, A, B, C, D)
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
		if (A + B + C + D != 360 || a != c ||a!=b||a!=d||b!=c|| b != d ||c!=d|| A != 90 || B != 90 || C != 90 || D != 90) return false;
		else return true;
	}
};
class Paralelogramm : public Quadrangle
{
protected:
	int a, b, c, d;
	int A, B, C, D;
	std::string name = "Параллелограмм";
public:
	Paralelogramm(int a, int b, int c, int d, int A, int B, int C, int D) :Quadrangle(a, b, c, d, A, B, C, D)
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
		if (A + B + C + D != 360 || a !=c||b!=d || A!=C||B!=D) return false;
		else return true;
	}
};
class Rhomb :public Quadrangle
{
protected:
	int a, b, c, d;
	int A, B, C, D;
	std::string name = "Ромб";
public:
	Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) :Quadrangle(a, b, c, d, A, B, C, D)
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
		if (A + B + C + D != 360 || a != c || a != b || a != d || b != c || b != d || c != d ||  A!=C ||B!=D) return false;
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
	Triangle90 triangle90(10, 20, 30, 50, 60, 90);
	print(&triangle90);
	Isoscelestriangle isoscelestriangle(10, 20, 10, 50, 80, 50);
	print(&isoscelestriangle);
	Triangle60 triangle60(30, 30, 30, 60, 60, 60);
	print(&triangle60);
	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	print(&quadrangle);
	Recangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
	print(&rectangle);
	Square square(20, 20, 20, 20, 90, 90, 90, 90);
	print(&square);
	Paralelogramm paralelogramm(20, 30, 20, 30, 30, 40, 30, 40);
	print(&paralelogramm);
	Rhomb rhomb(30, 30, 30, 30, 30, 40, 30, 40);
	print(&rhomb);
	return 0;
}



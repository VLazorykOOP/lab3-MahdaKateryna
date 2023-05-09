#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#if !defined(CODING_VS_CODE)
	#include <clocale>
#endif
using namespace std;

class Triangle {
	double a, b, c; // sides of the Triangle
	unsigned int color;
public:
	Triangle() : a(1.0), b(2.0), c(3.0), color(0) {}
	Triangle(double ai) : a(ai), color(0) {}
	Triangle(int ic) : a(1.0) { if (ic >= 0) color = ic; else color = 0; }
	Triangle(double a, int c) {
		this->a = a;
		if (c >= 0) color = c; else color = 0;
	}
	double getA() const
	{
		return a;
	}
	void setA(double a)
	{
		if (a < 0 || a > 1.e+100)
		{
			cout << " Error set  a \n";
			return;
		}
		this->a = a;
	}
	double getColor() const
	{
		return color;
	}
	void setColor(int c)
	{
		if (c < 0 || c > 10000)
		{
			cout << " Error set  color \n";
			return;
		}
		this->color = c;
	}
	double S() {
		return sqrt(((a+b+c)/2) * (((a+b+c)/2)-a) * (((a+b+c)/2)-b) * (((a+b+c)/2)-c));
	}
	double P() {
		return (a + b + c);
	}

	
	void printInfo()
	{
		cout << "\n a= " << a << "   b = " << b << "   c = " << c  << "   color = " << color;
		cout << "  S= " << S() << "   P = " << P() <<  endl;
	}

};
int mainExample1()
{
	Triangle obj;
	obj.printInfo();
	double in_a; int in_color;
	cout << " Input side and color Triangle  "; cin >> in_a >> in_color;
	Triangle obj1(in_a), obj2(in_color), obj3(in_a, in_color);
	obj1.printInfo();
	obj2.printInfo();
	obj3.printInfo();
	obj.setA(-5);
	obj.printInfo();
	obj.setA(5);
	obj.printInfo();
	obj.setA(2.e100);
	obj.printInfo();
	obj.setColor(-10);
	obj.printInfo();
	obj.setColor(10);
	obj.printInfo();
	obj.setColor(10001);
	obj.printInfo();
	cout << " End testing \n";
	return 1;
}


// Ключове слово static 

class foo
{
private:
	static int count; // загальне поле всім об'єктів
	// (У сенсі "оголошення")
public:
	foo() { incObj(); } // інкрементування під час створення об'єкта
	static int incObj() { return ++count; }
	int getcount() { return count; }
};
int  foo::count = 0;
// Ключове слово static ставиться перед типом способу.В основному використовуються
//для роботи зі статичними полями класу.

/*  Example 3
Створити тип даних - клас вектор, який має поля x, y типу double і змінну стану. У класі визначити
o	конструктор без параметрів(інінціалізує поля в нуль);
o	конструктор з одним параметром типу double (інінціалізує поля);
o	конструктор з одним параметром вказівник на тип double (інінціалізує поля x, y значенням масиву за вказівником, якщо вказівник NULL (nulptr) то встановити код помилки);
o	деструктор із виведенням інформації про стан вектора;
o	визначити функції друку, додавання, віднімання, векторний добуток які здійснюють ці арифметичні операції з даними цього класу;
o	функцію ділення на ціле типу double(при діленні на 0 змінити стан, а ділення не виконувати);
o	визначити функцію порівняння менше які повертають true або false.
У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу.
*/
enum STATE {
	OK, BAD_INIT, BAD_DIV
};

int object_count;
class LongVector
{
	long* v;
	int num;   // default num=2
	int state = 0;
public:
	LongVector() : LongVector(2) { object_count++; }
	LongVector(int n) {
		if (n <= 0) n = 2;  // default num =2;
		num = n;
		v = new long[n];
		for (int i = 0; i < n; i++) {
			v[i] = 0;
		}
		object_count++;
	}
	LongVector(int n, long b) : LongVector(n) {
		for (int i = 0; i < num; i++) v[i] = b;
		object_count++;
	};
	LongVector(int n, long* p) : LongVector(n) {
		if (p != nullptr) for (int i = 0; i < num; i++) v[i] = p[i];
		object_count++;
	};
	LongVector(const LongVector& s) {
		num = s.num;
		v = new long[num];
		state = s.state;
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
		object_count++;
	};
	LongVector operator+(LongVector s) const {
		if (num != s.num) {
			LongVector result;
			result.state = 1;
			return result;
		}
		else {
			LongVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] + s.v[i];
			}
			return result;
		}
	}
	LongVector operator-(const LongVector s) const {
		if (num != s.num) {
			LongVector result;
			result.state = 1;
			return result;
		}
		else {
			LongVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] - s.v[i];
			}
			return result;
		}
	};
	LongVector operator*(unsigned int scalar) const {
		LongVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] * scalar;
		}
		return result;
	};
	bool operator>(const LongVector s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] <= s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	bool operator!=(const LongVector s) const {
		if (num != s.num) {
			return true;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return true;
				}
			}
			return false;
		}
	};
	bool operator==(const LongVector s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	LongVector operator=(LongVector s) {

		if (num != s.num)
		{
			delete[] v;
			num = s.num;
			v = new long[num];
			state = s.state;
		}
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
		return *this;
	};
	~LongVector() {
		delete[] v;
		object_count--;
	}
	void set(int index, long x = 0) { if (index >= 0 && index <= num) v[index] = x; else state = 1; }
	long get(int index) { if (index >= 0 && index <= num) return v[index]; else state = 1; }
	void Output() {
		if (state == 1) {
			cout << "Index error";
			return;
		}
		if (num != 0) {
			for (int i = 0; i < num; i++) {
				cout << " v [ " << i << " ]   " << v[i] << '\t';
				cout << endl;
			}
		}
	};
	void Input() {
		int in_num = 0;
		do {
			cout << "Input size Vec\n";
			cin >> in_num;
			} while (in_num <= 0);
			if (num != in_num) {
				num = in_num;
				if (v) delete[] v;
				v = new long[num];
			}
			for (int i = 0; i < num; i++) {
				cout << " v [ " << i << " ]= "; cin >> v[i];
			}
		};
	};

int mainExample3()
{
	object_count = 0;
	LongVector v1;
	cout << "Vector 1: ";
	v1.Output();
	cout << endl;

	LongVector v2(5);
	cout << "Vector 2: ";
	v2.Output();
	cout << endl;

	LongVector v3(3, 7);
	cout << "Vector 3: ";
	v3.Output();
	cout << endl;

	LongVector v4(v3);
	cout << "Vector 4 (copy of Vector 3): ";
	v4.Output();
	cout << endl;

	LongVector v5;
	v5 = v2;
	cout << "Vector 5 (assigned from Vector 2): ";
	v5.Output();
	cout << endl;

	v3.set(0, 9);
	cout << "Vector 3 (after setting first element to 9): ";
	v3.Output();
	cout << endl;

	cout << "The first element of Vector 3 is: " << v3.get(0) << endl;

	cout << "Vector 3 + Vector 4";
	v1 = v3 + v4;
	v1.Output();

	cout << "Vector 1 - Vector 3";
	v1 = v1 - v4;
	v1.Output();

	cout << "Vector 1 * 4";
	v1 = v1 * 4;
	v1.Output();

	cout << "Vector 1 > Vector 4: " << (v1 > v4) << endl;
	cout << "Vector 1 != Vector 4: " << (v1 != v4) << endl;
	cout << "Vector 1 == Vector 4: " << (v1 == v4) << endl;

	v3.set(5, 1);
	cout << "Vector 3 (after trying to set 6th element to 1): ";
	v3.Output();
	cout << endl;

	return 0;
}
/*example  4
Створити тип даних - клас вектор, який має вказівник на ComplexDouble, число елементів і змінну стану. У класі визначити
o	 конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль);
o	конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
o	конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу).
o	конструктор копій та операцію присвоєння; // !!!
o	деструктор звільняє пам'ять;
o	визначити функції друку, додавання;
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу.
*/

#include<complex>
using namespace std;
typedef complex<double> ComplexDouble;
#define _RE 0
#define _IM 1

class ComplexVector
{
	ComplexDouble* v;
	int num;   // default num=2
	int state = 0;
public:
	ComplexVector() : ComplexVector(2) {}
	ComplexVector(int n);
	ComplexVector(int n, ComplexDouble&);
	ComplexVector(int n, ComplexDouble*);
	ComplexVector(const ComplexVector& s);
	ComplexVector& operator=(const ComplexVector& s);
	~ComplexVector() {
		std::cout << " del vec";
		if (v) delete[] v;
	}
	void Output();
	void Input();
	ComplexVector Add(ComplexVector& b);

};

ComplexVector::ComplexVector(int n) {
	if (n <= 0)    n = 2;  // default num =2;
	num = n;
	v = new ComplexDouble[n];
	for (int i = 0; i < n; i++) {
			v[i] = 0.0;
			//v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0;  
		}

}
ComplexVector::ComplexVector(int n, ComplexDouble& b) : ComplexVector(n) {
	for (int i = 0; i < num; i++) {
		v[i] = b;
		//v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0;  
	}
}

ComplexVector::ComplexVector(int n, ComplexDouble* p) : ComplexVector(n) {
	if (p != nullptr) 
	for (int i = 0; i < num; i++) 
		v[i] = p[i];
	
}

ComplexVector::ComplexVector(const ComplexVector& s) {
	// if (this == &s) return;  // the expression is used in the old standard
	num = s.num;
	v = new ComplexDouble[num];
	state = 0;
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
}

ComplexVector& ComplexVector::operator=(const ComplexVector& s) {

	if (num != s.num)
	{
		if (v) delete[] v;
		num = s.num;
		v = new ComplexDouble[num];
		state = 0;
	}
	for (int i = 0; i < num; i++)   v[i] = s.v[i];
	return *this;
}
void ComplexVector::Input() {
	int in_num=0;
		do {
			cout << "Input size Vec\n";
			cin >> in_num;
		} while (in_num <= 0);
		if (num != in_num ) {
			num = in_num;
			if (v) delete[] v;
		v = new ComplexDouble[num];
	}
	for (int i = 0; i < num; i++) {

#if defined(_MSC_VER)
cout << " v [ " << i << " ] real img  "; cin >> v[i] >> v[i]._Val[_IM];
#else 
double re,im;
cout << " v [ " << i << " ] real img  "; cin >> re>>im;
v[i].real(re); 
v[i].imag(im);
#endif		
		
		
	}
}

void ComplexVector::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << " v [ " << i << " ]   " << v[i] << '\t';
			cout << endl;
		}
	}
}

ComplexVector ComplexVector::Add(ComplexVector& b) {
	int tnum;
	tnum = num < b.num ? num : b.num;
	if (tnum >= 0) {
		ComplexVector tmp(tnum);
		for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
		return tmp;
	}
	return ComplexVector(1);
}


int mainExample4()
{
	ComplexDouble a(1.0, 2), b, c;
	cout << a << endl;
#if defined(_MSC_VER)
    b._Val[_RE] = 21.3;
	b._Val[_IM] = 22.3;
#else 
    b.real( 21.3);
	b.imag (22.3);
#endif	
	
	cout << b << endl;
	c = a + b;
	cout << c << endl;
	cout << " Test  " << endl;
	ComplexVector VecObj, VecObj1(10);
	cout << "VecObj \n";
	VecObj.Output();
	cout << "VecObj1 \n";
	VecObj1.Output();
	cout << " Input a " << endl;

#if defined(_MSC_VER)
 cin >> a >> a._Val[_IM];
#else 
double re,im;
cin >> re>>im;
a.real(re); 
a.imag(im);
#endif		
	cout << a << endl;
	ComplexVector VecObj2(10, a);
	VecObj2.Output();

	VecObj.Input();
	cout << endl;
	VecObj.Output();
	VecObj1 = VecObj.Add(VecObj2);
	VecObj1.Output();

	return 1;
}

/// 


#include<iostream>
using namespace std;
class Point;
class Shape;
class Dot;
class DispWindow;
class Rectangle;
class Line;
///////////////////////////////////////////////////////////////////////////////////////////////////
class Point
{
private:

public:
	int x, y;
	Point(int a = 0, int b = 0);//constructor
	Point(const Point&);//copy constructor
						//operators
	Point& operator =(Point&);//copy assignment
	Point& operator+(Point);//p+p;
	Point& operator+=(Point);
	//Point& operator*(float);//p*c;
							//instructors
	Point right(int n = 1);
	Point left(int n = 1);
	Point up(int n = 1);
	Point down(int n = 1);
	int get_x();
	int get_y();

};
///////////////////////////////////////////////////////////////////////////////////////////////////
class Shape//abstract class;
{
protected:
	//e(east), w(west), n(north), s(south), ne, nw, se, sw and c (center)
	Point _e, _w, _n, _s, _ne, _nw, _se, _sw, _c;
public:
	virtual void draw(DispWindow& w) = 0;
};
///////////////////////////////////////////////////////////////////////////////////////////////////
class DispWindow
{
private:
	Point orijin;
	int n;
	int m;
	char** buffer;
public:
	//DispWindow() {}//default constructor
	DispWindow(int a, int b);//constructor
	Point current();//returns orijin
	Point current(Point);//current position
	template<typename T>
	void draw(T&)
	{
		a.draw(*this);
	}//function to achieve shapes virtual function
	
	/*void draw(Line a);
	void draw(Rectangle a);
	void draw(Dot a);*/
	void show();
	int get_n();
	int get_m();
	void get_buffer(int, int, char);
	void set_orijin(Point);
};
///////////////////////////////////////////////////////////////////////////////////////////////////
class Dot :virtual public Shape
{
private:
	Point a;
public:
	Dot(Point);//constructor
	void draw(DispWindow&);
	Point se();
	Point s();
	Point e();
	Point w();
	Point n();
	Point ne();
	Point nw();
	Point sw();
	Point c();
};
///////////////////////////////////////////////////////////////////////////////////////////////////
class Rectangle :virtual public Shape
{
private:
	Point a, b;
public:
	Rectangle(Point, Point);
	void draw(DispWindow& w);
	Point se();
	Point s();
	Point e();
	Point w();
	Point n();
	Point ne();
	Point nw();
	Point sw();
	Point c();
};
///////////////////////////////////////////////////////////////////////////////////////////////////
class Line :virtual public Shape
{
private:
	Point a, b;
public:
	Line(Point, Point);//contructor
	void draw(DispWindow& w);
	Point se();
	Point s();
	Point e();
	Point w();
	Point n();
	Point ne();
	Point nw();
	Point sw();
	Point c();

};

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Point {
private:
	float x;
	float y;

public:
	Point(float x = 0, float y = 0) : x(x), y(y) {}
	float getX() const { return x; }
	float getY() const { return y; }

	float distance(const Point & a) const {
		return sqrt(pow(a.x - this->x, 2) + pow(a.y - this->y, 2));
	}
};

class Shape {
public:
	virtual ~Shape() = default;
	virtual bool contains(const Point &p ) const = 0;
};

class Rectangle : public Shape {
private:
	Point center;
	float dx;
	float dy;

public:
	Rectangle(Point center, float dx, float dy) :center(center), dx(dx), dy(dy){}

	bool contains(const Point & p) const {
		return abs(p.getX() - center.getX()) <= dx && abs(p.getY() - center.getY()) <= dy;
	}
};

class Square : public Rectangle {
public:
	Square(Point center, float side) :Rectangle(center, side / 2, side / 2) {}
};

class Ellipse : public Shape {
private: 
	Point f1;
	Point f2;
	float radius;

public:
	Ellipse(Point f1, Point f2, float radius) : f1(f1), f2(f2), radius(radius) {}
	
	bool contains(const Point & p) const {
		return p.distance(f1) + p.distance(f2) <= radius;
	}
};

class Circle : public Ellipse {
public:
	Circle(Point center, float radius):Ellipse (center, center, radius){}
};


int main() {
	const int frames = 40;
	const int framSleep = 70;

	for (float f = 0; f < frames; f++) {
		Rectangle r(Point(5 + f, 5), 2, 8);

	}









	system("pause");
	return 0;
}

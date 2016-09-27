#include <iostream>
using namespace std;
class Shape
{
	public:
		void setWidth(double w)
		{
			width = w;
		}
		void setHeight(double h)
		{
			height = h;
		}
	protected:
		double width;
		double height;
};
class Rectangle: public Shape
{
	public:
		double getArea(void)
		{
			return width*height;
		}
};
int main(void)
{
	Rectangle Rect;

	Rect.setWidth(5);
	Rect.setHeight(7);
	// Print the area of the object.
	cout << "Total area: " << Rect.getArea() << endl;
	return 0;
}

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
class PaintCost
{
	public:
		double getCost(double area)
		{
			return area*70.0;
		}
};
class Rectangle: public Shape, public PaintCost
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
	double area;
	Rect.setWidth(5);
	Rect.setHeight(7);
	area = Rect.getArea();
	// Print the area of the object.
	cout << "Total area: " << area << endl;
	cout << "Total painting cost is" << Rect.getCost(area)<<endl;
	return 0;
}

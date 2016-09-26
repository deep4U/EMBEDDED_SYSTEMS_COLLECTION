#include <iostream>

class Box
{
	public:
		double length;
		double width;
		double height;
		void setlength(double);
		void setwidth(double);
		void setheight(double);
		double getvolume();
};
double Box::getvolume()
{
	return length * width * height;
}
void Box::setlength(double a)
{
	length = a;
}
void Box::setwidth(double a)
{
	width = a;
} 
void Box::setheight(double a)
{
	height = a;
}

int main()
{
	Box Bo1,Bo2;
	double volume;
	Bo1.setlength(10.2);
	Bo2.setlength(2.2);
	Bo1.setwidth(2.43);
	Bo2.setwidth(2.411);
	Bo1.setheight(32.2);
	Bo2.setheight(6.1);
//	volume = Bo1.length * Bo1.width * Bo1.height;
	std::cout << "Volume of Bo1 is " << Bo1.getvolume() << std::endl;
//	volume = Bo2.length * Bo2.width * Bo2.height;
	std::cout << "volume of Bo2 is " << Bo2.getvolume() << std::endl;
	return 0;
}

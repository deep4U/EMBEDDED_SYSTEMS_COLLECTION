#include <iostream>

class Line
{
	public:
		double length;
		void setLength(double);
		double getLength(void);
};
void Line::setLength(double a)
{
length = a;
}
double Line::getLength(void)
{
return length;
}
// Main function for the program
int main(void)
{
	Line line;

	// set line length
	line.setLength(6.0);
	std::cout << "Length of line : " << line.getLength() << std::endl;
	// set line length without member function
	line.length = 10.0; // OK: because length is public
	std::cout << "Length of line : " << line.length << std::endl;
	return 0;
}

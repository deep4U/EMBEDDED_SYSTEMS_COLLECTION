#include <iostream>

class Box
{
	public:
		double length;
		double width;
		double height;
};

int main()
{
	Box Bo1,Bo2;
	double volume;
	Bo1.length=10.2;
	Bo2.length=2.2;
	Bo1.width=2.43;
	Bo2.width=2.411;
	Bo1.height=32.2;
	Bo2.height=6.1;
	volume = Bo1.length * Bo1.width * Bo1.height;
	std::cout << "Volume of Bo1 is " << volume << std::endl;
	volume = Bo2.length * Bo2.width * Bo2.height;
	std::cout << "volume of Bo2 is " << volume << std::endl;
	return 0;
}

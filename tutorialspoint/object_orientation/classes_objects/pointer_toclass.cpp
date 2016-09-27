#include <iostream>
using namespace std;
class Box
{
	public:
		Box(double a=2.0,double b=2.0 ,double c=2.0)
		{
			cout<<"constructing box of LBH as L"<<a<<" B"<<b<<" H"<<c <<endl;
			length=a;
			breath=b;
			height=c;
		}
		double volume()
		{
			return length*breath*height;
		}
		int compare(Box box)
		{
			return this->volume() > box.volume();
		}
	private:
		double length;
		double breath;
		double height;
};
int main(void)
{
	Box box1(2.2,12,4.2);
	Box box2(23,45.2,22.3);
	Box *a;
	a = &box1;
	cout << "volume of box1 is " << a->volume();
	a=&box2;
	cout << "volume og box2 is" << a->volume();
}


#include<iostream>
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
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   if(Box1.compare(Box2))
   {
      cout << "Box2 is smaller than Box1" <<endl;
   }
   else
   {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   return 0;
}

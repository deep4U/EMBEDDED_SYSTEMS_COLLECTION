#include<iostream>
using namespace std;
/*
By declaring a function member as static, you make it independent of any particular object of the class. 

A static member function can be called even if no objects of the class exist and the static functions are accessed using only the class name and the scope resolution operator ::.

A static member function can only access static data member, other static member functions and any other functions from outside the class.

Static member functions have a class scope and they do not have access to the this pointer of the class. 
*/


class Box
{
	public:
		static int ObjCount;
		Box(double a=2.0,double b=2.0 ,double c=2.0)
		{
			cout<<"constructing box of LBH as L"<<a<<" B"<<b<<" H"<<c <<endl;
			length=a;
			breath=b;
			height=c;
			ObjCount++;
		}
		double volume()
		{
			return length*breath*height;
		}
		static int getcount()
		{
			return ObjCount;
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
int Box::ObjCount = 0;
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
	cout<<"number of objects is "<<Box::getcount()<<endl;
   return 0;
}

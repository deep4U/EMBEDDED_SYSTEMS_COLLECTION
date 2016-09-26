#include <iostream>
using namespace std;
class Box {
protected:
	double width;
public:
	void setWidth(double);
	friend void printWidth(Box);
};
void Box::setWidth(double a)
{
	width=a;
}
void printWidth(Box B)
{
	cout<<"width of box is " <<B.width << endl;
}
int main( )
{
   Box box;
 
   // set box width with member function
   box.setWidth(10.0);
   
   // Use friend function to print the wdith.
   printWidth( box );
 
   return 0;
}

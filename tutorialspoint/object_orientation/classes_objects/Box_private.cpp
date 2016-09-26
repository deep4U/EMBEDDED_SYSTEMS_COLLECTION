#include <iostream>

class Box
{
		double width;
	public:
		double length;
		void setWidth(double);
		double getWidth(void);
};
void Box::setWidth(double a)
{
	width = a;
}
double Box::getWidth(void)
{
	return width;
}
int main( )
{
   Box box;
 
   // set box length without member function
   box.length = 10.0; // OK: because length is public
   std::cout<< "Length of box : " << box.length <<std::endl;
 
   // set box width without member function
   // box.width = 10.0; // Error: because width is private
   box.setWidth(10.0);  // Use member function to set it.
   std::cout << "Width of box : " << box.getWidth() <<std::endl;
 
   return 0;
}

#include <iostream>

class Box
{
	protected:
		double width;
	public:
		double length;
};
class smallBox:Box
{
        public:
                void setsmallWidth(double);
                double getsmallWidth(void);
};
void smallBox::setsmallWidth(double a)
{
	width = a;
}
double smallBox::getsmallWidth(void)
{
	return width;
}
int main( )
{
   smallBox box;
 
   // set box length without member function
   // set box width without member function
   box.setsmallWidth(10.0);  // Use member function to set it.
   std::cout << "Width of box : " << box.getsmallWidth() <<std::endl;
 
   return 0;
}

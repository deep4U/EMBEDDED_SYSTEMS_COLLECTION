#include <iostream>

class Line
{
	public:
		void setLength(int);
		int getLength(void);
		Line();
		~Line();
		Line( const Line &obj);
		Line(int L);
	private:
		int *ptr;
};
Line::~Line(void)
{
    std::cout << "Object is being deleted free memory" << std::endl;
	delete ptr;
}
void display(Line obj) 
{
	std::cout << "Length of line : " << obj.getLength()<<std::endl;
}
void Line::setLength(int a)
{
*ptr=a;
}
int Line::getLength(void)
{
return *ptr;
}
Line::Line()
{
	std::cout << "constructing line here allocating ptr" << std::endl;
	ptr= new int;
	
}
Line::Line(int L)
{
	std::cout<< "allocating ptr and assigning "<<L<<std::endl;
	ptr= new int;
	*ptr=L;
}
Line::Line(const Line &obj)
{
	std::cout << "copy constructore allocating ptr"<<std::endl;
	ptr=new int;
	*ptr=*obj.ptr;
}
// Main function for the program
int main( )
{
   Line line(10);

   display(line);

   return 0;
}

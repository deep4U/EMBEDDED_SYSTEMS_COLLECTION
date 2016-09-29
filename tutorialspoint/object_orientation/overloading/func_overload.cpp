#include<iostream>
using namespace std;

class Showme {
public:
	void show(int a)
	{
		cout<<"showint:"<<a<<endl;
	}
	void show(double a)
	{
		cout<<"showfloat:"<<a<<endl;
	}
	void show(char* a)
	{
		cout<<"showstring"<<a<<endl;
	}
};
int main(void)
{
	Showme printer;
	printer.show(8);
	printer.show("hi this is string here");
	printer.show(234.23);
	return 0;
}

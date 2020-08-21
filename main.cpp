#include"HeaderMain.h"
void hi(int& a)
{
	int b= a;
}
int main()
{
	int a = 5;
	hi(a);
	std::cout << a;
	
	return 0;
}
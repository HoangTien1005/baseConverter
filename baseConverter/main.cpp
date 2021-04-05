

#include "baseConverter.h"

int main()
{

	baseConverter bC;
	bC.nhap();
	int base;
	do 
	{
		cout << "nhap co so can chuyen (2 -> 100): ";
		cin >> base;
	} while (base > 100 && base < 0);
	cout << "------------------------------------------------------------------------------" << endl;
	bC.xuat();
	bC.DecimalToBase(base);
	cout << " -> ";
	bC.xuat();
	cout << endl;
	return 0;
}

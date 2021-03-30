

#include "baseConverter.h"

int main()
{
	
	baseConverter bC;
	bC.nhap();
	int base;
	cout << "nhap co so can chuyen: ";
	cin >> base;
	bC.DecimalToBase(base);
	bC.xuat();
	return 0;
}

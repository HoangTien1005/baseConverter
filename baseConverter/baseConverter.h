#ifndef BASECONVERTER_H
#define BASECONVERTER_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

										// chỉ có hệ nhị phân là không có dấu (-)
class baseConverter {					// chuyển qua trung gian là thập phân
private:
	string input = "";						// chuỗi ng dùng nhập 
	int base = 0;

	bool inputCheck();					// kiểm tra định dạng chuỗi
	bool baseCheck();					// kiểm tra định dạng số
	long long int toDecimal();			// trung gian qua thập phân
	char getChar(int number);			// chuyển số sang ký tự 
	int getNum(char ch);				// chuyển ký tự sang số
	
	

public:
	void nhap();						// nhập input với base
	void xuat();						// xuất kết quả
	
	string DecimalToBase(int base);		// từ thập phân sang base ng dùng yêu cầu
	
	
};
#endif
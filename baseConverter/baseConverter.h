#ifndef BASECONVERTER_H
#define BASECONVERTER_H

#include <iostream>
#include <string>

using namespace std;

										// chỉ có hệ nhị phân là không có dấu (-)
class baseConverter {					// chuyển qua trung gian là thập phân
private:
	string input;						// chuỗi ng dùng nhập 
	int base;
	bool baseCheck();					// kiểm tra định dạng số
	string toDecimal();					// trung gian qua thập phân
	string flipBit();					// biểu diễn số âm hệ nhị phân ( bù 1 )
	

public:
	void nhap();						// nhập input với base
	void xuat();						// xuất kết quả
	char getChar(int number);			// chuyển số sang ký tự 
	int getNum(char ch);				// chuyển ký tự sang số
	string DecimalToBase(int base);		// từ thập phân sang base ng dùng yêu cầu
};
#endif
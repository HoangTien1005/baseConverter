#ifndef BASECONVERTER_H
#define BASECONVERTER_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

										
class baseConverter {					// chuyển qua trung gian là thập phân
private:
	string input = "";						// chuỗi người dùng nhập 
	int base = 0;

	float mod(float n, int m);			// lấy phần thập phân
	int isRealNumber();					// trả về index của dấu '.'
	bool inputCheck();					// kiểm tra định dạng chuỗi
	bool baseCheck();					// kiểm tra định dạng số
	float toDecimal();					// trung gian qua thập phân
	char getChar(int number);			// chuyển số sang ký tự 
	string getString(int number);
	int getNum(char ch);				// chuyển ký tự sang số
	
	

public:
	void nhap();						// nhập input với base
	void xuat();						// xuất kết quả
	
	string DecimalToBase(int base);		// từ thập phân sang base người dùng yêu cầu
	
	
};
#endif
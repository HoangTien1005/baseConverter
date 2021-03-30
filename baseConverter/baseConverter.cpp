#include "baseConverter.h"

bool baseConverter::inputCheck()
{
    int i = 0;
    if (input[0] == '-') {
        if (input.length() > 1) i = 1;
        else return false;
    }
    
    
    for ( i; i < input.length(); i++) {
        if ((input[i] >= '0' && input[i] <= '9') ||
            (input[i] >= 'A' && input[i] <= 'Z'))
            continue;
        else return false;
    }
    return true;
}

bool baseConverter::baseCheck()
{
    char charBase = getChar(base);
    for (int i = 0; i < input.length(); i++) {
        if (charBase < input[i]) return false;
    }
    return true;
}

long long int baseConverter::toDecimal()
{
    int i = 0;
    if (input[0] == '-') i = 1;
    long long int sum = 0;
    for (i ; i < input.length(); i++) {
        sum += getNum(input[i]) * pow(base, input.length() - i - 1);
    }
    return sum;
}

void baseConverter::nhap()
{
   
    do {
        cout << " nhap chuoi: ";
        getline(cin, input);
    } while (!inputCheck());

    do {
        cout << " nhap co so: ";
        cin >> base;
    } while (!baseCheck());
}

void baseConverter::xuat()
{
    cout << input << ": base " << base << endl;
}

char baseConverter::getChar(int number)
{
    if (number >= 10) return (char)(number + 55);
    else return (char)(number + '0');
}

int baseConverter::getNum(char ch)
{
    if (ch >= 'A') return (int)ch - 55;
    else return (int)ch - '0';
}

string baseConverter::DecimalToBase(int base)
{
   
    long long int dec = this->toDecimal();
    string res = "";
    while (dec > 0) {
        res = getChar(dec % base) + res;
        dec = dec / base;
    }
    
    if (base == 2) {
        while (res.length() < 32) {
            res = '0' + res;
        }
    }
    if (input[0] == '-') res = '-' + res;
   
    this->base = base;
    this->input = res;
    return res;
}

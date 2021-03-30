#include "baseConverter.h"

float baseConverter::mod(float n, int m)
{
    int temp = (int)n / m;
    return n - temp*m;
   
}

int baseConverter::isRealNumber()
{
    int i;
    for ( i = 0; i < input.length(); i++) {
        if (input[i] == '.') break;
    }
     return i;
}

bool baseConverter::inputCheck()
{
    int dotCount = 0;
    int i = 0;
    if (input[0] == '-') {
        if (input.length() > 1) i = 1;
        else return false;
    }
    
    
    for ( i; i < input.length(); i++) {
        if ((input[i] >= '0' && input[i] <= '9') ||
            (input[i] >= 'A' && input[i] <= 'Z') ||
            dotCount <=1)
        {
            if (dotCount == 2) return false;
            if (input[i] == '.')
            {
                dotCount++;
            }
            continue;
        }
            
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

float baseConverter::toDecimal()
{
    int i = 0;
    if (input[0] == '-') i = 1;
    float sum = 0;
    int length = input.length();
    int dotIndex = isRealNumber();          // index của dấu '.'

    for (i ; i < dotIndex; i++) {
        sum += getNum(input[i]) * pow(base, dotIndex - i - 1);      // xử lý trước dấu .
    }
    for (i = dotIndex + 1; i < length; i++)
    {
        sum += getNum(input[i]) * pow(base, dotIndex - i);          // xử lý sau dấu chấm
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
    int countAfterDot = 0;
    float dec = this->toDecimal();
    float temp = mod(dec, 1);           // biến tạm giữ phần số thực
    

    string res = "";
    while (dec > 0) {
        res = getChar(mod(dec, base)) + res;
        dec =(int)(dec / base);
    }
    if (input[0] == '-') res = '-' + res;
    if (temp > 0) res += '.';
    while (temp != 0 && countAfterDot <=5) {
        temp = temp * base;
        res += getChar((int)temp);
        temp = mod(temp, 1);
        countAfterDot++;    
    }
    this->base = base;
    this->input = res;
    return res;
}

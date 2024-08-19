#include <iostream>
#include <cmath>
int main ()
{
    char dau;
    int num1;
    int num2;
    int ket_qua;
    std::cout<<"Nhập số 1: ";
    std::cin>>num1;
    std::cout<<"Nhập số 2: ";
    std::cin>>num2;
    std::cout<<"Nhập phép tính (+,-,*,/): ";
    std::cin>>dau;
    switch (dau)
    {
    case '+':
        ket_qua=num1+num2;
        break;
    case '-':
        ket_qua=num1-num2;
        break;
    case '*':
        ket_qua=num1*num2;
        break;
    case '/':
        ket_qua=num1/num2;
        break;
    
    default:
        std::cout<<"Thats not the right symbol :/";
        break;
    }
    std::cout<<"Kết quả của bạn khi "<<num1<<dau<<num2<<" là: "<<ket_qua;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int a,b,result;
    cout<<"Welcome to Virtual calculator \n";
    cout<<"Input Two Numbers \n";
    cin>>a>>b;
    cout<<"Enter + for Addition\nEnter - for Subtraction\nEnter x for Multiplication\nEnter / for Division \n";
    char ch;
    cin>>ch;
    switch(ch)
      {
        case '+':
        result=a+b;
        cout<<"Result is "<<result;
        break;
        case '-':
        result=a-b;
        cout<<"Result is "<<result;
        break;
        case 'x':
        result=a*b;
        cout<<"Result is "<<result;
        break;
        case '/':
        if(b!=0)
        {
          result=a/b;
          cout<<"Result is "<<result;
          break; 
        }
        else
        {
          cout<<"ERROR! Division by zero is not possible";
          break;
        }
        
        default:
        cout<<"Invalid Input";
        break;
      }
    return 0;
}

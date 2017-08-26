#include<iostream>
using namespace std;

int main()
{
    char op;
    int a, b , mod;

    cout << "Ingrese operador: '+' o '-' o '*' o 'i'(inverso): ";
    cin >> op;

    cout << "Ingrese el primer numero: ";
    cin >> a;
	cout << "Ingrese el segundo numero: ";
	cin >> b; 
	cout << "Ingrese el modulo: ";
	cin >> mod;

    switch(op)
    {
        case '+':
            cout << (a+b) % mod;
            break;

        case '-':
            cout << (a-b) % mod ;
            break;

        case '*':
            cout <<(a*b) % mod;
            break;

        case '/':
            cout << "---";
            break;

        default:
            cout << "Error! el operador es incorrecto";
            break;
    }

    return 0;
}

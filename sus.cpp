# include <iostream>
#include <string>
using namespace std;

void pointer(int x, int &y, int *z) {
    x = 11;
    y = 12;
    *z = 13;
}

int main() {

    int a = 3;
    int b = 4;
    int c = 5;
    string d = "mccga yyds";

    // * state that the variable is some kind of pointer (can be pointer of any data type)
    // use & to get the address of the variable
    int *ptr;

    ptr = &a;
    *ptr = 10;
    cout << ptr << endl;

    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "c: " << c << '\n';
    
    return 0;
}
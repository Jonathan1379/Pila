#include <iostream>
#include "listadobleligada.h"
#include "Pila.h"
#include "Cola.h"
using namespace std;

int main()
{
     Pila<int> pila;

    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);

    while (!pila.empty())
    {
        cout << *pila.top() << endl;
        pila.pop();
    }
    return 0;
}

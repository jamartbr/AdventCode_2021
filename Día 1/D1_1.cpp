#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int primero, segundo, suma=0;
    
    ifstream flujo;
    flujo.open("input.txt");
    
    for (int i=0; i<1999; i++) {
        flujo >> segundo;
        if(segundo>primero) {
            suma++;
        }
        primero = segundo;
    }
    
    cout << suma;

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int primero, segundo, suma=0;
    
    cin >> primero;
    
    for (int i=0; i<1999; i++) {
        cin >> segundo;
        if(segundo>primero) {
            suma++;
        }
        primero = segundo;
    }
    
    cout << suma;

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    string cadena, gamma, epsilon;
    
    int vector[12] = {0};
    
    for (int i=0; i<1000; i++) {
        cin >> cadena;
        for (int j=0; j<12; j++) {
            vector[j] += cadena.at(j)-48;
        }
    }
    
    for (int j=0; j<12; j++) {
        if (vector[j]>500) {
            gamma += '1';
            epsilon += '0';
        }
        else {
            gamma += '0';
            epsilon += '1';
        }
    }
    
    cout << gamma << endl << epsilon;

    return 0;
}

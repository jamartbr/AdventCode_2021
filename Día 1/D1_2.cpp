#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3, n4, suma=0;
    
    cin >> n1 >> n2 >> n3;
    
    for (int i=0; i<1999; i++) {
        cin >> n4;
        if(n4>n1) {
            suma++;
        }
        n1 = n2;
        n2 = n3;
        n3 = n4;
    }
    
    cout << suma;

    return 0;
}

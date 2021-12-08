#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string cad;
    
    int cant = 0;
    
    for (int i=0; i<200; i++) {
        getline(cin, cad);
        int pos = 60;
        while (pos<cad.size()) {
            int n = 0;
            while (pos<cad.size() && isalpha(cad.at(pos))) {
                n++;
                pos++;
            }
            pos++;
            if (n==2 || n==3 || n==4 || n==7) {
                cant++;
            }
        }
    }
    
    cout << cant;

    return 0;
}

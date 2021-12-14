#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string cad;
    cin >> cad;
    
    map<string, char> productos;
    
    string aux;
    getline(cin, aux);
    getline(cin, aux);
    for (int i=0; i<100; i++) {
        getline(cin,aux);
        string necesita;
        necesita+=aux.at(0);
        necesita+=aux.at(1);
        char produce = aux.at(aux.size()-1);
        productos.emplace(necesita, produce);
    }
    
    /*auto iter = productos.begin();
    while (iter != productos.end()) {
        cout << "[" << iter->first << ","
                    << iter->second << "]\n";
        ++iter;
    }
    cout << endl;*/
    
    for (int k=0; k<10; k++) {
        for (int i=0; i<cad.size()-1; i+=2) {
            string izq;
            for (int j=0; j<=i; j++) {
                izq+=cad.at(j);
            }
            string necesita;
            necesita+=cad.at(i);
            necesita+=cad.at(i+1);
            izq+=productos[necesita];
            for (int j=i+1; j<cad.size(); j++) {
                izq+=cad.at(j);
            }
            cad = izq;
        }
    }
    
    int max = 0;
    int min = cad.size();
    int veces[26] = {0};
    for (int i=0; i<cad.size(); i++) {
        veces[cad.at(i)-'A']++;
    }
    for (int i=0; i<26; i++) {
        if (veces[i]<min && veces[i]!=0) {
            min = veces[i];
        }
        if (veces[i]>max) {
            max = veces[i];
        }
    }
    
    cout << max-min;

    return 0;
}

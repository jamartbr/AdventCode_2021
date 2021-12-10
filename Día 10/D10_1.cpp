#include <iostream>
#include <string>

using namespace std;

int comprobar (string cad) {
    string chunks;
    int n_chunks = 0;
    
    for (int j=0; j<cad.size(); j++) {
        switch (cad.at(j)) {
        case '(':
            chunks += 'p';
            n_chunks++;
            break;
        case '[':
            chunks += 'c';
            n_chunks++;
            break;
        case '{':
            chunks += 'l';
            n_chunks++;
            break;
        case '<':
            chunks += 'm';
            n_chunks++;
            break;
        case ')':
            {
                if (chunks.at(n_chunks-1)!='p') {
                    return 3;
                }
                string aux1;
                for (int i=0; i<chunks.size()-1; i++) {
                    aux1 += chunks.at(i);
                }
                chunks = aux1;
                n_chunks--;
            }
            break;
        case ']':
            {
                if (chunks.at(n_chunks-1)!='c') {
                    return 57;
                }
                string aux2;
                for (int i=0; i<chunks.size()-1; i++) {
                    aux2 += chunks.at(i);
                }
                chunks = aux2;
                n_chunks--;
            }
            break;
        case '}':
            {
                if (chunks.at(n_chunks-1)!='l') {
                    return 1197;
                }
                string aux3;
                for (int i=0; i<chunks.size()-1; i++) {
                    aux3 += chunks.at(i);
                }
                chunks = aux3;
                n_chunks--;
            }
            break;
        case '>':
            {
                if (chunks.at(n_chunks-1)!='m') {
                    return 25137;
                }
                string aux4;
                for (int i=0; i<chunks.size()-1; i++) {
                    aux4 += chunks.at(i);
                }
                chunks = aux4;
                n_chunks--;
            }
            break;
        }
    }
    return 0;
}

int main()
{
    string cad;
    
    int suma = 0;
    
    for (int i=0; i<106; i++) {
        cin >> cad;
        suma += comprobar(cad);
    }
    
    cout << suma;
    

    return 0;
}

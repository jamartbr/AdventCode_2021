#include <iostream>
#include <string>

using namespace std;

int comprobar (string cad, string & chunks) {
    chunks = "";
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
    
    string aux;
    for(int i=0; i<chunks.size(); i++) {
        aux = chunks.at(i) + aux;
    }
    chunks = aux;
    
    return 0;
}

int main()
{
    string cad;
    
    string chunks;
    
    long long int suma = 0;
    
    long long int vector[106] = {0};
    
    for (int i=0; i<106; i++) {
        suma = 0;
        cin >> cad;
        if (comprobar(cad, chunks) == 0) {
            for (int j=0; j<chunks.size(); j++) {
                switch (chunks.at(j)) {
                case 'p':
                    suma*=5;
                    suma++;
                    break;
                case 'c':
                    suma*=5;
                    suma+=2;
                    break;
                case 'l':
                    suma*=5;
                    suma+=3;
                    break;
                case 'm':
                    suma*=5;
                    suma+=4;
                    break;
                }
            }
        }
        vector[i] = suma;
    }
    
    long long int ordenados[53] = {0};
    ordenados[0] = vector[1];
    int n_ordenados = 1;
    for (int i=2; i<106; i++) {
        bool incluido = false;
        if (vector[i]!=0) {
            for (int j=0; j<n_ordenados; j++) {
                if (vector[i] < ordenados[j]) {
                    for (int k=n_ordenados-1; k>=j; k--) {
                        ordenados[k+1] = ordenados[k];
                    }
                    ordenados[j] = vector[i];
                    incluido = true;
                    j = n_ordenados;
                }
            }
            if (!incluido) {
                ordenados[n_ordenados] = vector[i];
            }
            n_ordenados++;
        }
    }
    
    cout << ordenados[26];
    

    return 0;
}

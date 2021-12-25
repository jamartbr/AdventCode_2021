#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int ALTO = 13, ANCHO = 81;

class Papel {
    
private:
    
    char matriz[ALTO][ANCHO];
    
public:

    Papel () {
        for (int i=0; i<ALTO; i++) {
            for (int j=0; j<ANCHO; j++) {
                matriz[i][j] = '.';
            }
        }
        for (int i=0; i<106; i++) {
            string cad;
            cin >> cad;
            int pos = 0;
            string num1;
            while (isdigit(cad.at(pos))) {
                num1 += cad.at(pos);
                pos++;
            }
            pos++;
            string num2;
            while (pos<cad.size()) {
                num2 += cad.at(pos);
                pos++;
            }
            
            int aux1 = stoi(num1);
            if (aux1>=ANCHO)
                aux1 = 1310-aux1;
                
            int aux2 = stoi(num2);
            if (aux2>=ALTO)
                aux2 = 894-aux2;
            matriz[aux2][aux1] = '#';
        }
    }
    
    void doblarx (int n) {
        for (int j=n; j<ANCHO; j++) {
            for (int i=0; i<ALTO; i++) {
                if (matriz[i][j]=='#') {
                    matriz[i][ANCHO-1-j] = '#';
                }
                matriz[i][j] = ' ';
            }
        }
    }
    
    void doblary (int n) {
        for (int i=n; i<ALTO; i++) {
            for (int j=0; j<ANCHO; j++) {
                if (matriz[i][j]=='#') {
                    matriz[ALTO-1-i][j] = '#';
                }
                matriz[i][j] = ' ';
            }
        }
    }
    
    int contar () {
        int suma = 0;
        for (int i=0; i<ALTO; i++) {
            for (int j=0; j<ANCHO; j++) {
                if (matriz[i][j]=='#') {
                    suma++;
                }
            }
        }
        return suma;
    }
    
    void to_string () {
        for (int i=0; i<ALTO; i++) {
            for (int j=0; j<ANCHO; j++) {
                cout << matriz[i][j];
            }
            cout << endl;
        }
        /*for (int i=0; i<ALTO; i++) {
            for (int j=0; j<ANCHO; j++) {
                if (matriz[i][j]=='#')
                    cout << j << "," << i << endl;
            }
        }
        cout << endl;*/
    }
    
};

int main()
{
    Papel papel;
    
    papel.doblarx(655);
    papel.doblary(447);
    papel.doblarx(327);
    papel.doblary(223);
    papel.doblarx(163);
    papel.doblary(111);
    papel.doblarx(81);
    papel.doblary(55);
    papel.doblarx(40);
    papel.doblary(27);
    papel.doblary(13);
    papel.doblary(6);
    
    cout << papel.contar() << endl;
    papel.to_string();
    

    return 0;
}

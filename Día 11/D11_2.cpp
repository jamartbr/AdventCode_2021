#include <iostream>
#include <string>

using namespace std;

class Mapa {
  
private:
    
    int mapa[10][10];
    bool brilla[10][10];
  
public:
    
    Mapa () {
        for (int i=0; i<10; i++) {
            string cad;
            cin >> cad;
            for (int j=0; j<10; j++) {
                mapa[i][j] = cad.at(j)-48;
                brilla[i][j] = false;
            }
        }
    }
    
    int get (int i, int j) {
        if (i>=0 && i<10 && j>=0 && j<10)
            return mapa[i][j];
        else
            return 0;
    }
    
    void aumentar (int i, int j) {
        if (i>=0 && i<10 && j>=0 && j<10)
            mapa[i][j]++;
    }
    
    int turno () {
        int suma = 0;
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                if (mapa[i][j]!=9)
                    mapa[i][j]++;
                else
                    suma += encender(i,j);
            }
        }
        apagar();
        return suma;
    }
    
    int encender (int i, int j) {
        int suma = 1;
        brilla[i][j] = true;
        mapa[i][j] = 0;
        
        for (int x=i-1; x<=i+1; x++) {
            for (int y=j-1; y<=j+1; y++) {
                aumentar(x,y);
                if (get(x,y)>9) {
                    suma += encender(x,y);
                }
            }
        }
        return suma;
    }
    
    void apagar () {
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                if (brilla[i][j]) {
                    brilla[i][j] = false;
                    mapa[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    Mapa mapa;
    
    int contador = 0;
    
    bool seguir = true;
    while (seguir) {
        contador++;
        if (mapa.turno()==100) {
            cout << contador;
            seguir = false;
        }
    }
    
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Mapa {
    
private:
    
    int mapa[100][100];

public:

    Mapa () {
        for (int i=0; i<100; i++) {
            string cad;
            cin >> cad;
            for (int j=0; j<100; j++) {
                mapa[i][j] = cad.at(j)-48;
            }
        }
    }
    
    void set (int n, int i, int j) {
        mapa[i][j] = n;
    }
    
    int get (int i, int j) {
        if (i>=0 && i<100 && j>=0 && j<100) {
            return mapa[i][j];
        } else {
            return 9;
        }
    }
    
    
    int puntos_bajos () {
        string puntos;
        for (int i=0; i<100; i++) {
            for (int j=0; j<100; j++) {
                if (get(i,j)<get(i-1,j) && get(i,j)<get(i,j-1) && get(i,j)<get(i+1,j) && get(i,j)<get(i,j+1)) {
                    puntos += to_string(get(i,j));
                }
            }
        }
        
        int resultado = 0;
        for (int i=0; i<puntos.size(); i++) {
            resultado += puntos.at(i)-47;
        }
        
        return resultado;
    }

};

int main()
{
    Mapa mapa;
    
    cout << mapa.puntos_bajos();

    return 0;
}

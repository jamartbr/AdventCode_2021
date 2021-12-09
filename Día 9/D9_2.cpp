#include <iostream>
#include <string>

using namespace std;

class Mapa {
    
private:
    
    int mapa[100][100];
        
    bool visto[100][100] = {false};

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
    
    int buscar (int i, int j) {
        visto[i][j] = true;
        
        int n = 1;
        
        bool seguir = false;
        
        do {
            seguir = false;
            
            if (!visto[i][j+1] && get(i,j+1)!=9) {
                seguir = true;
                n += buscar2(i,j+1);
            }
            if (!visto[i+1][j] && get(i+1,j)!=9) {
                seguir = true;
                n += buscar3(i+1,j);
            }
            if (!visto[i][j-1] && get(i,j-1)!=9) {
                seguir = true;
                n += buscar4(i,j-1);
            }
            if (!visto[i-1][j] && get(i-1,j)!=9) {
                seguir = true;
                n += buscar1(i-1,j);
            }
        } while (seguir);
        
        return n;
    }
    
    int buscar1 (int i, int j) {
        visto[i][j] = true;
        
        int n = 1;
        
        bool seguir = false;
        
        do {
            seguir = false;
            
            if (!visto[i][j-1] && get(i,j-1)!=9) {
                seguir = true;
                n += buscar4(i,j-1);
            }
            if (!visto[i-1][j] && get(i-1,j)!=9) {
                seguir = true;
                n += buscar1(i-1,j);
            }
            if (!visto[i][j+1] && get(i,j+1)!=9) {
                seguir = true;
                n += buscar2(i,j+1);
            }
        } while (seguir);
        
        return n;
    }
    
    int buscar2 (int i, int j) {
        visto[i][j] = true;
        
        int n = 1;
        
        bool seguir = false;
        
        do {
            seguir = false;
            
            if (!visto[i-1][j] && get(i-1,j)!=9) {
                seguir = true;
                n += buscar1(i-1,j);
            }
            if (!visto[i][j+1] && get(i,j+1)!=9) {
                seguir = true;
                n += buscar2(i,j+1);
            }
            if (!visto[i+1][j] && get(i+1,j)!=9) {
                seguir = true;
                n += buscar3(i+1,j);
            }
        } while (seguir);
        
        return n;
    }
    
    int buscar3 (int i, int j) {
        visto[i][j] = true;
        
        int n = 1;
        
        bool seguir = false;
        
        do {
            seguir = false;
            
            if (!visto[i][j+1] && get(i,j+1)!=9) {
                seguir = true;
                n += buscar2(i,j+1);
            }
            if (!visto[i+1][j] && get(i+1,j)!=9) {
                seguir = true;
                n += buscar3(i+1,j);
            }
            if (!visto[i][j-1] && get(i,j-1)!=9) {
                seguir = true;
                n += buscar4(i,j-1);
            }
        } while (seguir);
        
        return n;
    }
    
    int buscar4 (int i, int j) {
        visto[i][j] = true;
        
        int n = 1;
        
        bool seguir = false;
        
        do {
            seguir = false;
            
            if (!visto[i-1][j] && get(i-1,j)!=9) {
                seguir = true;
                n += buscar1(i-1,j);
            }
            if (!visto[i][j-1] && get(i,j-1)!=9) {
                seguir = true;
                n += buscar4(i,j-1);
            }
            if (!visto[i+1][j] && get(i+1,j)!=9) {
                seguir = true;
                n += buscar3(i+1,j);
            }
        } while (seguir);
        
        return n;
    }
    
    int cuencas (int vector[]) {
        int n_vector = 0;
        
        for (int i=0; i<100; i++) {
            for (int j=0; j<100; j++) {
                if (mapa[i][j]!=9 && !visto[i][j]) {
                    vector[n_vector] = buscar(i,j);
                    n_vector++;
                }
            }
        }
        
        return n_vector;
    }

};

int main()
{
    Mapa mapa;
    
    int vector[465] = {0};
    
    int n_vector = mapa.cuencas(vector);
    
    int max1=0, max2=0, max3=0;
    for (int i=0; i<n_vector; i++) {
        if (vector[i]>max3) {
            if (vector[i]>max2) {
                if (vector[i]>max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = vector[i];
                } else {
                    max3 = max2;
                    max2 = vector[i];
                }
            } else {
                max3 = vector[i];
            }
        } 
    }
    
    cout << max1*max2*max3;

    return 0;
}

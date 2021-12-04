#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Bingo {
    
private:

    int matriz[5][5];
    
public:
    
    Bingo () {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                cin >> matriz[i][j];
            }
        }
    }
    
    void set (int i, int j, int n) {
        matriz[i][j] = n;
    }
    
    int get (int i, int j) {
        return matriz[i][j];
    }
    
    void borrar (int n) {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (matriz[i][j]==n) {
                    matriz[i][j] = -1;
                }
            }
        }
    }
    
    bool ComprobarBingo () {
        return (ComprobarCols() || ComprobarFilas());
    }
    
    bool ComprobarCols () {
        for (int j=0; j<5; j++) {
            bool bingo = true;
            for (int i=0; i<5; i++) {
                if (matriz[i][j]!=-1)
                    bingo = false;
            }
            if (bingo==true) {
                return true;
            }
        }
        return false;
    }
    
    bool ComprobarFilas () {
        for (int i=0; i<5; i++) {
            bool bingo = true;
            for (int j=0; j<5; j++) {
                if (matriz[i][j]!=-1)
                    bingo = false;
            }
            if (bingo==true) {
                return true;
            }
        }
        return false;
    }
    
    int sumar () {
        int suma = 0;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (matriz[i][j]!=-1) {
                    suma += matriz[i][j];
                }
            }
        }
        return suma;
    }
    
    void to_string () {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    string cadena;
    cin >> cadena;
    
    Bingo cartones[100];
    
    int pos=0;
    int n_ganador;
    int n_final;
    bool bingo = false;
    while (!bingo) {
        string numero;
        while (isdigit(cadena.at(pos))) {
            numero+=cadena.at(pos);
            pos++;
        }
        pos++;
        for (int i=0; i<100; i++) {
            cartones[i].borrar(stoi(numero));
        }
        
        for (int i=0; i<100; i++) {
            if (cartones[i].ComprobarBingo()) {
                bingo = true;
                n_ganador = i;
                n_final = stoi(numero);
            }
        }
    }
    
    int suma = cartones[n_ganador].sumar();
    
    cout << suma*n_final;
    
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Mapa {
    
private:

    int mapa[999][999];

public:

    Mapa () {
        for (int i=0; i<999; i++) {
            for (int j=0; j<999; j++) {
                mapa[i][j] = 0;
            }
        }
    }
    
    void Marcar (int i, int j) {
        mapa[i][j]++;
    }
    
    int Cumulos () {
        int suma = 0;
        for (int i=0; i<999; i++) {
            for (int j=0; j<999; j++) {
                if (mapa[i][j]>1) {
                    suma++;
                }
            }
        }
        return suma;
    }
    
    void to_string () {
        for (int i=0; i<999; i++) {
            for (int j=0; j<999; j++) {
                if (mapa[i][j]==0) {
                    cout << ". ";
                } else {
                    cout << mapa[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
    
};

int main()
{
    
    Mapa mapa;
    
    string cadena;
    
    
    for (int k=0; k<500; k++) {
        getline(cin, cadena);
        
        int pos = 0;
        string x1, x2, y1, y2;
        while (isdigit(cadena.at(pos))) {
            x1 +=  cadena.at(pos);
            pos++;
        }
        pos++;
        while (isdigit(cadena.at(pos))) {
            y1 +=  cadena.at(pos);
            pos++;
        }
        pos+=4;
        while (isdigit(cadena.at(pos))) {
            x2 +=  cadena.at(pos);
            pos++;
        }
        pos++;
        while (pos < cadena.size()) {
            y2 +=  cadena.at(pos);
            pos++;
        }
        
        int nx1=stoi(x1), nx2=stoi(x2), ny1=stoi(y1), ny2=stoi(y2);
        
        if (nx1==nx2) {
            if (ny1<ny2) {
                for (int i=ny1; i<=ny2; i++) {
                    mapa.Marcar(nx1, i);
                }
            } else {
                for (int i=ny2; i<=ny1; i++) {
                    mapa.Marcar(nx1, i);
                }
            }
        } else if (ny1==ny2) {
            if (nx1<nx2) {
                for (int i=nx1; i<=nx2; i++) {
                    mapa.Marcar(i, ny1);
                }
            } else {
                for (int i=nx2; i<=nx1; i++) {
                    mapa.Marcar(i, ny1);
                }
            }
        } else {
            if (nx1<nx2) {
                if (ny1<ny2) {
                    for (int i=nx1; i<=nx2; i++) {
                        for (int j=ny1; j<=ny2; j++) {
                            if (i-nx1==j-ny1) {
                                mapa.Marcar(i, j);
                            }
                        }
                    }
                } else {
                    for (int i=nx1; i<=nx2; i++) {
                        for (int j=ny1; j>=ny2; j--) {
                            if (i-nx1==ny1-j) {
                                mapa.Marcar(i, j);
                            }
                        }
                    }
                }
            } else {
                if (ny1<ny2) {
                    for (int i=nx1; i>=nx2; i--) {
                        for (int j=ny1; j<=ny2; j++) {
                            if (nx1-i==j-ny1) {
                                mapa.Marcar(i, j);
                            }
                        }
                    }
                } else {
                    for (int i=nx1; i>=nx2; i--) {
                        for (int j=ny1; j>=ny2; j--) {
                            if (nx1-i==ny1-j) {
                                mapa.Marcar(i, j);
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << mapa.Cumulos() << endl;
    mapa.to_string();

    return 0;
}

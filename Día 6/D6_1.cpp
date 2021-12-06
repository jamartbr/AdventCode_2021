#include <iostream>
#include <string>

using namespace std;

class Banco {
    
private:

    int *peces = new int [0];
    int n_peces;
    
public:
    
    Banco () {
        peces = nullptr;
        n_peces = 0;
    }
    
    void redimensionar (int n) {
        if (peces!=nullptr) {
            int *aux = new int [n];
            for (int i=0; i<n; i++) {
                aux[i] = peces[i];
            }
            delete[] peces;
            peces = aux;
            n_peces = n;
        } else {
            peces = new int [n];
            n_peces = n;
        }
    }
    
    void set (int n, int cant) {
        peces[n] = cant;
    }
    
    int get (int n) {
        return peces[n];
    }
    
    int size () {
        return n_peces;
    }
    
    void insert (int n) {
        redimensionar(n_peces+1);
        peces[n_peces-1] = n;
    }
    
    void add () {
        insert(9);
    }
    
    void dia () {
        for (int i=0; i<n_peces; i++) {
            if (peces[i]!=0) {
                peces[i]--;
            } else {
                peces[i] = 6;
                add();
            }
        }
    }
    
    void to_string () {
        for (int i=0; i<n_peces; i++) {
            cout << peces[i] << ",";
        }
        cout << endl;
    }
    
};

int main()
{
    int suma = 0;
    
    string cadena;
    cin >> cadena;
    for (int i=0; i<cadena.size(); i+=2) {
        Banco banco;
        int n = cadena.at(i)-48;
        banco.insert(n);
    
        for (int j=0; j<80; j++) {
            banco.dia();
        }
        
        suma += banco.size();
    }
    
    cout << suma;

    return 0;
}

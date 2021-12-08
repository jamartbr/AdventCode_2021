#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Codigo {
    
private:
    
    string codigo[10];
    
public:
    
    Codigo () {
    }
    
    void decodificar(string cad) {
        string vector[6];
        int n_vector = 0;
        
        int pos = 0;
        while (pos<58) {
            string num;
            while (pos<58 && isalpha(cad.at(pos))) {
                num += cad.at(pos);
                pos++;
            }
            pos++;
            if (num.size()==2) {
                codigo[1] = num;
            } else if (num.size()==3) {
                codigo[7] = num;
            } else if (num.size()==4) {
                codigo[4] = num;
            } else if (num.size()==7) {
                codigo[8] = num;
            } else {
                vector[n_vector] = num;
                n_vector++;
            }
        }
        
        while (n_vector>0) {
            for (int i=0; i<6; i++) {
                if (vector[i].size()==5) {
                    if (contiene_numero(vector[i], codigo[7])) {
                        codigo[3] = vector[i];
                        vector[i]="k";
                        n_vector--;
                    } else if (n_vector<5 && contiene_segmento(vector[i],restar(8,9))) {
                        codigo[2] = vector[i];
                        vector[i]="k";
                        n_vector--;
                    } else if (n_vector<5) {
                        codigo[5] = vector[i];
                        vector[i]="k";
                        n_vector--;
                    }
                } else if (contiene_numero(vector[i], codigo[4])) {
                    codigo[9] = vector[i];
                    vector[i]="k";
                    n_vector--;
                } else if (n_vector<3) {
                    if (contiene_numero(vector[i], codigo[5])) {
                        codigo[6] = vector[i];
                        vector[i]="k";
                        n_vector--;
                    } else if (n_vector==1 && vector[i]!="k"){
                        codigo[0] = vector[i];
                        vector[i]="k";
                        n_vector--;
                    } 
                }
            }
        }
    }
    
    bool contiene_numero (string cad, string n) {
        if (n==""){
            return false;
        }
        
        string numero = n;
        for (int i=0; i<numero.size(); i++) {
            for (int j=0; j<cad.size(); j++) {
                if (cad.at(j)==numero.at(i)) {
                    numero.at(i) = ' ';
                }
            }
            if (numero.at(i)!=' ') {
                return false;
            }
        }
        return true;
    }
    
    bool contiene_segmento (string cad, char seg) {
        for (int i=0; i<cad.size(); i++) {
            if (cad.at(i)==seg) {
                return true;
            }
        }
        return false;
    }
    
    char restar (int num1, int num2) {
        string n1 = codigo[num1];
        string n2 = codigo[num2];
        for (int i=0; i<n1.size(); i++) {
            for (int j=0; j<n2.size(); j++) {
                if (n1.at(i)==n2.at(j)) {
                    n1.at(i) = ' ';
                }
            }
            if (n1.at(i)!=' ') {
                return n1.at(i);
            }
        }
    }
    
    void to_string() {
        for (int i=0; i<10; i++) {
            cout << "Número " << i << ": " << codigo[i] << endl;
        }
    }
    
    char calcular (string cad) {
        char c = '0';
        for (int i=0; i<10; i++) {
            if (contiene_numero(cad,codigo[i]) && contiene_numero(codigo[i],cad)) {
                c += i;
            }
        }
        return c;
    }
    
};

int main()
{
    string cad, numero;
    
    int solucion = 0;
    
    for (int i=0; i<200; i++) {
        numero ="";
        
        getline(cin, cad);
        Codigo codigo;
        codigo.decodificar(cad);
        
        int pos = 61;
        while (pos<cad.size()) {
            string num;
            while (pos<cad.size() && isalpha(cad.at(pos))) {
                num += cad.at(pos);
                pos++;
            }
            pos++;
            numero += codigo.calcular(num);
        }
        solucion += stoi(numero);
    }
    
    
    cout << solucion;
    

    return 0;
}

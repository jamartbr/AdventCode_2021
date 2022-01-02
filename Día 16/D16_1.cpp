#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string toBin (string hex) {
    string bin;
    for (int i=0; i<hex.size(); i++) {
        switch (hex.at(i)) {
        case '0':
            bin+="0000";
            break;
        case '1':
            bin+="0001";
            break;
        case '2':
            bin+="0010";
            break;
        case '3':
            bin+="0011";
            break;
        case '4':
            bin+="0100";
            break;
        case '5':
            bin+="0101";
            break;
        case '6':
            bin+="0110";
            break;
        case '7':
            bin+="0111";
            break;
        case '8':
            bin+="1000";
            break;
        case '9':
            bin+="1001";
            break;
        case 'A':
            bin+="1010";
            break;
        case 'B':
            bin+="1011";
            break;
        case 'C':
            bin+="1100";
            break;
        case 'D':
            bin+="1101";
            break;
        case 'E':
            bin+="1110";
            break;
        case 'F':
            bin+="1111";
            break;
        }
    }
    return bin;
}

int toDec (string bin) {
    int dec = 0, potencia = 0;
    for (int i=bin.size()-1; i>=0; i--) {
        dec += (bin.at(i)-'0') * pow(2,potencia);
        potencia++;
    }
    return dec;
}

int comprimir(vector<string> &paquetes) {
    string resultado;
    for (int i=0; i<paquetes.size(); i++) {
        resultado += paquetes.at(i);
    }
    paquetes.clear();
    return toDec(resultado);
}

int analizar(vector<int> &numeros, string bin, int &suma) {
    int pos = 0;
    while (bin.size()-pos>=11) {
        string version;
        for (int i=0; i<3; i++) {
            version+=bin.at(pos+i);
        }
        pos+=3;
        suma+=toDec(version);
        string type;
        for (int i=0; i<3; i++) {
            type+=bin.at(pos+i);
        }
        pos+=3;
        if (type=="100") {
            vector<string> subpaquetes;
            while (bin.at(pos)=='1') {
                string paquete;
                for (int i=1; i<5; i++) {
                    paquete+=bin.at(pos+i);
                }
                pos+=5;
                subpaquetes.push_back(paquete);
            }
            string paquete;
            for (int i=1; i<5; i++) {
                paquete+=bin.at(pos+i);
            }
            pos+=5;
            subpaquetes.push_back(paquete);
            numeros.push_back(comprimir(subpaquetes));
        } else {
            string binred;
            pos++;
            if (bin.at(pos-1)=='0') {
                string size;
                for (int i=0; i<15; i++) {
                    size+=bin.at(pos+i);
                }
                pos+=15;
                for (int i=0; i<toDec(size); i++) {
                    binred+=bin.at(pos+i);
                }
                int num = numeros.size();
                pos+=analizar(numeros, binred, suma);
            } else {
                string n_subp;
                for (int i=0; i<11; i++) {
                    n_subp+=bin.at(pos+i);
                }
                pos+=11;
                for (int i=0; i<toDec(n_subp); i++) {
                    string aux;
                    for (int j=pos; j<bin.size(); j++) {
                        aux+=bin.at(j);
                    }
                    pos+=analizar(numeros, aux, suma);
                }
            }
        }
    }
    return pos;
}

int main()
{
    vector<int> numeros;
    
    string cad, bin;
    cin >> cad;
    
    bin = toBin(cad);
    
    int suma = 0;
    analizar(numeros, bin, suma);
    cout << suma;

    return 0;
}

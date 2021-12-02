#include <iostream>

using namespace std;

int main()
{
    int x=0, depth=0;
    
    string cadena;
    
    for (int i=0; i<1000; i++) {
	    getline(cin, cadena);
	    if (cadena.at(0)=='f') {
	        x+=cadena.at(8)-48;
	    }
	    if (cadena.at(0)=='d') {
	        depth+=cadena.at(5)-48;
	    }
	    if (cadena.at(0)=='u') {
	        depth-=cadena.at(3)-48;
	    }
	}
	
	cout << x*depth;

    return 0;
}

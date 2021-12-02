#include <iostream>

using namespace std;

int main()
{
    int x=0, depth=0, aim=0;
    
    string cadena;
    
    for (int i=0; i<1000; i++) {
	    getline(cin, cadena);
	    if (cadena.at(0)=='f') {
	        x+=cadena.at(8)-48;
	        depth+=(cadena.at(8)-48)*aim;
	    }
	    if (cadena.at(0)=='d') {
	        aim+=cadena.at(5)-48;
	    }
	    if (cadena.at(0)=='u') {
	        aim-=cadena.at(3)-48;
	    }
	}
	
	cout << x*depth;

    return 0;
}

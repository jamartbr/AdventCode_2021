#include <iostream>

using namespace std;

int main()
{
    
    const int MAX_X = 292, MIN_X = 240, MAX_Y = -57, MIN_Y = -90;
    
    int suma = 0;
    
    for (int x=22; x<293; x++) {
        for (int y=-90; y<100; y++) {
            int pos_x = 0;
            int impulso_x = x;
            int pos_y = 0;
            int impulso_y = y;
            while (pos_y>=MIN_Y) {
                pos_x+=impulso_x;
                if (impulso_x>0)
                    impulso_x--;
                pos_y+=impulso_y;
                impulso_y--;
                if (MIN_X<=pos_x && pos_x<=MAX_X && MIN_Y<=pos_y && pos_y<=MAX_Y) {
                    cout << x << ", " << y << endl;
                    pos_y=MIN_Y-1;
                    suma++;
                }
            }
        }
    }
    
    cout << suma;

    return 0;
}

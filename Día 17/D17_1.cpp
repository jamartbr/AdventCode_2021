#include <iostream>

using namespace std;

int main()
{
    
    const int MAX_X = 292, MIN_X = 240, MAX_Y = -57, MIN_Y = -90;
    
    int alturamax = 0;
    
    for (int x=22; x<24; x++) {
        int pos_x = 0;
        int impulso_x = x;
        for (int y=0; y<1000; y++) {
            int pos_y = 0;
            int impulso_y = y;
            int max = alturamax;
            while (pos_y>MAX_Y) {
                pos_x+=impulso_x;
                if (impulso_x>0)
                    impulso_x--;
                pos_y+=impulso_y;
                impulso_y--;
                if (pos_y>max) {
                    max = pos_y;
                }
            }
            if (pos_y>=MIN_Y) {
                cout << x << ", " << y << endl;
                alturamax = max;
            }
        }
    }
    
    cout << alturamax;

    return 0;
}

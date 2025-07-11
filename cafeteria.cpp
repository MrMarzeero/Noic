#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d; 
    cin >> a >> b >> c >> d;
    int volCafe = 0;
    bool possivel = false;

    while(volCafe <= c) {
        int volLeite = c - volCafe;
        if(volLeite >= a && volLeite <= b) {
            possivel = true;
            break;
        }

        volCafe += d;
    }      

    cout << (possivel ? "S\n" : "N\n");
    return 0;
}

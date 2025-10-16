//NOIC - Tutorial
#include <bits/stdc++.h>
using namespace std;
 
const int inf = 1e9; 
const int maxn = 200010;
int a[maxn], L[maxn], R[maxn];

int main() {
    int n; cin >> n;

    a[0] = inf;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    //calcula maior valor de possível aI baseado no último cara != -1 à esquerda
    int last = 0;
    for (int i = 1; i <= n; i++) {       
        if(a[i] == -1) L[i] = a[last] + (i - last); 
        else last = i;
    }

    //calcula maior valor de possível aI baseado no último cara != -1 à direita
    last = 0;
    for (int i = n; i >= 1; i--) {
        if(a[i] == -1) R[i] = a[last] + (last - i);
        else last = i;
    }

    for (int i = 1; i <= n; i++) { 
        if(a[i] == -1) a[i] = min(L[i], R[i]);

        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}

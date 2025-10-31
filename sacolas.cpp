// NOIC - Tutorial
// Otávio Pinheiro
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, S; cin >> n >> S;

    int cnt = 1, peso = 0;
    for (int i = 0; i < n; i++) {
        int atual; cin >> atual;
      //se o peso do produto atual não pode na sacola, pegamos outra e colocamos esse produto
        if(peso + atual > S) {
            cnt++;
            peso = atual;
        } else peso += atual;
    }   

    cout << cnt << '\n';
    return 0;
}

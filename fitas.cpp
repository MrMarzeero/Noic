// NOIC - Tutorial
// Otávio Pinheiro
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e3 + 10;
const int maxcomp = 1e6 + 100;

int n, m, act = 1;
char g[maxn][maxn];
int comp[maxn][maxn]; 
int green[maxcomp], yellow[maxcomp];

int dX[] = {0, 1, 0, -1};
int dY[] = {1, 0, -1, 0};

void dfs(int x, int y) {
    comp[x][y] = act;
    for (int i = 0; i < 4; i++) {
        int pX = x + dX[i], pY = y + dY[i];
        if(pX >= 1 && pX <= n && pY >= 1 && pY <= m)
            if(!comp[pX][pY] && g[pX][pY] == '#')
                dfs(pX, pY);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    //pinta os componentes do grafo
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { 
            if(!comp[i][j] && g[i][j] == '#') { 
                dfs(i, j);
                act++;
            }
        }
    }

    //calcula qtd de fitas se pintar componente de verde
    for (int i = 1; i <= n + 1; i++) {
        int last = 0;
        for (int j = 1; j <= m + 1; j++) {
            if(g[i][j] != '#') green[last]++;
            last = comp[i][j];
        }
    }

    //qtd de fitas se pintar componente de amarelo
    for (int i = 1; i <= m + 1; i++) {
        int last = 0;
        for (int j = 1; j <= n + 1; j++) {
            if(g[j][i] != '#') yellow[last]++;
            last = comp[j][i];
        }
    }

    //para cada componente, calcula se pinta de verde ou de amarelo
    for (int i = 1; i < act; i++)
        res += min(green[i], yellow[i]);
    cout << res << '\n';
    return 0;
}

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

int dX[] = {0, 0, 1, -1};
int dY[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    comp[x][y] = act;
    if (y == m || g[x][y+1] != '#') green[act]++;
    if (x == n || g[x+1][y] != '#') yellow[act]++;
    for (int i = 0; i < 4; i++) {
        int pX = x + dX[i], pY = y + dY[i];
        if(pX >= 1 && pX <= n && pY >= 1 && pY <= m) {
            if(!comp[pX][pY] && g[pX][pY] == '#') {
                dfs(pX, pY);
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    //pinta os componentes do grafo
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { 
            if(!comp[i][j] && g[i][j] == '#') { 
                dfs(i, j);
                act++;
            }
        }
    }

    //para cada componente, calcula se pinta de verde ou de amarelo
    int res = 0;
    for (int i = 1; i < act; i++)
        res += min(green[i], yellow[i]);

    cout << res << '\n';
    return 0;
}

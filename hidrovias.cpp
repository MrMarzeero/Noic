//NOIC - Tutorial
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

const int maxn = 1e5 + 10;

vector<pii> rod;

//Union-Find
int parent[maxn], sz[maxn];

int find(int x) {
    if(parent[x] == x) 
        return x;
    return parent[x] = find(parent[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;

    if(sz[x] >= sz[y]) {
        sz[x] += sz[y];
        parent[y] = x;
    } else {
        sz[y] += sz[x];
        parent[x] = y;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    
    bool res = true;
    for (int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;
        if(t == 1) {
            if(find(a) == find(b)) res = false;
            join(a, b);
        } else rod.push_back({a, b});
    }

    int build = 0;
    for (auto [a, b] : rod) {
        if(find(a) == find(b)) continue;
        join(a, b); build++;
    }

    if(build < (int)rod.size() - k) res = false;

    cout << (res ? "S\n" : "N\n");
    return 0;
}

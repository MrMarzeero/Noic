//NOIC - Tutorial
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

const int maxn = 1e5 + 10;
vector<pii> hid(maxn), rod(maxn);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;
        if(t == 1) hid.push_back({a, b});
        else rod.push_back({a, b});
    }

        


    return 0;
}

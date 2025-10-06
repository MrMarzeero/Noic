//NOIC - Tutorial
#include <bits/stdc++.h>
using namespace std;

#define int long long

//calcula soma [a, b]: a + (a + 1) + ... + b
int sum(int a, int b) {
    return (b + a)*(b - a + 1) / 2;
}

void solve() {
    int l, a, b; cin >> l >> a >> b;

    //binary search encontra maior x <= b tal que:
    // a + (a + 1) + ... + x < l
        int lo = a, hi = b, res = 1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(sum(a, mid) < l) {
            res = (mid - a + 1) + 1;
            lo = mid + 1;
        } else hi = mid - 1;
    }

    if(res > b - a + 1) res--;
    cout << res << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    while(q--)
        solve();

    return 0;
}

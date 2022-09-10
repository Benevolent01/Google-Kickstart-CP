#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
#define REP(x, y)  for(long long (x) = 0; (x) < (y); ++(x))
#define REP2(x, y) for(long long (x) = 1; (x) <= (y); ++(x))
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#define in(input) freopen(input, "r", stdin)
#define out(output) freopen(output, "w", stdout)
#undef int
#define int ll

void solve() {
    bitset<10> num;
    for(int i = 0; i < 10; i++) {
        int a; cin >> a; num[i] = a;
    }
    int n; cin >> n;
    vector<int> dp(n + 1, 1e9);
    for(int i = 1; i <= n; i++) {
        string s = to_string(i);
        bool ok = 1;
        for(char c : s)
            if(!num[c - '0']) ok = 0;
        if(ok) dp[i] = s.size();
        for(int j = 1; j <= i && i * j <= n; j++)
            dp[i * j] = min(dp[i * j], dp[i] + dp[j] + 1);
    }
    printf((dp[n] < 1e9) ? ("%lld\n") : "Impossible\n", dp[n] + 1);
}

#undef int
int main() {
    in("input.txt");
    out("output.txt");
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}



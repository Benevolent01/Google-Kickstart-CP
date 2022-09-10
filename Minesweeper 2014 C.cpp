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

int dx[8] = {-1, 1, -1, 0, 1, -1, 0, 1};
int dy[8] = {0, 0, -1, -1,-1, 1, 1,1};

int a[305][305], cnt = 0, n;
bool visited[305][305];

void floodfill(int i, int j) {
    if(i < 0 || j < 0 || i >= n || j >= n) 
        return;
    if(!visited[i][j] && a[i][j] == 9) { 
        visited[i][j] = 1;
        a[i][j] = 4;
	//Remember to floodfill all 8 directions and not just 4
        for(int k = 0; k < 8; k++) {
            floodfill(i + dx[k], j + dy[k]);
        }
    }
    return;
}

bool check(int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < n);
}

void solve() {
    cin >> n;
    vector<string> s;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        s.pb(t);
    }
    memset(a, 0, sizeof a);
    memset(visited, 0, sizeof visited);
    cnt = 0;
    //Mark the mines (5)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == '*') a[i][j] = 5;
        }
    }
    //Mark the non-neighbouring with mines cells with 9 (9)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == '.') {
                bool ok = 1;
                for(int k = 0; k < 8; k++) {
                    if(check(i + dx[k], j + dy[k])) {
                        if(s[i + dx[k]][j + dy[k]] == '*') {
                            ok = 0;
                            break;
                        }
                    }
                }
                if(ok) a[i][j] = 9;
            }
        }
    }
    //Floodfill! To all directions, not just the 4 (that was my mistake) and count
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 9) {
                floodfill(i, j);
                cnt++;
            }
        }
    }
    //Fill the neighbouring with the nines cells with 8 (or really whatever)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 4) {
                for(int k = 0; k < 8; k++) {
                    if(check(i + dx[k], j + dy[k])) {
                        if(a[i + dx[k]][j + dy[k]] == 0)
                            a[i + dx[k]][j + dy[k]] = 8;
                    }
                }
            }
        }
    }
    //In the end add what's left 0 (the 0s that need to be clicked separately)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 0)
                cnt++;
        }
    }
    cout << cnt << endl;
}


#undef int
int main() {
//    in("input.txt");
//    out("output.txt");
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}



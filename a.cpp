#include <bits/stdc++.h>
using namespace std;
#define int long long

int const N = 1e5+10, M = 1e8+7;
int n, ans, p[N], cnt[N];
string s, t;

int32_t main () {
    ios::sync_with_stdio(false), cin.tie(0);

    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = p[i-1] * 10 % M;
    }

    cin >> t >> s;
    n = s.size();

    for (int i = n-1 ; i > 0; i--) {
        cnt[i-1] = cnt[i] + (s[i] == '?');
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            ans = ( ans + (t[i]-'0') * p[ cnt[i] ] ) % M;
        } else if (s[i] > t[i]) {
            break;   
        } else if (s[i] < t[i]) {
            ans = ( ans + p[ cnt[i] ] ) % M;
            break;
        }
    }

    cout << ans << endl;
}
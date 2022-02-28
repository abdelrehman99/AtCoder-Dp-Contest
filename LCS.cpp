#include <bits/stdc++.h>
using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define F first
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
#define cin(v, n)                    \
    for (int i = 0; i < (int)n; i++) \
        cin >> v[i];
#define cout(v, n)                   \
    for (int i = 0; i < (int)n; i++) \
        cout << v[i] << (i == n - 1 ? "\n" : " ");
#define WL(t) while (t--)
#define S second
#define PB push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define runtime() cerr << ((double)clock() / CLOCKS_PER_SEC) << endl;
#define MP make_pair
#define llu unsigned long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll mod = 1e9 + 7, N = 2e6 + 7, M = 2e6 + 7, INF = INT_MAX / 10;
ll powe(ll x, ll y)
{
    x = x % mod, y = y % (mod - 1);
    ll ans = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            ans = (1ll * x * ans) % mod;
        }
        y >>= 1;
        x = (1ll * x * x) % mod;
    }
    return ans;
}

ll n, w;
string s, t, res = "";
vvl dp;

ll rec(ll idx, ll jdx)
{
    if (idx == s.size() || jdx == t.size()) return 0;
    ll h, h2;
    if (dp[idx][jdx] != -1)
        return dp[idx][jdx];
    if (s[idx] == t[jdx])
    {
        return dp[idx][jdx] = 1 + rec(idx + 1, jdx + 1);
        //if (k.size() < h.size()) k = h;
        //return dp[idx][jdx] = k;
    } 
    h = rec(idx + 1, jdx);
    h2 = rec(idx, jdx + 1);
    //cout << idx << " " << jdx << " " << k << endl;
    return dp[idx][jdx] = max(h, h2);
}

void build(ll idx, ll jdx)
{
    if (idx == s.size() || jdx == t.size())
        return;
    ll h = INT_MIN, h2 = INT_MIN;
    if (s[idx] == t[jdx])
    {
        res.PB(s[idx]), build(idx + 1, jdx + 1);
        return;
    }
    h = rec(idx + 1, jdx);
    h2 = rec(idx, jdx + 1);
    //cout << h << " " << h2 << endl;
    if (h > h2)
    {
        build(idx + 1, jdx);
    }
    else build(idx, jdx + 1);
    // cout << idx << " " << jdx << " " << k << endl;
}
 
void solve()
{
    cin >> s >> t;
    n = max(s.size(), t.size());
    dp.assign(n + 10, vl (n + 10, -1));
    rec(0, 0);
    build(0, 0);
    cout << res << endl;
    //cout << *(st.rend() + 1);
}

signed main()
{
    fast;
    //int t = 1;
    // cin >> t;
    //WL(t)
    {
        solve();
    }
    runtime();
    return 0;
}

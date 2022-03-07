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

ll n, m, res = -1;
vvl adj;
vl vis, dp; 

ll dfs(ll i)
{
    if (vis[i]) return dp[i];
    vis[i] = 1;
    dp[i] = 0;
    //ll mx = 0;
    //cout << i << endl;
    for (auto &j : adj[i])
    {
        //cout << j << " ";
        dp[i] = max(1 + dfs(j), dp[i]);
    }
    //cout << endl;
    //cout << i << " " << mx << " " << d << endl;
    //dp[i] = mx - d;
    //cout << i << " " << mx << " " << d << " " << dp[i] << endl;
    return dp[i];
}

void solve()
{
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, false);
    dp.resize(n + 1);
    FOR (i, m)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].PB(y);
    }
    /* for (ll i = 1; i <= n; i++)
    {
        for (auto &j : adj[i])
        {
            cout << j << " ";
            //dp[i] = max(dfs(j, d + 1), dp[i]);
        }
        cout << endl;
    } */
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i]) dfs(i);
    }
    ll c = 1;
    for (ll i = 1; i <= n; i++) c = max(c, dp[i]);
    /* for (ll i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << endl; */
    cout << c << endl;
}

signed main()
{
    fast;
    int t = 1;
    //cin >> t;
    WL(t)
    {
        solve();
    }
    runtime();
    return 0;
}

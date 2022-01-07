//--> Karan's Code <--
#define _USE_MATH_DEFINES
#include <cmath>
#include<bits/stdc++.h>

/*
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
*/

#define loop(i,a,b) for (auto i = a; i < b; i++)
#define loopb(i,a,b) for (auto i = a; i <= b; i++)
#define bloop(i,a,b) for (auto i = a ; i >= b;i--)
#define pb push_back
#define eb emplace_back
#define mkp(a,b) make_pair(a,b)   //mp for map
#define lgt(x) (int)x.length()
#define Sz(x) (int)x.size()
#define ff first
#define ss second
#define nl cout<<endl
#define all(x) x.begin(),x.end()
#define ncr(n,r) fact[n]*modInv(fact[r])*modInv(fact[n-r])
#define tr(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
#define mk_tree(k) loop(i,0,k){int x,y; cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define bits(x)  (std::string(std::bitset<8>(x).to_string<char,std::string::traits_type, std::string::allocator_type>() ).c_str())
using namespace std;
/*
//For ordered_set
using namespace __gnu_pbds;
#define os_find(k) find_by_order(k)
#define os_order(k) order_of_key(k)
*/
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int, int> mpii;
typedef map<ll, ll> mpll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
/*
//For ordered_set
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
*/
const double pi = M_PI;
//const int mod=1e9+7;
int N = 2e5 + 100;

//----------------OPTIMIZED FUNCTIONS----------------//

ll power(ll a, ll b, ll mod = LLONG_MAX)
{
    if (b == 0 || a == 1)  return 1;
    if (a == 0) return 0;
    ll po = power(a, b / 2, mod) % mod;
    if (b & 1)  return (((po * po) % mod) * a) % mod;
    else    return (po * po) % mod;

}

ll fact(ll n, ll mod = LLONG_MAX) {            //overflow for n>20
    return (n == 1 || n == 0) ? 1 : (n * fact(n - 1) % mod) % mod;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

//--------------------MAIN CODE--------------------//

ll dp[200005];

ll solve(vector<pair<ll, pll>> &v, ll ind, ll N) {
    if (ind >= N) return 0;
    if (dp[ind] != -1) return dp[ind];
    ll newstart = v[ind].ss.ff;
    pair<ll, pll> p = {newstart + 1, {0, 0}};
    ll newind = upper_bound(v.begin(), v.end(), p) - v.begin();
    return dp[ind] = max(solve(v, newind, N) + v[ind].ss.ss, solve(v, ind + 1, N));
}

int main()
{
    fio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t = 1;
    //cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        vector<pair<ll, pll>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].ff >> v[i].ss.ff >> v[i].ss.ss;
        }
        // for (auto x : v) {
        //     cout << x.ff << " " << x.ss.ff << " " << x.ss.ss; nl;
        // }
        sort(v.begin(), v.end());
        ll ans = solve(v, 0, n);
        cout << ans; nl;
    }
}
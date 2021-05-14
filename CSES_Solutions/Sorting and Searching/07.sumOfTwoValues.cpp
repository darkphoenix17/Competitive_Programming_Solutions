//--> Karan's Code <--
#define _USE_MATH_DEFINES
#include <cmath>
#include<bits/stdc++.h>

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

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int, int> mpii;
typedef map<ll, ll> mpll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


const double pi = M_PI;
//const int mod=1e9+7;
int N = 2e5 + 100;

/*

set <int> adj[N];
bool vis[N];
vector<int> ord;
//int val[N];
//int dis[N];
//int low[N];
int ans=0;
*/
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
/*

void dfs(int s,int par) {
    vis[s]=1;
    if(condition) {

    }
    for(auto x:adj[s]){
        if(vis[x]==0){
            dfs(x,s);
        }
    }
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

*/

int main()
{
    fio;
    ll t = 1;
    //cin>>t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        pll p[n];
        loop(i, 0, n) {
            cin >> p[i].ff;
            p[i].ss = i + 1;
        }
        sort(p, p + n);
        mpll mp;
        ll mark1, mark2, f = 0, no;
        loop(i, 0, n) {
            if (p[i].ff <= x / 2) mp[p[i].ff]++;
            if (p[i].ff > x / 2) {
                if (mp[x - p[i].ff] != 0) {
                    no = x - p[i].ff;
                    f = 1;
                    mark2 = p[i].ss;
                    break;
                }
            }
        }
        if (f == 1) {
            loop(i, 0, n) {
                if (no == p[i].ff && p[i].ss != p[mark2 - 1].ss) {
                    mark1 = p[i].ss;
                    break;
                }
            }
            cout << mark1 << " " << mark2 << "\n";
        } else {
            if (x % 2 == 0) {
                vl v;
                loop(i, 0, n) {
                    if (p[i].ff == x / 2) v.pb(p[i].ss);
                }
                if (Sz(v) >= 2) cout << v[0] << " " << v[1];
                else cout << "IMPOSSIBLE";
            } else cout << "IMPOSSIBLE";
        }
    }
}

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
#define Sz(x) ((int)x.size())
#define ff first
#define ss second
#define nl cout<<endl
#define ncr(n,r) fact[n]*modInv(fact[r])*modInv(fact[n-r])
#define tr(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
#define mk_tree(k) loop(i,0,k){int x,y; cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define bits(x)  (std::string(std::bitset<8>(x).to_string<char,std::string::traits_type, std::string::allocator_type>() ).c_str())
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int,int> mpii;
typedef map<ll,ll> mpll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

    
const double pi= M_PI;
const int mod=1e9+7;
int N=2e5+100;

/*

set <int> adj[N];
bool vis[N];
vector<int> ord;
//int val[N];
//int dis[N];
//int low[N];    
int ans=0;
*/
ll power(ll a, ll b, ll MOD = LLONG_MAX)
{
    if (b == 0 || a == 1)  return 1;
    if (a == 0) return 0;
    ll po=power(a,b/2,MOD)%MOD;
    if (b & 1) {
        return (((po*po)%MOD)*a)%MOD;
    }
    else {
        return (po*po)%MOD;
    }
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

void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod,vector<pair<int,int>> &v)
{
    if (n == 1){
        v.pb(mkp(from_rod,to_rod));
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod,v);
    v.pb(mkp(from_rod,to_rod));
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod,v);
}

int main()
{
    fio;
    ll t=1;
    //cin>>t;
    while(t--){
        vector<pair<int,int>> v;
        int n;
        cin>>n;
        towerOfHanoi(n,1,3,2,v);
        cout<<v.size();nl;
        for(auto x:v){
            cout<<x.ff<<" "<<x.ss;nl;
        }
    }
}
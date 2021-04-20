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
    
ll power(ll x, ll n){
	if (n == 0) return 1;
	ll po = power(x, n / 2);
	if (n & 1) return x * po * po;
	return po * po;
}

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

ll fun1(ll a,ll b){
    return a*a+b;
}
ll fun2(ll a,ll b){
    return a*a-b+1;
}


int main()
{
    fio;
    ll t=1;
    cin>>t;
    while(t--){
        ll x,y,ans;
        cin>>x>>y;
        if(y>x){
            if(y%2!=0){
                ans=fun2(y,x);    //y*y-x+1;
            }
            else 
                ans=fun1(y-1,x);     //y*y+x-1;
        }
        else if(y==x){
                ans=fun2(y,x);
        }
        else{
            if(x%2==0){
                ans=fun2(x,y);     //x*x-y+1;
            }
            else
                ans=fun1(x-1,y);    //x*x+y-1;
        }
        cout<<ans;nl;
    }
}
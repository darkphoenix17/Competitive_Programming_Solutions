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


int main()
{
    fio;
    ll t=1;
    //cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1 || n==2){
            cout<<"NO";
            continue;
        }
        if(n==3){
            cout<<"YES";nl;
            cout<<"2";nl;
            cout<<"1 2";nl;
            cout<<"1";nl;
            cout<<"3";
            continue;
        }
        if(n-3>0 && (n-3)%4==0 || n%4==0){
            vi v1,v2;
            if((n-3)%4==0){
                v1.pb(1);
                v1.pb(2);
                v2.pb(3);
                for(int i=4;i<=n;i+=4){
                    v1.pb(i);
                    v1.pb(i+3);
                    v2.pb(i+1);
                    v2.pb(i+2);
                }
                cout<<"YES";nl;
                cout<<v1.size();nl;
                for(auto x:v1){
                    cout<<x<<" ";
                }
                nl;
                cout<<v2.size();nl;
                for(auto x:v2){
                    cout<<x<<" ";
                }
            }
            else{
                for(int i=1;i<=n;i+=4){
                    v1.pb(i);
                    v1.pb(i+3);
                    v2.pb(i+1);
                    v2.pb(i+2);
                }
                cout<<"YES";nl;
                cout<<v1.size();nl;
                for(auto x:v1){
                    cout<<x<<" ";
                }
                nl;
                cout<<v2.size();nl;
                for(auto x:v2){
                    cout<<x<<" ";
                }
            }
        }
        else cout<<"NO";
    }
}
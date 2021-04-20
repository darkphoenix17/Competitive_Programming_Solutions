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


int main()
{
    fio;
    ll t=1;
    //cin>>t;
    while(t--){
        vi v(26,0);
        string s;
        cin>>s;
        for(auto x:s){
            v[x-'A']++;
        }
        int cnt=0;
        loop(i,0,26){
            if(v[i]%2!=0){
                cnt++;
            }
        }
        if(cnt>1){
            cout<<"NO SOLUTION";nl;
            continue;
        }
        char mid_char='@';
        int mid_cnt;
        vector<char> ans;
        loop(i,0,26){
            if(v[i]%2!=0){
                mid_char=i+'A';
                mid_cnt=v[i];
            }
            else{
                int temp=v[i]/2;
                while(temp--){
                    ans.pb(i+'A');
                }
            }
        }
        for(char x:ans){
            cout<<x;
        }
        if(cnt==1){
            while(mid_cnt--){
                cout<<mid_char;
            }
        }
        reverse(ans.begin(),ans.end());
        for(char x:ans){
            cout<<x;
        }
    }
}
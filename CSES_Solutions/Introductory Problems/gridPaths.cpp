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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

    
const double pi= M_PI;
//const int mod=1e9+7;
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
ll power(ll a, ll b, ll mod = LLONG_MAX)
{
    if (b == 0 || a == 1)  return 1;
    if (a == 0) return 0;
    ll po=power(a,b/2,mod)%mod;
    if (b & 1)  return (((po*po)%mod)*a)%mod;
    else    return (po*po)%mod;
    
}

ll fact(ll n,ll mod =LLONG_MAX){               //overflow for n>20 
    return (n==1||n==0)?1:(n*fact(n-1)%mod)%mod;
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

ll ans=0,steps=0;
bool v[7][7];
int reserved[48];

void solve(ll row,ll col){
    if(row==6 && col==0){
        if(steps==48) ans++;
        return;
    }

    bool t= v[row][col] 
    || (row>0 && row<6 && !v[row+1][col] && !v[row-1][col] &&
            ((col==0 && v[row][col+1]) || (col==6 && v[row][col-1])))
    || (col>0 && col<6 && !v[row][col+1] && !v[row][col-1] && 
            ((row==0 && v[row+1][col]) || (row==6 && v[row-1][col])))
    || (row>0 && row<6 && col>0 &&col<6 && v[row-1][col] && v[row+1][col] && !v[row][col-1] && !v[row][col+1])
    || (row>0 && row<6 && col>0 &&col<6 && v[row][col-1] && v[row][col+1] && !v[row-1][col] && !v[row+1][col]);

    if(t) return;

    v[row][col]=true;
    if(reserved[steps]!=-1){
        switch(reserved[steps]){
            case 0:
                if(row >0 && !v[row-1][col]){
                    steps++;
                    solve(row-1,col);
                    steps--;
                }
                break;
            case 2:
                if(row < 6 && !v[row+1][col]){
                    steps++;
                    solve(row+1,col);
                    steps--;
                }
                break;
            case 3:
                if(col >0 && !v[row][col-1]){
                    steps++;
                    solve(row,col-1);
                    steps--;
                }
                break;
            case 1:
                if(col<6 && !v[row][col+1]){
                    steps++;
                    solve(row,col+1);
                    steps--;
                }
                break;
        }
        v[row][col]=false;
        return;
    }
    if(row >0 && !v[row-1][col]){
        steps++;
        solve(row-1,col);
        steps--;
    }
    if(row < 6 && !v[row+1][col]){
        steps++;
        solve(row+1,col);
        steps--;
    }
    if(col >0 && !v[row][col-1]){
        steps++;
        solve(row,col-1);
        steps--;
    }
    if(col<6 && !v[row][col+1]){
        steps++;
        solve(row,col+1);
        steps--;
    }

    v[row][col]=false;
}

int main()
{
    fio;
    ll t=1;
    //cin>>t;
    while(t--){
        string s;
        cin>>s;
        loop(i,0,lgt(s)){
            if(s[i]=='?') reserved[i]=-1;
            else if(s[i]=='U') reserved[i]=0;
            else if(s[i]=='D') reserved[i]=2;
            else if(s[i]=='L') reserved[i]=3;
            else if(s[i]=='R') reserved[i]=1;
        }

        solve(0,0);
        cout<<ans;nl;
    }
}
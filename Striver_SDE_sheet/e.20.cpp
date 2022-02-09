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
//const ll mod=1e9+7;
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


//For Factorial(Start)
// Change MOD value if required and set MAX
/*
const ll MAX = 5010;
const ll MOD = 998244353;
vector<ll> fac, finv, inv;

void binom_init() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD; //ref: https://cp-algorithms.com/algebra/module-inverse.html
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll binom(ll n, ll r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
}
*/
//For Factorial(End)

//--------------------MAIN CODE--------------------//

//update the p[node] to the same number as of which city in p it is grouped to. like update p[3]=1 since p[1]=1 and node 3 and node 1 are connected and belong to the same group now.
int root(vi &p, int u) {
	if (p[u] != u) {
		p[u] = root(p, p[u]);
	}
	return p[u];
}

int main()
{
	fio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//binom_init();
	ll t = 1;
	//cin >> t;
	while (t--) {
		//The rail connections will be stored on the queue for further computation
		//When road connection comes up, we will connect the road connection as it comes and then check for the rail connection that is stored in queue. if(q.empty()) then both the graphs have same grouping(i.e from any u node we can go to any v nodein that group)
		queue<pii> q;
		int n, Q;
		cin >> n >> Q;
		vi p(n + 1);
		loopb(i, 1, n) p[i] = i;
		while (Q--) {
			int w, u, v;
			cin >> w >> u >> v;
			if (w == 2) {		//road connection
				int ru = root(p, u), rv = root(p, v);
				if (ru != rv) {
					p[rv] = ru;		//Update the road connection and group together if not already in the same group
				}
			}
			else {
				q.push({u, v});   //Store the rail connection in queue for further computation or checking
			}
			int flag = 0;
			while (!q.empty()) {	//Since after each query we have to output the decision that the transport network is balanced or not we need to compute for each Q
				auto &[nu, nv] = q.front();
				int ru = root(p, nu), rv = root(p, nv);   //Check the queue for rail nodes
				if (ru != rv) {		//Check of the rail node connected are in same group already
					//If No then print NO and don't remove the node pair from the queue and break it loop
					flag = 1;
					cout << "NO\n";
					break;
				}
				//if Yes then pop the queue value and check for further node pairs in queue
				q.pop();
			}
			//if the queue get empty and all the rails network are already in the same group as road network then the transport netwrok is balanced and we print YES
			if (!flag) {
				cout << "YES\n";
			}
		}
	}
}
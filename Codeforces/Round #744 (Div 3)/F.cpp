//--> Karan's Code <--
#define _USE_MATH_DEFINES
#include <cmath>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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
using namespace __gnu_pbds;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int, int> mpii;
typedef map<ll, ll> mpll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

int main()
{
	fio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t = 1;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		queue<pii> q;
		loop(i, 0, n) {
			cin >> arr[i];
			if (arr[i] == 0) q.push(mkp(i, 0));
		}
		int ans = 0;
		while (!q.empty()) {
			int i = q.front().ff;
			int lvl = q.front().ss;
			ans = max(ans, lvl);
			q.pop();
			if (arr[(i + n - k) % n] == 1) {
				q.push(mkp((i + n - k) % n, lvl + 1));
				arr[(i + n - k) % n] = 0;
			}
		}
		int f = 1;
		loop(i, 0, n) {
			if (arr[i] == 1) {
				cout << -1;
				f = 0;
				break;
			}
		}
		if (f) cout << ans;
		nl;
	}
}
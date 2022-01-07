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

void check(vector<vector<char>> &v, vector<vector<char>> &ext, int x, int y, int k) {
	int cnt = 0, i = x - 1, jl = y - 1, jr = y + 1;
	while (i >= 0 && jl >= 0 && jr < v[0].size() && v[i][jl] == '*' && v[i][jr] == '*') {
		//cout << i << " " << jl << " " << jr << " " << cnt; nl;
		i--;
		jl--;
		jr++;
		cnt++;
	}
	if (cnt < k) return;
	for (int i = 0; i <= cnt; i++) {
		ext[x - i][y - i] = '*';
		ext[x - i][y + i] = '*';
	}
	return;
}


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
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<char>> v(n, vector<char>(m)), ext(n, vector<char>(m, '.'));
		//char ar[n][m];
		loop(i, 0, n) {
			loop(j, 0, m) cin >> v[i][j];
		}
		//char ext[n][m];
		//memset(ext,'.',sizeof(ext));
		loop(i, 0, n) {
			loop(j, 0, m) {
				if (v[i][j] == '*') {
					check(v, ext, i, j, k);
				}
			}
		}
		bool flag = true;
		loop(i, 0, n) {
			loop(j, 0, m) {
				if (v[i][j] != ext[i][j]) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
		// loop(i, 0, n) {
		//     loop(j, 0, m) cout << v[i][j];
		//     nl;
		// } cout << "----\n";
		// loop(i, 0, n) {
		//     loop(j, 0, m) cout << ext[i][j];
		//     nl;
		// }
		if (flag) cout << "YES";
		else cout << "NO";
		nl;

	}
}
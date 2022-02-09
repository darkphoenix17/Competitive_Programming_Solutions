typedef long long int ll;
class Solution {
public:
	string subStrHash(string s, int pwr, int modulo, int k, int hashValue) {
		ll power = pwr;
		ll len = s.length();
		ll firstPointer = len - k;
		string ans = "";
		ll mod = modulo;
		power %= mod;
		vector<ll> p(k, -1);
		p[0] = 1;
		for (int i = 1; i < k; i++) {
			p[i] = (p[i - 1] * power) % mod;
		}
		ll sum = 0; //Hash is stored here during runtime
		// here the hash value will be updated during runtime and checked each time if it matches the hashValue
		//We can see that when we compute the hash by sliding window of length k from right to left of the original string we see a monotonous change in the value of hash

		//First find the hash sum of the string from the back part of lenght k i.e (n-k,n-k+1,....,n-1)
		//I.e. Computing the last (k length window)
		for (ll i = 0; i < k; i++) {
			ll ind = firstPointer + i;
			ll val = s[ind] - 'a' + 1;
			ll multi = p[i] % mod;
			ll res = (val * multi) % mod;
			sum = (sum + res) % mod;
			if (sum == hashValue) ans = s.substr(firstPointer, k);
		}

		//We will be doing rolling hash function. As per our hash function the power is exponentially increases as we go from left to right
		//Keeping this in mind we will start from the back substring of length k and so sliding the window toward the left side.
		//While doing sliding window->
		//Step1: We leave the kth element from last substring by subtracting its value from cur hash
		//Step2: As we know, we slide from right to left we know that the hash should be multiplied by power p first before letting the new update in the hash from the left first value i.e. hash=(hash*power)%mod
		//		Reason is because when we start from the back of the string hash[i-1]=((hash[i]*power)%mod+(s[i-1]-'a'+1)%mod)%mod (Applicable only if the last k length window is been computed already)
		//Step 3: Since the power is been mulitplied to the hash we can add the first left element of the current window to make the window of length k. I.e. hash[i-1]=(hash[i]+(s[i-1]-'a'+1)%mod)%mod
		//Check for the left most window inside the loop by sliding the window towards the left side which is what the question asked for.
		firstPointer--;
		while (firstPointer >= 0) {
			ll subtract = (((s[firstPointer + k] - 'a' + 1) % mod) * (p[k - 1] % mod)) % mod;
			sum = (sum - subtract + mod) % mod;
			sum = (sum * power) % mod;
			ll addn = ((s[firstPointer] - 'a' + 1) % mod);
			sum = (sum + addn) % mod;
			if (sum == hashValue) ans = s.substr(firstPointer, k);
			firstPointer--;
		}
		return ans;
	}
};
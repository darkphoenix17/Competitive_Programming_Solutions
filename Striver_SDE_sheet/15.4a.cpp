//Using Rabin-Karp String Matching method.
class Solution {
public:
	int d = 256;
	int search(string pat, string txt, long long q)
	{
		int M = pat.length();
		int N = txt.length();
		int i, j;
		long long p = 0; // hash value for pattern
		long long t = 0; // hash value for txt
		long long h = 1;

		// The value of h would be "pow(d, M-1)%q"
		for (i = 0; i < M - 1; i++) h = (h * d) % q;
		// Calculate the hash value of pattern and first window of text
		for (i = 0; i < M; i++) {
			p = (d * p + pat[i]) % q;
			t = (d * t + txt[i]) % q;
		}
		// Slide the pattern over text one by one
		for (i = 0; i <= N - M; i++) {
			// Check the hash values of current window of text and pattern. If the hash values match then only check for characters one by one
			if ( p == t ) {
				bool flag = true;
				/* Check for characters one by one */
				for (j = 0; j < M; j++) {
					if (txt[i + j] != pat[j]) {
						flag = false;
						break;
					}
				}
				if (!flag) continue;
				// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
				if (j == M) {
					return i;
					//cout<<"Pattern found at index "<< i<<endl;
				}
			}
			// Calculate hash value for next window of text: Remove leading digit, add trailing digit
			if ( i < N - M ) {
				t = (d * (t - txt[i] * h) + txt[i + M]) % q;
				// We might get negative value of t, converting it to positive
				if (t < 0)
					t = (t + q);
			}
		}
		return -1;
	}

	int strStr(string hs, string nd) {
		if (nd.size() == 0) return 0;
		d = 256;
		return search(nd, hs, 1000000);
	}
};



class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle == "")
			return 0;
		else {
			if (haystack.find(needle) != string::npos)
				return haystack.find(needle);
			else
				return -1;
		}
	}
};

class Solution {
public:
	int strStr(string s1, string s2) {
		if (s2 == "") return 0;
		int find = s1.find(s2);
		return find;

	}
};
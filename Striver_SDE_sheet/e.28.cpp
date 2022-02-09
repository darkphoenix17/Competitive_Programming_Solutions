class Bitset {
public:
	vector<int> v;
	int c;// count of flips
	int cc;// count of set bits
	int n;//size
	Bitset(int size) {
		n = size;
		v = vector<int>(size, 0);
		c = 0;
		cc = 0;
	}

	void fix(int idx) {
		if (c % 2 == 0) {
			if (v[idx] == 0) {
				v[idx] = 1;
				cc++;
			}
		}
		else {
			if (v[idx] == 1) {
				v[idx] = 0;
				cc++;
			}
		}
	}

	void unfix(int idx) {
		if (c % 2 == 0) {
			if (v[idx] == 1) {
				v[idx] = 0;
				cc--;
			}
		}
		else {
			if (v[idx] == 0) {
				v[idx] = 1;
				cc--;
			}
		}
	}

	void flip() {
		c++;
		cc = (n - cc);
	}

	bool all() {
		if (cc == n) return true;
		return false;
	}

	bool one() {
		if (cc > 0) return true;
		return false;
	}

	int count() {
		return cc;
	}

	string toString() {
		string ans = "";
		for (int i = 0; i < v.size(); i++) {
			if (c % 2 == 0) {
				if (v[i] == 1) ans += '1';
				else ans += '0';
			}
			else {
				if (v[i] == 0) ans += '1';
				else ans += '0';
			}
		}
		return ans;
	}
};
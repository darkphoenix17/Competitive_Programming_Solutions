//Roman to Int
class Solution {
public:
	vector<int> toNum(string a) {
		vector<int> v;
		map <char, int> m;
		m['I'] = 1;
		m['V'] = 2;
		m['X'] = 3;
		m['L'] = 4;
		m['C'] = 5;
		m['D'] = 6;
		m['M'] = 7;
		for (auto x : a) {
			v.push_back(m[x]);
		}
		return v;
	}
	int romanToInt(string s) {
		vector<int> a;
		a = toNum(s);
		map <int, int> mp;
		mp[1] = 1;
		mp[12] = 4;
		mp[2] = 5;
		mp[13] = 9;
		mp[3] = 10;
		mp[34] = 40;
		mp[4] = 50;
		mp[35] = 90;
		mp[5] = 100;
		mp[56] = 400;
		mp[6] = 500;
		mp[57] = 900;
		mp[7] = 1000;
		int ans = 0;
		for (int i = 0; i < a.size(); i++) {
			int temp = 0;
			temp = a[i];
			while (i + 1 < a.size() && a[i + 1] > a[i]) {
				temp = temp * 10 + a[i + 1];
				i++;
			}
			ans += mp[temp];
		}
		return ans;
	}
};

//Int to Roman
class Solution {
public:
	string intToRoman(int num) {
		vector<pair<int, string>> v;
		v.push_back(make_pair(1, "I"));
		v.push_back(make_pair(4, "IV"));
		v.push_back(make_pair(5, "V"));
		v.push_back(make_pair(9, "IX"));
		v.push_back(make_pair(10, "X"));
		v.push_back(make_pair(40, "XL"));
		v.push_back(make_pair(50, "L"));
		v.push_back(make_pair(90, "XC"));
		v.push_back(make_pair(100, "C"));
		v.push_back(make_pair(400, "CD"));
		v.push_back(make_pair(500, "D"));
		v.push_back(make_pair(900, "CM"));
		v.push_back(make_pair(1000, "M"));

		string s = "";
		for (int i = v.size() - 1; i >= 0; i--) {
			int tim = num / v[i].first;
			while (tim--) {
				s += v[i].second;
			}
			num = num % v[i].first;
		}
		return s;
	}
};
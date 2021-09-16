class Solution {
public:
	vector<int> compute(string s) {
		vector<int> v;
		int i = 0;
		while (i < s.size()) {
			if (s[i] == '.') i++;
			while (s[i] == '0' && i + 1 < s.size()) i++;
			int num = 0;
			while (s[i] != '.' && i + 1 < s.size()) {
				num = num * 10 + (s[i] - '0');
				i++;
			}
			if (i + 1 == s.size()) num = num * 10 + (s[i] - '0');
			v.push_back(num);
			i++;
		}
		return v;
	}

	int compareVersion(string version1, string version2) {
		vector<int> v1 = compute(version1), v2 = compute(version2);
		for (int i = 0; i < min(v1.size(), v2.size()); i++) {
			if (v1[i] > v2[i]) return 1;
			else if (v2[i] > v1[i]) return -1;
		}
		if (v1.size() > v2.size()) {
			for (int i = v2.size(); i < v1.size(); i++) if (v1[i] != 0) return 1;
		}
		else if (v1.size() < v2.size()) {
			for (int i = v1.size(); i < v2.size(); i++) if (v2[i] != 0) return -1;
		}
		return 0;
	}
};
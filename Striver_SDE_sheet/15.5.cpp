class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string max = *max_element(strs.begin(), strs.end());
		string min = *min_element(strs.begin(), strs.end());
		for (int i = 0; i < min.size(); i++) {
			if (min[i] == max[i]) { continue;}
			min.resize(i);
			return min;
		}
		return min;
	}
};

//Using Trie
class Solution {
public:
	struct TrieNode {
		bool islast;
		TrieNode *child[26];
		TrieNode() {
			for (int i = 0; i < 26; i++) {
				child[i] = nullptr;
			}
			islast = false;
		}
	};

	void inputstring(TrieNode* cur, string s) {
		for (int i = 0; i < s.length(); i++) {
			int ind = s[i] - 'a';
			if (!cur->child[ind]) {
				cur->child[ind] = new TrieNode();
			}
			cur = cur->child[ind];
		}
		cur->islast = true;
	}

	int checkchild(TrieNode *cur, int *ind) {
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (cur->child[i] != nullptr) {
				cnt++;
				*ind = i;
			}
		}
		return cnt;
	}

	string getAns(TrieNode* cur) {
		int ind;
		string ans = "";
		while (checkchild(cur, &ind) == 1 && !cur->islast) {
			cur = cur->child[ind];
			ans += ('a' + ind);
		}
		return ans;
	}

	string longestCommonPrefix(vector<string>& strs) {
		TrieNode* root = new TrieNode();
		for (int i = 0; i < strs.size(); i++) {
			inputstring(root, strs[i]);
		}
		return getAns(root);
	}
};
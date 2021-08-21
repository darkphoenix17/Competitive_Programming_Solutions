class Solution {
public:
    void funct(string s, int ind, vector<string> &cur, vector<vector<string>> & ans) {
        if (ind == s.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(s, ind, i)) {
                cur.push_back(s.substr(ind, i - ind + 1));
                funct(s, i + 1, cur, ans);
                cur.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        funct(s, 0, cur, ans);
        return ans;
    }
};
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<string, vector<int>> mp;
    vector<vector<int>> ans;
    for (int i = 0; i < A.size(); i++) {
        string b = A[i];
        sort(b.begin(), b.end());
        mp[b].push_back(i + 1);
    }
    for (auto x : mp) {
        ans.push_back(x.second);
    }
    return ans;
}
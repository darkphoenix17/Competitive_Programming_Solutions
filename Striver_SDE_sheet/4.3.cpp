class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> smp;
        for (auto x : nums) {
            smp.insert(x);
        }
        int mx = 0;
        for (auto x : smp) {
            if (smp.find(x - 1) == smp.end()) {
                int curnum = x;
                int curst = 1;
                while (smp.find(curnum + 1) != smp.end()) {
                    curnum++;
                    curst++;
                }
                mx = max(mx, curst);
            }
        }
        return mx;
    }
};
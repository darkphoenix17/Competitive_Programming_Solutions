class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //This method is know as Boyer-Moore Voting ALgorithm
        // Solution to this video: https://youtu.be/yDbkQd9t2ig?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2
        /*Hint: here the number having freq. greater than floor(n/3) c
        an only be at max 2 numbers as by bounding the other minority have to become less.
        */
        int n = nums.size();
        vector<int> ans;
        int el1 = -1, el2 = -1, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (el1 == nums[i]) cnt1++;
            else if (el2 == nums[i]) cnt2++;
            else if (cnt1 == 0) el1 = nums[i], cnt1 = 1;
            else if (cnt2 == 0) el2 = nums[i], cnt2 = 1;
            else {
                cnt1--;
                cnt2--;
            }
        }
        //check explicitly if el1 and el2 are actually having cnt>floor(n/3);
        cnt1 = cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
        }
        if (cnt1 > floor(n / 3)) ans.push_back(el1);
        if (cnt2 > floor(n / 3)) ans.push_back(el2);
        return ans;
    }
};
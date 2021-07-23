class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int i = 0, n = nums.size();
		return nums[n / 2];
	}
};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		/*it is called Boyer-Moore Voting ALgorithm which works on bounding.
		As the majoirty element is suppose to come more than n/2 times,
		We try to balance out the array by picking first element that comes in iteration as maxmium and
		try to balance it our with other minority.
		By doing the balance, it will be quite clear that the remaining maxmimun number
		at the end of array is our maxmimum element in the whole array as per the bounding.
		*/
		int el = -1;  //local maxmium
		int cnt = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (cnt == 0) el = nums[i];
			if (el == nums[i]) cnt++;
			else cnt--;
		}
		return el;
	}
};
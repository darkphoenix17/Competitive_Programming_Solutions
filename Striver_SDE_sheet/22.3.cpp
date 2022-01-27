class KthLargest {
public:
	//priority_queue<int> maxi;
	priority_queue<int, vector<int>, greater<int>> mini;
	int size;
	KthLargest(int k, vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			mini.push(nums[i]);
		}
		while (mini.size() > k) {
			mini.pop();
		}
		size = k;
	}

	int add(int val) {
		mini.push(val);
		if (mini.size() > size) mini.pop();
		return mini.top();
	}
};

/**
 * Your KthLargest object will be instanciatedas such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
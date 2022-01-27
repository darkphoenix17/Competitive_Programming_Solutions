/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


class MedianFinder {
public:
	priority_queue<int> mini;
	priority_queue<int, vector<int>, greater<int>> maxi;
	MedianFinder() {
	}

	void addNum(int num) {
		if (maxi.empty() && mini.empty()) mini.push(num);
		else {
			int m = maxi.size();
			int n = mini.size();
			if (m == n) {
				int med = (maxi.top() + mini.top()) / 2;
				if (num > med) {
					maxi.push(num);
				}
				else mini.push(num);
			}
			else if (m > n) {
				int med = maxi.top();
				if (num > med) {
					mini.push(maxi.top());
					maxi.pop();
					maxi.push(num);
				}
				else mini.push(num);
			}
			else {
				int med = mini.top();
				if (num < med) {
					maxi.push(mini.top());
					mini.pop();
					mini.push(num);
				}
				else maxi.push(num);
			}
		}
	}

	double findMedian() {
		int m = maxi.size();
		int n = mini.size();
		double med;
		if (m == n) med = double(maxi.top() + mini.top()) / double(2);
		else if (m > n) med = double(maxi.top());
		else med = double(mini.top());
		return med;
	}
};




class MedianFinder {
public:
	std::deque<int> arr_;

	MedianFinder() {

	}

	void addNum(int num) {
		if (arr_.empty()) {
			arr_.emplace_back(num);
			return;
		}
		auto it = std::upper_bound(arr_.begin(), arr_.end(), num);
		arr_.insert(it, num);
	}

	double findMedian() {
		int n = arr_.size();
		if (n % 2) {
			return arr_[n / 2];
		}
		return static_cast<double>(arr_[n / 2 - 1] + arr_[n / 2]) / 2;
	}
};


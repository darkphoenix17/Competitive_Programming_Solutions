class Solution {
public:
	int kthElement(int arr1[], int arr2[], int n, int m, int k)
	{
		if (n < m) return kthElement(arr2, arr1, m, n, k);
		int lo = 0, hi = n;
		while (lo <= hi) {
			int cut1 = (lo + hi) >> 1;
			int cut2 = k - cut1;
			//cout<<cut1<<" "<<cut2<<endl;
			if (cut2 > m) {
				lo = cut1 + 1;
				continue;
			}
			else if (cut2 < 0) {
				hi = cut1 - 1;
				continue;
			}
			int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
			int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
			int r1 = cut1 == n ? INT_MAX : arr1[cut1];
			int r2 = cut2 == m ? INT_MAX : arr2[cut2];
			//cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
			if (l1 <= r2 && l2 <= r1) {
				return max(l1, l2);
			}
			else if (l1 > r2) {
				hi = cut1 - 1;
			}
			else lo = cut1 + 1;
		}
	}
};

class Solution {
public:
	int kthElement(int arr1[], int arr2[], int n, int m, int k)
	{
		if (n < m) return kthElement(arr2, arr1, m, n, k);
		int lo = max(0, k - m), hi = min(n, k);
		while (lo <= hi) {
			int cut1 = (lo + hi) >> 1;
			int cut2 = k - cut1;
			//cout<<cut1<<" "<<cut2<<endl;
			int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
			int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
			int r1 = cut1 == n ? INT_MAX : arr1[cut1];
			int r2 = cut2 == m ? INT_MAX : arr2[cut2];
			//cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
			if (l1 <= r2 && l2 <= r1) {
				return max(l1, l2);
			}
			else if (l1 > r2) {
				hi = cut1 - 1;
			}
			else lo = cut1 + 1;
		}
	}
};
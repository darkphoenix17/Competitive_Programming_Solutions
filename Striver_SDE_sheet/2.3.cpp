class Solution {
public:
	void nextPermutation(vector<int>& a) {
		/*Algorithm steps
		    In a dictionary order then is always a peek point staring from back where the number or element before it should be changed eg. 13542 here the peak point is 5 and the number 3 should be changed to get the next permutation.
		    Step 1: Loop from back:
		            till a[i]<a[i+1] and i store in ind1;
		    Step 2: Again loop from back:
		            till first i such that a[i]>a[ind1] and i store in ind2;
		    Step 3: Now swap (a[ind1],a[ind2]);
		    Note: here the order of numbers from back remains increasing(from back) itself and that remaining interval is descending(from front) ;
		    Step 4: Now after swaping, the remaing order should be acsending in order to get next permutation so reverse the remaining further section after the swap as they as in descending order already
		*/
		int n = a.size();
		int ind1 = -1, ind2;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] < a[i + 1]) {
				ind1 = i;
				break;
			}
		}
		if (ind1 != -1) {
			for (int i = n - 1; i >= ind1; i--) {
				if (a[i] > a[ind1]) {
					ind2 = i;
					break;
				}
			}
			swap(a[ind1], a[ind2]);
		}
		reverse(a.begin() + ind1 + 1, a.end());
	}
};
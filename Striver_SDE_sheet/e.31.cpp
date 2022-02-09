class Solution {
public:
	int minMoves(int target, int maxDoubles) {
		int cnt = 0;
		while (target > 1) {
			if (target % 2 == 0 && maxDoubles) {
				maxDoubles--;
				target /= 2;
				cnt++;
				continue;
			}
			if (!maxDoubles) {
				cnt += target - 1;
				return cnt;
			}
			target--;
			cnt++;
		}
		return cnt;
	}
};
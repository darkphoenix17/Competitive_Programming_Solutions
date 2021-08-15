// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	static bool sortbysec(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
		if (a.first.second < b.first.second) return true;
		else if (a.first.second > b.first.second) return false;
		else if (a.second < b.second) return true;
		else return false;
	}
	//Function to find the maximum number of meetings that can
	//be performed in a meeting room.
	int maxMeetings(int start[], int end[], int n) {
		vector<pair<pair<int, int>, int>> v;
		for (int i = 0; i < n; i++) {
			v.push_back(make_pair(make_pair(start[i], end[i]), i));
		}
		sort(v.begin(), v.end(), sortbysec);
		// sort(v.begin(),v.end(),[](const pair<pair<int,int>,int> &a,const pair<pair<int,int>,int> &b){
		//     if(a.first.second<b.first.second) return true;
		//     else if (a.first.second>b.first.second) return false;
		//     else if(a.second<b.second) return true;
		//     else return false;
		// });    //using lambda function
		int prev = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			//cout<<v[i].first.first<<" "<<v[i].first.second<<endl;
			if (prev < v[i].first.first) {
				prev = v[i].first.second;
				ans++;
			}
		}
		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int start[n], end[n];
		for (int i = 0; i < n; i++) cin >> start[i];

		for (int i = 0; i < n; i++) cin >> end[i];

		Solution ob;
		int ans = ob.maxMeetings(start, end, n);
		cout << ans << endl;
	}
	return 0;
}  // } Driver Code Ends
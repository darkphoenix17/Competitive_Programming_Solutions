class Solution {
public:
	vector<string> AllPossibleStrings(string s) {
		int n = s.size();
		vector<string> ans;
		for (int num = 0; num < (1 << n); num++) {
			string sub = "";
			for (int i = 0; i < n; i++) {
				if (num & (1 << i)) {
					sub += s[i];
				}
			}
			if (sub.size() > 0)
				ans.push_back(sub);
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
// 		string findCombination(unsigned int m, string s){
// 	        unsigned int i=0;
// 	        unsigned k=s.length();
// 	        string res="";
// 	        while(m>>i>0 && i<=k-1){
// 	            if((m>>i)&1==1){
// 	                res+=s[k-i-1];
// 	            }
// 	            i++;
// 	        }
// 	        return res;
// 	    }
// 		vector<string> AllPossibleStrings(string s){
// 		    vector<string> ans;
// 		    unsigned int n=s.length();
// 		    n=1>>n;
// 		    //n--;
// 		    unsigned int i=0;
// 		    while(i<n){
// 		        string temp=findCombination(i,s);
// 		        if(!temp.empty())
// 		            ans.push_back(temp);
// 		        i++;
// 		    }
// 		    return ans;
// 		}
};
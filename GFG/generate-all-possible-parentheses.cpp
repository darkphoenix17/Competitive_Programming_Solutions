//QuestionLink: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
public:
    vector<string> AllParenthesis(int n)
    {
        vector<string> ans;
        int open = 0, close = 0;
        find(open, close, "", n, ans);
        return ans;
    }
    void find(int open, int close, string s, int n, vector<string> & ans) {
        if (close == n) {
            ans.push_back(s);
            return;
        }
        if (open > close) find(open, close + 1, s + ')', n, ans);
        if (open < n) find(open + 1, close, s + '(', n, ans);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}
// } Driver Code Ends
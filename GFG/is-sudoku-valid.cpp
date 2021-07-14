//QuestionLink: https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int isValid(vector<vector<int>> mat) {
        set<string> st;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int x = mat[i][j];
                if (x != 0) {
                    string row = to_string(x) + "row" + to_string(i);
                    string col = to_string(x) + "column" + to_string(j);
                    string sublock = to_string(x) + "board" + to_string(i / 3) + "" + to_string(j / 3);
                    if (st.find(row) != st.end() || st.find(col) != st.end() || st.find(sublock) != st.end()) return 0;
                    else {
                        st.insert(row);
                        st.insert(col);
                        st.insert(sublock);
                    }
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for (int i = 0; i < 81; i++)
            cin >> mat[i / 9][i % 9];

        Solution ob;
        cout << ob.isValid(mat) << "\n";
    }
    return 0;
}  // } Driver Code Ends
//QuestionLink: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int arr[], int n) {
        int maxl[n], maxr[n];   // maximun of left sub array and right subarray respectively;
        int maxlel = maxl[0] = arr[0]; //intermediate max left value
        int maxrel = maxr[n - 1] = arr[n - 1]; //intermediate max right value
        for (int i = 1; i < n; i++) {
            maxl[i] = max(maxlel, arr[i]); //max left value strating from left
            maxlel = maxl[i];
            maxr[n - i - 1] = max(maxrel, arr[n - i - 1]); //max right value starting from right
            maxrel = maxr[n - i - 1];
        }
        int water[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            water[i] = min(maxl[i], maxr[i]) - arr[i]; // water at each building
            ans += water[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    //testcases
    cin >> t;

    while (t--) {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;

    }

    return 0;
}  // } Driver Code Ends
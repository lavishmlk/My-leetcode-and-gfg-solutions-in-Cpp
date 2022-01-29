// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
//knk
  public:
    int FindElement(int arr[], int N) {
       int SE[N];
        int GE[N];
        GE[0] = arr[0];
        SE[N - 1] = arr[N - 1];
        for (int i = 1; i < N; i++) {
            if (GE[i - 1] < arr[i])
                GE[i] = arr[i];
            else
                GE[i] = GE[i - 1];
        }
        for (int i = N - 2; i >= 0; i--) {
            if (arr[i] < SE[i + 1])
                SE[i] = arr[i];
            else
                SE[i] = SE[i + 1];
        }
        for (int j = 0; j < N; j++) {
            if ((j == 0 && arr[j] < SE[j + 1]) ||
                (j == N - 1 && arr[j] > GE[j - 1]) ||
                (arr[j] < SE[j + 1] && arr[j] > GE[j - 1]))
                return arr[j];
        }

        return -1;
    }
};


// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        Solution ob;
        cout << ob.FindElement(a, n);
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
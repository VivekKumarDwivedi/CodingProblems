#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int count = 0;  // count triplet
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            while (j < n) {
                if (abs(arr[i] - arr[j]) <= a) {
                    int k = j + 1;
                    while (k < n) {
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                            count++;
                        }
                        k++;
                    }
                }
                j++;
            }
        }
        return count;
    }
};

int main() {
    int n; // size of array
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);  // Initialize vector with size n
    
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int a, b, c;
    cout << "Enter the value of a, b, c: ";
    cin >> a >> b >> c;
    Solution sol;
    int count = sol.countGoodTriplets(arr, a, b, c);
    cout << "Number of Good Triplets: " << count << endl;
    return 0;
};
/*
Enter the size of the array: 5
Enter the array elements: 1 1 2 2 3
Enter the value of a, b, c: 0 0 1
Number of Good Triplets: 0*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
    
    vector<double> ans;
    //declaration  min heap and max heap
    priority_queue<int,vector<int>,greater<int>> minh;
    priority_queue<int> maxh;
    
    for (int num : a) {
// Step 1: Insert into appropriate heap
    if (maxh.empty() || num <= maxh.top()) {
        maxh.push(num);
    } else {
     minh.push(num);
   }
    // Step 2: Balance the heaps
    if (maxh.size() > minh.size() + 1) {
    minh.push(maxh.top());
    maxh.pop();
    } else if (minh.size() > maxh.size()) {
    maxh.push(minh.top());
    minh.pop();
    }
    //  Compute the  median
    if (maxh.size() == minh.size()) {
    double median = (maxh.top() + minh.top()) / 2.0;
    ans.push_back(median);
    } else {
     ans.push_back(maxh.top());
    }   
    }
return ans;
}

int main()
{
     int n;
     cout<<"Enter the size of array:";
     cin>>n;
     vector<int> a;
     for(int i=0; i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
     }

    vector<double> result = runningMedian(a);

     cout<<"Running median array is: ";
     for(int i=0; i<result.size();i++){
        cout<<result[i]<<" ";
     }

    

    

    return 0;
}

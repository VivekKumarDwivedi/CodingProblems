#include<bits/stdc++.h>
using namespace std;

int main() {
//Number of test Cases
int T;
cin >> T;
while (T--) {
int n, k;
cin >> n >> k;
vector<int> arr(n);
for (int i = 0; i < n; ++i) {
cin >> arr[i];
}
long long count = 0;
long long prefix_sum = 0;
unordered_map<int, int> mod_count;
mod_count[0] = 1; // Start with mod 0 count as 1
for (int i = 0; i < n; ++i) {
prefix_sum += arr[i];
int mod = ((prefix_sum % k) + k) % k;
// Directly add the current count of this mod (0 if not present)
count += mod_count[mod];
// Increase the count for this mod
mod_count[mod]++;

}
cout << count << endl;
}
return 0;
}
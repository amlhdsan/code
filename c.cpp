#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<pair<int, int>> segments;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') {
                    i++;
                }
                int end = i - 1;
                segments.push_back({start, end});
            } else {
                i++;
            }
        }
        
        bool valid = true;
        for (auto seg : segments) {
            int start = seg.first;
            int end = seg.second;
            int len = end - start + 1;
            if (len >= 2) {
                continue;
            }
            int idx = start;
            bool left_flower = (idx > 0 && s[idx-1] == '1');
            bool right_flower = (idx < n-1 && s[idx+1] == '1');
            
            if (left_flower && right_flower) {
                if ((idx >= 2 && s[idx-2] == '0') || (idx + 2 < n && s[idx+2] == '0')) {
                    // valid
                } else {
                    valid = false;
                }
            } else if (left_flower) {
                if (idx >= 2 && s[idx-2] == '0') {
                    // valid
                } else {
                    valid = false;
                }
            } else if (right_flower) {
                if (idx + 2 < n && s[idx+2] == '0') {
                    // valid
                } else {
                    valid = false;
                }
            }
        }
        
        cout << (valid ? "YES" : "NO") << '\n';
    }
    
    return 0;
}

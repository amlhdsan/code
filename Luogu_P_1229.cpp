#include <bits/stdc++.h>
using namespace std;

int a;
string s1, s2;

int main() {
    cin >> s1 >> s2;
    
    for(int i = 0; i < s1.size(); ++i)
        for(int j = 1; j < s2.size(); ++j)
            if(s1[i] == s2[j] && s1[i + 1] == s2[j - 1])
                a++;

    cout << (1 << a);

    return 0;
}

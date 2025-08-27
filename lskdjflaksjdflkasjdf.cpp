#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

int N;
map<int, set<int>> pos;
map<int,int> cnt;
multiset<int> cntms;
set<pair<int,int>> head;

int main(){
    freopen("food.in", "r", stdin);
    freopen("food.out", "w", stdout);
    N = read();
    for(int i=1;i<=N;i++){
        int a = read();
        pos[a].insert(i);
        cnt[a]++;
    }
    for(auto &p: cnt){
        cntms.insert(p.second);
        head.insert({*pos[p.first].begin(), p.first});
    }
    if(!cntms.empty()){
        int mx = *cntms.rbegin();
        if(mx > (N+1)/2){
            writeln(-1);
            return 0;
        }
    }
    vector<int> ans;
    ans.reserve(N);
    int prev = -1;
    int rem = N;
    for(int step=0;step<N;step++){
        bool found = false;
        for(auto it = head.begin(); it != head.end(); ++it){
            int idx = it->first;
            int val = it->second;
            if(val == prev) continue;
            int old = cnt[val];
            auto itf = cntms.find(old);
            if(itf!=cntms.end()) cntms.erase(itf);
            if(old-1>0) cntms.insert(old-1);
            int newmax = 0;
            if(!cntms.empty()) newmax = *cntms.rbegin();
            int rem_after = rem-1;
            bool ok = (newmax <= (rem_after+1)/2);
            auto itg = cntms.find(old-1);
            if(old-1>0 && itg!=cntms.end()) cntms.erase(itg);
            cntms.insert(old);
            if(ok){
                ans.push_back(idx);
                prev = val;
                rem--;
                pos[val].erase(idx);
                auto itc = cntms.find(old);
                if(itc!=cntms.end()) cntms.erase(itc);
                if(old-1>0) cntms.insert(old-1);
                cnt[val] = old-1;
                head.erase({idx, val});
                if(cnt[val]>0){
                    head.insert({*pos[val].begin(), val});
                }
                found = true;
                break;
            }
        }
        if(!found){
            writeln(-1);
            return 0;
        }
    }
    for(size_t i=0;i<ans.size();i++){
        if(i) putchar(' ');
        write(ans[i]);
    }
    putchar('\n');
    return 0;
}

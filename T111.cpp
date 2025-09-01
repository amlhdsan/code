#include <iostream>
#include <vector>
using namespace std;

typedef long long int;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    int W;
    cin >> n >> q >> W;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 差分数组
    vector<int> diff(n + 2, 0);

    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;
        diff[l] += d;
        if (r + 1 <= n) diff[r + 1] -= d;

        // 累加差分数组，更新a
        vector<int> current_a = a;
        int health = W;
        bool alive = true;
        int attack_count = 0;

        for (int i = 1; i <= n; i++) {
            // 更新攻击力
            if (i > 1) diff[i] += diff[i - 1];
            current_a[i] += diff[i];

            // 开始攻击
            int attack = current_a[i];
            while (health > 0) {
                health -= attack;
                attack_count++;
                attack *= 2;

                if (health <= 0) {
                    alive = false;
                    break;
                }
            }
            if (!alive) break;
        }
        
        cout << attack_count - 1 << endl;
    }

    return 0;
}

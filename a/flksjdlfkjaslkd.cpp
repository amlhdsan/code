#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

// Structure to hold coordinates
struct Point {
    long long x, y;
};

// Function to make a query and read the response
long long query(char dir, long long k) {
    cout << "? " << dir << " " << k << endl;
    long long s;
    cin >> s;
    return s;
}

// Manhattan distance
long long manhattan(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void solve() {
    int n;
    cin >> n;
    vector<Point> anchors(n);
    for (int i = 0; i < n; ++i) {
        cin >> anchors[i].x >> anchors[i].y;
    }

    const long long K = 1e9;

    long long s_R = query('R', K);
    query('L', K); // Move back to start
    long long s_U = query('U', K);

    set<pair<long long, long long>> candidate_coords;

    for (int i = 0; i < n; ++i) {
        // Solve the system for (A, B)
        // |A - K| + |B| = s_R
        // |A| + |B - K| = s_U
        
        // Summing the equations:
        // |A| + |A-K| + |B| + |B-K| = s_R + s_U
        // Let g(t) = |t| + |t-K|. Then g(A) + g(B) = s_R + s_U
        
        // Subtracting the equations:
        // |A-K| - |A| - (|B-K| - |B|) = s_R - s_U
        // Let h(t) = |t-K| - |t|. Then h(A) - h(B) = s_R - s_U
        
        // From h(A) - h(B) = s_R - s_U, we can find candidate pairs (A,B).
        // Since h(t) is piecewise linear/constant, we can find B from A.
        // B = K - (s_R + s_U - |A| - |A - K|)/2
        // A = K - (s_R + s_U - |B| - |B - K|)/2

        long long A1 = (s_R - s_U + K) / 2;
        long long B1 = s_R - abs(A1 - K);
        candidate_coords.insert({anchors[i].x - A1, anchors[i].y - B1});
        candidate_coords.insert({anchors[i].x - A1, anchors[i].y + B1});
        
        long long B2 = (s_U - s_R + K) / 2;
        long long A2 = s_U - abs(B2 - K);
        candidate_coords.insert({anchors[i].x - A2, anchors[i].y - B2});
        candidate_coords.insert({anchors[i].x + A2, anchors[i].y - B2});
        
        // A direct solve gives two pairs of solutions for (A, B)
        long long A_sol1 = (s_R - s_U + K);
        long long B_sol1 = (s_R + s_U - K);
        if (A_sol1 % 2 == 0 && B_sol1 % 2 == 0) {
            long long cur_A = A_sol1 / 2;
            long long cur_B = B_sol1 / 2 - abs(cur_A - K);
             candidate_coords.insert({anchors[i].x - cur_A, anchors[i].y - cur_B});
        }

        long long A_sol2 = (s_R + s_U - K);
        long long B_sol2 = (s_U - s_R + K);
        if (A_sol2 % 2 == 0 && B_sol2 % 2 == 0) {
             long long cur_A = A_sol2 / 2 - abs(B_sol2/2 - K);
             long long cur_B = B_sol2 / 2;
             candidate_coords.insert({anchors[i].x - cur_A, anchors[i].y - cur_B});
        }
    }

    for (auto const& p : candidate_coords) {
        Point candidate = {p.first, p.second};
        if (candidate.x < -K || candidate.x > K || candidate.y < -K || candidate.y > K) continue;

        long long s_R_check = -1, s_U_check = -1;

        // Check s_R
        long long min_dist_R = -1;
        Point moved_R = {candidate.x + K, candidate.y};
        for (const auto& anchor : anchors) {
            long long d = manhattan(anchor, moved_R);
            if (min_dist_R == -1 || d < min_dist_R) {
                min_dist_R = d;
            }
        }
        s_R_check = min_dist_R;
        
        // Check s_U
        long long min_dist_U = -1;
        Point moved_U = {candidate.x, candidate.y + K};
        for (const auto& anchor : anchors) {
            long long d = manhattan(anchor, moved_U);
            if (min_dist_U == -1 || d < min_dist_U) {
                min_dist_U = d;
            }
        }
        s_U_check = min_dist_U;

        if (s_R_check == s_R && s_U_check == s_U) {
            cout << "! " << candidate.x << " " << candidate.y << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUint);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
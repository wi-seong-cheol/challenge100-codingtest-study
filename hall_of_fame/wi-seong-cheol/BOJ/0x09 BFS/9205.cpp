//
//  9205.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 7/26/24.
//

/*
 [Input]
 2
 2
 0 0
 1000 0
 1000 1000
 2000 1000
 2
 0 0
 1000 0
 2000 1000
 2000 2000
 [Output]
 happy
 sad
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 500,000
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/9205

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
#define Point pair<int, int>
#define X first
#define Y second
int n;
vector<Point> stores;
vector<bool> vis;
Point ST, EN;

bool inside(Point a, Point b) {
    return abs(a.X - b.X) + abs(a.Y - b.Y) <= 1000;
}

bool bfs() {
    queue<Point> Q;
    Q.push(ST);

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if(inside(cur, EN)) return true;
        for(int i = 0; i < int(stores.size()); i++) {
            if(vis[i]) continue;
            if(inside(cur, stores[i])) {
                vis[i] = true;
                Q.push(stores[i]);
            }
        }
    }

    return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        stores.clear();
        vis = vector<bool>(n, false);
        cin >> ST.X >> ST.Y;
        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            stores.push_back({x, y});
        }
        cin >> EN.X >> EN.Y;
        if(bfs()) cout << "happy\n";
        else cout << "sad\n";
    }

	return 0;
}

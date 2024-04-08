//
//  16946.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 4/8/24.
//

/*
 [Input]
 3 3
 101
 010
 101
 [Output]
 303
 050
 303
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,000,000
// 난이도: Gold 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/16946

#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define X first
#define Y second
int n, m;
unordered_map<int, int> group;
string board[1001];
int res[1001][1001];
int chk[1001][1001];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(int x, int y, int group_num) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    chk[x][y] = group_num;
    int cnt = 1;

    while(!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == '1') continue;
            if(chk[nx][ny] != 0) continue;
            chk[nx][ny] = group_num;
            Q.push({nx, ny});
            cnt++;
        }
    }

    return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int id = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '1' || chk[i][j] != 0) continue;
            int cnt = bfs(i, j, id);
            group[id] = cnt;
            id++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '0') continue;
            int sum = 1;
            unordered_set<int> group_sum;

            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(OOB(nx, ny) || board[nx][ny] == '1') continue;
                group_sum.insert(chk[nx][ny]);
            }

            for(auto key: group_sum) {
                sum += group[key];
            }
            res[i][j] = sum % 10;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }

	return 0;
}

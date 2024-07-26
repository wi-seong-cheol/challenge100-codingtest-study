//
//  14444.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 4/4/24.
//

/*
 [Input]
 abab
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14444

#include <iostream>
#include <algorithm>

using namespace std;
int p[100001];
string s;

void manacher(string s) {
    int r = 0;
    int c = 0;
    int len = int(s.size());

    for(int i = 0; i < len; i++) {
        if(i <= r) {
            p[i] = min(p[2 * c - i], r - i);
        } else {
            p[i] = 0;
        }
        while(i - p[i] - 1 >= 0 &&
              i + p[i] + 1 < len &&
              s[i - p[i] - 1] == s[i + p[i] + 1]) {
            p[i]++;
        }
        if(r < i + p[i]) {
            r = i + p[i];
            c = i;
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> s;
    string text = "#";
    for(char ch: s) {
        text += ch;
        text += "#";
    }
    manacher(text);
    int answer = 0;
    for(int i = 0; i < text.size(); i++) {
        answer = max(answer, p[i]);
    }
    cout << answer;

	return 0;
}

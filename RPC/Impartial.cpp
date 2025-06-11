#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool solve(const string& a, string s, string t) {
    if (t.length() < s.length()) {
        swap(s, t);
    }

    queue<string> q;
    q.push(t);

    int maxSteps = s.length() + t.length();
    for (int step = 0; step < maxSteps; ++step) {
        string word = q.front();
        q.pop();

        string curr = word + word;
        int cntS = 0, cntT = 0;

        for (size_t i = 0; i < word.length(); ++i) {
            if (i + t.length() <= curr.length() && curr.substr(i, t.length()) == t)
                cntT++;
            if (i + s.length() <= curr.length() && curr.substr(i, s.length()) == s)
                cntS++;
        }

        if (cntT > cntS)
            return false;

        for (char c : a) {
            q.push(c + word);
        }
    }

    return true;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        string a, s, t;
        cin >> a >> s >> t;
        cout << solve(a, s, t) << endl;
    }
    return 0;
}
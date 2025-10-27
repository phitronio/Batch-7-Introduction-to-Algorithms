#include <bits/stdc++.h>
using namespace std;

string s1, s2;

string LCS(int i, int j) {
    if (i == s1.size() || j == s2.size()) return "";


    if (s1[i] == s2[j]) {
        return s1[i] + LCS(i+1, j+1);
    } else {
        string skip1 = LCS(i+1, j);
        string skip2 = LCS(i, j+1);
        return (skip1.size() >= skip2.size()) ? skip1 : skip2;
    }
}

int main() {
    cin >> s1 >> s2;
    string lcs = LCS(0, 0);
    cout << "LCS length: " << lcs.size() << "\n";
    cout << "LCS: " << lcs << "\n";
    return 0;
}

// Verified: https://leetcode.com/problems/longest-palindromic-substring/

string preprocess(const string &s, char sep = '#') {
    string t(2 * s.length() + 1, sep);
    for (int i = 0; i < s.length(); i++)
        t[2 * i + 1] = s[i];
    return t;
}
vector<int> manacher(const string &s) {
    int n = s.length();
    vector<int> p(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int k = i > r ? 0 : min(p[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
            k++;
        p[i] = --k;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return p;
}
string getPalindrome(const string &s, int i, int p) {
    return s.substr((i - p) / 2, p);
}
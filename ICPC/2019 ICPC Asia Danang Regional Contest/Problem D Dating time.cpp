#include<bits/stdc++.h>
using namespace std;

auto parseTime(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    return make_pair(hour, minute);
}

double angle(int h, int m) {
    h %= 12;
    double ha = (h + m / 60.0) * 2.0 / 12.0;
    double ma = m * 2.0 / 60.0;
    return ma - ha;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string start, end;
        cin >> start >> end;
        double alpha;
        cin >> alpha;
        alpha /= 180.0;
        int h1, m1, h2, m2;
        tie(h1, m1) = parseTime(start);
        tie(h2, m2) = parseTime(end);
        int res = 0;
        vector<double> a;
        if (alpha == 0) {
            a = {0};
        } else if (alpha == 1) {
            a = {1, -1};
        } else {
            a = {alpha, -alpha, 2 - alpha, -(2 - alpha)};
        }
        double pre = angle(h1, m1);
        for (double x: a) 
            if (abs(pre - x) < 1e-6) 
                res++;
        while (h1 < h2 || (h1 == h2 && m1 < m2)){
            m1++;
            if (m1 == 60) {
                m1 = 0;
                h1++;
            }
            double cur = angle(h1, m1);
            for (double x : a) {
                if (pre < x && x < cur) 
                    res++;
                if (abs(x - cur) < 1e-6)
                    res++;
            }
            pre = cur;
        }
        cout << res << endl;
    }
    return 0;
}
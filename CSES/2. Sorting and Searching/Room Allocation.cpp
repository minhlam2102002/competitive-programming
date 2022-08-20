/*
    author: Minh Lam
    version: 1.0.2
*/

#include<bits/stdc++.h>
using namespace std;

#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl;
#define debugv(v) cerr << __LINE__ << ": " << #v << " = "; for (auto &i: v) cerr << i << " "; cerr << endl;
#define readv(v) for(auto &e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define forEach(e, v) for (auto &e : v) 
#define forIndex(i, v) for (int i = 0; i < (int)v.size(); i++)
#define endl "\n"

using ll = long long;
using str = string;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;

const int MAXN = 1e5 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

struct Customer{
    int start, finish, id;
    bool operator<(const Customer &other) const{
        if(start != other.start) return start < other.start;
        return finish < other.finish;
    }
};


void solve() {
    int n; cin >> n;
    vector<Customer> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].start >> customers[i].finish;
        customers[i].id = i;
    }
    sort(all(customers));
	priority_queue<pii, vector<pii>, greater<pii>> pq;
    int rooms = 0, lastRoom = 0;
    vi res(n);
    forEach(customer, customers) {
        if (pq.empty()) {
            lastRoom++;
            pq.push({customer.finish, lastRoom});
            res[customer.id] = lastRoom;
        } else {
            pii minn = pq.top();
            if (minn.first >= customer.start) {
                lastRoom++;
                pq.push({customer.finish, lastRoom});
                res[customer.id] = lastRoom;
            } else {
                pq.pop();
                pq.push({customer.finish, minn.second});
                res[customer.id] = minn.second;
            }
        }
        rooms = max(rooms, (int)pq.size());
    }
    cout << rooms << endl;
    forEach(e, res) cout << e << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    #endif

    int t = 1; 
    // int t; cin >> t;
    while (t--) {
        solve();
    }

    #ifndef ONLINE_JUDGE
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    #endif
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// Binary Exponentiation
// https://cp-algorithms.com/algebra/binary-exp.html
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long binpow(long long a, long long b, long long m) {
    // if m is prime, then caculate (a^(b mod(m-1))) % m instead of (a^b) % m due to Fermat's Little Theorem
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Sieve of Eratosthenes
void sieve(vector<bool> &is_prime, int n) {
    // Time complexity: O(n log log sqrt(n))
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) 
        if (is_prime[i]) 
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
}
vector<char> segmentedSieve(long long L, long long R) {
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0)
            return false;
    return true;
}

bool probablyPrimeFermat(int n, int iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpow(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) 
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

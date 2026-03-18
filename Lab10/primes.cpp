#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;
vll p;

void sieve(ll upperbound)
{
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < _sieve_size; ++i)
    if (bs[i])
    {
      for (ll j = i * i; j < _sieve_size; j += i)
        bs[j] = 0;
      p.push_back(i);
    }
}

bool isPrime(ll N)
{
  if (N < _sieve_size)
    return bs[N];
  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
    if (N % p[i] == 0)
      return false;
  return true;
}

vll primeFactors(ll N)
{
  vll factors;
  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
    while (N % p[i] == 0)
    {
      N /= p[i];
      factors.push_back(p[i]);
    }
  if (N != 1)
    factors.push_back(N);
  return factors;
}

int numPF(ll N)
{
  int ans = 0;
  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
    while (N % p[i] == 0)
    {
      N /= p[i];
      ++ans;
    }
  return ans + (N != 1);
}

int numDiffPF(ll N)
{
  int ans = 0;
  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
  {
    if (N % p[i] == 0)
      ++ans;
    while (N % p[i] == 0)
      N /= p[i];
  }
  if (N != 1)
    ++ans;
  return ans;
}

ll sumPF(ll N)
{
  ll ans = 0;
  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
    while (N % p[i] == 0)
    {
      N /= p[i];
      ans += p[i];
    }
  if (N != 1)
    ans += N;
  return ans;
}

int numDiv(ll N)
{
  int ans = 1;
  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
  {
    int power = 0;
    while (N % p[i] == 0)
    {
      N /= p[i];
      ++power;
    }
    ans *= (power + 1);
  }
  return (N != 1) ? ans * 2 : ans;
}

ll sumDiv(ll N)
{
  ll ans = 1;
  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
  {
    ll multiplier = p[i], total = 1;
    while (N % p[i] == 0)
    {
      N /= p[i];
      total += multiplier;
      multiplier *= p[i];
    }
    ans *= total;
  }
  if (N != 1)
    ans *= (N + 1);
  return ans;
}

ll EulerPhi(ll N)
{
  ll ans = N;
  for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
  {
    if (N % p[i] == 0)
      ans -= ans / p[i];
    while (N % p[i] == 0)
      N /= p[i];
  }
  if (N != 1)
    ans -= ans / N;
  return ans;
}

int main()
{
  sieve(10000000);

  printf("%lld\n", p.back());

  for (ll i = p.back() + 1;; ++i)
    if (isPrime(i))
    {
      printf("Next prime: %lld\n", i);
      break;
    }

  printf("%d\n", isPrime((1LL << 31) - 1));
  printf("%d\n", isPrime(136117223861LL));
  printf("\n");

  vll r;

  r = primeFactors((1LL << 31) - 1);
  printf("%lld\n", (1LL << 31) - 1);
  for (auto &pf : r)
    printf("> %lld\n", pf);
  printf("\n");

  r = primeFactors(136117223861LL);
  printf("%lld\n", 136117223861LL);
  for (auto &pf : r)
    printf("> %lld\n", pf);
  printf("\n");

  r = primeFactors(142391208960LL);
  printf("%lld\n", 142391208960LL);
  for (auto &pf : r)
    printf("> %lld\n", pf);
  printf("\n");

  printf("numPF(60) = %d\n", numPF(60));
  printf("numDiffPF(60) = %d\n", numDiffPF(60));
  printf("sumPF(60) = %lld\n", sumPF(60));
  printf("numDiv(60) = %d\n", numDiv(60));
  printf("sumDiv(60) = %lld\n", sumDiv(60));
  printf("EulerPhi(36) = %lld\n", EulerPhi(36));

  return 0;
}
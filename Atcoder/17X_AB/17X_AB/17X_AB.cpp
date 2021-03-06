﻿#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long int, long long int> P;

void abc_170a();
void abc_171a();
void abc_172a();
void abc_173a();
void abc_174a();
void abc_175a();

void abc_170b();
void abc_171b();
void abc_172b();
void abc_173b();
void abc_174b();
void abc_175b();

int main()
{
  //abc_170a();
  //abc_171a();
  //abc_172a();
  //abc_173a();
  //abc_174a();
  //abc_175a();

  //abc_170b();
  //abc_171b();
  //abc_172b();
  //abc_173b();
  //abc_174b();
  abc_175b();

}

void abc_170a()
{
  vector<int> x(5);
  for (int i = 0; i < 5; ++i) cin >> x[i];

  for (int i = 0; i < 5; ++i)
  {
    if (x[i] == 0)
    {
      cout << i + 1 << "\n";
      return;
    }
  }
}

void abc_171a()
{
  char c;
  cin >> c;

  if (c == tolower(c)) cout << "a\n";
  else cout << "A\n";
}

void abc_172a()
{
  int a;
  cin >> a;

  cout << a + a * a + a * a * a << "\n";
}

void abc_173a()
{
  int N;
  cin >> N;

  if (N % 1000) cout << 1000 - N % 1000 << "\n";
  else cout << "0\n";
}

void abc_174a()
{
  int x;
  cin >> x;

  if (x >= 30) cout << "Yes\n";
  else cout << "No\n";
}

void abc_175a()
{
  string s;
  cin >> s;

  int cnt = 0, tmp = 0;
  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] == 'S')
    {
      tmp = 0;
    }
    else
    {
      ++tmp;
      cnt = tmp;
    }
  }

  cout << cnt << "\n";
}


void abc_170b()
{
  int x, y;
  cin >> x >> y;

  for (int i = 0; i <= x; ++i)
  {
    int n_c = i, n_t = x - i;
    if (n_c * 2 + n_t * 4 == y)
    {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}

void abc_171b()
{
  int N, K;
  cin >> N >> K;
  vector<int> p(N);
  for (int i = 0; i < N; ++i) cin >> p[i];

  sort(p.begin(), p.end());

  int price = 0;
  for (int i = 0; i < K; ++i)
  {
    price += p[i];
  }
  cout << price << "\n";
}

void abc_172b()
{
  string s, t;
  cin >> s >> t;

  int cnt = 0;
  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] != t[i]) ++cnt;
  }

  cout << cnt << "\n";
}

void abc_173b()
{
  int N;
  cin >> N;

  int n_ac = 0, n_wa = 0, n_tle = 0, n_re = 0;
  for (int i = 0; i < N; ++i)
  {
    string s;
    cin >> s;

    if (s == "AC") ++n_ac;
    else if (s == "WA") ++n_wa;
    else if (s == "TLE") ++n_tle;
    else ++n_re;
  }

  cout << "AC x " << n_ac << "\n";
  cout << "WA x " << n_wa << "\n";
  cout << "TLE x " << n_tle << "\n";
  cout << "RE x " << n_re << "\n";
}

void abc_174b()
{
  long long int N, D;
  cin >> N >> D;
  vector<P> xy(N);
  for (int i = 0; i < N; ++i) cin >> xy[i].first >> xy[i].second;

  int cnt = 0;
  for (int i = 0; i < N; ++i)
  {
    if (xy[i].first * xy[i].first + xy[i].second * xy[i].second <= D * D) ++cnt;
  }
  cout << cnt << "\n";
}

void abc_175b()
{
  int N;
  cin >> N;
  vector<int> l(N);
  for (int i = 0; i < N; ++i) cin >> l[i] ;

  sort(l.begin(), l.end());

  for (int i = 0; i < N; ++i) cout << l[i] << " ";
  cout << "\n";

  int cnt = 0;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      for (int k = 0; k < j; ++k)
      {
        if (l[i] != l[j] && l[j] != l[k] && l[j] + l[k] > l[i])
        {
          ++cnt;
          cout << l[i] << " " << l[j] << " " << l[k] << "\n";
        }
      }
    }
  }
  cout << cnt << "\n";


  //vector<int> vec(N);
  //for (int i = 0; i < N; ++i) cin >> vec[i];
  //sort(vec.begin(), vec.end());

  //int ans = 0;

  //for (int i = 0; i < N; ++i) {
  //  for (int j = 0; j < i; ++j) {
  //    for (int k = 0; k < j; ++k) {
  //      if (vec[k] != vec[j] && vec[i] != vec[j] &&
  //        vec[k] + vec[j] > vec[i]) {
  //        ans++;
  //        cout << vec[i] << " " << vec[j] << " " << vec[k] << "\n";

  //      }
  //    }
  //  }
  //}
  //cout << ans << "\n";

}

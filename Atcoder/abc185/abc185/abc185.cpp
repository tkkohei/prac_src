#include <iostream>
#include <vector>

using namespace std;

void A()
{
  vector<int> a(4);
  for (int i = 0; i < 4; ++i) cin >> a[i];
  
  int t_min = a[0];
  for (int i = 0; i < 4; ++i)
    if (t_min > a[i]) t_min = a[i];
  cout << t_min << "\n";
}

void B()
{
  int N, m, t; cin >> N >> m >> t;
  vector<pair<int, int>> tt(m + 1);
  tt[0].first = 0, tt[0].second = 0;
  for (int i = 1; i < tt.size(); ++i) cin >> tt[i].first >> tt[i].second;

  int n = N;
  for (int i = 1; i < tt.size(); ++i)
  {
    n -= tt[i].first - tt[i - 1].second;
    if (n <= 0)
    {
      cout << "No\n";
      return;
    }
    n += tt[i].second - tt[i].first;
    if (n > N) n = N;
  }
  if (n - (t - tt[tt.size() - 1].second) <= 0)
  {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
}

long long int fuctorial(int n)
{
  long long int fuct = 1;
  for (int i = 1; i <= n; ++i) fuct *= i;
  return fuct;
}


long long int comb(int n, int k)
{
  return fuctorial(n) / (fuctorial(n - k) * fuctorial(k));
}

void C()
{
  int L; cin >> L;

  cout << comb(L - 1, L - 12) << "\n";
}

long long int comb_chi(long long int n, long long int k)
{
  if (k == 0) return 1;
  return (n * comb_chi(n - 1, k - 1)) / k;
}

void C2()
{
  int L; cin >> L;

  if (L < 12)
  {
    cout << 0 << "\n";
    return;
  }
  cout << comb_chi(static_cast<long long int>(L - 1), static_cast<long long int>(11)) << "\n";
}

int main()
{
  //A();
  //B();
  //C(); //オーバーフローしてしまう
  C2();
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

void D()
{
  int N, M; cin >> N >> M;
  if (M == 0)
  {
    cout << "\n";
    return;
  }
  vector<int> A(M);
  for (int i = 0; i < A.size(); ++i) cin >> A[i];
  sort(A.begin(), A.end());

  int t_min;
  if (A[0] != 1) t_min = A[0] - 1;
  else           t_min = A[1] - A[0] - 1;
  for (int i = 1; i < A.size(); ++i)
  {
    if (t_min > A[i] - A[i - 1]) t_min = A[i] - A[i - 1] - 1;
    if (t_min <= 0)
    {
      cout << 0 << "\n";
      return;
    }
  }
  if (A[A.size() - 1] != N && t_min > N - A[A.size() - 1]) t_min = N - A[A.size() - 1];

  int cnt = 0;
  if (A[0] != 1) cnt += ceil((A[0] - 1) / (float)t_min);
  for (int i = 1; i < A.size(); ++i)
  {
    cnt += ceil(((A[i] - A[i - 1] - 1) / (float)t_min));
  }
  if (A[A.size() - 1] != N) cnt += ceil((N - A[A.size() - 1]) / (float)t_min);

  cout << cnt <<"\n";
}

int main()
{
  //A();
  //B();
  //C(); //オーバーフローしてしまう
  //C2();
  D();
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void A()
{
  int n, w;
  cin >> n >> w;
  cout << n / w << "\n";
}

void B()
{
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; ++i)
  {
    for (int j = 0; j < w; ++j)
    {
      cin >> a[i][j];
    }
  }
  int t_min = 100;
  for (int i = 0; i < h; ++i) 
    for (int j = 0; j < w; ++j)
      if (t_min > a[i][j]) t_min = a[i][j];

  int v_sum = 0;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      v_sum += a[i][j] - t_min;

  cout << v_sum << "\n";

}

string int_to_string(int n, int base)
{
  string s;
  while (n) 
  {
    s = to_string(n % base) + s;
    n /= base;
  }
  return s;
}

bool in_7(string num_str)
{
  for (int i = 0; i < num_str.size(); ++i)
    if (num_str[i] == '7') return true;
  return false;
}

void C()
{
  int n;
  cin >> n;

  int v_sum = 0;
  for (int i = 0; i < n; ++i)
  {
    if (in_7(int_to_string(i + 1, 10)) || in_7(int_to_string(i + 1, 8)))
      continue;
    ++v_sum;
  }
  cout << v_sum << "\n";
}

bool check_in_7(int n, int base)
{
  while (n)
  {
    int digit = n % base;
    if (digit == 7) return true;
    n /= base;
  }
  return false;
}

void C2()
{
  int n;
  cin >> n;

  int v_sum = 0;
  for (int i = 0; i < n; ++i)
  {
    if (check_in_7(i + 1, 10) || check_in_7(i + 1, 8)) continue;
    ++v_sum;
  }
  cout << v_sum << "\n";
}

void D()// O(N^2)
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  long long int v_sum = 0;
  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j)
      v_sum += abs(a[i] - a[j]);
  cout << v_sum << "\n";
}


void D2()//O(NlogN)
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  long long int v_sum = 0, cum_sum = 0;
  for (int j = 0; j < n; ++j)
  {
    v_sum += static_cast<long long int>(a[j]) * j - cum_sum;
    cum_sum += a[j];
  }
  cout << v_sum << "\n";
}


int main()
{
  //A();
  //B();
  //C();
  //C2();
  //D();
  D2();
}

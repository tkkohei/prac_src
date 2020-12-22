#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
再帰関数での全探索
bit全探索(2^n通り)
*/

void many_equals();

void train_ticket();

void all_green();

void takahashi_meat();

int main()
{
  //many_equals();
  //train_ticket();
  //all_green();
  takahashi_meat();
}


void many_equals()
{
  string S;
  cin >> S;
  vector<int> a(S.size());

  for (int i = 0; i < S.size(); ++i)
  {
    a[i] = S[i] - '0';
  }

  cout << (1 << (S.size() - 1)) << "\n";;

  long long int n_sum = 0;
  for (int i = 0; i < 1 << (S.size() - 1); ++i)
  {
    //cout << i << "\n";
    long long int tmp = a[0];
    for (int p = 0; p < S.size() - 1; ++p)
    {
      //p left shift先にあれば
      if (i & 1 << p)
      {
        n_sum += tmp;
        tmp = a[p + 1];
      }
      else
      {
        tmp = tmp * 10 + a[p + 1];
      }
    }
    n_sum += tmp;
  }

  cout << n_sum << "\n";
}

void train_ticket()
{
  string abcd;
  cin >> abcd;
  vector<int> a(abcd.size());
  for (int i = 0; i < abcd.size(); ++i)
  {
    a[i] = abcd[i] - '0';
  }

  vector<char> sign(3);

  for (int i = 0; i < 1 << (abcd.size() - 1); ++i)
  {
    int v_sum = a[0];
    for (int j = 0; j < abcd.size() - 1; ++j)
    {
      if (i & 1 << j)
      {
        v_sum += a[j + 1];
        sign[j] = '+';
      }
      else
      {
        v_sum -= a[j + 1];
        sign[j] = '-';
      }
    }
    //iの位置は+,それ以外は-を行う判定
    if (v_sum == 7)
    {
      for (int k = 0; k < 3; ++k)
      {
        cout << abcd[k] << sign[k];
      }
      cout << abcd[3] << "=7\n";

      return;
    }
  }
}

void all_green()
{
  int D, G;
  cin >> D >> G;
  vector<pair<int, int>> p_c(D);
  for (int i = 0; i < p_c.size(); ++i)
  {
    cin >> p_c[i].first >> p_c[i].second;
  }

  int ans = INT_MAX;
  for (int bit = 0; bit < (1 << p_c.size()); ++bit)
  {
    int s = 0, cnt = 0, rest_max = -1;
    for (int i = 0; i < p_c.size(); ++i)
    {
      if (bit & 1 << i)
      {
        s += 100 * (i + 1) * p_c[i].first + p_c[i].second;
        cnt += p_c[i].first;
      }
      else
      {
        rest_max = i;
      }
    }

    if (s < G)
    {
      int s1 = 100 * (rest_max + 1);
      // ピッタリの個数ずらし
      int need = (G - s - 1) / s1 + 1;
      if (need >= p_c[rest_max].first) continue;
      cnt += need;
    }
    ans = min(ans, cnt);
  }
  cout << ans << "\n";
}


//この解法はbit探索せず解答できた
void takahashi_meat()
{
  int N;
  cin >> N;
  vector<int> t(N);
  for (int i = 0; i < N; ++i) cin >> t[i];

  sort(t.begin(), t.end(), greater<>());
  int m1 = 0, m2 = 0;
  for (int i = 0; i < N; ++i)
  {
    if (m1 <= m2) m1 += t[i];
    else          m2 += t[i];
  }
  cout << max(m1, m2) << "\n";
}
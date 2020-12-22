#include <iostream>
#include <vector>

using namespace std;

void abc_150a();

void abc_151a();

void abc_152a();

void abc_154a();

void abc_156a();

void abc_157a();

void abc_158a();

void abc_159a();

int main()
{
  //abc_150a();
  //abc_151a();
  //abc_152a();
  //abc_154a();
  //abc_156a();
  //abc_157a();
  //abc_158a();
  abc_159a();
}

void abc_150a()
{
  int K, X;
  cin >> K >> X;

  if (500 * K >= X) cout << "Yes\n";
  else cout << "No\n";
}

void abc_151a()
{
  char C;
  cin >> C;

  cout << (char)((int)C + 1) << "\n";
}

void abc_152a()
{
  int N, M;
  cin >> N >> M;
  if (N == M) cout << "Yes\n";
  else cout << "No\n";
}

void abc_154a()
{
  string S, T;
  cin >> S >> T;
  int a, b;
  cin >> a >> b;
  string U;
  cin >> U;

  if (S == U) cout << a - 1 << " " << b << "\n";
  else cout << a << " " << b - 1 << "\n";

}


void abc_156a()
{
  int N, R;
  cin >> N >> R;

  if (N >= 10) cout << R << "\n";
  else cout << R + 100 * (10 - N) << "\n";
}

void abc_157a()
{
  int N;
  cin >> N;

  if (N % 2 == 0) cout << N / 2 << "\n";
  else cout << N / 2 + 1 << "\n";
}

void abc_158a()
{
  vector<char> s(3);
  for (int i = 0; i < 3; ++i) cin >> s[i];
  for (int i = 0; i < 3; ++i)
  {
    for (int j = i + 1; j < 3; ++j)
    {
      if (s[i] != s[j])
      {
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";

}

int combination2(int n)
{
  return n * (n - 1) / 2;
}

void abc_159a()
{
  int N, M;
  cin >> N >> M;

  cout << combination2(N) + combination2(M) << "\n";
}
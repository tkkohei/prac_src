#include <iostream>
#include <vector>

using namespace std;

void atc001_dfs(vector<vector<char>>& map, int H, int W, int x, int y, bool& is_root);
void solve_atc001();

void arc31_dfs(int row, int col, int H, int W, vector<vector<char>>& field_c);
void solve_arc031();

void arc037_dfs(int i, int N, vector<vector<bool>>& adj, vector<bool>& visited, bool& is_tree);
void solve_arc037();

int main()
{
  //solve_atc001();
  //solve_arc031();
  solve_arc037();
}

void atc001_dfs(vector<vector<char>>& map, int H, int W, int x, int y, bool& is_root)
{
  if (0 <= x && x < H &&
      0 <= y && y < W)
  {
    if (map[x][y] == 'g')
    {
      is_root = true;
      return;
    }
    else if (map[x][y] == '.' || map[x][y] == 's')
    {
      map[x][y] = '#';

      atc001_dfs(map, H, W, x - 1, y, is_root);
      atc001_dfs(map, H, W, x + 1, y, is_root);
      atc001_dfs(map, H, W, x, y - 1, is_root);
      atc001_dfs(map, H, W, x, y + 1, is_root);
    }
  }
}

void solve_atc001()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char>> c(H, vector<char>(W));
  pair<int, int> point;
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      cin >> c[i][j];
      if (c[i][j] == 's') point = make_pair(i, j);
    }
  }

  bool is_root = false;
  atc001_dfs(c, H, W, point.first, point.second, is_root);

  if (is_root) cout << "Yes\n";
  else         cout << "No\n";
}


void arc31_dfs(int row, int col, int H, int W, vector<vector<char>>& field_c)
{
  if (0 <= row && row < H && 0 <= col && col < W)
  {
    //cout << row << " " << col << "\n";

    if (field_c[row][col] == 'o')
    {
      field_c[row][col] = 'x';
      arc31_dfs(row - 1, col, H, W, field_c);
      arc31_dfs(row + 1, col, H, W, field_c);
      arc31_dfs(row, col - 1, H, W, field_c);
      arc31_dfs(row, col + 1, H, W, field_c);
    }
  }
  return;
}

void solve_arc031()
{
  const int H = 10, W = 10;
  vector<vector<char>> field(H, vector<char>(W));
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      cin >> field[i][j];
    }
  }

  bool can_connect = false;
  vector<vector<char>> field_copy(H, vector<char>(W));
  for (int row = 0; row < H; ++row)
  {
    //cout << "row " << row << "\n";
    for (int col = 0; col < W; ++col)
    {
      //cout << "col " << col << "\n";
      int cnt = 0;
      //copy作成
      for (int i = 0; i < H; ++i)
      {
        for (int j = 0; j < W; ++j)
        {
          field_copy[i][j] = field[i][j];
        }
      }
      //島が1つか探索
      if (field_copy[row][col] == 'x')
      {
        field_copy[row][col] = 'o';
        for (int i = 0; i < H; ++i)
        {
          for (int j = 0; j < W; ++j)
          {
            if (field_copy[i][j] == 'o')
            {
              arc31_dfs(i, j, H, W, field_copy);
              ++cnt;
            }
          }
        }
      }
      //島が1つか判定
      if (cnt == 1) can_connect = true;
    }
  }

  if (can_connect) cout << "YES\n";
  else             cout << "NO\n";
}


void arc037_dfs(int index, int N, vector<vector<bool>>& adj, vector<bool>& visited, bool& is_tree)
{
  visited[index] = true;
  //cout << "visited " << index + 1 << "\n";

  for (int i = 0; i < N; ++i)
  {
    if (adj[index][i] || adj[i][index])
    {
      //cout << "index, i " << index + 1 << " " << i + 1 << "\n";
      if (visited[i])
      {
        is_tree = false;
      }
      else
      {
        adj[index][i] = adj[i][index] = false;
        arc037_dfs(i, N, adj, visited, is_tree);
      }
    }
  }
}

void solve_arc037()
{
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> adj(N, vector<bool>(N));
  for (int i = 0; i < M; ++i)
  {
    int u, v;
    cin >> u >> v;
    adj[u - 1][v - 1] = adj[v - 1][u - 1] = true;
  }

  vector<bool> visited(N);
  int cnt = 0;
  for (int i = 0; i < N; ++i)
  {
    bool is_tree = true;
    if (!visited[i])
    {
      //cout << "original\n";
      arc037_dfs(i, N, adj, visited, is_tree);
      if (is_tree) ++cnt;
    }
  }
  cout << cnt << "\n";
}

/*
2 3
2 4
5 6
6 7
6 8
7 8
original
visited 1
index, i 1 2
visited 2
index, i 2 3
visited 3
index, i 2 4
visited 4
original
visited 5
index, i 5 6
visited 6
index, i 6 7
visited 7
index, i 7 8
visited 8
index, i 8 6
index, i 6 8
1
*/
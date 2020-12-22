#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <climits>

using namespace std;

const int INF = INT_MAX / 4;
typedef pair<int, int> P;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
//int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };


bool bubunwa(int i, int sum);
void solve_bubunwa();

void lake_counting(int x, int y);
void solve_lake_counting();

int breadth_first_search(int R, int C, 
                         int sx, int sy, 
                         int gx, int gy,
                         vector<vector<char>>& field,
                         vector<vector<int>>& dis);
void solve_BFS();

/*
int joi_2007e_bfs(int H, int W, char N, P s, P g, vector<vector<char>>& field);
void solve_joi_2007e();
*/


int abc088D_bfs(int H, int W, int cnt, P s, P g, vector<vector<char>>& field);
void solve_abc088D();



vector<int> a;
int n, k;

int m;
vector<vector<char>> field;


int main()
{
  //solve_bubunwa();
  //solve_lake_counting();
  //solve_BFS();
  //solve_joi_2007e();
  solve_abc088D();
}


////////////////////////////
bool bubunwa(int i, int sum)
{
  //cout << "i:" << i << ", sum:" << sum << "\n";
  //stop cond
  if (i == n) return sum == k;
  //branch1
  if (bubunwa(i + 1, sum)) return true;
  //branch2
  if (bubunwa(i + 1, sum + a[i])) return true;
  return false;
}
void solve_bubunwa()
{
  // n:num
  // k:goal value
  // a:numerical sequence
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  if (bubunwa(0, 0)) cout << "Yes\n";
  else cout << "No\n";
}
/*
4 13
1 2 10 11
i:0, sum:0
i:1, sum:0
i:2, sum:0
i:3, sum:0
i:4, sum:0
i:4, sum:11
i:3, sum:10
i:4, sum:10
i:4, sum:21
i:2, sum:2
i:3, sum:2
i:4, sum:2
i:4, sum:13
Yes
*/

/////////////////////////////
//https://wikiwiki.jp/pku/2386%20Lake%20Counting
void lake_counting(int x, int y)
{
  field[x][y] = '.';
  for (int dx = -1; dx <= 1; ++dx)
  {
    for (int dy = -1; dy <= 1; ++dy)
    {
      int nx = x + dx, ny = y + dy;
      if (0 <= nx && nx < n &&
        0 <= ny && ny < m &&
        field[nx][ny] == 'W')
      {
        lake_counting(nx, ny);
      }
    }
  }
}
void solve_lake_counting()
{
  cin >> n >> m;
  field.resize(n);
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      char c;
      cin >> c;
      field[i].push_back(c);
    }
  }

  int cnt = 0;
  for(int i =0;i<n;++i)
  {
    for (int j = 0; j < m; ++j) 
    {
      if (field[i][j] == 'W')
      {
        lake_counting(i, j);
        ++cnt;
      }
    }
  }

  cout << cnt << "\n";
}
/*
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
3
*/




int breadth_first_search(int R, int C, 
                         int sx, int sy, 
                         int gx, int gy,
                         vector<vector<char>>& field,
                         vector<vector<int>>& dis)
{
  queue<P> que;
  que.push(P(sx, sy));
  dis[sx][sy] = 0;

  while (que.size())
  {
    P p = que.front();
    que.pop();
    //ゴール到着時
    if (p.first == gx && p.second == gy) break;
    //4近傍探索
    for (int i = 0; i < 4; ++i)
    {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 <= nx && nx < R &&
          0 <= ny && ny < C &&
          field[nx][ny] != '#' &&
          dis[nx][ny] == INF)
      {
        //cout << nx << " " << ny << "\n";
        que.push(P(nx, ny));
        dis[nx][ny] = dis[p.first][p.second] + 1;
      }
    }
  }

  //cout << setw(10);
  //for (int i = 0; i < R; ++i)
  //{
  //  cout << "\n";
  //  for (int j = 0; j < C; ++j)
  //  {
  //    cout << setw(10) << dis[i][j] << " ";
  //  }
  //}
  //cout << "\n";

  return dis[gx][gy];
}


void solve_BFS()
{
  int R, C;
  cin >> R >> C;
  int sx, sy;
  cin >> sx >> sy;
  int gx, gy;
  cin >> gx >> gy;
  vector<vector<char>> field(R, vector<char>(C));
  for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
      cin >> field[i][j];
  vector<vector<int>> dis(R, vector<int>(C));
  for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
      dis[i][j] = INF;

  int n_turn = breadth_first_search(R, C, sx - 1, sy - 1, gx - 1, gy - 1, field, dis);
  cout << n_turn << "\n";
}


/*
7 8
2 2
4 5
########
#......#
#.######
#..#...#
#..##..#
##.....#
########
2 1
1 2
3 1
1 3
4 1
3 2
1 4
4 2
1 5
5 2
1 6
5 3
5 4
5 5
4 5
5 6
3 5
4 6
3 6
3 4

 536870911  536870911  536870911  536870911  536870911  536870911  536870911  536870911
 536870911          0          1          2          3          4          5  536870911
 536870911          1  536870911  536870911  536870911  536870911  536870911  536870911
 536870911          2          3  536870911         11         10         11  536870911
 536870911          3          4  536870911  536870911          9         10  536870911
 536870911  536870911          5          6          7          8          9  536870911
 536870911  536870911  536870911  536870911  536870911  536870911  536870911  536870911
11
*/

/*
int joi_2007e_bfs(int H, int W, char N, P s, P g, vector<vector<char>>& field)
{
  queue<P> que;
  vector<vector<int>> dis(H, vector<int>(W));
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
      dis[i][j] = INF;
  que.push(P(s.first, s.second));
  dis[s.first][s.second] = 0;

  int HP = 1;
  while (que.size())
  {
    P p = que.front();
    que.pop();
    if (HP == (int)N) return dis[p.first][p.second];
    for (int i = 0; i < 4; ++i)
    {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 <= nx && nx < H &&
        0 <= ny && ny < W &&
        field[nx][ny] != 'X' &&
        dis[nx][ny] == INF)
      {
        if (field[nx][ny] != '.' &&
            field[nx][ny] != 'S' &&
            (int)field[nx][ny] <= HP) ++HP;
        que.push(P(nx, ny));
        dis[nx][ny] = dis[p.first][p.second] + 1;
      }
    }
  }
  return 0;
}

void solve_joi_2007e()
{
  int H, W;
  char N;
  cin >> H >> W >> N;

  P s, g;
  vector<vector<char>> field(H, vector<char>(W));
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      cin >> field[i][j];
      if (field[i][j] == 'S')
      {
        s.first = i, s.second = j;
      }
      else if (field[i][j] == N)
      {
        g.first = i, g.second = j;
      }
    }
  }


  int n_time = joi_2007e_bfs(H, W, N, s, g, field);
  cout << n_time << "\n";
}
*/


int abc088D_bfs(int H, int W, int cnt, P s, P g, vector<vector<char>>& field)
{
  vector<vector<int>> dist(H, vector<int>(W));
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
      dist[i][j] = -1;
  queue<P> que;
  que.push(s);
  dist[s.first][s.second] = 1;
  
  while (que.size())
  {
    P p = que.front();
    que.pop();

    if (p.first == g.first && p.second == g.second)
      return H * W - (cnt + dist[g.first][g.second]);

    for (int i = 0; i < 4; ++i)
    {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 <= nx && nx < H &&
        0 <= ny && ny < W &&
        field[nx][ny] != '#' &&
        dist[nx][ny] == -1)
      {
        que.push(P(nx, ny));
        dist[nx][ny] = dist[p.first][p.second] + 1;
      }
    }
  }

  return -1;
}
void solve_abc088D()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char>> field(H, vector<char>(W));
  int cnt_prevent = 0;
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      cin >> field[i][j];
      if (field[i][j] == '#') ++cnt_prevent;
    }
  }
  P s = P(0, 0), g = P(H - 1, W - 1);
  
  int score = abc088D_bfs(H, W, cnt_prevent, s, g, field);
  cout << score << "\n";
}

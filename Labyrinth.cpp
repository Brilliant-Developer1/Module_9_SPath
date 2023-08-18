// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> adj;
int visited[N][N];
vector<pii> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int level[N][N];
pii parent[N][N];

int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> que;

    que.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!que.empty())
    {
        pii upair = que.front();
        int i = upair.first;
        int j = upair.second;
        que.pop();

        for (auto d : direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && adj[ni][nj] != '#')
            {
                que.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main()
{

    int si, sj, di, dj;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string u;
        cin >> u;
        for (int j = 0; j < m; j++)
        {
            if (u[j] == 'A')
                si = i, sj = j;
            if (u[j] == 'B')
                di = i, dj = j;
        }

        adj.push_back(u);
    }

    bfs(si, sj);

    cout << level[di][dj] << endl;

    return 0;
}

/*
5 8
########
#.A#...#
#.##.#B#
#......#
########


YES
9
LDDRRRRRU
*/
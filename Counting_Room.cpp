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
//

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 10;
vector<string> adj;
int visited[N][N];
vector<pii> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int n, m;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int i, int j)
{

    if (!isValid(i, j))
        return;
    if (visited[i][j])
        return;
    if (adj[i][j] == '#')
        return;

    visited[i][j] = true;

    for (auto d : direction)
    {
        dfs(i + d.first, j + d.second);
    }
    // dfs(i, j - 1);
    // dfs(i, j + 1);
    // dfs(i - 1, j);
    // dfs(i + 1, j);
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string u;
        cin >> u;

        adj.push_back(u);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j] == '#')
                continue;
            if (visited[i][j])
                continue;
            dfs(i, j);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}

/*
5 8
########
#..#...#
####.#.#
#..#...#
########



3
*/
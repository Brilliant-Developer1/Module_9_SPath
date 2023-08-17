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

const int N = 1e5 + 10;
vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> level(N, 0);

void bfs(int s)
{
    queue<int> que;
    que.push(s);
    level[s] = 0;
    visited[s] = true;

    while (!que.empty())
    {
        int u = que.front();
        que.pop();

        for (int v : adj[u])
        {

            if (visited[v] == true)
                continue;
            que.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); // weited hole

        adj[v].push_back(u); // weited hole
    }

    bfs(1);
    cout << level[n] << endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Level of " << i << ": " << level[i] << endl;
    // }
    return 0;
}
/*


*/
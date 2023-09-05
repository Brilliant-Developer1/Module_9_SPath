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
#include <queue>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s)
{
    queue<int> que;

    que.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;

    while (!que.empty())
    {
        int u = que.front();
        que.pop();

        // section 1 A node is being processed
        // working as lavel order
        // cout << "Node: " << u << endl;

        for (int v : adj[u])
        {
            // section 2 : child processing
            if (visited[v] == true)
                continue;
            que.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
            // section 3 : child processing
        }
        // section 4 same as section 1
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

    int s, d;
    cin >> s >> d;

    // O(n+m)
    bfs(s);

    cout << "Distance: " << level[d] << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "ParentOf: " << i << " " << parent[i] << endl;
    // }

    // Path finding O(n)
    vector<int> path;
    int curr = d;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}
/*
7 7
1 2
1 3
3 4
4 6
2 5
5 6
5 7
1
7


Distance: 3
Path: 1 2 5 7

*/
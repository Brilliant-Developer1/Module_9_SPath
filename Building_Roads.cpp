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

const int N = 1e5 + 5;
vector<int> adj[N]; // unweited er jonno
vector<bool> visited(N, false);

void dfs(int u)
{
    visited[u] = true;

    for (int v : adj[u])
    {

        if (visited[v])
            continue;
        dfs(v);
    }
}
int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v;

        adj[u].push_back(v); // weited hole

        adj[v].push_back(u); // weited hole
    }

    vector<int> leaders;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        leaders.push_back(i);
        dfs(i);
    }

    cout << leaders.size() - 1 << endl;
    for (int i = 1; i < leaders.size(); i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }

    return 0;
}

/*
8
4
1 2
3 4
5 6
5 7



3
1 3
3 5
5 8
*/
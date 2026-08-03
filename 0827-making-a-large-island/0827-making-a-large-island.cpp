class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }

    int size(int x) {
        return sz[find(x)];
    }
};

class Solution {
public:
    vector<pair<int,int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        DSU dsu(n * n);

        auto id = [&](int i, int j) {
            return i * n + j;
        };

        // Build islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0)
                    continue;

                // right
                if (j + 1 < n && grid[i][j + 1] == 1)
                    dsu.unite(id(i,j), id(i,j+1));

                // down
                if (i + 1 < n && grid[i + 1][j] == 1)
                    dsu.unite(id(i,j), id(i+1,j));
            }
        }

        int ans = 0;
        bool hasZero = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    ans = max(ans, dsu.size(id(i,j)));
                    continue;
                }

                hasZero = true;

                unordered_set<int> roots;
                int area = 1;

                for (auto d : dir) {

                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni < 0 || nj < 0 || ni >= n || nj >= n)
                        continue;

                    if (grid[ni][nj] == 0)
                        continue;

                    int root = dsu.find(id(ni,nj));

                    if (roots.insert(root).second)
                        area += dsu.sz[root];
                }

                ans = max(ans, area);
            }
        }

        return hasZero ? ans : n * n;
    }
};
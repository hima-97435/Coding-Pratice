class DSU {
public:
    vector<int> Parent, Size;

    DSU(int n) {
        Parent.resize(n + 1);
        Size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
        }
    }

    int find(int node) {
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] >= Size[pv]) {
            Size[pu] += Size[pv];
            Parent[pv] = pu;
        } else {
            Size[pv] += Size[pu];
            Parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int N = ROWS * COLS;
        DSU dsu(N);
        vector<int> directions = {0, 1, 0, -1, 0};
        int land = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 0) continue;
                land++;
                for (int d = 0; d < 4; d++) {
                    int nr = r + directions[d], nc = c + directions[d + 1];
                    if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS) {
                        if (grid[nr][nc] == 1) {
                            dsu.unionSets(r * COLS + c, nr * COLS + nc);
                        }
                    } else {
                        dsu.unionSets(N, r * COLS + c);
                    }
                }
            }
        }

        int borderLand = dsu.Size[dsu.find(N)];
        return land - borderLand + 1;
    }
};
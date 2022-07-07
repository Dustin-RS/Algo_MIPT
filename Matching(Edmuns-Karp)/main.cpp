#include <iostream>
#include <inttypes.h>
#include <vector>

class Kuhn {
public:
    Kuhn(int32_t n, int32_t m) {
        gr.resize(n + 1);
        right.assign(n+ m + 1, -1);
        used.assign(n + 1, false);
    }

    bool dfs(int32_t v) {
        if (used[v]) {
            return false;
        }
        used[v] = true;
        for (auto vert : gr[v]) {
            if (right[vert] == -1 || dfs(right[vert])) {
                right[vert] = v;
                right[v] = vert;
                return true;
            }
        }
        return false;
    }

    std::vector<std::vector<int32_t>> gr;
    std::vector<bool> used;
    std::vector<int32_t> right;
};

int32_t main() {
    int32_t n;
    int32_t m;
    std::cin >> n >> m;
    class Kuhn kh(n, m);
    for (int32_t i = 1; i <= n; ++i) {
        int32_t vert;
        while (true) {
            std::cin >> vert;
            if (vert == 0) {
                break;
            }
            kh.gr[i].push_back(vert+n);
        }
    }

    for (int32_t i = 1; i <= n; ++i) {
        kh.dfs(i);
        kh.used.assign(n + 1, false);
    }
    int32_t sz = 0;
    for (int32_t i = 1; i <= n ; ++i) {
        if (kh.right[i] != -1) {
            ++sz;
        }
    }
    std::cout << sz << std::endl;
    for (int32_t i = 1; i <= n; ++i) {
        if (kh.right[i] != -1) {
            std::cout << i <<" "<< kh.right[i] - n << " " << std::endl;
        }
    }
    return 0;
}


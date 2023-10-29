#include <ZhangShasha.h>

int min(int a, int b, int c);

int ZhangShasha::ted(const Tree& t1, const Tree& t2) {
    int n = t1.n;
    int m = t2.n;

    std::vector<int> t1_keyroots = t1.keyroots_r();
    std::vector<int> t2_keyroots = t2.keyroots_r();

    std::vector<int> t1_rightmost = t1.rightmost();
    std::vector<int> t2_rightmost = t2.rightmost();

    // use tabulation for computing tree edit distance - TED
    std::vector<std::vector<int>> td(n, std::vector<int>(m));
    // use tabulation for computing forest edit distance - FED
    std::vector<std::vector<int>> fd(n + 1, std::vector<int>(m + 1));

    // TODO: why is this not working?
    for (int k = t1_keyroots.size() - 1; k >= 1; --k) {
        for (int l = t2_keyroots.size() - 1; l >= 1; --l) {
            for (int i = t1_rightmost[k]; i < k + 1; ++i) {
                // insertions
                fd[i][t2_rightmost[l] + 1] = fd[i+1][t2_rightmost[l] + 1] + 1;
            }
            for (int j = t2_rightmost[k]; j < l + 1; ++j) {
                // deletions
                fd[t1_rightmost[k] + 1][j] = fd[t1_rightmost[k] + 1][j+1] + 1;
            }
            for (int i = t1_rightmost[k]; i < k + 1; ++i) {
                for (int j = t2_rightmost[l]; j < l + 1; ++j) {
                    if (t1_rightmost[i] == t1_rightmost[k] && t2_rightmost[j] == t2_rightmost[l]) {
                        fd[i][j] = min(
                            fd[i+1][j] + 1,
                            fd[i][j+1] + 1,
                            fd[i+1][j+1] + 1
                        );
                        td[i][j] = fd[i][j];
                    } else {
                        fd[i][j] = min(
                            fd[i+1][j] + 1,
                            fd[i][j+1] + 1,
                            fd[t1_rightmost[i] + 1][t2_rightmost[j] + 1] + td[i][j]
                        );
                    }
                }
            }
        }
    }

    return td[1][1];
}

int min(int a, int b, int c) {
    return std::min(std::min(a, b), c);
}
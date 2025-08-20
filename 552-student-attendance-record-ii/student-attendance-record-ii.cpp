#include <iostream>
using namespace std;

class Solution {
    static const int MOD = 1000000007;
    static const int LIMIT_A = 2;
    static const int LIMIT_L_RUN = 3;

    struct Subsequences {
        int width = 0;
        size_t states[LIMIT_A][LIMIT_L_RUN][LIMIT_L_RUN] = {};
    };

    Subsequences Merge(const Subsequences& a, const Subsequences& b) {
        if (a.width == 0) {
            return b;
        }
        if (b.width == 0) {
            return a;
        }

        Subsequences c;
        c.width = a.width + b.width;

        for (auto aa = 0; aa < LIMIT_A; ++aa) {
            for (auto ba = 0; ba < (LIMIT_A - aa); ++ba) {
                auto ca = aa + ba;

                for (auto arl = 0; arl < LIMIT_L_RUN; ++arl) {
                    for (auto bll = 0; bll < (LIMIT_L_RUN - arl); ++bll) {
                        for (auto all = 0; all < LIMIT_L_RUN; ++all) {

                            auto cll = all;
                            // If a is made of all-L, then b's left Ls increase c's left L
                            if (a.width == arl) {
                                cll += bll;
                                if (cll >= LIMIT_L_RUN) {
                                    break;
                                }
                            }

                            for (auto brl = 0; brl < LIMIT_L_RUN; ++brl) {

                                auto crl = brl;
                                // If b is made of all-L, then a's right Ls increase c's right L
                                if (b.width == brl) {
                                    crl += arl;
                                    if (crl >= LIMIT_L_RUN) {
                                        break;
                                    }
                                }

                                c.states[ca][cll][crl] += a.states[aa][all][arl] * b.states[ba][bll][brl];
                            }
                        }
                    }
                }
            }
        }

        for (auto a = 0; a < LIMIT_A; ++a) {
            for (auto ll = 0; ll < LIMIT_L_RUN; ++ll) {
                for (auto rl = 0; rl < LIMIT_L_RUN; ++rl) {
                    c.states[a][ll][rl] %= MOD;
                }
            }
        }

        return c;
    }

public:
    int checkRecord(int n) {

        if (n == 0) {
            return 0;
        }

        Subsequences curr;
        curr.width = 1;
        curr.states[0][0][0] = 1; // 'P'
        curr.states[0][1][1] = 1; // 'L'
        curr.states[1][0][0] = 1; // 'A'

        Subsequences res;
        auto n_buildup = 0;
        if (n & 0x1) {
            res = curr;
            n_buildup = 1;
        }

        
        for (auto i = 1; n != n_buildup; ++i) {

            curr = Merge(curr, curr);

            if (n & (0x1 << i)) {
                res = Merge(res, curr);
                n_buildup |= (0x1 << i);
            }
        }

        size_t results = 0;
        for (auto a = 0; a < LIMIT_A; ++a) {
            for (auto ll = 0; ll < LIMIT_L_RUN; ++ll) {
                for (auto rl = 0; rl < LIMIT_L_RUN; ++rl) {

                    results += res.states[a][ll][rl];
                }
            }
        }

        return results % MOD;
    }
};
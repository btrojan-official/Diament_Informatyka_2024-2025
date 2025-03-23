#include <bits/stdc++.h>
using namespace std;

short sqrt2(short num) {
        short op = num;
        short res = 0;
        short one = 1 << 14; // The second-to-top bit is set: 1L<<30 for long

        // "one" starts at the highest power of four <= the argument.
        while (one > op)
            one >>= 2;

        while (one != 0) {
            if (op >= res + one) {
                op -= res + one;
                res = (res >> 1) + one;
            }
            else
              res >>= 1;
            one >>= 2;
        }
        return res;
    }

int main() {
    s m;

    cin >> m;

    short result = sqrt2(m);
    cout << fixed << result << "Pierwiastek kwadratowy z " << m << " wynosi: " << result << endl;

    return 0;
}

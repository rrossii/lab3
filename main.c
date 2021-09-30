#include <stdio.h>
#include <math.h>

double y(double x) {
    return (x * sin(M_PI_4) / (1 - 2 * x * cos(M_PI_4) + x * x));
}

double s(double x, int n) {
    return pow(x, n) * sin(n * M_PI_4);
}

int main() {
    double a = 0.1, b = 0.8, eps = 0.0001;
    int n = 40, k = 10;
    for (double x = a; x <= b; x += (b - a) / k) {
        double sn = 0.;
        for (int i = 1; i <= n; i++) {
            sn += s(x, i);
        }
        double se = 0., s0 = 0., s1;
        int in = 1;
        while (1) {
            s1 = s(x, in);
            se += s1;
            if (fabs(s1 - s0) < eps) break;
            s0 = s1;
            in++;
        }
        printf("X=%lf SN=%lf SE=%lf Y=%lf\n", x, sn, se, y(x));
    }
    return 0;
}

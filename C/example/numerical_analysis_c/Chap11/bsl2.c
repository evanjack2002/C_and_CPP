/*=============================================================
// �� �� ����bsl2
// �������������ڶ��������ױ�����������ֵ
// ���������x �Ա���x��ֵ��
//           n �����������Ľ���
// �� �� ֵ���ڶ��������ױ�����������ֵ
//==============================================================*/
#include "math.h"
#include "stdio.h"

double bsl2(n, x)
double x;
int n;
{
    double t, Y0(), Y1();
    int j, nn, flag;
    double ax, nx, by0, by1;
    ax = fabs(x);

    if (ax == 0.0) {
        return (0.0);
    }

    nx = 2.0 / ax;                        /* ����2*n/x��Ҫ��ֵ2/x*/
    by0 = Y0(ax);                       /* ���Ƴ�ֵY0*/
    by1 = Y1(ax);                       /* ���Ƴ�ֵY1*/

    for (j = 1; j < n; j++) {
        t = j * nx * by1 - by0;          /* ���Ƽ���*/
        by0 = by1;
        by1 = t;
    }

    if (n == 0) {
        t = by0;
    } else {
        t = by1;
    }

    return (x < 0.0) && (n & 1) ? -t : t;  /* nΪ������xΪ��ʱ������-t*/
}

static double Y0(x)                     /* ����Y0(x)*/
double x;
{
    double x1, x2, t, t1, t2, y;
    x1 = fabs(x);

    if (x1 < 8.0) {                        /* ������ʽ�ƽ�*/
        x2 = x * x;
        t1 = -2957821389.0 + x2 * (7062834065.0 +
                                   x2 * (-512359803.6 + x2 * (10879881.29 +
                                           x2 * (-86327.92757 + x2 * (228.4622733)))));
        t2 = 40076544269.0 + x2 * (745249964.8 +
                                   x2 * (7189466.438 + x2 * (47747.26470 +
                                           x2 * (226.1030244 + x2))));
        t = t1 / t2 + 0.636619772 * J0(x) * log(x);
    } else {                              /* x>8�����*/
        y = 8.0 / x1;
        x2 = y * y;
        t1 = 1.0 + x2 * (-0.1098628627e-2 + x2 * (0.2734510407e-4 +
                         x2 * (-0.2073370639e-5 + x2 * 0.2093887211e-6)));
        t2 = -0.1562499995e-1 + x2 * (0.1430488765e-3 +
                                      x2 * (-0.6911147651e-5 + x2 * (0.7621095161e-6 -
                                              x2 * 0.934945152e-7)));
        t = x1 - 0.785398164;
        t = sqrt(0.0795774715 * y) * (sin(t) * t1 + y * cos(t) * t2);
    }

    return t;
}

static double Y1(x)                  /* ����Y1(x)*/
double x;
{
    double x1, x2, t, t1, t2, y;
    x1 = fabs(x);

    if (x1 < 8.0) {                        /* ������ʽ�ƽ�*/
        x2 = x * x;
        t1 = x * (-0.4900604943e13 + x2 * (0.1275274390e13 +
                                           x2 * (-0.5153438139e11 + x2 * (0.7349264551e9 +
                                                   x2 * (-0.4237922726e7 + x2 * (0.8511937935e4))))));
        t2 = 0.2499580570e14 + x2 * (0.4244419664e12 +
                                     x2 * (0.3733650367e10 + x2 * (0.2245904002e8 +
                                             x2 * (0.1020426050e6 + x2 * (0.3549632885e3 + x2)))));
        t = t1 / t2 + 0.636619772 * (J1(x) * log(x) - 1.0 / x);
    } else {                              /* x>8�����*/
        y = 8.0 / x1;
        x2 = y * y;
        t1 = 1.0 + x2 * (0.183105e-2 + x2 * (-0.3516396496e-4 +
                                             x2 * (0.2457520174e-5 + x2 * (-0.240337019e-6))));
        t2 = 0.04687499995 + x2 * (-0.2002690873e-3 +
                                   x2 * (0.8449199096e-5 + x2 * (-0.88228987e-6 +
                                           x2 * 0.105787412e-6)));
        t = x1 - 2.356194491;
        t = sqrt(0.0795774715 * y) * (sin(t) * t1 + y * cos(t) * t2);
    }

    return t;
}
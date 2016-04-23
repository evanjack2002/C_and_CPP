/*======================================================
//��������disroot
//�������������[a,b]�����ڵķ����Է���f(x)��һ��ʵ��
//���������a���������������˵㣩
//          b��������������Ҷ˵㣩
//          f�������Է�����˺�����
//          eps������Ҫ��
//����ֵ�����̵�ʵ��
=========================================================*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
double disroot(a, b, f, eps)
double a, b, (*f)(), eps;
{
    double x, ym;                  /* ���������е㼰�е㴦�ĺ���ֵ*/
    double ya = (*f)(a);           /* ������˵�ĺ���ֵ*/
    double yb = (*f)(b);           /* �����Ҷ˵�ĺ���ֵ*/

    while (b - a > eps) {          /* �����Ƿ����㾫��Ҫ�󣬲�����������Է�*/

        x = (a + b) / 2;
        printf("%1.7f    %1.7f    %1.7f\n", a, x, b);
        ym = (*f)(x);              /* �������е㼰�е㴦�ĺ���ֵ*/

        if (ym == 0) {             /* Ϊ0ʱ����*/
            return (x);
        }

        if (ya * ym < 0.0) {       /* �е������˵�b���е㺯��ֵ��Ϊ��˵㺯��ֵ*/
            b = x;
            yb = ym;
        } else {
            a = x;
            ya = ym;           /* �е�����Ҷ˵�a���е㺯��ֵ��Ϊ�Ҷ˵㺯��ֵ*/
        }
    }

    return ((a + b) / 2); /*�����󷵻������е�*/
}
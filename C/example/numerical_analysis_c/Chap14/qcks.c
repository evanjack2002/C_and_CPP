/*=============================================================
// 函 数 名：qcks
// 功能描述：快速排序，用递归方法实现
// 输入参数： x 存放待排序数据的数组
//            s 待排序区间的起始位置
//            t 待排序区间的结束位置
// 返 回 值：无
//==============================================================*/
void qcks(x, s, t)
int* x;
int s, t;
{
    int i, j, flag, tmp;

    if (t <= s + 1) {                   /* 区间只有一个或两个元素时*/
        if ((t == s + 1) && x[t] < x[s]) { /* 两个元素时，将小的交换到前面*/
            tmp = x[t];
            x[t] = x[s];
            x[s] = tmp;
        }

        return;
    }

    i = s + 1;                       /* 对i,j赋初值*/
    j = t;
    flag = x[s];                     /* 选取第一个值做岗哨*/

    do {
        while (x[i] < flag) {
            i++;    /* 扫描搜索需要交换的数据*/
        }

        while (x[j] > flag) {
            j--;    /* 扫描搜索需要交换的数据*/
        }

        if (i < j) {
            tmp = x[i];
            x[i] = x[j];
            x[j] = tmp;
        }
    } while (i < j);                  /* 对当前排序区间进行划分*/

    x[s] = x[j];
    x[j] = flag;

    if (s < j - 1) {                  /* 子区间不为空*/
        qcks(x, s, j - 1);
    }

    if (j + 1 < t) {
        qcks(x, j + 1, t);    /* 子区间不为空*/
    }

    return;
}
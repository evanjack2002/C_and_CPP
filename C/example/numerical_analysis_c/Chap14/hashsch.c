/*=============================================================
// �� �� ����hashsch
// �����������ڹ�ϣ���в���һ��Ԫ��
// ��������� HD ��ϣ�������ָ��
//            m ��ϣ���ĳ��ȣ�Ӧ��Ϊ����
//            a �����ҵ�Ԫ�صĹؼ���
// �� �� ֵ�����ҵ��򷵻���λ��,���򷵻�-1
//==============================================================*/

int hashsch(HT, m, a)
hashlist HT;
int m;
KeyType a;
{
    int temp, d, i;
    d = hashpos(a, 0, m);
    temp = d;
    i = 1;

    while (!KeyEqu(HT[d].KEY,
                   NULLTag)) {          /* ����NULLTag�ǿձ�־����Ҫ�Լ�����*/
        if (KeyEqu(HT[d].KEY, a)) {           /* �Ѿ��ҵ�������λ��*/
            return (d);
        }

        d = (d + 2 * i - 1) %
            m;                 /* ��Ϊ���Ҳ���ȣ�˵���Ѿ�������Ԫ��ռ�ݣ����̽��*/
        i++;

        if (d == temp) {                         /* ��ʱ����ʧ��*/
            return (-1);
        }
    }

    return (-1);                                   /* ��ʱ����ʧ��*/
}
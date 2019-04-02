#include "computer.c"
int main(void)
{
    sqStack sk;
    double value;
    ElemType e;
    char str[MAXSIZE] = { 0 };
    sk.base = sk.top = NULL;    //�����ж��Ƿ����

    //��ʼ����ջ
    InitStack(&sk);

    //�����������׺���ʽ
    printf("������ʽ���������ո񣡣�:");
    scanf("%s", str);

    //�Ƚ�������ƥ��
    if (!MatchBrack(str))
        return 0;

    GetMidStack(&sk, str);

    //���������׺���ʽ��ת����Ϊ������
    RotateStack(&sk);

    //���潫��׺���ʽת��׺���ʽ
    GetBackStack(&sk);

    //������ĺ�׺���ʽ��ת����Ϊ������
    RotateStack(&sk);

    //��ȡ��׺���ʽ���
    GetBackValue(&sk, &value);

    //PrintStack(sk);
    printf("Operation values:%lf", value);

    //DestroyStack(sk);
    DestroyStack(&sk);
    return 0;
}

#include "computer.c"
int main(void)
{
    sqStack sk;
    double value;
    ElemType e;
    char str[MAXSIZE] = { 0 };
    sk.base = sk.top = NULL;    //用于判断是否存在

    //初始化空栈
    InitStack(&sk);

    //接收输入的中缀表达式
    printf("输入算式（不包括空格！）:");
    scanf("%s", str);

    //先进行括号匹配
    if (!MatchBrack(str))
        return 0;

    GetMidStack(&sk, str);

    //将上面的中缀表达式翻转，变为正常的
    RotateStack(&sk);

    //下面将中缀表达式转后缀表达式
    GetBackStack(&sk);

    //将上面的后缀表达式翻转，变为正常的
    RotateStack(&sk);

    //获取后缀表达式结果
    GetBackValue(&sk, &value);

    //PrintStack(sk);
    printf("Operation values:%lf", value);

    //DestroyStack(sk);
    DestroyStack(&sk);
    return 0;
}

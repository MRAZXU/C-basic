#include <stdio.h>
//考点重点！！！！！
//运算顺序
int main()
{
    //程序中的短路：
    //||从左向右:遇到真值停止计算，所有条件为假才是假的
    //&&从左向右:遇到假停止计算，所有条件为真才是真的
    int i = 0;
    int j = 0;
    int k = 0;
    //++i ||( ++j && ++k);
    ++i || ++j && ++k;
    //遇见||和&&的混合表达式
    //STEP1把整个表达式看作||式
    //STEP2从左向右用短路法
    //SETP3最后计算||
    printf("%d\n", i);//1
    printf("%d\n", j);//0
    printf("%d\n", k);//0
    
    return 0;
}
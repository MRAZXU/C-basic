#include <stdio.h>
/**********************************/
//指针运算与数组名运算
//默认大端模式
//a为首元素地址
//&a为整个数组的首地址
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    //&a+1====a+sizeof(*&a)--就是a[0]移动到一个数组长度的位置
    //也就是在数组的边界
    int* p1 = (int*)(&a + 1); 
    //int(a)+1====地址自增1
    //可以编译通过但是不能访问
    int* p2 = (int*)((int)a + 1);
    //移动一个指针长度，也就是对应的一个数组元素长度
    int* p3 = (int*)(a + 1);
    
    printf("%d\n", p1[0]);//边界位置
    printf("%d\n", p1[-1]);//5
  //printf("%d\n", p2[0]);//这里发生了数组内段错误
    printf("%d\n", p3[1]);
    return 0;
}
// A. 数组下标不能是负数，程序无法运行
// B. p1[-1]将输出随机数，p2[0]输出2， p3[1]输出3
// C. p1[-1]将输出乱码， p2[0]和p3[1]输出2
//以上都不对
//1.乱码  5  2.段错误     3 .3
//但是这个题和唐老师讲的不一样
//还是有很多问题
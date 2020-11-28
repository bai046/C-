#include <stdio.h>

void func2(){
    printf("C语言自定义函数");
}

void func1(){
    printf("function1");
    func2();
}

int main(){
    func1();
    return 0;
}

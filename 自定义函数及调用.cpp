#include <stdio.h>

void func2(){
    printf("C�����Զ��庯��");
}

void func1(){
    printf("function1");
    func2();
}

int main(){
    func1();
    return 0;
}

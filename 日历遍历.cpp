#include <stdio.h>

main(){
/*判断输入年份是否是闰年的函数*/
int isLeapYear(int);

/*判断每月天数的函数*/
int monthDays(int,int);

/*判断某个日期是星期几的函数*/
int getWeekDay(int,int,int);

/*输出某年某月月历的函数*/
void outMonthDays(int,int);

  int Year,Month;
  printf("请输入年份:");
  scanf("%d",&Year);
  printf("%d年日历为:\n",Year);
  printf("----------------------------------------------\n");
  for(Month=1;Month<=12;Month++){
    outMonthDays(Year,Month);
  }
  return 0;
}
/*判断闰年函数的具体实现*/
int isLeapYear(int Year){
  if(Year%4==0 && Year%100!=0 || Year%400==0)
    return 1;
  return 0;
}
/*判断每月天数的具体实现*/
int monthDays(int Year,int Month){
 if(Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12){
    return 31;
 }else if(Month == 4 || Month == 6 || Month == 9 || Month == 11){
    return 30;
 }else{
    if(isLeapYear(Year))
        return 29;
    return 28;
 }
}
/*判断某年某月某号是周几的具体实现*/
int getWeekDay(int Year,int Month,int Day){
  int i,temp,weekday,Days=0;
  for(i=1;i<=Month-1;i++){
    Days+=monthDays(Year,i);
  }
  Days = Days + Day;
  temp = (Year-1)+(Year-1)/4-(Year-1)/100+(Year-1)/400+Days;
  weekday = temp % 7;
  return weekday;
}
/*打印某年某月日历的具体实现*/
void outMonthDays(int Year,int Month){
  int i,j,weekday;
  printf("%d年%d月日历\n",Year,Month);
  printf("  日  一  二  三  四  五  六\n");
  weekday = getWeekDay(Year,Month,1);
    for(i=0;i<weekday;i++){
    printf("    ");
  }
  for(j=1;j<=monthDays(Year,Month);j++){
    printf("%4d",j);
    if((j+weekday)%7==0){
        printf("\n");
    }
  }
  printf("\n");
printf("--------------------------------------------------------\n");
}

//以上代码中需注意：
//1、这里需要最注意的是对闰年的判断方法以及对某年某月某日是周几的判断方法，其它都是较为普通的编程；
//2、注意这里的对齐方式，转换说明符%4d表示该整数域宽为4，即占用4个打印位置。如果所显示的字符个数小于域宽，
//该值会自动在域宽内右对齐。在%和域宽数值之间使用一个-（减号），可使域内的值左对齐；
//3、注意这里的函数式模块化编程，虽然是一个小程序，也要注意将功能分块封装，各个击破，降低编程难度，增强代码复用性。
//以上：https://blog.csdn.net/somanlee/article/details/68148079
//解析版：https://wenku.baidu.com/view/8a360f7cba1aa8114531d951.html



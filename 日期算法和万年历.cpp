#include<stdio.h>

#define DAYS_PER_WEEK 7
#define MONTHS 12
#define DATE_HEADER "   Sun   Mon   Tues  Wed   Thur  Fri   Sat"



int get_days(int, int, int);   //返回从公元元年算起，某年某月某日是第几天， 用这个数字算星期几 
int days_of_year(int, int, int);  //返回某年某月某日是当前年份第几天
int days_of_month(int, int);  //返还某年某月有几天
int day_of_week(int, int, int); //返回某年某月某日是星期几，星期天返回0 

void print_date_of_month(int, int);    // 打印某年某月的日历     

int main()
{
    int days = get_days(2018, 5, 9) % DAYS_PER_WEEK;
    printf("%d\n", day_of_week(2018, 5, 9));
    
    print_date_of_month(2018, 8);
    
    return 0;
 }



//返回这一天从公元元年算起是第几天
 
int get_days(int year, int month, int day)
{
    int days = days_of_year(year, month, day);
    int temp = year-1;
    return temp * 365 + temp / 4 - temp / 100 + temp / 400 +  days;
}
 
 

 //返回这一天在当年是第几天 
int days_of_year(int year, int month, int day)
{
     int i;
     int days = 0;
     for(i = 1; i < month; i++)
     {
         days += days_of_month(year, i);
         
     }
     return days + day;
}

//返回这个月一共有多少天 
int days_of_month(int year, int month)
{
    //存储平年每月的天数 
    const int  month_days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(2 == month && is_leap_year(year))
        return 29; // 如果是闰年2月，返回29天 
    else
        return month_days[month-1];  //正常返回 
}

//判断是不是闰年 
_Bool is_leap_year(int year)
{
    return (year % 400 == 0 ) || (year % 4 == 0 && year % 100 != 0);
}

int day_of_week(int year, int month, int day)
{
    return get_days(year, month, day) % DAYS_PER_WEEK;
 } 

//输出某年某个月的日历 
void print_date_of_month(int year, int month)
{
    //打印月份,为了让月份显示居中， 打印一些空格（根据打印星期的那行大概估算一下） 
    printf("               ");
    switch(month)
    {
        case 1: printf("January\n");    break;
        case 2: printf("February\n");    break;
        case 3: printf("March\n");    break;
        case 4: printf("April\n");    break;
        case 5: printf("May\n");    break;
        case 6: printf("June\n");    break;
        case 7: printf("July\n");    break;
        case 8: printf("August\n");    break;
        case 9: printf("September\n");    break;
        case 10: printf("October\n");    break;
        case 11: printf("November\n");    break;
        case 12: printf("December\n");    break;
        default: printf("Bad input of month, please enter a right month.\n"); return;
        
    }
    //先把星期打印出来 
    printf("%s\n", DATE_HEADER);
    
    //先求出这个月第一天星期几 
    int day_of_week = get_days(year, month, 1) % DAYS_PER_WEEK;
    
    //因为星期天是在第一个位置，所以对星期求模（求余），比如星期天，其实是第一个位置，所以它应该是 7 % 7 = 0； 
    int first = day_of_week % DAYS_PER_WEEK;
    
    //求出这个月一共有几天 
    int days = days_of_month(year, month);
    
    int i, j;
    //先打印第一天的位置 
    for(i = 0; i < first; i++) {
        printf("      ");
    }
    printf("%6d", 1);
    //如果今天是星期六，换行 
    if(first == 6)
        printf("\n");
    
    //打印剩下的日期 
    for(i = 1; i < days; i++)
    {
        printf("%6d", i + 1);
        //如果是星期六或者是最后一天，换行 
        if((first + i) % 7 == 6 || i + 1 == days)
            printf("\n");
    } 
}

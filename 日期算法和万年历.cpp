#include<stdio.h>

#define DAYS_PER_WEEK 7
#define MONTHS 12
#define DATE_HEADER "   Sun   Mon   Tues  Wed   Thur  Fri   Sat"



int get_days(int, int, int);   //���شӹ�ԪԪ������ĳ��ĳ��ĳ���ǵڼ��죬 ��������������ڼ� 
int days_of_year(int, int, int);  //����ĳ��ĳ��ĳ���ǵ�ǰ��ݵڼ���
int days_of_month(int, int);  //����ĳ��ĳ���м���
int day_of_week(int, int, int); //����ĳ��ĳ��ĳ�������ڼ��������췵��0 

void print_date_of_month(int, int);    // ��ӡĳ��ĳ�µ�����     

int main()
{
    int days = get_days(2018, 5, 9) % DAYS_PER_WEEK;
    printf("%d\n", day_of_week(2018, 5, 9));
    
    print_date_of_month(2018, 8);
    
    return 0;
 }



//������һ��ӹ�ԪԪ�������ǵڼ���
 
int get_days(int year, int month, int day)
{
    int days = days_of_year(year, month, day);
    int temp = year-1;
    return temp * 365 + temp / 4 - temp / 100 + temp / 400 +  days;
}
 
 

 //������һ���ڵ����ǵڼ��� 
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

//���������һ���ж����� 
int days_of_month(int year, int month)
{
    //�洢ƽ��ÿ�µ����� 
    const int  month_days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(2 == month && is_leap_year(year))
        return 29; // ���������2�£�����29�� 
    else
        return month_days[month-1];  //�������� 
}

//�ж��ǲ������� 
_Bool is_leap_year(int year)
{
    return (year % 400 == 0 ) || (year % 4 == 0 && year % 100 != 0);
}

int day_of_week(int year, int month, int day)
{
    return get_days(year, month, day) % DAYS_PER_WEEK;
 } 

//���ĳ��ĳ���µ����� 
void print_date_of_month(int year, int month)
{
    //��ӡ�·�,Ϊ�����·���ʾ���У� ��ӡһЩ�ո񣨸��ݴ�ӡ���ڵ����д�Ź���һ�£� 
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
    //�Ȱ����ڴ�ӡ���� 
    printf("%s\n", DATE_HEADER);
    
    //���������µ�һ�����ڼ� 
    int day_of_week = get_days(year, month, 1) % DAYS_PER_WEEK;
    
    //��Ϊ���������ڵ�һ��λ�ã����Զ�������ģ�����ࣩ�����������죬��ʵ�ǵ�һ��λ�ã�������Ӧ���� 7 % 7 = 0�� 
    int first = day_of_week % DAYS_PER_WEEK;
    
    //��������һ���м��� 
    int days = days_of_month(year, month);
    
    int i, j;
    //�ȴ�ӡ��һ���λ�� 
    for(i = 0; i < first; i++) {
        printf("      ");
    }
    printf("%6d", 1);
    //��������������������� 
    if(first == 6)
        printf("\n");
    
    //��ӡʣ�µ����� 
    for(i = 1; i < days; i++)
    {
        printf("%6d", i + 1);
        //��������������������һ�죬���� 
        if((first + i) % 7 == 6 || i + 1 == days)
            printf("\n");
    } 
}

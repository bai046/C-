//
//	char timestr[128]="";
//	time_t app_time_stamp = 0;
#include<stdio.h>
#include<time.h>
int main()
{
time_t t;//time_t是一种类型，定义time_t类型的t
time(&t);//取得当前时间
printf("%s\n",ctime(&t));//ctime(&t)将日期转为字符串并打印
return 0;
}	
//
//	//方法1
//	app_time_stamp = time( 0 );
//    strftime(timestr, 128, "%a, %d %b %Y %H:%M:%S GMT", localtime(&app_time_stamp));
//    printf("Date&Time:%s", timestr);
//
//   //方法2
//    struct tm *p;
//    app_time_stamp = time( 0 );
//    p=gmtime(&app_time_stamp); //无时区信息
//    strftime(timestr, 128, "%Y-%m-%d %H:%M:%S", p);
//    printf("Date&Time:%s", timestr);
//  
//   //方法3
//   struct tm timeinfo;
//   time_t t = time( 0 );
//   timeinfo = *localtime(&app_time_stamp);
//   printf("Date&Time:%s", timestr);
//
//   //方法4
//   struct timeval tv_now;
//   gettimeofday(&tv_now, NULL);
//   localtime_r(&tv_now.tv_sec, &timeinfo);
//   printf(""Date&Time:%04d-%02d-%02d,%02d:%02d:%02d",\
//            1900+(timeinfo.tm_year), (timeinfo.tm_mon)+1,timeinfo.tm_mday, timeinfo.tm_hour, timeinfo.tm_min, \
//            timeinfo.tm_sec);
//


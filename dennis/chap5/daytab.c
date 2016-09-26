#include<stdio.h>
static char daytab[2][13]={
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year,int month,int day)
{
	int i,leap;
	if(month > 12 || month < 1 || day<1)
		return -1;

	leap= year%4==0 && year%100 !=0 || year % 400;
	if(day>daytab[leap][month])
		return -2;
	for(i=0;i<month;i++)
		day+=daytab[leap][i];
	return day;
}
int month_day(int year,int yearday,int *pmonth,int *pday)
{
	if( yearday<1)
		return -1;
	int i,leap;

	leap= year%4==0 && year%100 !=0 || year % 400;
	if( yearday>(365 + leap ))
		return - 2;
        for(i=1;yearday>daytab[leap][i];i++)
                yearday-=daytab[leap][i];
        *pday=yearday;
	*pmonth=i;
return 0;
}
/* main: test day_of_year and month_day */
int main(void)
{
	int year, month, day, yearday;
	
	for (year = 1970; year <= 2000; ++year) {
		for (yearday = 1; yearday < 366; ++yearday) {
			if (month_day(year, yearday, &month, &day) == -1) {
				printf("month_day failed: %d %d\n",
					year, yearday);
			} else if (day_of_year(year, month, day) != yearday) {
				printf("bad result: %d %d got %d\n", year, yearday,day_of_year(year,month,day));
				printf("month = %d, day = %d\n", month, day);
			}
		}
	}
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

int get_first_weekday(int year)
{
    int d;
    d=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1) % 7;
    return d;
}




int main()
{
    system("color 4F");
    int year,month,day,daysinMonth,weekDay=0,startingDay;
    printf("enter year->>");
    scanf("%d",&year);

    char *months[]={"january","february","march","april","may","june","july","august","september","october","november","december"};
    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

    if((year%4==0 && year%100!=0)||year%400==0)
        monthDay[1]=29;

    startingDay=get_first_weekday(year);

    for(month=0;month<12;month++)
    {
        daysinMonth=monthDay[month];
        printf("\n----------------%s----------------\n",months[month]);
        printf("\n  sun  mon  tue  wed  thus  fri  sat\n");

        for(weekDay=0;weekDay<startingDay;weekDay++)
        printf("     ");

        for(day=1;day<=daysinMonth;day++)
        {
            printf("%5d",day);

            if(++weekDay>6)
            {
                printf("\n");
                weekDay=0;
            }
            startingDay=weekDay;
        }

    }
}
#include <stdio.h>
#include <stdlib.h>

/* For a given date, determine the weekday it corresponds to,
   and calculate how many times date falls on the same weekday,
   starting from next year and ending on a given year.
 * Zeller's Congruence
 * ( q + ( (13 * (m + 1)) / 5 ) + k + (k/4) + (j/4) + (5 * j) ) % 7
 * 	q is the day
 * 	m is the month (if month is jan or feb, add 12 to month and
	subtract 1 from year
 *	j is the first two digits of the year (zero-based century)
 *	k is the last two digits of the year (offset in century)
 *	Result is the day of the week, starting from 0 = Sat
 */

int zeller(int day, int month, int year){
	if (month == 1 || month == 2) {
			month += 12;
			year--;
	}
	int century = year / 100;
	int offset = year % 100;
	
	int day_of_week = ( day + ( (13 * (month + 1)) / 5 ) + offset + (offset/4) + (century/4) + (5 * century) ) % 7;
	return day_of_week;
}

void weekday_print(int day_of_week){
	printf("It's a ");
	switch(day_of_week){
			case 0:
				printf("Saturday.\n");
				break;
			case 1:
				printf("Sunday.\n");
				break;
			case 2:
				printf("Monday.\n");
				break;
			case 3:
				printf("Tuesday.\n");
				break;
			case 4:
				printf("Wednesday.\n");
				break;
			case 5:
				printf("Thursday.\n");
				break;
			case 6:
				printf("Friday.\n");
				break;
		}
	}
	
int main() {
    int user_year = -1;
    int user_month = -1;
    int user_day = -1;
    printf("Enter date [year month day]: ");
    scanf("%d %d %d", &user_year, &user_month, &user_day);

    int max_day = -1;
    if (user_month > 0 && user_month <= 7) {
        if (user_month % 2 == 0) {
            max_day = 30;
        } else {
            max_day = 31;
        }
    } else if (user_month > 7 && user_month <= 12) {
        if (user_month % 2 == 0) {
            max_day = 31;
        } else {
            max_day = 30;
        }
    }
    if (user_month == 2) {
        max_day -= 2;
    }

    if (user_day < 1 || user_day > max_day) {
        printf("Invalid date.\n");
        return EXIT_FAILURE;
    }

    int end_year = -1;
    printf("\nEnter end year: ");
    scanf("%d", &end_year);
	
	int weekday = zeller(user_day,user_month,user_year);
	
	weekday_print(weekday);
	
	int year_counter = 0;
	for(int i = user_year + 1; i <= end_year; i++){
		int compare_weekday = zeller(user_day,user_month,i);
		if (compare_weekday == weekday){
			year_counter++;
		} 
	}
    printf("Same day-and-month on same weekday between %d and %d: %d\n", user_year + 1, end_year, year_counter);
    return EXIT_SUCCESS;
	}

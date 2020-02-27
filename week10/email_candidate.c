#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(char* n1, char* n2){
    *n1 = *n1 + *n2;
    *n2 = *n1 - *n2;
    *n1 = *n1 - *n2;
}

int my_strlen(const char *str){
	int length = 0;
	while(1){
		if (str[length]=='\0'){
			return length;
		}
		length++;
	}
	/*
	for(;str[length]!='\0';length++);
	return length;
	*/
}

char* my_strcpy(char *dst, const char *src){
	int src_length = my_strlen(src);
	for(int i = 0; i<=src_length; i++){
		dst[i] = src[i];
	}
	return dst;
}

char* my_strcat(char *dst, const char *src){
	int baselength = my_strlen(dst);
	int src_length = my_strlen(src);
	for(int i = 0; i<=src_length; i++){
		dst[baselength + i] = src[i];
	}
	return dst;
	/* can also be done by making dst point at
	the end of its string, and using strcpy */
}

/*
char* substring(char* source_string, int start, int size){
	char* substring = malloc((size+1)*sizeof(char));
	source_string += start;
	for(int i = 0; i < size; i++){
		substring[i] = source_string[i];
	}
	substring[size] = '\0';
	return substring;	
}
*/

char* substring(char* source_string, char* dst, int start, int size){
	source_string += start;
	for(int i = 0; i < size; i++){
		dst[i] = source_string[i];
	}
	dst[size] = '\0';
	return dst;
}


char* inttostring(int input, char* dst){
	int i = 0;
	do{
		dst[i++] = input % 10 + '0';
	}while((input /= 10) > 0);
	dst[i] = '\0';
	int str_len = i;

	for(int j = 0; j < str_len/2; j++){
		swap(&dst[j],&dst[str_len-j-1]);
	}

	return dst;
}

void generate_email(char* name, char* surname, int year){
    char cand1[100]="", cand2[100]="", cand3[100]="", ending[100]="@itu.edu.tr", temp[100]="";
	
	my_strcat(cand1,substring(name,temp,0,1));
	my_strcat(cand1,surname);
	my_strcat(cand1,inttostring(year % 100, temp));
	my_strcat(cand1,ending);
	
	my_strcat(cand2,substring(name,temp,0,2));
	my_strcat(cand2,substring(surname,temp,0,2));
	my_strcat(cand2,inttostring(rand()%1000, temp));
	my_strcat(cand2,ending);
	
	my_strcat(cand3,surname);
	my_strcat(cand3,name);
	my_strcat(cand3,inttostring(year, temp));
	my_strcat(cand3,ending);
	
	printf("First mail is: %s; Second mail is: %s; Third mail is: %s\n", cand1, cand2, cand3);
//	printf("ABC");
}

int main(){
	srand(time(NULL));
	char name[10];
	char surname[10];
	int year;
	
	printf("Enter your name: ");
	scanf("%s", name);
	printf("Enter your surname: ");
	scanf("%s", surname);
	printf("Enter your birthyear: ");
	scanf("%d", &year);
	
	generate_email(name, surname, year);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SETS 4
#define TOTAL_STUDENTS 44
#define STUDENTS_FOR_EACH_SET TOTAL_STUDENTS/SETS

int num = 0;
int randomnumber; 
int allocated_students[TOTAL_STUDENTS];

void print_Array()	{
	printf("\narray -"); 
	for(int i=0; i<TOTAL_STUDENTS; i++)	{
		printf(" %d\t", allocated_students[i]);
	}
}

int check(int num)	{
	int flag=0;
	for(int i=0; i<TOTAL_STUDENTS; i++)	{
		if(allocated_students[i] == num)	{
			flag = 0;
			break;
		}
		else
			flag = 1;			
	}
	return flag;
}

void printRandoms(int lower, int upper, int i)
{
Again:	num = (rand() % (upper - lower + 1)) + lower;
		
		if(check(num))	{
	
        	printf("non repeated - %d \n", num);
        	allocated_students[i]=num;
		}
        else {
	       	goto Again;
        }
}

int main()	{
	srand(time(0));
	int array_index = 0;
	for(int j=1; j<=SETS; j++)	{
		srand(time(0));
		printf("\n---------------Set - %d---------------\n", j);
		for(int i=0; i<STUDENTS_FOR_EACH_SET; i++, array_index++)	{
		printRandoms(1, TOTAL_STUDENTS,array_index);
		}
	}
	print_Array();
	return 0;
}

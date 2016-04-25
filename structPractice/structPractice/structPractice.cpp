// structPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define LEN 20
#define M1 "Have a nice day with "
#define M2 " and have much laughs."

struct names {
	char first[LEN];
	char last[LEN];
};

struct human {
	struct names firstLast;
	int age;
	float weight;
};
typedef struct human person;

int main() {

	struct human Lee = { {"Bruce", "Lee"}, 25, 65.5 };
	person Kim = { {"Sam", "Kim"}, 35, 70.3 };
	
	printf("Dear %s, \n\n", Lee.firstLast.first);
	printf("Thank you %s. \n", Lee.firstLast.first);
	printf("Your age is %d \n", Lee.age);
	printf("with good records \n");
	printf("%sCharles%s \n\n", M1, M2);

    return 0;
}
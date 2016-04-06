// firstGithubSln.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j;
	int *ptr;
	ptr = &i;
	*ptr = 10;
	j = *ptr;

	printf("i = %d\n", i);
	printf("&i = %d\n", &i);
	printf("j = %d\n", j);
	printf("&j = %d\n", &j);
	printf("*ptr = %d\n", *ptr);
	printf("ptr = %d\n", ptr);

	system("pause");
	return 0;
}
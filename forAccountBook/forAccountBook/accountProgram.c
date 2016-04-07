#include <stdio.h>
// #pragma warning(disable:4996)

int main() {
	int i, firstRow, lastRow;
	char firstColumn[3], secondColumn[3];

	printf("곱할 첫 번째 열을 입력하세요.\n 예: A, B, F 등등: ");
	scanf_s("%s", firstColumn, sizeof(firstColumn));
	printf("곱할 두 번째 열을 입력하세요.\n 예: A, B, F 등등: ");
	scanf_s("%s", secondColumn, sizeof(secondColumn));

	printf("시작하는 행의 숫자를 입력하세요.\n 예: 4, 6, 10 등등: ");
	scanf("%d", &firstRow);
	printf("끝나는 행의 숫자를 입력하세요.\n예: 4, 6, 10 등등: ");
	scanf("%d", &lastRow);
	
	printf("=");
	for (i = firstRow; i < lastRow+1; i++) {
		printf("$%s%d*%s%d", firstColumn, i, secondColumn, i);
		if (i != lastRow)
			printf("+");
	}

	printf("\n끝났습니다. 메모장에 적힌 내용을 그대로 셀에 복사하세요!\n");

	return 0;
}
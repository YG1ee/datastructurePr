#include <stdio.h>
// #pragma warning(disable:4996)

int main() {
	int i, firstRow, lastRow;
	char firstColumn[3], secondColumn[3];

	printf("���� ù ��° ���� �Է��ϼ���.\n ��: A, B, F ���: ");
	scanf_s("%s", firstColumn, sizeof(firstColumn));
	printf("���� �� ��° ���� �Է��ϼ���.\n ��: A, B, F ���: ");
	scanf_s("%s", secondColumn, sizeof(secondColumn));

	printf("�����ϴ� ���� ���ڸ� �Է��ϼ���.\n ��: 4, 6, 10 ���: ");
	scanf("%d", &firstRow);
	printf("������ ���� ���ڸ� �Է��ϼ���.\n��: 4, 6, 10 ���: ");
	scanf("%d", &lastRow);
	
	printf("=");
	for (i = firstRow; i < lastRow+1; i++) {
		printf("$%s%d*%s%d", firstColumn, i, secondColumn, i);
		if (i != lastRow)
			printf("+");
	}

	printf("\n�������ϴ�. �޸��忡 ���� ������ �״�� ���� �����ϼ���!\n");

	return 0;
}
#include <stdio.h>

int main() {
	int i, firstRow, lastRow;
	char firstColumn, secondColumn;

	printf("���� ù ��° ���� �Է��ϼ���.\n ��: A, B, F ���: ");
	scanf("%c", &firstColumn);
	printf("���� �� ��° ���� �Է��ϼ���.\n ��: A, B, F ���: ");
	scanf("%c", &secondColumn);

	printf("�����ϴ� ���� ���ڸ� �Է��ϼ���.\n ��: 4, 6, 10 ���: ");
	scanf("%d", &firstRow);
	printf("������ ���� ���ڸ� �Է��ϼ���.\n��: 4, 6, 10 ���: ");
	scanf("%d", &lastRow);
	
	printf("=");
	for (i = firstRow; i < lastRow+1; i++) {
		pritnf("$%c%d*%c%d", firstColumn, i, secondColumn, i);
		if (i != lastRow)
			pritnf("+");
	}

	printf("�������ϴ�. �޸��忡 ���� ������ �״�� ���� �����ϼ���!\n");

	return 0;
}
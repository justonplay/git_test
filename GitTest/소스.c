#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int countNamesize(char* str);

int main(void)
{
	char name[39];
	
	printf("�̸��� �Է��ϼ��� (�ִ� 19�ڱ��� �Է�)\n");
	printf("======================================\n");
	scanf("%s", name);

	printf("\n�Է��� �̸��� %s �Դϴ�.\n", name);
	printf("�Է��� �̸��� ���ڼ��� %d �Դϴ�.\n", countNamesize(name));
	return 0;
}

int countNamesize(char* str)
{
	int i;

	for (i = 0; i < 39; i++)
	{
		if (str[i] == '\0') return i;
	}
	return i;
}
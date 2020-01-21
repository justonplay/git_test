#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int countNamesize(char* str);

int main(void)
{
	char name[39];
	
	printf("�̸��� �Է��ϼ��� (�ִ� 19�ڱ��� �Է�)\n");
	printf("======================================\n");
	scanf("%[^\n]", name);

	printf("\n�Է��� �̸��� %s �Դϴ�.\n", name);
	printf("�Է��� �̸��� ���ڼ��� %d �Դϴ�.\n", countNamesize(name));
	return 0;
}

int countNamesize(char* str)
{
	int i;
	int is_name_kor = 0;
	int count = 0;

	if (str[0] & 0x80) is_name_kor++;

	for (i = 0; i < 39; i++)
	{
		if (str[i] == '\0') return (count / (is_name_kor + 1));
		if (str[i] == ' ') continue;
		count++;
	}
	return (i / (is_name_kor + 1));
}
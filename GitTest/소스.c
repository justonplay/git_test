#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int countNamesize(char* str);

int main(void)
{
	char name[39];
	
	printf("이름을 입력하세요 (최대 19자까지 입력)\n");
	printf("======================================\n");
	scanf("%[^\n]", name);

	printf("\n입력한 이름은 %s 입니다.\n", name);
	printf("입력한 이름의 글자수는 %d 입니다.\n", countNamesize(name));
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
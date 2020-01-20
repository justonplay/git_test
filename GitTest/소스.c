#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char name[39];
	
	printf("이름을 입력하세요 (최대 19자까지 입력)\n");
	printf("======================================\n");
	scanf("%s", name);

	printf("\n입력한 이름은 %s 입니다.\n", name);

	return 0;
}
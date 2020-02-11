#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print_Name(char *);
int input_Name(int *);

int main(void)
{
	int name_size;
	int blank = 0;
	
	printf("글을 입력하세요\n");
	printf("==================\n");
	name_size = input_Name(&blank);

	printf("입력한 글의 글자수는 %d 입니다.\n", name_size);
	printf("입력한 글의 글자수 (공백 포함)은 %d 입니다.\n", blank);
	return 0;
}

void print_Name(char* arr)
{
	printf("\n입력한 글은\n\n%s\n입니다.\n", arr);

	free(arr);
}

int input_Name(int *count_cha_blank)
{
	int count_bit = 0;
	int count_cha = 0;
	int is_buffer_kor = 0;
	char buffer[2];
	char* name;

	name = (char*)malloc(2);

	buffer[0] = getchar();

	while (buffer[0] != '\n')
	{
		count_bit++;

		if (buffer[0] & 0x80)
		{
			buffer[1] = getchar();
			count_bit++;
			is_buffer_kor = 1;
		}
		else
		{
			is_buffer_kor = 0;
		}

		name = (char*)realloc(name, count_bit + 1);

		if (is_buffer_kor)
		{
			name[count_bit - 1] = buffer[1];
			name[count_bit - 2] = buffer[0];
		}
		else
		{
			name[count_bit - 1] = buffer[0];
		}

		if (name[count_bit - 1] == ' ') count_cha--;

		count_cha++;
		(*count_cha_blank)++;
		
		buffer[0] = getchar();
	}
	name[count_bit] = NULL;

	print_Name(name);

	return count_cha;
}

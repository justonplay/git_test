#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_Name(char *);
int input_Name(int *, float *);
float calc_type_speed(int, int);

int main(void)
{
	int name_size;
	int blank = 0;
	float type_speed;
	
	printf("글을 입력하세요\n");
	printf("==================\n");
	name_size = input_Name(&blank, &type_speed);

	printf("입력한 글의 글자수는 %d 입니다.\n", name_size);
	printf("입력한 글의 글자수 (공백 포함)은 %d 입니다.\n", blank);
	printf("글을 입력한 평균 타속은 %0.3f자 (초당) 입니다.\n", type_speed);
	return 0;
}

void print_Name(char* arr)
{
	printf("\n입력한 글은\n\n%s\n입니다.\n", arr);

	free(arr);
}

int input_Name(int *count_cha_blank, float *type_speed)
{
	int count_bit = 0;
	int count_cha = 0;
	int is_buffer_kor = 0;
	int start_time;
	int end_time;
	char buffer[2];
	char* name;

	name = (char*)malloc(2);
	start_time = clock();
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

	end_time = clock();

	*type_speed = calc_type_speed(end_time - start_time, count_cha);

	print_Name(name);

	return count_cha;
}

float calc_type_speed(int timetime, int count_cha)
{
	return (float)count_cha / ((float)(timetime / CLOCKS_PER_SEC));
}
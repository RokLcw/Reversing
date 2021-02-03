#include<stdio.h>
#include<string.h>

int main()
{
	char table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char text[100000] = { 0, };
	char encoding[400000] = { 0, };
	int tLength = 0, tIndex = 0, eIndex = 0, step = 0;

	printf_s("input text : ");
	fgets(text, 100000, stdin);
	text[strlen(text) - 1] = '\0';

	tLength = strlen(text);

	while (tIndex < tLength)
	{
		// 입력한 글자를 3개씩 묶어서 2진수로 바꿔주는 과정
		step = 0;
		step = step << 0 | text[tIndex + 0];
		step = step << 8 | text[tIndex + 1];
		step = step << 8 | text[tIndex + 2];

		// 8bit를 6bit로 짤라주는 과정
		encoding[eIndex + 0] = table[(step >> 18) & 0x3F];
		encoding[eIndex + 1] = table[(step >> 12) & 0x3F];
		encoding[eIndex + 2] = table[(step >> 6) & 0x3F];
		encoding[eIndex + 3] = table[(step >> 0) & 0x3F];

		eIndex += 4;
		tIndex += 3;
	}

	if (tLength % 3 == 2 || tLength == 2)
	{
		encoding[eIndex - 1] = 0x3D;
	}
	else if (tLength % 3 == 1 || tLength == 1)
	{
		encoding[eIndex - 1] = 0x3D;
		encoding[eIndex - 2] = 0x3D;
	}

	printf("\nEncoding Results: ");
	for (int i = 0; i < eIndex; i++)
	{
		printf("%c", encoding[i]);
	}
	printf("\n");

	return 0;
}
﻿#include<stdio.h>
#include<string.h>

int main()
{
	char table[256] = {
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 00-0F */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 10-1F */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,63,  /* 20-2F */
		52,53,54,55,56,57,58,59,60,61,-1,-1,-1,0,-1,-1,  /* 30-3F */
		-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,  /* 40-4F */
		15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,  /* 50-5F */
		-1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,  /* 60-6F */
		41,42,43,44,45,46,47,48,49,50,51,-1,-1,-1,-1,-1,  /* 70-7F */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 80-8F */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* 90-9F */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* A0-AF */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* B0-BF */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* C0-CF */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* D0-DF */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,  /* E0-EF */
		-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1   /* F0-FF */
	};
	char text[400000] = { 0, };
	char decoding[100000] = { 0, };
	int tLength = 0, tIndex = 0, eIndex = 0, step = 0;

	printf_s("input text : ");
	fgets(text, 100000, stdin);
	text[strlen(text) - 1] = '\0';

	tLength = strlen(text);

	while (tIndex < tLength)
	{
		step = 0;
		step = step << 0 | table[text[tIndex + 0]];
		step = step << 6 | table[text[tIndex + 1]];
		step = step << 6 | table[text[tIndex + 2]];
		step = step << 6 | table[text[tIndex + 3]];

		decoding[eIndex + 0] = step >> 16;
		decoding[eIndex + 1] = (step >> 8) & 0xFF;
		decoding[eIndex + 2] = (step >> 0) & 0xFF;

		eIndex += 3;
		tIndex += 4;
	}

	printf("\ndecoding Results: ");
	for (int i = 0; i < tIndex; i++)
	{
		printf("%c", decoding[i]);
	}
	printf("\n");
}

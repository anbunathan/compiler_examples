#include<stdio.h>
#include <stdlib.h>
#include<string.h>
void main()
{
	FILE * f4;
	int lc, sa, l, op1, o, len, op2;
	char m1[20], la[20], op[20], otp[20], op1s[20];
	// char m1[100], la[100], op[100], otp[100],op1s[100];
	// FILE* ptr = fopen("abc.txt","r");
	// char buf1[100], buf2[100],buf3[100];
	
	// while (fscanf(ptr,"%19s\\t%19s\\t%19s", buf1, buf2, buf3)==1) {
	// 	printf("%s\n", buf1);
	// 	printf("%s\n", buf2);
	// 	printf("%s\n", buf3);
	// }	
	//clrscr();
	FILE* f1 = fopen("Input windows.txt", "r");
	FILE* f3 = fopen("symtab.txt", "w");
	// fscanf(f1, "%s\\t%s\\t%d", la, m1, &op1);
	fscanf(f1, "%s %s %d", la, m1, &op1);
	printf("%s\n", m1);
	if (strcmp(m1, "START") == 0)
	{
		sa = op1;
		lc = sa;
		printf("\t%s\t%s\t%d\n", la, m1, op1);
		// fflush(stdout);
	}
	else
		lc = 0;
	// fscanf(f1, "%s\\t%s", la, m1);
	fscanf(f1, "%s %s", la, m1);
	while (!feof(f1))
	{
		// fscanf(f1, "%d", &op2);
		// memcpy(op, &op2, 100);
		fscanf(f1, "%s", op);		
		printf("\n%d\t%s\t%s\t%s\n", lc, la, m1, op);
		if (strcmp(la, "-") != 0)
		{
			fprintf(f3, "\n%d\t%s\n", lc, la);
		}
		FILE* f2 = fopen("Optab.txt", "r");
		fscanf(f2, "%s %d", otp, &o);
		// // fscanf(f2, "%s\\t%d", otp, &o);
		while (!feof(f2))
		{
			if (strcmp(m1, otp) == 0)
			{
				lc = lc + 3;
				break;
			}
			fscanf(f2, "%s %d", otp, &o);
		}
		fclose(f2);
		if (strcmp(m1, "WORD") == 0)
		{
			lc = lc + 3;
		}
		else if (strcmp(m1, "RESW") == 0)
		{
			op1 = atoi(op); 
			lc = lc + (3 * op1);
		}
		else if (strcmp(m1, "BYTE") == 0)
		{
			if (op[0] == 'X')
				lc = lc + 1;
			else
			{
				len = strlen(op) - 2;
				lc = lc + len;
			}
		}
		else if (strcmp(m1, "RESB") == 0)
		{
			op1 = atoi(op);
			lc = lc + op1;
		}
		// // fscanf(f1, "%s\\t%s", la, m1);
		fscanf(f1, "%s %s", la, m1);
	}
	if (strcmp(m1, "END") == 0)
	{
		printf("Program length =\n%d", lc - sa);
	}
	fclose(f1);
	fclose(f3);
	//getch();
}

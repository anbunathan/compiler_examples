#include <stdio.h>
typedef struct
	{
		char IP[16];
		int Port;
		char FileName[255];
		int Min, Max;
	} DataStructure;
int main()
{
	
	DataStructure Data;
	FILE *f = fopen("connect.conf", "r");

	if (fscanf(f, "%s\n%d\n%s\n%d\n%d", Data.IP, &Data.Port, Data.FileName, &Data.Max, &Data.Min) != 5)
	{
		fprintf(stderr, "File not in correct format");
		return -1;
	}

	return 0;
}

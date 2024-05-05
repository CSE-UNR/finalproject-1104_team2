// Author: Ellison Domingo
// Date: 5/5/24
// Description: "LoadImage()" function for final project and simple version of display

#include<stdio.h>

#define MAX_ROWS 500
#define MAX_COLUMNS 500
#define TEST_FILE "test_image.txt"

void LoadImage(int cols, char image[][cols], FILE* file);

int main()
{
	char originalImage[MAX_ROWS][MAX_COLUMNS];
	
	LoadImage(MAX_COLUMNS, originalImage[MAX_ROWS][MAX_COLUMNS], TEST_FILE);	
}

// LoadImage() definition
void LoadImage(int cols, char image[][cols], FILE *file)
{
	printf("\n(Currently file name is hardcoded in for testing, will ask for input later)");
	
	char originalImage[MAX_ROWS][MAX_COLUMNS];

	FILE *filePtr = fopen("test_image.txt", "r");
	if (filePtr == NULL)
	{
		printf("file error\n");
	}
	
	int rowIndex = 0, columnIndex = 0;
	
	while(fscanf(filePtr, "%c", &originalImage[rowIndex][columnIndex]) == 1)
	{
		columnIndex = 0;
		while(fscanf(filePtr, "%c", &originalImage[rowIndex][columnIndex]) == 1)
		{
			columnIndex++;
		}
		rowIndex++;
	}
	
	fclose(filePtr);
		
	printf("\n\nImage successfully loaded.\n");
	
	for (int i = 0; i < rowIndex; i++)
	{
		for (int j = 0; j < columnIndex; j++)
		{
			printf("%c", originalImage[i][j]);
		}
		printf("\n");
	}
}

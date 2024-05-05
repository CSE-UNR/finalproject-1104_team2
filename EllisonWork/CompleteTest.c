// Author: Ellison Domingo
// Date: 5/5/24
// Description: Test Complete Final Project

#include<stdio.h>

#define MAX_ROWS 500
#define MAX_COLUMNS 500
#define TEST_FILE "test_image.txt"

void FirstMenu(int cols, int image[][cols], int *choice);
void LoadImage(int cols, char image[][cols], FILE* file);
void DisplayImage(int cols, char image[][cols]);

int main()
{
	char originalImage[MAX_ROWS][MAX_COLUMNS];
	int firstMenuChoice;
	
	do
	{
		FirstMenu(MAX_COLUMNS, originalImage, &firstMenuChoice);
	} while (firstMenuChoice != 4);
	
	printf("\nGoodbye!\n");
}

// FirstMenu() definition
void FirstMenu(int cols, int image[][cols], int *choice)
{
	
	
	printf("\nWelcome to the image processing program. Please select an option below.");
	printf("\n[1] Load new image");
	printf("\n[2] Display current image");
	printf("\n[3] Edit current image");
	printf("\n[4] Exit the program");
	
	printf("\n\nEnter the number of your choice here: ");
	scanf("%d", &*choice);
	
	switch (*choice)
	{
		case 1:
			LoadImage(MAX_COLUMNS, image, TEST_FILE);
			break;
		case 2:
			printf("\n(supposed to display image)\n");
			DisplayImage(MAX_COLUMNS, image);
			break;
		case 3:
			printf("\n(supposed to edit image)\n");
			break;
		case 4:
			printf("\n(supposed to exit program)\n");
			break;
		default:
			printf("\n(improper choice)\n");
			break;
	}
		
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
// DisplayImage() definition
void DisplayImage(int cols, char image[][cols])
{
	printf("\n");
	
	for (int rowIndex = 0; rowIndex < 12; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < 20; columnIndex++)
		{
			printf("%d", image[rowIndex][columnIndex]);
		}
		printf("\n");
	}
	
	
	
}

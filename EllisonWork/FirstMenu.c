// Author: Ellison Domingo
// Date: 4/29/24
// Description: "FirstMenu()" function for final project

#include<stdio.h>

void FirstMenu();

int main()
{
	FirstMenu();
}

// FirstMenu() definition
void FirstMenu()
{
	int firstMenuChoice;
	
	printf("\nWelcome to the image processing program. Please select an option below.");
	printf("\n[1] Load new image");
	printf("\n[2] Display current image");
	printf("\n[3] Edit current image");
	printf("\n[4] Exit the program");
	
	printf("\n\nEnter the number of your choice here: ");
	scanf("%d", &firstMenuChoice);
	
	switch (firstMenuChoice)
	{
		case 1:
			printf("\n(supposed to load image)\n");
			break;
		case 2:
			printf("\n(supposed to display image)\n");
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

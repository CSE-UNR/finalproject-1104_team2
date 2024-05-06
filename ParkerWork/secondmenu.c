int secondmenu(){
  int choice;
  do{
    printf("**EDITING**\n1: Crop image\n2: Dim image\n3: Brighten image\n0: Return to main menu\n");
    printf("Choose from one of the options above:");
    scanf("%d", &choice);
    if(choice<1 || choice>4){
      printf("\nInvalid choice try again.\n ");
  }
  }while( choice > 4 || choice < 1);
  return choice;


//Conor Raftery - G00274094
//RugbyProject


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
	//char filename[20];
	//char username[20];
	//char password[20];
	int IrfuNum;
	char firstName[20];
	char secondName[20];
	int age;
	float height;
	float weight;
	char club[20];
	char emailAddress[30];
	int tacklesMissed;
	int metresMade;
	int playerPos;
	
	struct node* NEXT;
};

int login();
int signup();
void addPlayerToStart(struct node** top);
void displayPlayers(struct node* top);
void outputFile(struct node* top);
void searchPlayer(struct node* top);
void deletePlayer(struct node* headptr, int pos);
void deleteAtStart(struct node** headptr);
void deleteAtEnd(struct node* headptr);
int posForDel(struct node* top);
int numberOfPlayers(struct node* top);
void updatePlayer(struct node* top);
void statsPos(struct node* top);
void statsWeight(struct node* top);
int inputFromFile(struct node** top);


void main() {

	int loginOption = 0;
	int mainOption = 0;
	char filename[20];
	struct node* head_ptr;
	int deletePos = 0;
	int lastNode = 0;
	int statsOption = 0;
	int count = 0;
	int mainExit = 0;

	head_ptr = NULL;



	//if log in - load previous file
	do{

		printf("Please select option:\n");
		printf(" 1) Login\n 2) Sign up\n -1)Exit\n");
		scanf("%d", &loginOption);

		if (loginOption == 1) {

			loginOption = login();

		}
		else if (loginOption == 2) {

			loginOption = signup();
		}
		else {
			printf("Please enter a valid option / try again\n");
			mainExit = 99;
		}


	}while (loginOption != -1);

	inputFromFile(&head_ptr);

	if (mainExit != 99) {
		//prompt to add player(s) details
		do {



			printf("\n1) Add a new player \n");
			printf("2) Display all players\n");
			printf("3) Display a players details\n");
			printf("4) Update a players stats\n");
			printf("5) Delete a player\n");
			printf("6) Generate a players stats using one criteria\n");
			printf("7) Print all players details to output file\n");
			printf("8) List all the players of the following categories in order of height: i)2nd Row ii) Back row\n");
			printf("-1) Exit\n ");
			scanf("%d", &mainOption);

			switch (mainOption) {
			case 1:
				if (head_ptr == NULL) {
					addPlayerToStart(&head_ptr);
				}
				else {
					addPlayerToStart(&head_ptr); //Switch to addPlayer(head_ptr);
				}
				break;
			case 2:
				displayPlayers(head_ptr);
				break;
			case 3:
				searchPlayer(head_ptr);
				break;
			case 4:
				updatePlayer(head_ptr);
				break;
			case 5:
				deletePos = posForDel(head_ptr);
				lastNode = numberOfPlayers(head_ptr);
				if (head_ptr == NULL) {
					printf("No players available to delete\n");
				}
				else if (deletePos != 0 && deletePos > 1 && deletePos != lastNode) {
					deletePlayer(head_ptr, deletePos);
				}
				else if (deletePos == 1) {
					deleteAtStart(&head_ptr);
				}
				else if (deletePos == lastNode) {
					deleteAtEnd(head_ptr);
				}

				break;
			case 6:
				printf("Please select stats option according to:\n");
				printf("1)Player position\n");
				printf("2)Weight\n");
				scanf("%d", &statsOption);
				if (statsOption == 1) {
					statsPos(head_ptr);
				}
				else if (statsOption == 2) {
					statsWeight(head_ptr);
				}
				else {
					printf("Invalid option!\n");
				}
				break;
			case 7:

				printf("Please select stats option according to:\n");
				printf("1)Player position\n");
				printf("2)Weight\n");
				scanf("%d", &statsOption);
				if (statsOption == 1) {
					statsPos(head_ptr);
				}
				else if (statsOption == 2) {
					statsWeight(head_ptr);
				}
				else {
					printf("Invalid option!\n");
				}

				outputFile(head_ptr);
				printf("Please see 'Rugby.txt'\n");
				break;
			case 8:
				printf("**Option not completed**\n");
				break;
			case -1:
				printf("Program Exited, please see 'Rugby.txt'\n");
				outputFile(head_ptr);
				break;
			default:
				printf("Please enter a valid option!\n");
			}
		} while (mainOption != -1);
	}
	getch();
}//main

int login() {

	char username[20];
	char password[20];
	char enteredUsername[20];
	char enteredPassword[20];
	FILE* filep;
	int read;
	struct node* temp;
	int i;
	char ch;
	
	printf("Entered login\n============================\n");

	printf("Please enter username:\n");
	scanf("%s", username);

	printf("Please enter password:\n");

	//================================================

	for (i = 0; i<6; i++)
	{
		ch = getch();
		password[i] = ch;
		ch = '*';
		printf("%c", ch);
	}

	password[i] = '\0';

	/*If you want to know what you have entered as password, you can print it*/
	//printf("\nYour password is :");


//========================================

	filep = fopen("login.txt", "r");

	if (filep == NULL) {
		printf("\nFile not found! Please sign up!\n");
		signup();
		getch();
		return 1;
	}

	else if (filep != NULL) {
		printf("file found\n");
		getch();


		while (!feof(filep)) {
			read = fscanf(filep, "%s %s", enteredUsername, enteredPassword);

			if (read > 0) {
				if (strcmp(username, enteredUsername) == 0 && strcmp(password, enteredPassword) == 0) {
					printf("Username and Password match!\n");
					getch();
					return -1;
				}//inner if
				else {
				
					//return 1;
				}//else
			}//outerif
		}//while

		printf("Username and password do not match! Please sign up!\n");
		getch();
		return 1;
		//signup();

		fclose(filep);
	}//else if


}//Login

int signup() {

	char username[20];
	char password[20];
	char enteredUsername[20];
	char enteredPassword[20];
	char filename[20];
	FILE* filep;
	int read;
	int i;
	char ch;

	printf("Entered sign up\n============================\n");

	printf("Please enter a username:\n");
	scanf("%s", username);

	printf("Please enter a password:\n");

	//====================================

	for (i = 0; i<6; i++)
	{
		ch = getch();
		password[i] = ch;
		ch = '*';
		printf("%c", ch);
	}

	password[i] = '\0';


	//======================================

	filep = fopen("login.txt", "a");

	fprintf(filep, "\n%s\n", username);
	fprintf(filep, "%s\n", password);

	if (filep != NULL) {
		fclose(filep);
		printf("\nAccount created!\n");
		return 1;
	}

}//signup


void addPlayerToStart(struct node** top) {

	//Used to hold my head_ptr
	struct node* temp;
	int tempNum = 0;

	//Creates a new node
	temp = (struct node*)malloc(sizeof(struct node));
	

	printf("\nPlease enter the players IRFU Number:\n");
	scanf("%d", &temp->IrfuNum);

	printf("Please enter the players First Name:\n");
	scanf("%s", temp->firstName);

	printf("Please enter the players Second Name:\n");
	scanf("%s", temp->secondName);

	printf("Please enter the players Age:\n");
	scanf("%d", &temp->age);

	printf("Please enter the players Height:\n");
	scanf("%f", &temp->height);

	printf("Please enter the players Weight:\n");
	scanf("%f", &temp->weight);

	printf("Please enter the players Club:\n");
	scanf("%s", temp->club);

	printf("Please enter the players E-mail Address:\n");
	scanf("%s", temp->emailAddress);

	printf("Please enter the players Position:\n");
	printf("\t 1) Prop\n");
	printf("\t 2) Hooker\n");
	printf("\t 3) Second Row\n");
	printf("\t 4) Back Row\n");
	printf("\t 5) Half Back\n");
	printf("\t 6) Centre\n");
	printf("\t 7) Winger/Full Back\n");
	scanf("%d", &temp->playerPos);

	printf("Please enter the players Tackles Missed Per Match:\n");
	printf("\t 1) Never\n");
	printf("\t 2) Less than 3\n");
	printf("\t 3) Less than 5\n");
	printf("\t 4) More than 5\n");
	scanf("%d", &temp->tacklesMissed);

	printf("Please enter the players Meters Made Per Match:\n");
	printf("\t 1) None\n");
	printf("\t 2) Less than 10 metres\n");
	printf("\t 3) Less than 20 metres\n");
	printf("\t 4) More than 20 metres\n");
	scanf("%d", &temp->metresMade);
	
	//Make new node the start of list
	temp->NEXT = *top;

	//head_ptr now points at temp
	*top = temp;

}//addPlayerToStart

void displayPlayers(struct node* top) {

	struct node* temp;

	temp = (struct node*)malloc(sizeof(struct node));

	temp = top;

	printf("The list of players are: \n");

	//Loop while outputting value
	while (temp != NULL) {
		printf("\nIRFU Number: %d\n", temp->IrfuNum);
		printf("First Name: %s\n", temp->firstName);
		printf("Second Name: %s\n", temp->secondName);
		printf("Age: %d\n", temp->age);
		printf("Height: %.2f\n", temp->height);
		printf("Weight: %.2f\n", temp->weight);
		printf("Club: %s\n", temp->club);
		printf("Email Address: %s\n", temp->emailAddress);
		
		switch(temp->playerPos) {
		case 1:
			printf("Player Position: Prop\n");
			break;
		case 2:
			printf("Player Position: Hooker\n");
			break;
		case 3:
			printf("Player Position: Second Row\n");
			break;
		case 4:
			printf("Player Position: Back Row\n");
			break;
		case 5:
			printf("Player Position: Half Back\n");
			break;
		case 6:
			printf("Player Position: Centre\n");
		case 7:
			printf("Player Position: Winger/Full Back\n");
			break;
		default:
			printf("Player Position: None\n");
		}

		switch (temp->tacklesMissed) {
		case 1:
			printf("Tackles Missed: Never\n");
			break;
		case 2:
			printf("Tackles Missed: Less than 3\n");
			break;
		case 3:
			printf("Tackles Missed: Less than 5\n");
			break;
		case 4:
			printf("Tackles Missed: More than 5\n");
			break;
		default:
			printf("Tackles missed: N/A \n");
		}

		switch (temp->metresMade) {
		case 1:
			printf("Metres Made: None \n");
			break;
		case 2:
			printf("Metres Made: Less than 10 metres \n");
			break;
		case 3:
			printf("Metres Made: Less than 20 metres \n");
			break;
		case 4:
			printf("Metres Made: More than 20 metres \n");
			break;
		default:
			printf("Metres Made: N/A \n");

		}

		temp = temp->NEXT;
	}

}//Display Players

void searchPlayer(struct node* top) {

	struct node* temp;
	int searchOption = 0;
	int count = 0;
	int found = 0;

	temp = (struct node*)malloc(sizeof(struct node));
	temp = top;

	//temp = top;
	//*top = temp;

	printf("Please enter IRFU Number you wish to find:\n");
	scanf("%d", &searchOption);

	while (temp != NULL) {

		//Search selected option
		if (temp->IrfuNum == searchOption) {
			printf("\nIRFU Number: %d\n", temp->IrfuNum);
			printf("First Name: %s\n", temp->firstName);
			printf("Second Name: %s\n", temp->secondName);
			printf("Age: %d\n", temp->age);
			printf("Height: %.2f\n", temp->height);
			printf("Weight: %.2f\n", temp->weight);
			printf("Club: %s\n", temp->club);
			printf("Email Address: %s\n", temp->emailAddress);

			switch (temp->playerPos) {
			case 1:
				printf("Player Position: Prop\n");
				break;
			case 2:
				printf("Player Position: Hooker\n");
				break;
			case 3:
				printf("Player Position: Second Row\n");
				break;
			case 4:
				printf("Player Position: Back Row\n");
				break;
			case 5:
				printf("Player Position: Half Back\n");
				break;
			case 6:
				printf("Player Position: Centre\n");
			case 7:
				printf("Player Position: Winger/Full Back\n");
				break;
			default:
				printf("Player Position: None\n");
			}

			switch (temp->tacklesMissed) {
			case 1:
				printf("Tackles Missed: Never\n");
				break;
			case 2:
				printf("Tackles Missed: Less than 3\n");
				break;
			case 3:
				printf("Tackles Missed: Less than 5\n");
				break;
			case 4:
				printf("Tackles Missed: More than 5\n");
				break;
			default:
				printf("Tackles missed: N/A \n");
			}

			switch (temp->metresMade) {
			case 1:
				printf("Metres Made: None \n");
				break;
			case 2:
				printf("Metres Made: Less than 10 metres \n");
				break;
			case 3:
				printf("Metres Made: Less than 20 metres \n");
				break;
			case 4:
				printf("Metres Made: More than 20 metres \n");
				break;
			default:
				printf("Metres Made: N/A \n");

			}
			found = 1;
			break;
		}
		temp = temp->NEXT;
	}

	if (found == 0) {
		printf("Element not found\n");
	}

}//searchList

void deletePlayer(struct node* headptr, int searchOption) {

	struct node* temp;
	struct node* oldtemp;
	int count = 0;
	int found = 0;
	int foundPos = 0;

	temp = (struct node*)malloc(sizeof(struct node));
	temp = headptr;

	while (temp != NULL) {
		count++;
		//Search selected option
		if (temp->IrfuNum == searchOption) {
			foundPos = count;
		}

		temp = temp->NEXT;
	}

	temp = headptr;

		for (int i = 0; i < foundPos - 1; i++) {

			oldtemp = temp;
			temp = temp->NEXT;
			printf("Stuck in for");

		}
		oldtemp->NEXT = temp->NEXT;
		free(temp);


	
}//DeletePlayer

void deleteAtStart(struct node** headptr) {

	struct node* temp;

	temp = *headptr;

	*headptr = temp->NEXT;

	free(temp);

}

int posForDel(struct node* top) {

	struct node* temp;
	int searchOption = 0;
	int count = 0;
	int found = 0;
	int foundPos = 0;

	temp = (struct node*)malloc(sizeof(struct node));
	temp = top;

	printf("Please enter IRFU Number you wish to find:\n");
	scanf("%d", &searchOption);

	while (temp != NULL) {
		count++;
		//Search selected option
		if (temp->IrfuNum == searchOption) {
			foundPos = count;
		}
		temp = temp->NEXT;
	}
	if (foundPos == 0) {
		printf("Element not found\n");
	}
	return foundPos;

}//posForDel

int numberOfPlayers(struct node* top) {

	struct node* temp;
	int searchOption = 0;
	int count = 0;

	temp = (struct node*)malloc(sizeof(struct node));
	temp = top;

	while (temp != NULL) {
		count++;
		temp = temp->NEXT;
	}
	return count;
}

void deleteAtEnd(struct node* headptr)
{
	struct node* temp;
	struct node* old_temp;

	temp = headptr;

	//Loop until the function is at the last node -- also kept track of the node immediately before that
	while (temp->NEXT != NULL)
	{

		old_temp = temp;
		temp = temp->NEXT;
	}

	// Make the node immediately before the last element the new end of the list...
	old_temp->NEXT = NULL;

	free(temp);
}
void updatePlayer(struct node* top) {
	struct node* temp;
	int searchOption = 0;
	int count = 0;
	int found = 0;

	temp = (struct node*)malloc(sizeof(struct node));
	temp = top;

	//temp = top;
	//*top = temp;

	printf("Please enter IRFU Number you wish to update:\n");
	scanf("%d", &searchOption);

	while (temp != NULL) {

//Search selected option
if (temp->IrfuNum == searchOption) {
	printf("\nPlease enter the players IRFU Number:\n");
	scanf("%d", &temp->IrfuNum);

	printf("Please enter the players First Name:\n");
	scanf("%s", temp->firstName);

	printf("Please enter the players Second Name:\n");
	scanf("%s", temp->secondName);

	printf("Please enter the players Age:\n");
	scanf("%d", &temp->age);

	printf("Please enter the players Height:\n");
	scanf("%f", &temp->height);

	printf("Please enter the players Weight:\n");
	scanf("%f", &temp->weight);

	printf("Please enter the players Club:\n");
	scanf("%s", temp->club);

	printf("Please enter the players E-mail Address:\n");
	scanf("%s", temp->emailAddress);

	printf("Please enter the players Position:\n");
	printf("\t 1) Prop\n");
	printf("\t 2) Hooker\n");
	printf("\t 3) Second Row\n");
	printf("\t 4) Back Row\n");
	printf("\t 5) Half Back\n");
	printf("\t 6) Centre\n");
	printf("\t 7) Winger/Full Back\n");
	scanf("%d", &temp->playerPos);

	printf("Please enter the players Tackles Missed Per Match:\n");
	printf("\t 1) Never\n");
	printf("\t 2) Less than 3\n");
	printf("\t 3) Less than 5\n");
	printf("\t 4) More than 5\n");
	scanf("%d", &temp->tacklesMissed);

	printf("Please enter the players Meters Made Per Match:\n");
	printf("\t 1) None\n");
	printf("\t 2) Less than 10 metres\n");
	printf("\t 3) Less than 20 metres\n");
	printf("\t 4) More than 20 metres\n");
	scanf("%d", &temp->metresMade);


	found = 1;
	break;
}
temp = temp->NEXT;
	}

	if (found == 0) {
		printf("Element not found\n");
	}
}//updatePlayer

void statsPos(struct node* top) {

	int chosenPos = 0;
	float playerCount = 0;

	float neverMissed = 0;
	float lessThree = 0;
	float lessFive = 0;
	float moreFive = 0;
	float neverMissedPercent = 0;
	float lessThreePercent = 0;
	float lessFivePercent = 0;
	float moreFivePercent = 0;

	int saveOption = 0;
	FILE* reportFile;

	struct node* temp;
	int searchOption = 0;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = top;

	printf("Please select which stats you want to view for specific position:\n");
	printf("\t 1) Prop\n");
	printf("\t 2) Hooker\n");
	printf("\t 3) Second Row\n");
	printf("\t 4) Back Row\n");
	printf("\t 5) Half Back\n");
	printf("\t 6) Centre\n");
	printf("\t 7) Winger/Full Back\n");
	scanf("%d", &chosenPos);


	while (temp != NULL) {

		if (temp->playerPos == chosenPos) {
			playerCount++;

			if (temp->tacklesMissed == 1) {
				neverMissed++;
			}
			else if (temp->tacklesMissed == 2) {
				lessThree++;
			}
			else if (temp->tacklesMissed == 3) {
				lessFive++;
			}
			else if (temp->tacklesMissed == 4) {
				moreFive++;
			}
		}
		temp = temp->NEXT;
	}//while

	//calculations
	neverMissedPercent = (neverMissed / playerCount) * 100;
	lessThreePercent = (lessThree / playerCount) * 100;
	lessFivePercent = (lessFive / playerCount) * 100;
	moreFivePercent = (moreFive / playerCount) * 100;

		printf("Would you like to:\n");
		printf("1) Overwrite current details in report file\n");
		printf("2) Add these details at the end of the report file\n");
		scanf("%d", &saveOption);

	if (saveOption == 1) {
		//w
		reportFile = fopen("report.txt", "w");
	}
	else if (saveOption == 2) {
		//a
		reportFile = fopen("report.txt", "a");
	}
	else {
		printf("Invalid option!\n");
		return;
	}


	switch (chosenPos) {
	case 1:
		printf("Players in Position: Prop\n");
		fprintf(reportFile, "Players in Position: Prop\n");
		break;
	case 2:
		printf("Players in Position: Hooker\n");
		fprintf(reportFile, "Players in Position: Hooker\n");
		break;
	case 3:
		printf("Players in Position: Second Row\n");
		fprintf(reportFile, "Players in Position: Second Row\n");
		break;
	case 4:
		printf("Players in Position: Back Row\n");
		fprintf(reportFile, "Players in Position: Back Row\n");
		break;
	case 5:
		printf("Players in Position: Half Back\n");
		fprintf(reportFile, "Players in Position: Half Back\n");
		break;
	case 6:
		printf("Players in Position: Centre\n");
		fprintf(reportFile, "Players in Position: Centre\n");
	case 7:
		printf("Players in Position: Winger/Full Back\n");
		fprintf(reportFile, "Players in Position: Winger/Full Back\n");
		break;
	default:
		printf("Players in Position: None\n");
		fprintf(reportFile, "Players in Position: None\n");
	}

	printf("Percentage of players who miss no tackles: %.2f\n", neverMissedPercent);
	fprintf(reportFile, "Percentage of players who miss no tackles: %.2f\n", neverMissedPercent);

	printf("Percentage of players who miss less than 3 tackles per match: %.2f\n", lessThreePercent);
	fprintf(reportFile, "Percentage of players who miss less than 3 tackles per match: %.2f\n", lessThreePercent);

	printf("Percentage of players who miss less than 5 tackles per match: %.2f\n", lessFivePercent);
	fprintf(reportFile, "Percentage of players who miss less than 5 tackles per match: %.2f\n", lessFivePercent);

	printf("Percentage of players who miss more than 5 tackles per match: %.2f\n", moreFivePercent);
	fprintf(reportFile, "Percentage of players who miss more than 5 tackles per match: %.2f\n", moreFivePercent);
	fprintf(reportFile, "\n");

	fclose(reportFile);

	printf("Please see 'report.txt'\n");

}//statsPos

void statsWeight(struct node* top) {
	float chosenWeight = 0;
	float playerCount = 0;

	float noMeters = 0;
	float lessTen = 0;
	float lessTwenty = 0;
	float moreTwenty = 0;
	float noMetersPercent = 0;
	float lessTenPercent = 0;
	float lessTwentyPercent = 0;
	float moreTwentyPercent = 0;

	int saveOption = 0;
	FILE* reportFile;

	struct node* temp;
	int searchOption = 0;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = top;

	printf("Please enter weight (kg):\n");
	scanf("%f", &chosenWeight);


	while (temp != NULL) {

		if (temp->weight >= chosenWeight) {
			playerCount++;

			if (temp->metresMade == 1) {
				noMeters++;
			}
			else if (temp->metresMade == 2) {
				lessTen++;
			}
			else if (temp->metresMade == 3) {
				lessTwenty++;
			}
			else if (temp->metresMade == 4) {
				moreTwenty++;
			}
		}
		temp = temp->NEXT;
	}//while

	 //calculations
	noMetersPercent = (noMeters / playerCount) * 100;
	lessTenPercent = (lessTen / playerCount) * 100;
	lessTwentyPercent = (lessTwenty / playerCount) * 100;
	moreTwentyPercent = (moreTwenty / playerCount) * 100;


		printf("Would you like to:\n");
		printf("1) Overwrite current details in report file\n");
		printf("2) Add these details at the end of the report file\n");
		scanf("%d", &saveOption);
	
	if (saveOption == 1) {
		//w
		reportFile = fopen("report.txt", "w");
	}
	else if (saveOption == 2) {
		//a
		reportFile = fopen("report.txt", "a");
	}
	else {
		printf("Invalid option!\n");
		return;
	}

	printf("Players over the weight of: %.2f\n", chosenWeight);
	fprintf(reportFile, "Players over the weight of: %.2f\n", chosenWeight);

	printf("Percentage of players who make no metres in a game: %.2f\n", noMetersPercent);
	fprintf(reportFile, "Percentage of players who make no metres in a game: %.2f\n", noMetersPercent);

	printf("Percentage of players who make less than 10 metres in a game: %.2f\n", lessTenPercent);
	fprintf(reportFile, "Percentage of players who make less than 10 metres in a game: %.2f\n", lessTenPercent);

	printf("Percentage of players who make less than 20 metres in a game: %.2f\n", lessTwentyPercent);
	fprintf(reportFile, "Percentage of players who make less than 20 metres in a game: %.2f\n", lessTwentyPercent);

	printf("Percentage of players who make more than 20 metres in a game: %.2f\n", moreTwentyPercent);
	printf(reportFile, "Percentage of players who make more than 20 metres in a game: %.2f\n", moreTwentyPercent);
	fprintf(reportFile, "\n");

	fclose(reportFile);

	printf("Please see 'report.txt'\n");
}//statsWeight









void outputFile(struct node* top) {

	struct node* temp;

	temp = (struct node*)malloc(sizeof(struct node));

	temp = top;

	FILE* readInFile;

	readInFile = fopen("readIn.txt", "a");

	//Loop while outputting value
	while (temp != NULL) {

		fprintf(readInFile, "%d\n", temp->IrfuNum);
		fprintf(readInFile, "%s\n", temp->firstName);
		fprintf(readInFile, "%s\n", temp->secondName);
		fprintf(readInFile, "%d\n", temp->age);
		fprintf(readInFile, "%.2f\n", temp->height);
		fprintf(readInFile, "%.2f\n", temp->weight);
		fprintf(readInFile, "%s\n", temp->club);
		fprintf(readInFile, "%s\n", temp->emailAddress);
		fprintf(readInFile, "%d\n", temp->playerPos);
		fprintf(readInFile, "%d\n", temp->tacklesMissed);
		fprintf(readInFile, "%d\n", temp->metresMade);

		temp = temp->NEXT;
	}

	fclose(readInFile);


	FILE* mainFile;

	mainFile = fopen("Rugby.txt", "a");

	temp = (struct node*)malloc(sizeof(struct node));

	temp = top;

	fprintf(mainFile, "The list of players are: \n");

	//Loop while outputting value
	while (temp != NULL) {
		fprintf(mainFile, "\nIRFU Number: %d\n", temp->IrfuNum);
		fprintf(mainFile, "First Name: %s\n", temp->firstName);
		fprintf(mainFile, "Second Name: %s\n", temp->secondName);
		fprintf(mainFile, "Age: %d\n", temp->age);
		fprintf(mainFile, "Height: %.2f\n", temp->height);
		fprintf(mainFile, "Weight: %.2f\n", temp->weight);
		fprintf(mainFile, "Club: %s\n", temp->club);
		fprintf(mainFile, "Email Address: %s\n", temp->emailAddress);

		switch (temp->playerPos) {
		case 1:
			fprintf(mainFile, "Player Position: Prop\n");
			break;
		case 2:
			fprintf(mainFile, "Player Position: Hooker\n");
			break;
		case 3:
			fprintf(mainFile, "Player Position: Second Row\n");
			break;
		case 4:
			fprintf(mainFile, "Player Position: Back Row\n");
			break;
		case 5:
			fprintf(mainFile, "Player Position: Half Back\n");
			break;
		case 6:
			fprintf(mainFile, "Player Position: Centre\n");
		case 7:
			fprintf(mainFile, "Player Position: Winger/Full Back\n");
			break;
		default:
			fprintf(mainFile, "Player Position: None\n");
		}

		switch (temp->tacklesMissed) {
		case 1:
			fprintf(mainFile, "Tackles Missed: Never\n");
			break;
		case 2:
			fprintf(mainFile, "Tackles Missed: Less than 3\n");
			break;
		case 3:
			fprintf(mainFile, "Tackles Missed: Less than 5\n");
			break;
		case 4:
			fprintf(mainFile, "Tackles Missed: More than 5\n");
			break;
		default:
			fprintf(mainFile, "Tackles missed: N/A \n");
		}

		switch (temp->metresMade) {
		case 1:
			fprintf(mainFile, "Metres Made: None \n");
			break;
		case 2:
			fprintf(mainFile, "Metres Made: Less than 10 metres \n");
			break;
		case 3:
			fprintf(mainFile, "Metres Made: Less than 20 metres \n");
			break;
		case 4:
			fprintf(mainFile, "Metres Made: More than 20 metres \n");
			break;
		default:
			fprintf(mainFile, "Metres Made: N/A \n");

		}

		temp = temp->NEXT;
	}
	fclose(mainFile);

}//outputFile


int inputFromFile(struct node** top) {

	//Used to hold my head_ptr
	FILE* readInFile;
	int result;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	readInFile = fopen("readIn.txt", "r");

	if (readInFile == NULL) {
		printf("No previous data found\n");
		return 1;
	}

		
		while (fscanf(readInFile, "%d", &temp->IrfuNum) == 1) {
			struct node* temp;

			//Creates a new node
			temp = (struct node*)malloc(sizeof(struct node));

			fscanf(readInFile, "%d", &temp->IrfuNum);

			fscanf(readInFile, "%s", temp->firstName);

			fscanf(readInFile, "%s", temp->secondName);

			fscanf(readInFile, "%d", &temp->age);

			fscanf(readInFile, "%f", &temp->height);

			fscanf(readInFile, "%f", &temp->weight);

			fscanf(readInFile, "%s", temp->club);

			fscanf(readInFile, "%s", temp->emailAddress);

			fscanf(readInFile, "%d", &temp->playerPos);

			fscanf(readInFile, "%d", &temp->tacklesMissed);

			fscanf(readInFile, "%d", &temp->metresMade);


			//Make new node the start of list
			temp->NEXT = *top;

			//head_ptr now points at temp
			*top = temp;

			
			//return 0;
		}
		fclose(readInFile);
	

}//InputFromFile

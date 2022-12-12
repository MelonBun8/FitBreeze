//whole login & register system + file handling + file edit function + main function formatting: SAAD ARFAN
//MP3 player + encryption + getpass
//data collection for fitbreeze + final report + the 2 getters + execution function
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <MMsystem.h>
#include<string.h>
#define ENTER 13 //ASCII values for special characters, used in getPass()
#define TAB 9
#define BCKSPC 8
#define MAX_LINE_LENGTH 50 //USED IN LOGIN PAGE, WHEN READING THE FILE
#define BUFFER_SIZE 50// temporary line size setter for file editing

//*********DEFINING GLOBAL VARIABLES
int plan_line, day_line, part_line, prog_1_line, prog_2_line, prog_3_line, prog_4_line, prog_5_line, prog_6_line, prog_7_line, start_error, pg_one_inp;
FILE *filePointer; 


typedef struct{//creating a struct (group of related variables for user) typedef allows us to user user as any other data type

	char username[50];
	char password[50];
	char plan;// CAN be either '0' for underweight, '2' for overweight and '1' for regular
	char day;//if the day is 0, BMI hasn't been checked, goes up to 7 
	char part;//part zero means we give them their diet plan, part one means they are coming back to the app to check their progress
	char prog1;//can be either 1, 2, 3, or 4 (25%, 50%, 75% and 100% respectively)
	char prog2;
	char prog3;
	char prog4;
	char prog5;
	char prog6;
	char prog7;
	
}user;

user current;//defining our current user with user data type / struct
//*********DEFINING FUNCTIONS BEFORE MAIN BODY

void bollywood(){

	system("cls");
	int choices = 0;
	
	while(choices!=5 && choices != 4){
		printf("1.JUMME KI RAAT \n2.KABHI JO BADAL BARSE \n3.USKAA HI BANNA \n4.Back to the main menu\n5.Exit\t");
		scanf("%d",&choices);
		switch(choices){
			case 1:
				printf("now playing jumme ki raat hai");
				PlaySound("Jumme Ki Raat.wav",NULL,SND_ASYNC);
				break;
			case 2:
				PlaySound("Kabhi Jo Baadal Barse.wav",NULL,SND_ASYNC);
				break;
			case 3:
				PlaySound("Uska Hi Banna.wav",NULL,SND_ASYNC);
				break;
			case 0:
				PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
				break;
			case 4:
				back();
				break;
			case 5:
				exit(0);
				
	}//switch END
	
	system("cls");

	}//while END
}//bollywood function END

void hollywood(){
	system("cls");
	int choices = 0;

	while(choices!=5 && choices != 4){
		printf("1.JUMME KI RAAT \n2.KABHI JO BADAL BARSE \n3.USKAA HI BANNA \n4.Back to the main menu\n5.Exit\t");
		scanf("%d",&choices);
		switch(choices){
			case 1:
				printf("now playing jumme ki raat hai");
				PlaySound("Jumme Ki Raat.wav",NULL,SND_ASYNC);
				break;
			case 2:
				PlaySound("Kabhi Jo Baadal Barse.wav",NULL,SND_ASYNC);
				break;
			case 3:
				PlaySound("Uska Hi Banna.wav",NULL,SND_ASYNC);
				break;
			case 0:
				PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
				break;
			case 4:
				back();
				break;
			case 5:
				exit(0);
		}//switch END
	system("cls");
	}//while END

}//hollywood END

void AllSongs(){
	
	system("cls");
	int choices = 0;

	while(choices!=8 && choices !=7){
		printf("1.JUMME KI RAAT \n2.KABHI JO BADAL BARSE \n3.USKAA HI BANNA \n4.JUMME KI RAAT \n5.KABHI JO BADAL BARSE \n6.USKAA HI BANNA\n7.Back to the main menu\n8.Exit\t");
		scanf("%d",&choices);
		switch(choices){
			
			case 1:
				PlaySound("Jumme Ki Raat.wav",NULL,SND_ASYNC);
				break;
			case 2:
				PlaySound("Kabhi Jo Baadal Barse.wav",NULL,SND_ASYNC);
				break;
			case 3:
				PlaySound("Uska Hi Banna.wav",NULL,SND_ASYNC);
				break;
			case 4:
				PlaySound("Jumme Ki Raat.wav",NULL,SND_ASYNC);
				break;
			case 5:
				PlaySound("Kabhi Jo Baadal Barse.wav",NULL,SND_ASYNC);
				break;
			case 6:
				PlaySound("Uska Hi Banna.wav",NULL,SND_ASYNC);
				break;
			case 0:
				PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
				break;
			case 7:
				back();
				break;
			case 8:
				exit(0);
				
		}//switch END
		system("cls");
	}//while END
}//aLLsongs END

void back (){ // used to go back to main menu of music player

	PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
	system("cls");
	mainMusic();

}

int mainMenu(){

	int choice;
	system("cls");

	puts("*****************************\n\tMAIN -|- MENU\n*****************************");
	printf("Welcome %s, what would you like to do?\n\n",current.username);
	puts("\n1. Start / Resume your fitness journey");
	puts("2. Enter workout mode and listen to your favorite songs as you work out!");
	puts("\nEnter your choice: ");
	fflush(stdin);
	
	scanf("%d",&choice);
	return choice;
	
}//mainMenu END

void introPage(){//Main menu of MP3 Player
	system("cls");
	printf("\n\n");                                                                                                                                                              
	puts("\t\t#  #  # ###### #       ####   ####  #    # ######    #####  ####     ##### #    # ######    #    # #    #  ####  #  ####     #####  #        ##   #   # ###### #####");  
	puts("\t\t#  #  # #      #      #    # #    # ##  ## #           #   #    #      #   #    # #         ##  ## #    # #      # #    #    #    # #       #  #   # #  #      #    #"); 
	puts("\t\t#  #  # #####  #      #      #    # # ## # #####       #   #    #      #   ###### #####     # ## # #    #  ####  # #         #    # #      #    #   #   #####  #    #"); 
	puts("\t\t#  #  # #      #      #      #    # #    # #           #   #    #      #   #    # #         #    # #    #      # # #         #####  #      ######   #   #      #####");  
	puts("\t\t#  #  # #      #      #    # #    # #    # #           #   #    #      #   #    # #         #    # #    # #    # # #    #    #      #      #    #   #   #      #   #");  
	puts("\t\t ## ##  ###### ######  ####   ####  #    # ######      #    ####       #   #    # ######    #    #  ####   ####  #  ####     #      ###### #    #   #   ###### #    #\n\n\n"); 
		
}//IntroPage END

int mainMusic(){
	
	system("COLOR 5E");
	system("cls");
	introPage();
	int options;
	printf("1.Bollywood songs\n2.Hollywood songs\n3.All songs\n4.Exit ");
	fflush(stdin);
	scanf("%d",&options);

	switch(options){
		case 1:
			bollywood();
			break;
		case 2:
		    hollywood();
		    system("cls");
			break;
		case 3:
		    AllSongs();
			break;	
		case 4:
			return;
			break;
		}//switch END
	
}//mainMusic END

char* crypt( char choice, char to_be_crypted[50]){//encrypts and decrypts strings (will use for encryption of username and password before storing to text file)
	
	int i; 
	switch(choice){
	   	
		case 'e':
		case 'E':
			
	      for(i = 0; (i < 50 && to_be_crypted[i] != '\0'); i++){
	        to_be_crypted[i] = to_be_crypted[i] + 8; //encryption key is : add 8 to ASCII value
			}
	      break;
	
	    case 'D':
	   	case 'd':
	   		
	      for(i = 0; (i < 50 && to_be_crypted[i] != '\0'); i++){
	        to_be_crypted[i] = to_be_crypted[i] - 8; //decryption key is : minus 8 to ASCII value
		}
	      break;
	
	   default:
	      printf("\nError\n");
	    }//switch END
		
		return to_be_crypted;	

}//crypt function END

void executioner(){//DELETES CURRENT PROFILE (ONCE 7 DAYS ARE COMPLETE)

	FILE *tempFile;
	char buffer[BUFFER_SIZE];
	int cnt, change_line;

	fflush(stdin);
	
	tempFile = fopen("replace.tmp", "w");
	filePointer = fopen("profiles.txt", "r");
	
	cnt = -1;
	while((fgets(buffer, BUFFER_SIZE, filePointer)) != NULL){
		cnt +=1;
		
		if(cnt == (plan_line - 2) || cnt == (plan_line - 1) || cnt == plan_line || cnt == day_line || cnt == part_line || cnt == prog_1_line || cnt == prog_2_line || cnt == prog_3_line || cnt == prog_4_line || cnt == prog_5_line || cnt == prog_6_line || cnt == prog_7_line || cnt == (prog_7_line + 1)){
			continue;//skips / deletes those lines by not writing them to updated file.
		}
		else{
			fputs(buffer, tempFile);
		}
	}
	
	fclose(filePointer);
	fclose(tempFile);
	
	
	int ret = remove("profiles.txt");

	   if(ret == 0) {
	      printf("Profile deleted successfully");
	   } else {
	      printf("Error: unable to delete the profile");
	   }

	rename("replace.tmp","profiles.txt");
	
}//executioner END

void finalReport(){//CREATES FINAL REPORT OF 7 DAYS, GIVING TOTAL PERCENT COMPLETION

	float *progress = (char *) calloc(8,sizeof(int));
	//float progress[8];
	float total = 0;
	char medal;
	progress[0] = (current.prog1 - 48);
	progress[1] = (current.prog2 - 48);
	progress[2] = (current.prog3 - 48);
	progress[3] = (current.prog4 - 48);
	progress[4] = (current.prog5 - 48);
	progress[5] = (current.prog6 - 48);
	progress[6] = (current.prog7 - 48);
	
	for (int i = 0; i < 7; i++){
		total += progress[i];
	}//for END
	
	total = (total * 25.0) / 7.0;
	
	if(total >= 50 && total < 70){
		printf("Nice job, you managed to obtain %.1lf%% progress, and earned yourself a bronze medal!!\n",total);
	}
	else if(total >= 70 && total < 85){
		printf("Great job! you managed to obtain %.1lf%% progress, and earned yourself a silver medal!!\n",total);
	}
	else if(total >= 85 && total <= 100){
		printf("Excellent work! you managed to obtain %.1lf%% progress, and earned yourself a gold medal!!\n",total);
	}
	
	free(progress);
	
	puts("Congratulations on completing your 7 day fitness program! If you are happy with your results, great!\nbut if you would like to lose more weight, consider signing up again and restarting the challenge\nafter all, consistency is key!");
	puts("\n\nThank you for using FitBreeze (C), we hope our app proved fruitful to you.\n\n**ACCOUNT DELETED, REGISTER AGAIN TO RESTART**");	
	executioner();
	
		
}//finalReport END

void fileEdit(char edit_choice, char change[2] ){//FILE EDITING FUNCTION  | edit_choice options: P: plan, D: day, numbers 1 to 7 for progress of 7days: progress, R: part
	//makes a temporary file, copies everything except line to be edited, which is updated, temp file made permanent, old file deleted
	//all we have to do is input edit choice as well as our new value
	FILE *tempFile;
	
	char buffer[BUFFER_SIZE];
	char newline[BUFFER_SIZE] = {'\0'};
	int cnt, change_line;
	
	switch (edit_choice){
		case 'P'://plan
			change_line = plan_line;
		break;
		case 'D'://day
			change_line = day_line;
		break;
		case 'R'://part
			change_line = part_line;
		break;	
		case '1'://progress
			change_line = prog_1_line; 
		break;
		case '2'://progress
			change_line = prog_2_line; 
		break;
		case '3'://progress
			change_line = prog_3_line; 
		break;
		case '4'://progress
			change_line = prog_4_line; 
		break;
		case '5'://progress
			change_line = prog_5_line; 
		break;
		case '6'://progress
			change_line = prog_6_line; 
		break;
		case '7'://progress
			change_line = prog_7_line; 
		break;
		
			
	}
	newline[0] = change[0];
	newline[1] = '\n';
	fflush(stdin);
	
	tempFile = fopen("replace.tmp", "w");
	filePointer = fopen("profiles.txt", "r");
	
	cnt = -1;
	while((fgets(buffer, BUFFER_SIZE, filePointer)) != NULL){
		cnt +=1;
		
		if(cnt == change_line){
			fputs(newline, tempFile);
		}
		else{
			fputs(buffer, tempFile);
		}
	}
	
	fclose(filePointer);
	fclose(tempFile);
	
	
	int ret = remove("profiles.txt");

	rename("replace.tmp","profiles.txt");
	
}//FILE EDIT FUNCTION END

void progGetter(){//ASKS THE USER FOR A PROGRESS UPDATE FOR THE DAY, THEN UPDATES FILE AND TEMP CURRENT 
	//ALSO UPDATES THE DAY AFTER
	system("cls");
	printf("****Day %c Completed****\n\n",current.day);
	puts("Please choose how much you believe you followed our program: \n");
	puts("1. Very little (~25%)\n2. About halfway (~50%)\n3. Mostly, with minor setbacks (~75%)\n4. Completely - start to finish (~100%)");
	char prog_update[2] = {'\0'};
	fflush(stdin);
	gets(prog_update);

	switch( current.day ){
		case '1':
			fileEdit('1', prog_update);
			break;
		case '2':
			fileEdit('2', prog_update);
			break;	
		case '3':
			fileEdit('3', prog_update);
			break;
			
		case '4':
			fileEdit('4', prog_update);
			break;
			
		case '5':
			
			fileEdit('5', prog_update);
			break;
			
		case '6':
			fileEdit('6', prog_update);			
			break;
			
		case '7':
			fileEdit('7', prog_update);
			break;		
			
	}//switch END
	//PART RESETS TO 0 TOO
	
	char part_updater[2] = {'\0'};
	current.part -= 1;
	part_updater[0] = current.part;
	fileEdit('R', part_updater);
	//AFTER getting progress, changes over to the next day
	char day_incrementer[2] = {'\0'};
	current.day += 1; //moves up one ASCII value, we don't go over 7, so there's no issue.
	day_incrementer[0] = current.day;
	fileEdit('D', day_incrementer );
	
}//progGetter END

void planGetter(){//OUTPUTS THE ENTIRE NURITION + EXERCISE PLAN FOR THE DAY
	//we will have 21 text files, name eg: "05.txt" will have plan of day 5 of underweight plan 
	system("cls");
	char part_updater[2] = {'\0'};
	current.part += 1;
	part_updater[0] = current.part;
	char file_name[10] = {'\0'};
	file_name[0] = current.plan;
	file_name[1] = current.day;
	strcat(file_name,".txt");
	FILE *planFile;
	planFile = fopen(file_name,"r");
	char line[500];
	int line_num = -1;
	
	while (fgets(line, sizeof(line), planFile)) {
		puts(line);
	}

	fileEdit('R', part_updater);
	fclose(planFile);
	puts("Press enter to continue...");
	fflush(stdin);
	getchar();

}//day_getter FUNCTION END

int startPage(){//START PAGE DISPLAY FUNCTION
	puts("_____________________/\\//_______                            ___ ___  \n___  ____/__(_)_  /_//\\/___  __ )_____________________________ \\__ \\ \n__  /_   __  /_  __/    __  __  |_  ___/  _ \\  _ \\__  /_  _ \\__ \\__ \\\n_  __/   _  / / /_      _  /_/ /_  /   /  __/  __/_  /_/  __/_  /_  /\n/_/      /_/  \\__/      /_____/ /_/    \\___/\\___/_____/\\___/_/_/_/_/ ");
                                                                     
	puts("\nWelcome to Fitbreeze, your one and only destination for all your fitness needs!\n");
	
	do{
		start_error = 0;
		
		puts("Please select from the following options to get started:");
		puts("1. Login to your account (pre-existing users)\n2. Register a new account (new users)\n" );
		scanf("%d", &pg_one_inp);
		if (pg_one_inp != 1 && pg_one_inp != 2) {
			system("cls");
			puts("Invalid input, try again.\n");
			start_error = 1;
			}
		}
	while (start_error == 1);	

	return pg_one_inp;

}//END OF START PAGE DISPLAY FUNCTION

void getPass(char arr[50]){//Function to get password

	int i=0;
	char ch;

	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			arr[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			arr[i++] = ch;
			printf("* \b");
		}
	}//while END

}//getPass END

void loginPage(){//LOGIN FUNCTION START
	//the login function will open and read profiles file line by line and verify input details.
	int username_match = 0, password_match = 0, plan_get = 0, day_get = 0, part_get=0, prog1_get = 0, prog2_get = 0, prog3_get = 0, prog4_get = 0, prog5_get = 0, prog6_get = 0, prog7_get = 0;
	system("cls");
	
	FILE *filePointer = fopen("profiles.txt", "r");
	char line[500];
	int line_num = -1;
	
	//while(strcmp
	
	puts("********LOGIN********\n");
	fflush(stdin);
	puts("Enter your username");
	gets(current.username);
	fflush(stdin);
	puts("\nEnter your password" );	
	getPass(current.password);
	
	while (fgets(line, sizeof(line), filePointer)) {
		line_num += 1;
		char curr_word[30] = {'\0'};
		int i = 0;
		
		while(line[i]!='\0'){
			if(line[i]=='\n'){//This is so that newline character not read, messes up the strcmp
					i++;
					continue;
				}
				curr_word[i] = line[i];
				i++;
			}//inner while END	
			
		if((prog7_get == 1)){
			
		//	printf("\nYou are on part %c of day %c of your program, day 5s progress is: %c, which is on line number %d in the file\n",current.part, current.day, current.prog5, prog_5_line);
			puts("\nYou have successfully logged in! Now moving to Main page\n(Press enter to continue)\n");
			fflush(stdin);
			getchar();
			fclose(filePointer);
			break;
		}
			
		if(prog6_get == 1){
			prog7_get = 1;
			current.prog7 = curr_word[0];
			continue;
		}
		
		if(prog5_get == 1){
			prog6_get = 1;
			current.prog6 = curr_word[0];
			continue;
		}
		
		if(prog4_get == 1){
			prog5_get = 1;
			current.prog5 = curr_word[0];
			continue;
		}
		
		if(prog3_get == 1){
			prog4_get = 1;
			current.prog4 = curr_word[0];
			continue;
		}
		
		if(prog2_get == 1){
			prog3_get = 1;
			current.prog3 = curr_word[0];
			continue;
		}
		
		if(prog1_get == 1){
			prog2_get = 1;
			current.prog2 = curr_word[0];
			continue;
		}
		
		if(part_get == 1){
			prog1_get = 1;
			current.prog1 = curr_word[0];
			continue;
		}
		
		if(day_get == 1){
			part_get = 1;
			current.part = curr_word[0];
			continue;
		}
		
		
		if(plan_get == 1){
			day_get = 1;
			current.day = curr_word[0];
			continue;
		}
		
		if(password_match == 1){
			plan_get = 1;
			current.plan = curr_word[0];
			continue;
		}
		
		if(username_match == 1){
			if((strcmp(current.password,crypt('D',curr_word))) == 0){
			password_match = 1;
			continue;
		}
		}
		
		if(username_match == 0){
			if((strcmp(current.username,crypt('D',curr_word))) == 0){
				username_match = 1;
				plan_line = line_num + 2;
				day_line = line_num + 3;
				part_line = line_num + 4;
				prog_1_line = line_num + 5;
				prog_2_line = line_num + 6;
				prog_3_line = line_num + 7;
				prog_4_line = line_num + 8;
				prog_5_line = line_num + 9;
				prog_6_line = line_num + 10;
				prog_7_line = line_num + 11;
				continue;
				
			}
		}
	
		
	}//while end
			
	if((username_match == 0) || (password_match == 0)){
			puts("\nINCORRECT LOGIN DETAILS, TRY AGAIN");
			fflush(stdin); 
			getchar();
			fflush(stdin);
			loginPage();
		}

	
}//END OF LOGIN FUNCTION

void registerPage(){//REGISTER FUNCTION START

	system("cls");
	int pass_match = 0;
	
	while(pass_match != 1){
	
	char pass_check[50];
	puts("********REGISTER********\n");
	puts("Enter a username");
	fflush(stdin);
	gets(current.username);
	puts("\nEnter a password" );
	fflush(stdin);
	getPass(current.password);
	puts("\nEnter password again" );
	fflush(stdin);
	getPass(pass_check);

	if(strcmp(pass_check,current.password) != 0){
		system("cls");
		puts("Your passwords do not match, retry\n");
	}
	else if(strcmp(pass_check,current.password) == 0){
		pass_match = 1;
		system("cls");
	}
	current.plan = '0';
	current.day = '0';
	current.part = '0';
	current.prog1 = '0';
	current.prog2 = '0';
	current.prog3 = '0';
	current.prog4 = '0';
	current.prog5 = '0';
	current.prog6 = '0';
	current.prog7 = '0';
	
	}//while end
	
	filePointer = fopen("profiles.txt", "a"); //OPENING THE FILE IN APPEND MODE (DOES NOT REPLACE CONTENTS, ADDS THEM TO END OF FILE INSTEAD
	fprintf(filePointer, "%s\n", crypt('e',current.username));
	fprintf(filePointer, "%s\n", crypt('e',current.password));
	fprintf(filePointer, "%c\n", current.plan);
	fprintf(filePointer, "%c\n", current.day);
	fprintf(filePointer, "%c\n", current.part);
	fprintf(filePointer, "%c\n", current.prog1);
	fprintf(filePointer, "%c\n", current.prog2);
	fprintf(filePointer, "%c\n", current.prog3);
	fprintf(filePointer, "%c\n", current.prog4);
	fprintf(filePointer, "%c\n", current.prog5);
	fprintf(filePointer, "%c\n", current.prog6);
	fprintf(filePointer, "%c\n", current.prog7);
	fprintf(filePointer, "-\n");// this is required due to some nuisance with file reading
	fclose(filePointer);
	
}//END OF REGISTER FUNCTION

//MAIN CODE STARTS HERE

void main(){
	
	system("COLOR 31"); // changes color of cmd, latter char decides text color, former bg color
	
	
	int first_choice = startPage();// calls for output of start page
	if (first_choice == 1){
		loginPage();
	}
	else if(first_choice == 2){
		registerPage();
		puts("You have successfully registered! Now moving to login page\n(Press enter to continue)\n");
		getchar();
		loginPage();
	}
	system("cls");
	
	//LOGIN DONE
	
	
	if((current.day) == '0'){//if new or restarting user
	
     	char day[3];//to be able to put as string into file edit function 
		puts("Before beginning your fitness journey, answer the following questions to get a customized fitness plan tailored to your needs.");
		puts("\nEnter your height (in cm. | 1 inch = 2.54 cm )");
		//I can sue dynamic memory allocation here to free up space for height and weight later
		float height, weight, BMI;
		char category[2];
		scanf("%f",&height);
		puts("Enter your weight (in KG | 1 KG = 2.21 lbs.)");
		scanf("%f",&weight);
		height = height/100;//convert cm to m
		BMI = weight / (height * height);
		if(BMI < 18.5 ){//underweight
		printf("According to your physical measurements, your BMI is %.1lf and falls in the underweight category. You will be assigned to the underweight plan.\n", BMI);
			category[0] = '0';
		}
		else if(BMI >= 18.5 && BMI <= 24.9){//regular weight
		printf("According to your physical measurements, your BMI is %.1lf and falls in the regular weight category. You will be assigned to the regular plan.\n", BMI);
			category[0] = '1';
		}
		else if( BMI >= 25 && BMI <= 29.9){//obese
			printf("According to your physical measurements, your BMI is %.1lf and falls in the overweight category. You will be assigned to the overweight plan.\n", BMI);
			category[0] = '2';
		}
		else if( BMI>=30){//severely obese
			printf("According to your physical measurements, your BMI is %.1lf and falls in the obese category. You will be assigned to the overweight plan.\nHowever, we recommend consulting with a physician before attemting this plan for your own safety", BMI);
			category[0] = '2';
		}
		
		
		fileEdit('P' , category );//file is updated
		current.plan = category[0];//update temporary record as well
		day[0] = '1';
		current.day = '1';//setting the day to one now
		fileEdit('D', day);//updating file to set day to one
		fflush(stdin);
		puts("\nPress enter to continue");
		getchar();
	}
	system("cls");
	
	int main_menu_choice, exit_app;
	
	while(1){//MAIN MENU LOOP START!!!
	
	main_menu_choice = mainMenu();
	
	exit_app = 1;

	switch(main_menu_choice){//main menu switch

		case 1://fitness journey pathway

			while((exit_app == 1) && (current.day != '8')){//while NOT EXITED AND 7th day not completed

				if(current.part=='0'){

					system("cls");
					planGetter();
					puts("Would you like to continue? Or exit the app and continue to progress reporting later? (progress is saved)\n1. continue\n2. exit");
					fflush(stdin);
					scanf("%d",&exit_app);
					fflush(stdin);
					if(exit_app == 2){
						exit(0);//quits
					}

				}

				if(current.part == '1'){
				
					progGetter();
					puts("Would you like to continue to the next day? Or exit app and resume later? (progress is saved)\n1. continue\n2. exit");
					fflush(stdin);
					scanf("%d",&exit_app);
					fflush(stdin);
					if(exit_app == 2){
						exit(0);//quits
					}
				
				}
			}//while END
				
			if(current.day == '8'){//7 day program complete
				getchar();
				system("cls");
				finalReport();
			}
			
			puts("\nPress enter to close the app...");
			getchar();
			exit(0);//quits
			break;//CASE BREAK
		
		case 2://case MP3 option selected
			mainMusic();
			system("COLOR 31");
			break;
		
		case 3://case EXIT option selected
			exit(0);

		}//main menu switch END

	}//loop END for main menu

	fflush(stdin);	
	getchar();

}//main END

//BYE 


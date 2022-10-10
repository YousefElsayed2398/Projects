/* Yousef Elsayed G01259710
 * Lab 5: section 215
 * Lab 5: 
 */


#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>



#define SIZE 20
#define WSIZE 20



void get_adjective(char letter, char adjective[]){
	letter = toupper(letter);	

	if(letter >= 'A' &&  letter <= 'E'){
		strcpy(adjective,"The Awsome ");
	}
	else if(letter >= 'F' && letter <= 'J'){
		strcpy(adjective,"The Funny ");
	}
	else if(letter >= 'K' && letter <= 'O'){
		strcpy(adjective,"The dangerous ");
	}
	else if(letter >= 'P' && letter <= 'T'){
		strcpy(adjective,"The lovley");
	}
	else if(letter >= 'U' && letter <= 'Z'){
		strcpy(adjective,"The electrifying");
	}
	
}









int valid_month(char month[]){
        int x = 0,i = 0;
    for(i; i < strlen(month); i++){
        month[i] = toupper(month[i]);
    }
        
        if(strcmp(month,"JAN") ==0 || strcmp(month,"FEB") ==0 || strcmp(month,"MAR") ==0) x++;
        else if (strcmp(month,"APR") ==0 || strcmp(month,"MAY") ==0 || strcmp(month,"JUN") ==0) x++;
        else if (strcmp(month,"JUL") ==0 || strcmp(month,"AUG") ==0 || strcmp(month,"SEP") ==0) x++;
        else if (strcmp(month,"OCT") ==0 || strcmp(month,"NOV") ==0 || strcmp(month,"DEC") ==0) x++;

	

        
	return x;
}



















void get_subject(char month[], char subject[]){
	int x,i = 0;
    for(i; i < strlen(month); i++){
        month[i] = toupper(month[i]);
    }
    
	if(strcmp(month,"JAN") ==0 || strcmp(month,"FEB") ==0 || strcmp(month,"MAR") ==0) x = 1;
       	else if (strcmp(month,"APR") ==0 || strcmp(month,"MAY") ==0 || strcmp(month,"JUN") ==0)	x = 2;
	else if (strcmp(month,"JUL") ==0 || strcmp(month,"AUG") ==0 || strcmp(month,"SEP") ==0) x = 3;
	else if (strcmp(month,"OCT") ==0 || strcmp(month,"NOV") ==0 || strcmp(month,"DEC") ==0) x = 4;
	
	


	switch(x){
	
		case (1): 
			strcpy(subject,"biography");
			break;
		case(2): 
			strcpy(subject,"revenge");
			break;
		case(3): 
			strcpy(subject,"battle");
			break;
		case(4):
		    strcpy(subject,"fairy tail");
		    break;
		defualt:
			strcpy(subject,"worng");
			break;
		}
}

void get_complement(int digit, char complement[]){

	switch(digit){

		case(0):case(1):
			strcpy(complement,"of a movie star");
			break;
		case(2):case(3):
			strcpy(complement,"of a hero");
			break;
		case(4):case(5):
			strcpy(complement,"of a jedi");
			break;
		case(6):case(7):
			strcpy(complement,"of an ogre");
			break;
		case(8):case(9):
			strcpy(complement,"of a dreamer");

	}


}




int main(){

char y = 'y';
while(y == 'y'|| y == 'Y'){
char k[100],p[10],u[10],adjective[SIZE], subject[SIZE], complement[SIZE], moiveTitle[WSIZE];
char c,month[5];
int num,lik;
printf("Enter the first letter of your last name [A-Z]: \n");

 fgets(k, 100, stdin);
 sscanf(k,"%c",&c);
while(!(isalpha(c))){
	printf("Character is not valid re-enter:\n");
	fgets(k, 100, stdin);
	sscanf(k,"%c",&c);
	
}

printf("Enter your birth month [JAN|FEB|...|DEC]: \n");
   fgets(k,100,stdin);
   sscanf(k,"%s", month);
   lik = valid_month(month); 
while(lik ==  0){
    printf("Enter In valid Month:\n");
    fgets(k,100,stdin);
    sscanf(k,"%s", month);
    lik = valid_month(month);
}

printf("Enter the last digit of your cellphone [0-9]: \n");
fgets(k,100,stdin);
sscanf(k,"%d",&num);
while(isalpha(num) || num > 9){
	printf("not valid digit please re-enter\n");
	fgets(k,100,stdin);
	sscanf(k,"%d",&num);

}

get_adjective(c,adjective);
get_complement(num,complement);
get_subject(month,subject);

printf("The Movie Title of your life is: %s %s %s\n", adjective,subject,complement);
printf("Do you want to quit [Y|y]?\n");
fgets(k,100,stdin);
sscanf(k,"%c",&y);
}

return 0;
}


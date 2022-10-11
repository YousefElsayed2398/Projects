#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int is_valid_name(char name[]){
    int p = 0,i =0;
    int k = strlen(name);
    if(k > 7) return 0;
    for(i; i < k; i++){
        if((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')) continue;
        else
            p++;
    }
    if(p != 0) return 0;
    else return 1;

}



int is_valid_seed(char k[]){

        int p = 0,seed;
        char u[20];
        seed = atoi(k);
        sprintf(u,"%d",seed);

        if((seed >=1) && (seed <= 99999) && (strlen(u) == strlen(k))) p++;
       return p;
}




int calculate_net_height(int ft,int in){
    ft *= 12;
    ft += in;
    return ft;
}

int make_bet(){
    char k[10];
    int bet;
    printf("Enter a bet [1-11]:\n");
    fgets(k,10,stdin);
    sscanf(k,"%d",&bet);
    while(bet < 1 || bet > 11){
        printf("Not valid Bet re-enter:\n");
        fgets(k,10,stdin);
        sscanf(k,"%d",&bet);
    }
    return bet;
}


int game_logic(int score, int netHight, char name[],int rpoints){
        char c,k[10];
        int bet;

        int ballHight = 0;
        int c_ball = 0;


        while(rpoints > 0 && score > 0){
        ballHight = throw_ball(netHight);
        c_ball = throw_ball(netHight);
        bet = make_bet();
        
        if(ballHight > netHight){

            printf("Ball height: %d inches, the ball is over the net\n",ballHight);
            score -= bet;
            printf("Deducting %d points\n",bet);
            printf("%s now has %d points\n",name,score);
        }
        else if((ballHight <= netHight) && (ballHight > (netHight / 2))){
            printf("Bet %d points\n", bet);
            score += 2;
            printf("Ball height: %d inches, ball is below the net\n",ballHight);
            printf("Deducting 2 points\n");
            printf("%s now has %d points\n",name,score);
        }

        else if(ballHight < (netHight / 2)){
            printf("Ball hight: %d, Throw again? Type Y or N:\n",ballHight);
            fgets(k,10,stdin);
            sscanf(k,"%c",&c);
                if(c == 'Y' || c == 'y'){
                    ballHight = throw_ball(netHight);
                    if(ballHight > netHight) {
                    score -= 4;
                    printf("Ball height: %d inches, the ball is below the net\n",ballHight);
                    printf("subtracting 4\n");
                    printf("%s now has %d points\n",name,score);
                    }
                }
                    else{
                        score += bet;
  			            printf("Adding %d to score\n",bet);
                        printf("%s now has %d points\n",name,score);
                        }
        }
            /* computer */

            printf("Computer Turn\n");
        if(c_ball > netHight){
            printf("Ball height: %d inches, the ball is over the net\n",c_ball);
            rpoints -= 9;
            printf("Deducting 9 pints\n");
            printf("computer now has %d points\n",rpoints);
        }
        else if((c_ball <= netHight) && (c_ball > (netHight / 2))){

            rpoints += 4;
            printf("Ball height: %d inches, ball is below the net\n",c_ball);
            printf("adding 4 points to computer\n");
            printf("computer now has %d points\n",rpoints);
        }
        else if(c_ball < (netHight / 2)){
                    c_ball = throw_ball(netHight);
                    if(c_ball > netHight) {
                    rpoints -= 7;
                    printf("Ball height: %d inches, the ball is below the net\n",c_ball);
                    printf("subtracting 7 points\n");
                    printf("computer now has %d points\n",rpoints);
                    }
                
                    else{
                        printf("Ball height: %d inches,the ball is below the net\n",c_ball);
                        rpoints += 6;
  			            printf("Adding 6 to score\n");
  			            printf("Computer now has %d points\n",rpoints);	
                        	
                        
                        }

        }

        }
        
        if(rpoints <= 0){return 1;}
        return 0;
}


/*
 * The above function is ment to implement the logic
 * 1 we have to gather the needed info as Parms
 * 2 we need score, bet, net hight, ball thrown hight
 * 3 we change the score based upon the throw and bet
 * 4 if ball hight at net or lower +2 to socre
 * 5 if ball hight is less than 1/2 then they have option to re-throw, but if they miss again it's +4 to score. if they say NO to re-throw then it's (score += bet)
 *
 */

int throw_ball(int net)
{
	int thrown;
	net += 16;
    
	thrown = rand() % (net + 1);
	return thrown;

}




/*
 *  The above function needs a way to throw the ball 
 *  1 we know that it need to be in [0, net_height + 16]
 *  2 we can have the parameter be the net hight 
 *  3 we need to use the rand() function to throw
 *  4 we return how hight the ball went
 *  5 in main we check if it went over 
 */








int main(){
        int n,v,count = 5,net,ft,in,hpoints = 75,rpoints = 75,games = 3,H_won = 0,C_won = 0,res;
        char name[15],gname[15];
        char k[20],jim[20],kin[20];
	    char f,t,i,N,y;
	    printf("Welcome to the Gehntoo game\n");
        printf("Enter Your Name\n");        
        fgets(gname,15,stdin);
        sscanf(gname,"%s",name);
 


        n = is_valid_name(name);
        while(n != 1){
                printf("Name is Not Valid\n");
                fgets(gname,15,stdin);
                sscanf(gname,"%s",name);
                n = is_valid_name(name);
        }



        printf("Enter a seed value to use in the range of [1-99999]\n");
        fgets(jim,20,stdin);
        sscanf(jim, "%s",kin);


        v = is_valid_seed(kin);
        while(v != 1){
                printf("re-enter seed\n");
                fgets(jim,20,stdin);
                sscanf(jim, "%s",kin);
                v = is_valid_seed(kin);
        } /* makes user re - enter val if not valid ("1") */

        v = atoi(kin);
        srand(v);



        printf("Enter the height of the net in feet and inches [xxft xxin] where xx must be [1-99]\n");
        while(count != 0){  /* beging of loop for hight */
        count = 5;
        fgets(k,20,stdin);
        sscanf(k,"%d %c %c %d %c %c",&ft,&f,&t,&in,&i,&N);

        if(ft < 99 || in < 99) count--;
        if(f == 'F' || f == 'f') count--;
        if(t == 'T' || t == 't') count--;
        if(i == 'I' || i == 'i') count--;
        if(N == 'N' || N == 'n') count--;
        if(count != 0) printf("Hight not valid Please re-enter\n");

        } /* end of while loop for geting height */
	
	y = 'y';
	while((y != 'n' || y != 'N') && (games > 0)){
        net = calculate_net_height(ft,in);
        
	    res = game_logic(hpoints,net,name,rpoints);


        if(res == 1) {
            C_won++;
            printf("Comupter Won this Round\n");
        }
        else{ 
            H_won++;
            printf("%s Won this Round\n",name);
        }
        printf("%s has %d wins and Computer has %d wins\n",name,H_won,C_won);
        games--;


        if(games != 0){
        printf("Would You Like To Play Again ['Y']:\n");
        fgets(k, 20,stdin);
        sscanf(k,"%c",&y);
        }
        else {printf("The Game is Over\n");
        printf("The Computer won %d times\n",C_won);
        printf("%s has won %d times\n",name,H_won);  
        }

	}
        return 0;
}


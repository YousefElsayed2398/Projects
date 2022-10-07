/*
 * Yousef Elsayed G01259710
 * CS 262, Lab 215
 * Lab 2: BSA caculator
 */


#include <stdio.h>
#include <math.h>



//Twc = 0.007184 * W0.425 * H0.725
#define BSA(weight, height) (weight * height)
int main()
{

    double heightCm;
    double weightKgs;


    printf("what is your weight in kgs and what is your height in cms");

    
    scanf("%lf %lf",&heightCm,&weightKgs);	
   // weightKgs = pow(weightKgs,.425);
   // heightCm = pow(heightCm,725);
	printf("The height is: %f\n", heightCm);
	printf("The weight is: %f\n", weightKgs);
    printf("The BSA is:  %.4f\n", BSA(pow(heightCm, .725), pow(weightKgs,.425)) * 0.007184);

    




}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

    char name[50];
	char surname[50];
	char address[50];
	char username[50];
	char password[50]; /* In these global variables we will have stored the user's credentials */
	
	double totalcost;
	double finalcost;
	double municipality;
	char Card[17];/*i also made these varibales global because even if i managed to change them inside functions AND bring them out, when i tried to insert them in new functions their values were 0.000 */
	
void Signup_user(char *name[] ,char *surname[] ,char *address[] , char *username[] ,char *password[]) {
    printf("Please give us a name, a surname, an adress, a username and a password.\n NOTE: the username must contain less than or equal to 4 characters.\n");
	scanf("%s %s %s %s %s", name, surname, address, username, password); /* We ask for credentials */
	system("cls");
	 while(strlen(username)>=5){   /* Check whether or not the user has a username with more than 4 characters */               
	 	
		 
	 	  printf("the username MUST contain less than 5 characters, please type a new username\n");
	 	  scanf("%s", &username);
	 	  system("cls"); 
	    
	 } 
	 

}





 void calculate_cost(int *Gtoken ,double *municipality ,double *totalcost ,double *finalcost ,double kw1 ,double kw2 ,double kw3){
	
	int KW;
	int SC;
	
    
	
	
	printf("Please inform us about the kilowatt-hour and your house's square centimeters\n"); /* We now try to get the necessary information we need to proceed with our check calculation */ 
		scanf("%d %d",&KW ,&SC); /* KW and SC are the names for the kilowatt-hours and the square centimeters */
		system("cls");
		
		if(KW<0){ /* In Case where the killowatt-hours are a negative number, we repeat untill we get 0 or a possitive one */
			while (KW<0){ 
				printf("The killowatt-hours has to be a possitive number\n");
				scanf("%d", &KW);
				system("cls");
			}
		}
		
		if(SC<0){ /* In Case where the square centimeters are a negative number, we repeat untill we get 0 or a possitive one */
			while (SC<0){
				printf("The square centimeters has to be a possitive number\n");
				scanf("%d", &SC);
				system("cls");
			}
		}
	 /*we will now start calclulating the costs */
	if(KW<=1600){
			if(SC<=75){
				*municipality=(SC*0.13*87)/365; /* 87 are the last 3 digits of my AM E19087 */
				*totalcost=KW*kw1;
			    *finalcost= *municipality + *totalcost;
		    }else if(SC<=115){
		        *municipality= (SC*0.26*87)/365; /* 87 are the last 3 digits of my AM E19087 */ 
				*totalcost=KW*kw1;
			    *finalcost= *municipality+ *totalcost;	
			}else{
				*municipality=(SC*0.42*87)/365; /* 87 are the last 3 digits of my AM E19087 */
				*totalcost=KW*kw1;
			    *finalcost= *municipality+ *totalcost;
			}
		}else if(KW<=2000){
				if(SC<=75){
				*municipality=(SC*0.13*87)/365; /* 87 are the last 3 digits of my AM E19087 */
				*totalcost=KW*kw2;
			    *finalcost= *municipality+  *totalcost;
		    }else if(SC<=115){
		        *municipality=(SC*0.26*87)/365; /* 87 are the last 3 digits of my AM E19087 */
				*totalcost=KW*kw2;
			    *finalcost= *municipality+ *totalcost;	
			}else{
				*municipality=(SC*0.42*87)/365; /* 87 are the last 3 digits of my AM E19087 */
				*totalcost=KW*kw2;
			    *finalcost= *municipality+ *totalcost;
			}
		}else{
				if(SC<=75){
				*municipality=(SC*0.13*87)/365; /* 87 are the last 3 digits of my AM E19087 */
				*totalcost=KW*kw3;
			    *finalcost= *municipality+ *totalcost;
		    }else if(SC<=115){
		        *municipality=(SC*0.26*87)/365; /* 87 are the last 3 digits of my AM E19087 */
				*totalcost=KW*kw3;
			    *finalcost= *municipality+ *totalcost;	
			}else{
				*municipality=(SC*0.42*87)/365; /* 87 are the last 3 digits of my AM E19087 */
				*totalcost=KW*kw3;
			    *finalcost= *municipality+ *totalcost;
			}
		}
		
		printf("Your Final Cost is: %f \n   Your Municipality Cost is : %lf\n   The Total Cost is: %f\n", *finalcost, *municipality, *totalcost);
		
	/*	Gtoken=1;   we now know the user had completed his cost calculation in order to proceed into paying */ /*couldnt make this work, it would pass the value=1 back but it wont do it while entering into a new function. */
		
	
}

void payment(int *Gtoken ,double finalcost ,char *Card[]){
	char method[50];
	
	double Costtoken;
	
	
	
	/*if(Gtoken==1){ Gtoken value wont pass in here through Login_user */  
	
	printf("Would you like to pay with Cash or Card?\n"); /*We ask for payment method */
	scanf("%s", method);
	system("cls");
	if(strcmp(method,"Cash")==0){ /* Cash payment Case */
		printf("Please Confirm the Finalcost Value in order to Continue.\n");
		scanf("%lf",Costtoken);
		do{
		    if(Costtoken==finalcost){ 
		scanf("Your transaction has been successful!\n");
			
		    }else{
		    printf("Please insert the correct number value.\n");
	        }
	    }while(Costtoken!=finalcost); 
	    
	}else if(strcmp(method,"Card")==0){ /* Card case */
	
		printf("You get a 10 percent iscount for paying with Card!\n");
		finalcost=finalcost-(finalcost*(10/100)); /* We give 10% discount */
		
		printf("Please insert your 16-digit Card number.\n"); /* We ask for the card info */
		scanf("%s", Card);
		system("cls");
		
		
		if(strlen(Card)!=16){ /* Here we check if the card number is a 16 digit one or not. If not, we make the user try again till he gives us a 16 digit one. */
			do{
				printf("The card number has to be a 16-digit one\n");
				scanf("%s", Card);
				system("cls");
			}while(strlen(Card)!=16);
		}
		printf("Please Confirm the Finalcost Value in order to Continue.\n");  /*We ask for Cost confirmation */ 
		scanf("%lf",Costtoken);
		do{ 
		    if(Costtoken==finalcost){ 
		scanf("Your transaction has been successful!\n");
		/* Gtoken=2; we now know the user has paied with Card .*/  
		    }else{
		    printf("Please insert the correct number value.\n");
	        }
	    }while(Costtoken!=finalcost); 
	}
 /* } */
}

void get_receipt(char name[],char surname[],char address[],double totalcost,double municipality ,char Card[], double finalcost ,int Gtoken){
	/* here we just print the receipt depending on the print screen i was provided */
	printf("**************************************************************\n");
	printf("*                     PERSONAL DETAILS                       \n");
	printf("*      Name                 :              %s                \n", name);
	printf("*      Surname              :              %s                \n", surname);
	printf("*      Address              :   %s                           \n", address);
	printf("*      Total days of consumption   :87\n");
	printf("**************************************************************\n");
	printf("*                         PRICING                            *\n");
	printf("*      Initial cost: %lf                                      \n", municipality+totalcost);
	printf("*       Details:                                             *\n");
	printf("*               Municipal Taxes: %lf                          \n", municipality);
	printf("*               Total Charges:  %lf                           \n",totalcost);
	printf("*      Final Cost(after credit card payment deduction): EUR %lf \n", finalcost);
	printf("*                                                            *\n");
	printf("**************************************************************\n");
	printf("*                     PAYMENT DETAILS                        *\n");
	printf("*Credit Card Number         : %s                               \n", Card);
	printf("**************************************************************\n");
	/* because my Gkey wouldnt work, i cannot differenciate whether or not the user has paied with Card or Cash. However, i still put it here to show that it works in both cases */
    
	
}

void Login_user(char username[] ,char password[] , double kw1 ,double kw2 ,double kw3){
	char UN[50];
	char PW[50];
	
	char token1[1];
	int Gtoken;
	
	
	printf("Please confirm your credentials to login.\n ");
	scanf("%s %s", UN, PW); /* The names UN and PW are abbreviations of the words UserName and PassWord, which we use to confirm his identity to our system */
	system("cls");
	
	if ((strcmp(username, UN)==0) && (strcmp(password, PW)==0)){ /*if the credentials are correct, we move on */
	  do{
	  printf("What do you want to do?\n a) Calculate cost\n b)Payment\n c)Receipt\n d) Exit\n");
	  scanf("%s", &token1);/* creation of another token named token1 to check what does the user want to do */
	  system("cls");
	  if(strcmp(token1,"a")==0){ /* if the user wants to Calculate cost, we run the function. */
		calculate_cost(&Gtoken, &municipality, &totalcost, &finalcost, kw1, kw2, kw3);
        }else if(strcmp(token1,"b")==0){ /*if the user wants to Pay, we run the function. */
        payment(&Gtoken ,finalcost ,&Card);
	    }else if(strcmp(token1,"c")==0){/*if the user wants to get his receipt, we run the function.*/
	    get_receipt(name, surname, address, totalcost, municipality ,Card ,finalcost ,Gtoken);
		}else{  /* If the choice is wrong, we inform him .*/
    	printf("Please select one of the choices.\n");
      }
	  }while(strcmp(token1,"d")!=0); /*if the choise is not d for exit, we make choose again. */
 }
}


int logout(){
	return 1; /*i really didnt understand what i was supposed to do in this function, so i just changed the number on my do{}while variable. */
} 

void Login_admin(double *kw1, double *kw2, double *kw3, char *username[] ,char *password[]){
	double choice[50];
	int price;
	double newkw;
	int gotostart=0;
	
	
	do{
	printf("Please enter your Credentials\n"); /*we ask for his credentials */
	scanf("%s %s", username, password);
	system("cls");
	
	if((strcmp(username, "root")==0) && (strcmp(password, "admin123")==0)){ /* if his credentials are correct */
	do{
	
		printf("Would you like to :\n a) Change cost.\n b) Exit.\n ");/*we ask him what he wants to do */
		
		scanf("%s", choice);
		
		if((strcmp(choice, "a")==0)){ /*if he wants to change cost */
			printf("Would you like to change the price of 1, 2, or 3?\n"); /*we ask him which one of the 3 prices he wants to change */
			scanf("%d",&price);
			if(price==1){
				printf("The current price is %lf, to what do you want to change it?\n", *kw1);
				scanf("%lf", &newkw);  /*we make a new variable to compare with the original */
				system("cls");
				printf("%lf", newkw);
				/* if((newkw>kw1+(kw1*20/100)) || (newkw<kw1-(kw1*20/100))){
				 	printf("The range of change HAS to be in the range of 20 percent\n");
				 } */ /* It wouldnt let me run this...*/
				 newkw=*kw1;
				 printf("Now the new price is %lf.\n",*kw1);
			}else if(price==2){
				printf("The current price is %lf, to what do you want to change it?\n", kw2);
				scanf("%lf", &newkw);
				system("cls");
				/* if((newkw>kw2+(kw2*20/100)) || (newkw<kw2-(kw2*20/100))){
				 	printf("The range of change HAS to be in the range of 20 percent\n");
				 } */ /* It wouldnt let me run this...*/
				 newkw=*kw2;
			}else if(price==3){
				printf("The current price is %lf, to what do you want to change it?\n", kw3);
				scanf("%lf", &newkw);
				system("cls");
				/* if((newkw>kw3+(kw3*20/100)) || (newkw<kw3-(kw3*20/100))){
				 	printf("The range of change HAS to be in the range of 20 percent\n");
				 } */ /* It wouldnt let me run this...*/
				 newkw=*kw3;
			}
		}else if((strcmp(choice, "b")==0)){ /*if he wants to Logout*/
		gotostart=exit_admin();
		}
	}while(gotostart==0);
	}else{ /*if his credentials are wrong, we inform him and he now has to try again */
		printf("Please type the correct Credentials.\n");
	}
 }while((strcmp(username,"root")==1) || (strcmp(password,"admin123")==1)); /*this is a loop until he gives the correct credentials or choose to exit the Admin UI screen */
}

int exit_admin(){
	return 1;/*i really didnt understand what i was supposed to do in this function, so i just changed the number on my do{}while variable. */
}

void terminate (){
	exit(0);
}
int main(int argc, char *argv[]) {
	char user[50];
	
	int token=1;
	char token1;
	
	double kw1=0.00542;
	double kw2=0.00682;
	double kw3=0.00822;
	
	/* In this project you will notice that after every action the user makes, i bring him back to the corresponding UI screen, mainy because that what most ATM's do and thats what i thought was right to do" */
	do{
	
	printf("Hello and Welcome to our Electricity Billing system!\n To continue please tell us, are you an admin or a user?\n You can also terminate the program by pressing 0.\n"); /* Ask if the user is an admin or not to determine the type of menu */
	scanf("%s", user);
	system("cls");
	if (strcmp(user,"user")==0){   /* if he is a user, we go into the User UI screen */
	int gotostart=0;   
	    do{
	        printf("Select action.\n 1) To sign up.\n 2) To login.\n 3) Log out.\n");
		    scanf("%d", &token); /* Token Creation to determine which action we will do next */
		    system("cls");
		    if (token==1){ /* Sign Up Case */		
		        Signup_user(name, surname ,address ,username ,password);
					
		    }else if(token==2){ /*Log in Case */
		        Login_user(username ,password, kw1, kw2 ,kw3);    
		    }else if(token==3){ /*Log out Case */
		     gotostart=logout();
			}else{
				printf("You must type a corresponding number to continue the operation");
			}
	    }while(gotostart==0); /* i dont plan on ever changing "gotostart" 's value because we will only exit if the user types 0 */    
	}else if (strcmp(user,"admin")==0){ /* If he is an admin, we go to the Admin UI screen */
		Login_admin(&kw1, &kw2, &kw3, username, password);
	}else if(strcmp(user,"0")==0){
		terminate();
	}
}while(strcmp(user,"0")==1);
	return 0; 
}


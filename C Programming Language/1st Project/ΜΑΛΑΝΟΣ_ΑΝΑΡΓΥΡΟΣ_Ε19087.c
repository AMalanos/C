#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char choice[50];

int users=0;

int token=0;

struct address{
	
	char road[50];
	
	int number;
	
	int zip;
	
};

struct client{
	
	char name[50];
	
	char surname[50];
	
	char password[50];
	
	char username[50];
	
	int square;
	
	float cost [12][3];
	
	struct address add;
	
	};
	
	void signup_user(struct client *c ,int users){
		
		char username[50]; /* a token we will use to make the real username */
		
		if(users==20){
			
			printf("We can only have up to 20 users Registered.");
			
		}else{
		
		    printf("Please tell me your name, surname ,full adress(road, road number and zip code) and your house's square meters\n"); /*we ask the users credentials */
		
		    scanf("%s", (*c).name);
		
		    scanf("%s", (*c).surname);
		
		    scanf("%s",(*c).add.road);
		
		    scanf("%d", &(*c).add.number);
		
		    scanf("%d",&(*c).add.zip);
		    
		    scanf("%d",&(*c).square);
		
		    system("cls");
		
		    printf("Now chose a password\n");
		
		    scanf("%s", (*c).password);
		
		    strcpy(username, (*c).surname); /* we copy the surname to a token to change to lowercase */
		
		    int i = 0;
		
		    while( username[i] ) { /* we change each uppercase letter to lowercase */
			
               tolower(username[i]); /* i cant see what the problem here is, it just puts the lowercase letters next to the uppercase ones... */
        
		       i++;
        }
		
		strcat(username, "123"); /* we add "123" to the username */ 
		
		strcpy((*c).username, username); /* we create the username */
		
		users= users+1; /* now we have +1 user*/
		
		
	  }
	}
	

	
	void login_user(struct client* c){
		
		char username[50];
		
		char password[50];
		
		char action[50];
		
	
			
			system("cls");
		
		printf("Please give us your Username and Password\n %s \n %s \n",(*c).username ,(*c).password);
		
		scanf("%s %s", username, password);
		
		system("cls");
		
		if (strcmp(username,(*c).username)==0 && strcmp(password,(*c).password)==0){ /* if the credentials are correct, we log in */
			
			printf("You have succesfully logged in!\n");
			
			sleep(5); /* we freeze the program for 5 seconds */
			
			do{
			
			system("cls");
			
			printf("What would you like to do?\n 1.View\n 2.Modify\n 3.Calculate\n 4.Payment\n 5.Most Expensive\n 6.Logout\n");
			
			scanf("%s", action); /* We will now run a function depending on what he wants */
			
			if(strcmp(action,"1")==0){
				
				view_user(c);
				
			}else if(strcmp(action,"2")==0){
				
				modify_user(c);
				
			}else if(strcmp(action,"3")==0){
			  	
		      calculate_cost(c);
		      
			}else if(strcmp(action,"4")==0){
				
				payment(c);
				
			}else if(strcmp(action,"5")==0){
				
				most_expensive(c);
				
			}else{
				
				printf("It has to be a number from 1 to 6.\n");
				
			}
			
		}while(strcmp(action,"6")==1);
	    
		}
	}
	
	void view_user(struct client c){
		
		/* We just Printf the Info */
		
		printf("Here is your Info.\n");
		
		printf("Name:%s\n",c.name);
		
		printf("Surname:%s\n",c.surname);
		
		printf("Username:%s\n",c.username);
		
		printf("Street:%s\n",c.add.road);
		
		printf("Street Number:%d\n",c.add.number);
		
		printf("Zip Code:%d",c.add.zip);
		
		sleep(5);
		
		system("cls"); /*here i just clear the screen after 5 seconds */
		
	}
	
	void modify_user(struct client c){
		
		printf("You can now modify your Street name, Street number and Zip code\n");
		
		scanf("%s %d %d", c.add.road, &c.add.number, &c.add.zip);
		
		system("cls");
		
	}
	
	void calculate_cost(struct client c){
		
		int i=1;
		
		int days;
		
		do{
			
			system("cls");
			
			printf("How many KW/hour did you spent on month No.%d\n", i);
			
			scanf("%f", &c.cost[i][1]);
			
			system("cls");
			 
			 do{
			 
			 if(c.cost[i][1]<0){
			 	
			 	printf("The number has to be positive.\n");
			 	
			 	scanf("%f", &c.cost[i][1]);
			 	
			 }
			 
		   }while(c.cost[i][1]<0);
		   
		   
		   if(i%2==1){ /*if the month is odd */
		   		
		   		days=31;
		   		
			   }else if(i==2){ /* if its february */
			   	
			   	days=28;
			   	
			   }else{ /* if its even */
			   	
			   	days=30;
			   	
			   }
		   if(c.cost[i][1]<1601){ /* we then calculate the costs */
		   	
		   	c.cost[i][2]= (c.square)*(c.cost[i][1])*0.005*days;
		   	
		   }else if(c.cost[i][1]<2001){
		   	
		   	c.cost[i][2]= (c.square)*(c.cost[i][1])*0.008*days;
		   	
		   }else{
		   	
		   	c.cost[i][2]= (c.square)*(c.cost[i][1])*0.009*days;
		   	
		   }
		   
		   i=i+1;
		   
		}while(i<13);
		
		token=1; /* now we know we completed the calculation */
		
	}
	
	void payment(struct client c){
		
		int i=1;
		
		int month;
		
		float costtoken;
		
		if(token==1){ /* if calculate cost has been completed we proceed to payment */
			
			printf("Which month would you like to pay?\n");
			
			do{
				
				printf("Month no.%d costs %f\n",i,c.cost[i][2]); /* we show the user the costs of each month */
				
				i=i+1;
				
			}while(i<13);
			
			scanf("%d",&month); /* he tells us which month he wishes to pay */
			
			printf("Please put the number you would like to pay\n");
			
			scanf("%f", &costtoken);
			
			if(costtoken==c.cost[month][2]){
				
				c.cost[month][3]=1;
				
			    printf("The payment was succesful!\n");
			    
			    system("cls");
			    
			}
		}
	}
	
	void most_expensive(struct client c){
		
		int i=1;
		
		int token;
		
		float monthMAX=0;
		
		while(i<13){
			
			if(c.cost[i][2]>monthMAX && c.cost[i][3]==0){
				
				monthMAX=c.cost[i][2]; /*we same the biggest cost and the month using the token */
				
				token=i;
			}
			
		}
		
		printf("The most expensive month was month No.%d with the expense of %f\n",token ,monthMAX);
	}
	
int main(int argc, char *argv[]) {
	
	struct client c; 
	
	do{
	
	system("cls");
	
	printf("Hello!\n Would you like to:\n A.Register\n B.Login\n C.Exit\n"); /* We ask what action the user will take */
	
	scanf("%s",&choice);
	
	system("cls");
	
	/* we make act accordingly to what he wants using if-else */
	
	if(strcmp(choice , "A")==0){
		
		signup_user(&c,users);
		
		
	}else if(strcmp(choice , "B")==0){
		
		login_user(&c);
		
	}else if(strcmp(choice, "C")){
		
		return 0;
		
	}
	
    }while(strcmp(choice ,"C")!=0);
    
	return 0;
	
}
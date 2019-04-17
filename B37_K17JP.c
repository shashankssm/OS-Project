
/*QUESTION : Write a program to implement priority scheduling algorithm with context switching time. 
Prompt to user to enter the number of processes and then enter their priority, burst time and arrival time also.
 Now whenever operating system preempts a process and shifts cpu's control to some another process of 
 higher priority assume that it takes 2 seconds for context switching(dispatcher latency).
 Form a scenario, where we can give the processes are assigned with priority where the lower integer number is higher priority and then context switch .. 
 as the process waits the priority of the process increase at rate of one per 2 time units of wait.
Calculate waiting time and turnaround time for each process.*/

/* NOTE : IF THE BELOW CODE IS NOT GIVING DESIERED OUTPUT THEN, 
KINDLY REMOVE THE COMMENT MARK FROM fflush(stdin) BEFORE EVERY SCANF FUNCTION TO REMOVE BUFFER */

/* NOTE : SYSTEM(COLOR 00) and SYSTEM("CLS") FUNCTION IS USED FOR BETTER USER INTERFACE EXPERIENCE,
 KINDLY REMOVE OR MARK THEM AS A COMMENT WHILE EXECUTING IT ON LINUX BASED OS*/
 



#include<stdio.h>
int main()
{
	char ch;
	int n,i,j,ptr,c,z,sum=0,avgtime;
	int atime[10],btime[10],wtime[10],priority[10],pn[10],tatime[10];
	
	system("COLOR E0");
	printf("__________________________________\n");
	printf("Enter the the no. of processes : ");
	scanf("%03d",&n);
	printf("__________________________________\n");
	//system("cls");

	
	for (i=0;i<n;i++)
	{
		system("COLOR FC");
		printf("\n\nprocess [%03d] \n",i+1);
		printf("************************\n");
		printf("Enter arrival time : ");
		scanf("%03d ",&atime[i]);
		printf("************************\n");
        
        printf("Enter Burst time : ");
        //fflush(stdin);
		scanf("%03d ",&btime[i]);
		printf("************************\n");
		
		printf("Enter Priority : ");
		//fflush(stdin);
		scanf("%03d ",&priority[i]);
		printf("************************\n");
		pn[i]=i+1;
		//system("cls");

	}
	
	for (i=0;i<n;i++)
	{
		ptr=i;
		
		for (j=i+1;j<n;j++)
		{
			if(priority[j]<priority[ptr])
			{
				ptr=j;
			}
		}
		
		c=priority[i];
		priority[i]=priority[ptr];
		priority[ptr]=c;
		
		c=btime[i];
		btime[i]=btime[ptr];
		btime[ptr]=c;
		
		c=pn[i];
		pn[i]=pn[ptr];
		pn[ptr]=c;
		
	}
	    wtime[0]=0;  
	      for(i=1;i<n;i++)
	      {
	      	wtime[i]=0;
	      	for(j=0;j<i;j++)
	      	{
	      		wtime[i] = wtime[i]+btime[j];
			}
            
			z = z+wtime[i];
			
		  }
	
	
	avgtime=z/n;
	system("COLOR F0");
	fflush(stdin);
	printf("__________________________________________________________________________________________________\n");
    	printf("|  PROCESS   |  ARRAIVAL TIME  |  BURST TIME  |  WAITING TIME  |  PRIORITY  |  TURN AROUND TIME  | \n");
	
	for (i=0;i<n;i++)
	{
		tatime[i]=btime[i]+wtime[i];
		printf("|    %03d     |        %03d      |      %03d     |    %03d     |     %03d    |         %03d        | \n",pn[i],atime[i],btime[i],wtime,pn[i],tatime[i]);
		sum= sum+tatime[i];
		
	}
	printf("__________________________________________________________________________________________________\n");

	
	int avgtatime= sum/n;
	printf("____________________________________");
	printf("\n|  AVERAGE WAIT TIME        : %03d  |",avgtime);
	printf("\n|  AVERAGE TURNAROUND TIME  : %03d  |",avgtatime);
	printf("\n____________________________________");

}





//FOR FURTHER ASSISTANCE CONTACT DEVELOPER : SHASHANKSSM@OUTLOOK.COM

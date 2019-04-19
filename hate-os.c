#include<stdio.h>
#include<conio.h>
int main()
{
  int count,j,n;
  int time,temp;
  int flag=0,tq=10;
  int waiting=0,turn_around=0,arrival[10],burst[10],rt[10];
  sleep(3); // cpu is idle for 3 sec
  system("COLOR 0A");
  printf("\n\n**********************************************************************************************************************\n");
  printf("\n\n**********************************************************************************************************************\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\t\t\t\t\t\t\t\t\tROUND ROBIN\n");
  printf("\n\n**********************************************************************************************************************\n");
  printf("\n\n**********************************************************************************************************************\n");
  sleep(2);
  printf("\n\nEnter the Total number of Process:  ");
  scanf("%d",&n);
  printf(" Time Quantum: 10\n");
  temp=n;
  for(count=0;count<n;count++)
  {
  	system("cls");
  	system("COLOR E");
    printf("\nEnter Arrival Time %d :\n",count+1);
    printf("Enter waiting time %d :\n",count+1);
    scanf("%d",&arrival[count]);
    scanf("%d",&burst[count]);
    rt[count]=burst[count];
  }
  
  printf("\n\nProcess\tTurnaroundtime\twaitingtime\n\n");
  for(time=0,count=0;temp!=0;)
  {
    if(rt[count]<=tq && rt[count]>0)
    {
      time+=rt[count];
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=tq;
      time+=tq;
    }
    if(rt[count]==0 && flag==1)
    {
      temp--;
      printf("P[%d]\t|\t%d\t|\t%d\t",count+1,time-arrival[count],time-arrival[count]-burst[count]);
      waiting+=time-arrival[count]-burst[count];
      turn_around+=time-arrival[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(arrival[count+1]<=time)
      count++;
    else
      count=0;
  }
  sleep(2);
  system("cls");
  system("COLOR 7C");
  printf("\nAverage Waiting Time= %f\n",waiting*1.0/n);
  printf("Avg Turnaround Time = %f",turn_around*1.0/n);
 
  return 0;
}

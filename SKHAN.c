#include<stdio.h>
#include<string.h>
//#include<sys/wait.h>
#include<conio.h>
void main()
{
	system("COLOR 40");
    char p[10][5],temp[5];
    int i,j,pt[10],wt[10],totwt=0,pr[10],temp1,n;
    float avgwt;
    printf("\n\n\\nt\t\t\tLOVELY PROFESSIONAL UNIVERSITY\n");
    printf("\n\n\t\t\t\tCSE- 316  OPERATING SYSTEM\n");
    printf("\n\n\t\t\t=======================================\n");
    printf("\n\t\t\tNAME    :  SHAHBAZ HASSAN KHAN\n\n");
    printf("\n\t\t\tSECTION :  K17JP\n");
    printf("\n\t\t\tROLL NO.:  30\n");
    printf("\n\t\t\tREG. NO :  11706072\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tLOADING");
    sleep(1);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t        _");
    sleep(1);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t               _");
    sleep(1);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t                    _");
    //printf("\t\t\t\t\t\t\t\t\n\n\n\nLOADING");
    //printf("\t\t\t\t\t\t\t\t\n\n\n\nLOADING");
    system("cls");
    printf("\n\nEnter no of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter process%d name: ",i+1);
        scanf("%s",&p[i]);
        printf("enter Burst time: ");
        scanf("%d",&pt[i]);
        printf("enter priority: ");
        scanf("%d",&pr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i]>pr[j])
            {
                temp1=pr[i];
                pr[i]=pr[j];
                pr[j]=temp1;
                temp1=pt[i];
                pt[i]=pt[j];
                pt[j]=temp1;
                strcpy(temp,p[i]);
                strcpy(p[i],p[j]);
                strcpy(p[j],temp);
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {   
       // wt[i]=0;
        //for(j=1;j<i;j++)
        
		
        wt[i]=wt[i-1]+pt[i-1];
        
    
      totwt=totwt+wt[i];
	  // s=s+wt[i];
    }
    avgwt=(float)totwt/n;
    printf("p_name\t B_time\t priority\t waiting-time\n");
    for(i=0;i<n;i++)
    {
       printf(" %s\t    %d\t    %d\t     %d\n" ,p[i],pt[i],pr[i],wt[i]);
    }
    printf("total waiting time=%d\n avg waiting time=%f",totwt,avgwt);
    sleep(3);
    system("cls");
    sleep(2);
    
    int ts,pid[10],need[10],wt1[10],tat[10],i1,j1,n2,n1;
    int bt[10],flag[10],ttat=0,twt=0;
    float awt,atat;
    system("COLOR 72");
    printf("\nEnter the number of Processors \n");
    scanf("%d",&n);
    n1=n;
    printf("\n Enter the Timeslice \n");
    scanf("%d",&ts);
    for(i=1;i<=n;i++)
    {
        printf("\n Enter the process ID  %d : ",i);
        scanf("%d",&pid[i]);
        printf("\n Enter the Burst Time for the process : ");
        scanf("%d",&bt[i]);
        need[i]=bt[i];
    }
    for(i=1;i<=n;i++)
    {
        flag[i]=1;
        wt[i]=0;
    }
    while(n!=0)
    {
        for(i=1;i<=n;i++)
        {
            if(need[i]>=ts)
            {
                for(j=1;j<=n;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
                    wt[j]+=ts;
                }
                need[i]-=ts;
                if(need[i]==0)
                {
                    flag[i]=0;
                    n--;
                }
            }
            else
            {
                for(j=1;j<=n;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
                    wt[j]+=need[i];
                }
                need[i]=0;
                n--;
                flag[i]=0;
            }
        }
    }
   // int twt=0;
    //int ttat=0;
    for(i=1;i<=n1;i++)
    {
        tat[i]=wt[i]+bt[i];
        twt=twt+wt[i];
        ttat=ttat+tat[i];
    }
    awt=(float)twt/n1;
    atat=(float)ttat/n1;
    printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
    for(i=1;i<=n1;i++)
    {
        printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,pid[i],bt[i],wt[i],tat[i]);
    }
    printf("\n The average Waiting Time= %f",awt);
    printf("\n The average Turn around Time= %f",atat);
}

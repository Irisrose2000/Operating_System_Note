#include<stdio.h>
int main()
{
    int n ,i,quantum;
    int bt[20],wt[20],tat[20],rt[20];
    int time =0,completed=0;
    int total_wt =0 ,total_tat=0;
    printf("enter the number of process :");
    scanf("%d",&n);
    printf("enter the burst time \n ");
    for(i=0;i<n;i++)
    {
        printf("p%d the burst time",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("enter the quantum time");
    scanf("%d",&quantum);
    while(completed < n)
    {
        int done =1;
        for(i=0;i<n;i++)
        {
            if(rt[i]>0)
            {
                done =0;
                if(rt[i] > quantum)
                {
                    time +=quantum;
                    rt[i]-= quantum;
                }
                else
                {
                    time += rt[i];
                    wt[i] = time-bt[i];
                    rt[i] = 0;
                    completed++;
                }
            }
        }
        if(done)
        {
            break;
        }
    }
      
    // calculate the turn around time
    for(i=0;i<n;i++)
    {
        tat[i] = wt[i] +bt[i];
    }
    printf("\n Process\t burst Time\t Waiting Time \t Turnaround Time\n");
    for(i=0;i<n;i++)
    {
        printf("p%d\t\t\t\t%d\t\t\t%d\t\t\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("The total waiting time is %d\n",total_wt);
    printf("The total turn around time is %d\n",total_tat);
    printf("The average waiting time is%d \n",total_wt/n);
    printf("The average turnaround time is %d\n",total_tat/n);
        
    }
    

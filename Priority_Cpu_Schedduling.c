#include<stdio.h>
void sort(int b[], int p[], int pr[], int n);
void compute_wt_tat(int b[], int p[], int pr[], int n);
int main()
{
    int n,i;
    printf("enter the number of process \n");
    scanf("%d",&n);
    int b[n],p[n],pr[n];
    printf("enter the burst time and priority for each processor\n");
    for(i=0;i<n;i++)
    {
        printf("process %d :",i+1);
        scanf("%d%d",&b[i],&pr[i]);
        p[i]= i + 1;
    }
    sort(b,p,pr,n);
    compute_wt_tat(b,p,pr,n);
    return 0;
}
void sort(int b[], int p[],int pr[] , int n)
{
    for(int i =0 ;i<n-1;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            if(pr[i]<pr[j])
            {
                int temp;
                temp =pr[i];
                pr[i]= pr[j];
                pr[j] = temp;
                
                temp = b[i];
                b[i] = b[j];
                b[j] = temp ;
                
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void compute_wt_tat(int b[] , int p[], int pr[] , int n)
{
    int wt[n], tat[n],total_wt=0,total_tat =0;
    wt[0]=0;
    
    for(int i =1 ;i<n;i++)
    {
       wt[i]=wt[i-1]+b[i-1];
       total_wt+= wt[i];
    }
     for(int i =0 ;i<n;i++)
    {
       tat[i]=wt[i]+b[i];
       total_tat+= tat[i];
    }
    printf("\nProcess\tPriority\tBT\tWT\tTAT");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t%d\t\t%d\t%d\t%d", p[i], pr[i], b[i], wt[i], tat[i]);
    }

    // Print Total & Average Times
    printf("\nTotal Waiting Time: %d", total_wt);
    printf("\nTotal Turnaround Time: %d", total_tat);
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
}

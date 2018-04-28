#include<stdio.h>
#include<stdlib.h>
#define n 5
struct data
{
	int processid;
	int bursttime;
	int arrivaltime;
	int priority;
};
struct data q1[n];
struct data q2[n];
int front1=0;
int rear1=0;
int front2=0;
int rear2=0;
int main ()
{
	int i;
//	printf("Enter no of Processes:");
//	scanf("%d",&n);
//	struct data q1[n];
	printf("Enter process's Arrival Time, Burst Time, Priority\n");
	for(i=0;i<n;i++)
	{
		q1[i].processid=i+1;
		scanf("%d%d%d",&q1[i].arrivaltime,&q1[i].bursttime,&q1[i].priority);
		rear1++;
	}
	for(i=0;i<n;i++)//sorting of elements in the queue 1 on the basis of arrival time using bubble sort
	{
		int k;
		for(k=0;k<n-i-1;k++)
		{
			if(q1[k].arrivaltime>q1[k+1].arrivaltime)
			{
				q1[k].arrivaltime=q1[k].arrivaltime+q1[k+1].arrivaltime-(q1[k+1].arrivaltime=q1[k].arrivaltime);//swapping
				q1[k].bursttime=q1[k].bursttime+q1[k+1].bursttime-(q1[k+1].bursttime=q1[k].bursttime);//swapping
				q1[k].priority=q1[k].priority+q1[k+1].priority-(q1[k+1].priority=q1[k].priority);//swapping
			}
		}
	}
	printf("The First Queue is:\n");
	printf("ProcessID\tArrival Time\tBurst Time\tPriority\n");
	for(i=0;i<n;i++)//printing sorted elements of the queue1
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n",q1[i].processid,q1[i].arrivaltime,q1[i].bursttime,q1[i].priority);
	}
	int completiontime=0;
	while(rear1>front1)
	{
		if(q1[front1].priority<=q1[front1+1].priority)
		{
			completiontime=completiontime+q1[front1].bursttime;
			printf("\nProcess with processid %d completed execution at a completion time of %d",q1[front1].processid,completiontime);
		}
		else
		{
			if(completiontime<q1[front1+1].arrivaltime)
			{
				int temp;
				temp=q1[front1+1].arrivaltime-completiontime;
				printf("\nProcess with processid %d executed for %d and went to second queue",q1[front1].processid,temp);
				q1[front1].bursttime=q1[front1].bursttime-temp;
			}
			else
			{
				printf("\nProcess with processid %d went to second queue without execution",q1[front1].processid);
			}
			q2[rear2].processid=q1[front1].processid;
			q2[rear2].arrivaltime=q1[front1].arrivaltime;
			q2[rear2].bursttime=q1[front1].bursttime;
			q2[rear2].priority=q1[front1].priority;
			rear2++;
		}
		for(i=0;i<rear1-1;i++)
		{
			q1[i].arrivaltime=q1[i+1].arrivaltime;
			q1[i].bursttime=q1[i+1].bursttime;
			q1[i].priority=q1[i+1].priority;
		}
		rear1--;
	}
	if(rear1==front1)
	{
	printf("The First Queue is empty and Priority scheduling is finished");
	}
	
}

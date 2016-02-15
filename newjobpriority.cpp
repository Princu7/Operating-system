# include <bits/stdc++.h>
using namespace std;
struct node
{
	int index,arrival,priority,burst;
};

bool funcSort(const node& a,const node& b)
{
        return a.arrival<b.arrival;
}

priority_queue <int> q;
int main(void)
{
	printf("Enter the number of jobs\n");
	int n;
	cin>>n;
	struct node job[n];
	printf("enter the arrival,burst and priority of each job\n");
	for(int i=0;i<n;i++)
	{
		int a,b,p;
		scanf("%d%d%d",&a,&b,&p);
		job[i].arrival=a;
		job[i].burst=b;
		job[i].priority=p;
		job[i].index=i;
	}
	sort(job,job+n,funcSort);
	int time=job[0].arrival;
	int count=1;
	int cur=0;
	while(time<=job[n-1].arrival)
	{
		cout<<"this is the time "<<time<<endl;
		//cout<<"this is size of queue "<<q.size()<<endl;
		if(job[cur].burst==0)
		{
			if(q.size()!=0)
			{
				cout<<"job no "<<cur<<" has completed its time and is replaced by job "<<q.top()<<endl;
				cur=q.top();
				q.pop();
			}
			else
			{
				cout<<" job no "<<cur<<" has completed its time and there are no more jobs in the queue "<<endl;
				time++;
				job[cur].priority=-1;
			}
		}
		else
		{
			cout<<"this is current job "<<cur<<endl;
		}
		if(job[count].arrival==time)
		{
			cout<<"job "<<count<<" has arrived"<<endl;
			if(job[count].priority>job[cur].priority)
			{
						cout<<"job "<<cur<<" is being replaced by job "<<count<<endl;
						q.push(cur);
						cur=count;	
			}
			count++;
		}
		job[cur].burst--;
		time++;
		cout<<"this is value of count"<<count<<endl<<endl;
	}
}

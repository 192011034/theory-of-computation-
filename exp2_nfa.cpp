#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,l,next_state[20],n,mat[5][5][5],flag,p;
	int num_states,final_state[5],num_symbols,num_final;
	int present_state[20],symbol[5],prev_trans,new_trans;
	char ch,input[20];
	printf("How many states in the NFA : ");
	scanf("%d",&num_states);
	printf("How many symbols in the input alphabet : ");
	scanf("%d",&num_symbols);
	for(i=0;i<num_symbols;i++)
	{
		printf("Enter the input symbol %d : ",i+1);
		scanf("%d",&symbol[i]);
	}
	printf("How many final states : ");
	scanf("%d",&num_final);
	for(i=0;i<num_final;i++)
	{
		printf("Enter the final state %d : ",i+1);
		scanf("%d",&final_state[i]);
	}
	//Initialize all entries with -1 in Transition table
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				mat[i][j][k]=-1;
			}
		}
	}
	//Get input from the user and fill the 3D transition table
	for(i=0;i<num_states;i++)
	{
		for(j=0;j<num_symbols;j++)
		{
			printf("How many transitions from state %d for the input %d : ",i,symbol[j]);
			scanf("%d",&n);
			for(k=0;k<n;k++)
			{
				printf("Enter the transition %d from state %d for the input %d : ",k+1,i,symbol[j]);
				scanf("%d",&mat[i][j][k]);
			}
		}
	}
	while(1)
	{
		printf("Enter the input string : ");
		scanf("%s",input);
		present_state[0]=0;
		prev_trans=1;
		l=strlen(input);
		for(i=0;i<l;i++)
		{
			int inp=(int)(input[i]-'0');
			new_trans=0;
			for(j=0;j<prev_trans;j++)
			{
				k=0;
				p=present_state[j];
				while(mat[p][inp][k]!=-1)
				{
					next_state[new_trans++]=mat[p][inp][k];
					k++;
				}
			}
			for(j=0;j<new_trans;j++)
			{
				present_state[j]=next_state[j];
			}
			prev_trans=new_trans;
		}
		flag=0;
		for(i=0;i<prev_trans;i++)
		{
			for(j=0;j<num_final;j++)
			{
				if(present_state[i]==final_state[j])
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
			printf("Acepted\n");
		else
			printf("Not accepted\n");
		printf("Try with another input\n");
	}
}



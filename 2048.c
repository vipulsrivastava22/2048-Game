#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count,a0,a1,st,t=0;
void play();
void win();
void hashing(int *a0,int *a1);
void endgame();
void hashing(int *a0,int *a1);
int swipeleft();
int swiperight();
int swipeup();
int swipedown();
void show();
int arrangeright();
int arrangeleft();
int arrangeup();
int arrangedown();
int callingallswipes();
void newtile();
int check[4][4];
int array[4][4];
int score=0;
int swipes=0;
int m0=0,m1=0;
int con[2];
int sarray[2];


int main()
{
	int choice;
	FILE *fp1;
	fp1=fopen("random.txt","r+");
	if(fp1==NULL)
	{
		fp1=fopen("random.txt","w");
		fprintf(fp1,"%d",0);
		fclose(fp1);
	}
	else
	{
		fscanf(fp1,"%d",&count);
		fseek(fp1,0,SEEK_SET);
	}
	while(1)
	{
		printf("1 : Play\n2 : Exit\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :	play();
						break;
			case 2 :	exit(0);
						break;
			default:	printf("Enter Valid Input : ");
						scanf("%d",&choice);
		}
		
	}
	fclose(fp1);
	return 0;
}


void play()
{
		int i,j;
		char ch;
		
		printf("A : Swipe Left\n");
		printf("D : Swipe Right\n");
		printf("W : Swipe Up\n");
		printf("S : Swipe Down\n");
		printf("Q : End Game\n");
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
			array[i][j]=0;
			check[i][j]=0;
			}
		}
		newtile();
		newtile();
		show();
		con[0]=score;
		while(1)
		{
			
			printf("\nEnter Choice : ");
			ch=getch();
			if(t>=2)
			t=0;
			switch(ch)
			{
				case 'a' :	
				case 'A' :	st=0;
							sarray[t]=st;
							t++;
							if(swipeleft()==0)
							{
								show();
								break;			
							}
							win();
							newtile();
							show();
							break;
				case 'd':	
				case 'D':		st=0;
							sarray[t]=st;
							t++;
							if(swiperight()==0)
							{
								show();
								break;
							}
							win();
							newtile();
							show();
							break;
				case 'w':   
				case 'W':   st=1;
							sarray[t]=st;
							t++;
							if(swipeup()==0)
							{
								show();
								break;
							}
							win();
							newtile();
							show();
							break;
				case 's':   
				case 'S':   st=1;
							sarray[t]=st;
							t++;
							if(swipedown()==0)
							{
								show();
								break;
							}
							win();
							newtile();
							show();
							break;
				case 'q' :  
				case 'Q' :  endgame();
							show();
							break;
				default:	printf("\nEnter Valid Input : \n");
							scanf("%c",&ch);
			}
		
		
		} 
}


void show()
{			
			int i,j;
			printf("\n");
			printf("\t-----------------------------------------------------------------\n");
			for(i=0;i<4;i++)
			{		
			
						for(j=0;j<4;j++)
						if(array[i][j]!=0)
						{
							printf("\t|\t%d",array[i][j]);
						}
						else
						{
							printf("\t|\t ");
						}
						printf("\t|\n");
						printf("\t-----------------------------------------------------------------\n");
						
					
			}
			
}


void hashing(int *a0,int *a1)
{

		
		switch(count)
		{
				case 1 : *a0=0;
						 *a1=0;
						 break;
				case 2 : *a0=1;
						 *a1=1;
						 break;	
				case 3 : *a0=0;
						 *a1=3;
						 break;	
				case 4 : *a0=1;
						 *a1=0;
						 break;	
				case 5 : *a0=1;
						 *a1=3;
						 break;	
				case 6 : *a0=0;
						 *a1=2;
						 break;	
				case 7 : *a0=2;
						 *a1=1;
						 break;	
				case 8 : *a0=1;
						 *a1=2;
						 break;	
				case 9 : *a0=2;
						 *a1=2;
						 break;	
				case 10 : *a0=3;
						 *a1=2;
						 break;	
				case 11 : *a0=0;
						 *a1=1;
						 break;	
				case 12 : *a0=2;
						 *a1=0;
						 break;	
				case 13 : *a0=3;
						 *a1=3;
						 break;	
				case 14 : *a0=3;
						 *a1=1;
						 break;	
				case 15 : *a0=2;
						 *a1=03;
						 break;	
				case 16 : *a0=3;
						 *a1=0;
						break;			
		}
		if(count<16)
		{
			count++;
		}
		else
		count=0;
		
}


void newtile()
{
		hashing(&a0,&a1);
		while(check[a0][a1]!=0)
		{
			hashing(&a0,&a1);
		}
		array[a0][a1]=2;
		check[a0][a1]=1;
}


int swipeleft()
{
		int i,j,shift,s=0,add=0,f=1;
		
		shift=arrangeleft();
		if(shift==1)
		{
			s=1;
		}
		swipes++;
		for(i=0;i<4;i++)
		{
			for(j=0;j<3;j++)
			{
				if(array[i][j]==array[i][j+1]&&check[i][j]!=0)
				{
					array[i][j]=array[i][j]+array[i][j+1];
					score=score+array[i][j];
					check[i][j]=1;
					array[i][j+1]=0;
					check[i][j+1]=0;
					add=1;
				}
				shift=arrangeleft();
				if(shift==1)
				{
					s=1;
				}
				
			}
		}
		con[1]=score;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(check[i][j]!=1&&check[i][j]==0)
				{
					f=0;	
				}
			}
		}
		if((f==1)&&(callingallswipes()==1))
		{
				endgame();
		}
		else
		if((f==1)&&(callingallswipes()==0))
		{
				s=0;	
		}
		else
		if(s==0&&add==0&&(f==0))
		{
			s=0;
		}
		else
		{
			s=1;
			con[0]=con[1];
		}
		return s;
}
int swiperight()
{
		int i,j,shift,s=0,add=0,f=1;
		swipes++;
		
		shift=arrangeright();
		if(shift==1)
		{
			s=1;
		}
		for(i=0;i<4;i++)
		{
			for(j=3;j>0;j--)
			{
				if(array[i][j]==array[i][j-1]&&(check[i][j]!=0))
				{
					array[i][j]=array[i][j]+array[i][j-1];
					score=score+array[i][j];
					check[i][j]=1;
					array[i][j-1]=0;
					check[i][j-1]=0;
					add=1;
				}
				shift=arrangeright();
				if(shift==1)
				{
					s=1;
				}
			}
		}
		con[1]=score;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(check[i][j]!=1&&check[i][j]==0)
				{
					f=0;	
				}
			}
		}
		if((f==1)&&(callingallswipes()==1))
		{
				endgame();
		}
		else
		if((f==1)&&(callingallswipes()==0))
		{
				s=0;	
		}
		else
		if(s==0&&add==0&&(f==0))
		{
			s=0;
		}
		else
		{
			s=1;
			con[0]=con[1];
		}
		return s;
}
int swipeup()
{
		int i,j,shift,s=0,add=0,f=1;
		swipes++;
		
		shift=arrangeup();
		if(shift==1)
		{
			s=1;
		}
		for(j=0;j<4;j++)
		{
			for(i=0;i<3;i++)
			{
				if(array[i][j]==array[i+1][j]&&(check[i][j]!=0))
				{
					array[i][j]=array[i][j]+array[i+1][j];
					score=score+array[i][j];
					check[i][j]=1;
					array[i+1][j]=0;
					check[i+1][j]=0;
					add=1;
				}
				shift=arrangeup();
				if(shift==1)
				{
					s=1;
				}			
			}
		}
		con[1]=score;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(check[i][j]!=1&&check[i][j]==0)
				{
					f=0;	
				}
			}
		}
			if((f==1)&&(callingallswipes()==1))
		{
				endgame();
		}
		else
		if((f==1)&&(callingallswipes()==0))
		{
				s=0;	
		}
		else
		if(s==0&&add==0&&(f==0))
		{
			s=0;
		}
		else
		{
			s=1;
			con[0]=con[1];
		}
		return s;
}
int swipedown()
{
		int i,j,shift,s=0,add=0,f=1;
		
		swipes++;
		shift=arrangedown();
		if(shift==1)
		{
			s=1;
		}
		for(j=0;j<4;j++)
		{
			for(i=3;i>0;i--)
			{
				if(array[i][j]==array[i-1][j]&&check[i][j]!=0)
				{
					array[i][j]=array[i][j]+array[i-1][j];
					score=score+array[i][j];
					check[i][j]=1;
					array[i-1][j]=0;
					check[i-1][j]=0;
					add=1;
				}
				shift=arrangedown();
				if(shift==1)
				{
					s=1;
				}
			}
		}
		con[1]=score;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(check[i][j]!=1&&check[i][j]==0)
				{
					f=0;	
				}
			}
		}
		if((f==1)&&(callingallswipes()==1))
		{
				endgame();
		}
		else
		if((f==1)&&(callingallswipes()==0))
		{
				s=0;	
		}
		else
		if(s==0&&add==0&&(f==0))
		{
			s=0;
		}
		else
		{
			s=1;
			con[0]=con[1];
		}
		return s;
}
void endgame()
{
	int hs;
	
	FILE *fp,*fp1;
	fp=fopen("highestscore.txt","r+");
	if(fp==NULL)
	{
		fp=fopen("highestscore.txt","w");
		fprintf(fp,"%d",0);
		fclose(fp);
	}
	else
	{
		fscanf(fp,"%d",&hs);
		if(score>hs)
		{
			fseek(fp,0,SEEK_SET);
			hs=score;
			fprintf(fp,"%d",score);
		}
	}
	fp1=fopen("random.txt","r+");
	if(fp1==NULL)
	{
		fp1=fopen("random.txt","w");
		fprintf(fp1,"%d",0);
		fclose(fp1);
	}
	else
	{
		
		fseek(fp1,0,SEEK_SET);
		fprintf(fp1,"%d",count);
	}
	printf("End Game");
	printf("\n\nScore : %d\t\tSwipes : %d\tHigh Score : %d",score,swipes,hs);
	fclose(fp);
	fclose(fp1);
	exit(0);
}
int arrangeright()
{
		int i,j,k,shift=0;
		for(i=0;i<4;i++)
		{
			
			for(j=3;j>=1;j--)
			{
						k=j;
						while(check[i][k]!=1&&(k!=-1))
						{
							k--;
						}
						if(j!=k&&(k!=-1))
						{
							shift=1;
							array[i][j]=array[i][k];
							check[i][j]=1;
							array[i][k]=0;
							check[i][k]=0;
						}
			}
				
		}
		return shift;
}
int arrangeleft()
{
	int i,j,k,shift=0;
		for(i=0;i<4;i++)
		{
			for(j=0;j<=2;j++)
			{
						k=j;
						while(check[i][k]!=1&&(k!=4))
						{
							k++;
						}
						if(j!=k&&(k<=3))
						{
							shift=1;
							array[i][j]=array[i][k];
							check[i][j]=1;
							array[i][k]=0;
							check[i][k]=0;
						}
			}
				
		}
		return shift;
}
int arrangeup()
{
		int i,j,k,shift=0;
		for(j=0;j<=3;j++)
		{
			for(i=0;i<=2;i++)
			{
						k=i;
						while(check[k][j]!=1&&(k!=4))
						{
							k++;
						}
						if(i!=k&&(k!=4))
						{
							shift=1;
							array[i][j]=array[k][j];
							check[i][j]=1;
							array[k][j]=0;
							check[k][j]=0;
						}
			}
				
		}
		return shift;
}
int arrangedown()
{
	int i,j,k,shift=0;
		for(j=0;j<=3;j++)
		{
			for(i=3;i>0;i--)
			{
						k=i;
						while(check[k][j]!=1&&(k!=-1))
						{
							k--;
						}
						if(i!=k&&(k!=-1))
						{
							shift=1;
							array[i][j]=array[k][j];
							check[i][j]=1;
							array[k][j]=0;
							check[k][j]=0;
						}
			}
				
		}
		return shift;
}

int callingallswipes()
{
		int flag=0;
		char ch;
		if((con[1]==con[0])&&(sarray[0]==0&&sarray[1]==0))
		{
			//printf("\nHINT : Left or Write Swipe is Not possible \n");
			m0=1;
			return 0;
		}
		else
		if((con[1]==con[0])&&(sarray[0]==1&&sarray[1]==1))
		{
			//printf("\nHINT : Up or Down Swipe is Not possible \n");
			m1=1;
			return 0;
		}
		else
		if((con[1]==con[0])&&(m0==1&&m1==1)&&((sarray[0]==1&&sarray[1]==0)||(sarray[0]==0&&sarray[1]==1)))
		{
			flag=1;
			return 1;
		}
		else
		{
			flag=0;
			m0=0;
			m1=0;
			return 0;
		}
}
void win()
{
	int i,j,ch;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if((array[i][j]/2048)==1)
			{
			
				printf("You Won \n");
				printf("Would u like to continue : Enter q for end game ");
				ch=getch();
				if(ch=='y'||ch=='Y')
				endgame();
			}
			
		}
	}
}

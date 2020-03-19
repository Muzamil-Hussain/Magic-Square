#include <iostream>
using namespace std;
int main()
{
	int dimension,x,y,value=1,count=1,xcheck=0,ycheck=0;
	cout<<"Enter the dimension of matrix: ";
	cin>>dimension;
	if (dimension <0 || dimension%2==0)
	{
		cout<<"Invalid input";
		main();
	}
	else
	{
	x=0; // for starting row
	y=dimension/2; //for starting column
	
	/*making magic square of size dimension*dimension*/
	int **magicsquare=new int *[dimension];
	for (int i=0;i<=dimension;i++)
	{
		*(magicsquare+i)=new int [dimension];
	}
	
	// assigning 0 to the newly created magic square to ovoid garbage value
	for (int i=0;i<dimension;i++)
	{
		for (int j=0;j<dimension;j++)
		{
				*(*(magicsquare+i)+j)=0;
		}
	}
	
	*(*(magicsquare+x)+y)=value; // setting 1 at middle 
	while (count <dimension*dimension)  //loop untill count reaches dimension*dimension
	{
		if (x==0)  // condition when digit is on 0th row
		{
			if (x==0 && y==dimension-1)  // if it is on first row and last column
			{
				x+=1; // in this case just increase in value of x 
				value+=1; // increase in value 
				*(*(magicsquare+x)+y)=value; //assigning value at that position 
				count+=1; //incrementing count
			}
			else if (x==0 && y!=dimension-1) // when on first row but not last column
			{
			x+=dimension-1; // increase of dimension-1 in row because it reaches at last row 
			y+=1; // increase of just 1 in column
			value+=1; 
			*(*(magicsquare+x)+y)=value;
			count+=1;
		    }	
		}
		if (y==dimension-1) // when the digit is on last column
		{
			x-=1; //decrease value of x by 1
			y-=(dimension-1); // decrease value of y by dimension-1 to reach at first column
			value+=1;
			*(*(magicsquare+x)+y)=value;
			count+=1;
		}
		if (x!=0 && y!=dimension-1)  // when neither x is on 0th row nor y is on last column
		{
			if (*(*(magicsquare+(x-1))+y+1)==0)  //checking if by putting next value in suggested box doesn't overlap anyother value placed before
			{
				//if not then 
				x-=1; 
				y+=1;
				value+=1;
				*(*(magicsquare+x)+y)=value;
				count+=1;	
			}
			else //if yes then just put the value below that
			{
				x+=1;
				value+=1;
				*(*(magicsquare+x)+y)=value;
				count+=1;
			}
		}
    }
    // displaying magic square in last
	for (int i=0;i<dimension;i++)
	{
		for (int j=0;j<dimension;j++)
		{
            cout<<*(*(magicsquare+i)+j)<<"\t";
		}
		cout<<"\n";
	}
}
}

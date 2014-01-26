#include<iostream>
using namespace std;

struct stack_S
{
	/* data */
	int s, d[1000];
};

stack_S tra;
int arr1[1000];


int main()
{
	int ia;
	bool isfirst = true;
	while(cin>>ia, ia)
	{
		if(isfirst) isfirst = false;
		else cout<<endl;
		while(cin>>arr1[0], arr1[0])
		{
			for (int i = 1; i < ia; ++i)
				cin>>arr1[i];

			int ib = 1;
			tra.s = 0;
			for(int i = 0 ; i < ia; ++i)
			{
				while( arr1[i] > ib && ib <= ia )
				{
					tra.d[ tra.s ] = ib;
					tra.s++;
					ib++;
				}
				if( arr1[i] == ib )
					ib++;
				else if( arr1[i] < ib )
				{
					if( tra.d[ tra.s-1 ] != arr1[i] )
					{
						ib = 0;
						break;
					}
					else tra.s--;
				}
			}
			if(ib) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}

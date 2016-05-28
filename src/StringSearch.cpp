#include "StringSearch.h"

int EditDistance(string name1,string name2){

	unsigned int l1=name1.size();
	unsigned int l2=name2.size();
	vector<vector<int> > D(l1 + 1, vector<int>(l2 + 1));

	for(unsigned int i=0;i<l1;i++)
	{
		D[i][0]=i;
	}

	for(unsigned int j=0;j<l2;j++)
	{
		D[0][j]=j;
	}

	for(unsigned int i=1;i<l1;i++)
	{
		for(unsigned int j=1;j<l2;j++)
		{
			if(name1[i]==name2[j])
			{
				D[i][j]=D[i-1][j-1];
			}
			else {
				D[i][j]=1+min(min(D[i-1][j-1],D[i-1][j]),D[i][j-1]);
			}
		}
	}

	return D[l1][l2];
}

string VerifyValidName(string name1,string name2){

	int val=0;

	val=EditDistance(name1,name2);

	if(val==0)
		return name2;
	else
		return "";
}

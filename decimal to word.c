#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the null-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
char* twodig(int p,int q,int r,char *onetoten[],char *eletotwi[],char *tenspos[]){

	char *arrr[10];
 	
	
	
	if(q==0){
		arrr[r]=onetoten[p];
		}
	else{
		
		if(q==1)
			arrr[r]=eletotwi[p];
		else if((q!=1)&&(p==0))
			arrr[r]=tenspos[q-2];		
		else
			arrr[r]= concat(tenspos[q-2],onetoten[p]);           
		 
	}


	return arrr[r];


}
int main()
{
	
	char *onetoten[]={"ziro","one","two","three","four","five","six","seven","eight","nine"};
	char *eletotwi[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	char *tenspos[]={"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	char *big[]={"hundred","thousend","lakh","carror","arab"};
	do{
		char *arrr[10];	
		int n,i,p,j,num[20],nod;
		printf("+++++++++=========================================================================================+++++++++++++\n");
		printf("enter a number to print in word\n");
		scanf("%d",&n);
		p=n;
	
		for(j=0;j<20;j++){
			num[j]=0;
			}
		i=0;
		while(p>0){
			num[i]=p%10;
			p=p/10;
			i++;
	
		
		}
		nod=i;
		if(nod==0)
		{
			arrr[0]="zero";
		}
		if(nod==2||nod==1)
		{
			arrr[0]=twodig(num[0],num[1],0,onetoten,eletotwi,tenspos);	
		}
		if(nod==3)
		{
			arrr[1]=concat(big[0],twodig(num[0],num[1],0,onetoten,eletotwi,tenspos));
			arrr[0]=concat(onetoten[num[2]],arrr[1]);
		}
		if(nod==4||nod==5)
		{
			arrr[1]=concat(big[0],twodig(num[0],num[1],0,onetoten,eletotwi,tenspos));
			arrr[2]=concat(onetoten[num[2]],arrr[1]);
			arrr[3]=concat(twodig(num[3],num[4],0,onetoten,eletotwi,tenspos),big[1]);
			arrr[0]=concat(arrr[3],arrr[2]);
		}
		if(nod==6||nod==7){
		
			arrr[1]=concat(big[0],twodig(num[0],num[1],0,onetoten,eletotwi,tenspos));
			arrr[2]=concat(onetoten[num[2]],arrr[1]);
			arrr[3]=concat(twodig(num[3],num[4],0,onetoten,eletotwi,tenspos),big[1]);
			arrr[4]=concat(arrr[3],arrr[2]);
			arrr[5]=concat(twodig(num[5],num[6],0,onetoten,eletotwi,tenspos),big[2]);
			arrr[0]=concat(arrr[5],arrr[4]);
		}
		if(nod==8||nod==9)
		{
			arrr[1]=concat(big[0],twodig(num[0],num[1],0,onetoten,eletotwi,tenspos));
			arrr[2]=concat(onetoten[num[2]],arrr[1]);
			arrr[3]=concat(twodig(num[3],num[4],0,onetoten,eletotwi,tenspos),big[1]);
			arrr[4]=concat(arrr[3],arrr[2]);
			arrr[5]=concat(twodig(num[5],num[6],0,onetoten,eletotwi,tenspos),big[2]);
			arrr[6]=concat(arrr[5],arrr[4]);
			arrr[7]=concat(twodig(num[7],num[8],0,onetoten,eletotwi,tenspos),big[3]);
			arrr[0]=concat(arrr[7],arrr[6]);
	
		}
		if(nod>9){
			arrr[0]="Limit doesn't exist, Please try another number";
		}
	



		printf("%s\n",arrr[0]);
		printf("++++++++++++++=====================================================================================++++++++++++\n");


	}while(2>1);


	return 0;
}


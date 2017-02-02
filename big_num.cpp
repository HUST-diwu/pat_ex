#include <cstdio>
#include <cstring>
struct bign{
	char d[100];
	char len;
	bign()
	{
		memset(d,0,sizeof(d));
		len=0;
	}
};

bign str_to_bign(char *str)
{
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++)
	{
		a.d[i]=str[a.len-i-1]-'0';
	}
	return a;
}

bign add(bign &a,bign &b)
{
	bign c;
	int carry=0;
	for(int i=0;i<a.len||i<b.len;i++)
	{
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	if(carry!=0){
		c.d[c.len++]=carry;
	}
	return c;
}

bign sub(bign &a,bign &b)
{
	bign c;
	for(int i=0;i<a.len||i<b.len;i++)
	{
		if(a.d[i]<b.d[i])
		{
			a.d[i+1]--;
			a.d[i]+=10;
		}
		c.d[c.len++]=a.d[i]-b.d[i];
	}
	while(c.d[c.len-1]==0&&c.len>=2)
	{
		c.len--;
	}
	return c;
}

bign multi(bign &a,int b)
{
	bign c;
	int carry=0;
	for(int i=0;i<a.len;i++)
	{
		int temp=a.d[i]*b+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	}
	while(carry!=0)
	{
		c.d[c.len++]=carry%10;
		carry/=10;
	}
	return c;
}

int main()
{
	char a[100];
	int b;
	scanf("%s %d",a,&b);
	bign A=str_to_bign(a);
	//bign B=str_to_bign(b);
	bign C=multi(A,b);
	for(int i=C.len-1;i>=0;i--)
		printf("%d",C.d[i]);
	printf("\n");
	return 0;
}
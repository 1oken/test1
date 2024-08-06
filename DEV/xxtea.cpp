#include<iostream>
#define ut32 unsigned int
#define delta 0x9e3779b9

using namespace std;
void xxtea_encrypt(ut32* src,ut32 n,ut32* key);
void xxtea_decrypt(ut32* enc,ut32 n,ut32* key);
void output(ut32* m,ut32 len);

void xxtea_encrypt(ut32* src,ut32 n,ut32* key)
{
	ut32 y,z,sum=0;
	ut32 e,rounds;
	int p;
	rounds =6+52/n;
	do{
		z=src[n-1];
		sum+=delta;
		e=(sum>>2)&3;
		for(p=0;p<n-1;p++)
		{
			y=src[p+1];
			src[p]+=(((z>>5^y<<2)+(y>>3^z<<4))^((sum^y)+(key[(p&3)^e]^z)));
			z=src[p];
		}
		y=src[0];
		src[n-1]+=(((z>>5^y<<2)+(y>>3^z<<4))^((sum^y)+(key[(p&3)^e]^z)));
	}while(rounds--);
}


void xxtea_decrypt(ut32* enc,ut32 n,ut32* key)
{
	ut32 y,z,sum;
	ut32 e,rounds;
	int p;
	rounds =6+52/n;
	sum=delta*rounds;
	
	do{
		e=(sum>>2)&3;
		for(p=n-1;p>0;p--){
			y=enc[(p+1)%n];
			z=enc[(p-1)];
			enc[0]-=(((z>>5^y<<2)+(y>>3^z<<4))^((sum^y)+(key[(p&3)^e]^z)));
			sum-=delta;
		}
	}while(rounds--);
}

int main()
{
	
}

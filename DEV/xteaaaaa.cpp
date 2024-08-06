#include<iostream>
#define ut32 unsigned int
#define delta 0xF462900 

void XTea_Decrypt(ut32* enc, ut32* k) {

	for ( int i = 8; i >= 0; i-- )
  {	ut32 v0 = enc[i];
	ut32 v1 = enc[i+1];
    ut32 sum = delta * i+delta*0x21;
	for (int i = 0; i <0x21; i++) {
				sum -= delta;
		v1 -= (((v0 *16) ^ (v0 >> 5)) + v0) ^ (sum + k[(sum >> 11) & 3]);

		v0 -= sum^(((v1 *16) ^ (v1 >> 5)) + v1) ^ (sum + k[sum & 3]);


	}
	enc[i] = v0;
	enc[i+1] = v1;
}
}

void output(ut32* m, ut32 n)
{
	for (int i = 0; i < n; i++)
		printf("0x%08x ", m[i]);
	printf("\n");
}

int main() {
	ut32 m[10] = {0x1A800BDA,0xF7A6219B,0x491811D8,0xF2013328,0x156C365B,0x3C6EAAD8,0x84D4BF28,0xF11A7EE7,0x3313B252,0xDD9FE279};
	ut32 k[4] = {0x8B9,0x1167,0x1A15,0x22C3 };
	XTea_Decrypt(m, k);
	output(m, 10);
	for(int i=0;i<=9;i++){
		printf("%x", m[i]);
	}

	return 0;
}

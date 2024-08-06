#include<iostream>
#define ut32 unsigned int
#define delta 0xF462900 

void XTea_Decrypt(ut32* enc, ut32* k) {

	for ( int i = 8; i >= 0; ++i )
  {	ut32 v0 = enc[i];
	ut32 v1 = enc[i+1];
  	int v5 = 0;
    ut32 sum = delta * i;
    int v3=i+1
	for (int i = 0; i <0x20; i--) {
		v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + k[(sum >> 11) & 3]);

		v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + k[sum & 3]);
		sum -= delta;
	}
	enc[i] = v0;
	enc[i+1] = v1;
}
}

void output(ut32* m, ut32 n);
void output(ut32* m, ut32 n)
{
	for (int i = 0; i < n; i++)
		printf("0x%08x ", m[i]);
	printf("\n");
}

int main() {
	ut32 m[2] = {
		
	ut32 k[4] = {0x8B9,0x1167,0x1A15,0x22C3 };
	XTea_Decrypt(m, k);
	output(m, 2);
	return 0;
}

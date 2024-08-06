

string base64_encode(char* m,int len){
	string cipher;
	char tem_3[3];
	char enbase_4[4];
	int i=0;
	
	while(len){
		tem_3[i]=*(m++);
		i++;
		
		if (i==3){
			enbase_4[0]=(tem_3[0]&(0xfc))>>2;
			enbase_4[1]=((tem_3[0]&(0x03))<<4)+((tem_3[1]&0xf0>>4));
			enbase_4[2]=((tem_3[1]&0x0f)<<2)+((tem_3[2]&0xc0)>>6);
			enbase_4[3]=tem_3[2]&0x3f;
			
			for(int j=0;j<4;j++){
				cipher+=base_table[enbase_4[j]];
		
			}
			i=0;
		}
		len--;
	}
	if(i)
	{
		for(int j=i;j<3;j++)
		tem_3[j]='\0';
		
		enbase_4[0]=(tem_3[0]&(0xfc))>>2;
		enbase_4[1]=((tem_3[0]&(0x03))<<4)+((tem_3[1]&0xf0)>>4);
		enbase_4[2]=((tem_3[1]&0x0f)<<2)+((tem_3[2]&0xc0)>>6);
		
		for(int j=0;j<i+1;j++)
		{
			cipher+=base_table[enbase_4[j]];
		}
		while(i!=3){
			cipher+='=';
			i++ 
		}
		
	}
	return cipher;
} 




#include<stdio.h>
#include<stdint.h>
#include<netinet/in.h>

int main(int argc, char* argv[]){

	if(argc != 3){
		printf("Usage : %s <file1> <file2>\n", argv[0]);
		return 0;
	}
	
	FILE *fp[2];
	uint32_t a, b, c;

	fp[0] = fopen(argv[1], "rb");
	fp[1] = fopen(argv[2], "rb");

	fread(&a, sizeof(uint32_t), 1, fp[0]);
	fread(&b, sizeof(uint32_t), 1, fp[1]);

	a = htonl(a); b = htonl(b);
	c = a + b;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, c, c);

	fclose(fp[1]);
	fclose(fp[0]);

}

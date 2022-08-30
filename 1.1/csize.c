#include <stdio.h>

int main()
{
	unsigned char ch = 0x30;
	unsigned int i = 12345;
	ch = i/1000%10 + 0x30;
	printf("short=%ld\n", sizeof(short));
	printf("char=%ld\n", sizeof(char));
    printf("unsigned char=%ld\n", sizeof(unsigned char));
	printf("int=%ld\n", sizeof(int));
	printf("unsigned int=%ld\n", sizeof(unsigned int));
	printf("unsigned short int=%ld\n", sizeof(unsigned short int));
	printf("unsigned long int=%ld\n", sizeof(unsigned long int));
	printf("float=%ld\n", sizeof(float));
	printf("double=%ld\n", sizeof(double));
	printf("long long int=%ld\n", sizeof(long long int));
	printf("int *=%ld\n", sizeof(int*));
	printf("char *=%ld\n", sizeof(char*));
	printf("float *=%ld\n", sizeof(float*));
	printf("double *%ld\n", sizeof(double*));
	printf("long long int *=%ld\n", sizeof(long long int*));
	printf("%c\n", ch);
	printf("%c\n", 0x2E);
	printf("ASCII \".\" is:%d\n", (int)'.');
	printf("\"\\r\" = %d\n", '\r');
	printf("\"\\n\" = %d\n", '\n');
	return 0;
}


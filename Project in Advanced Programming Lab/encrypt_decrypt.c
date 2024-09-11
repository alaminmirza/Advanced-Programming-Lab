#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


bool srand_called = false;

int Random_Number(int i)
{
    if (!srand_called) {
        srand(time(NULL) << 10);
        srand_called = true;
    }

    return rand() % i;
}


char *encrypt(char *code)
{
	int hash = strlen(code);
	char *encrypt = malloc((hash * 3) + 3);
	char *toHash = encrypt;

	for (char ch = *code; ch != '\0'; ch = *(++code))
	{
		int hashNum = encrypt - toHash; 
		*(encrypt++) = (char) 126 - Random_Number(66);
		*(encrypt++) = (char) 126 - Random_Number(66);
		*(encrypt++) = ch + hash - hashNum ;
	}

	*(encrypt++) = (char) 126 - Random_Number(66);
	*(encrypt++) = (char) 126 - Random_Number(66);
	*encrypt = '\0';

	return toHash;
}


char *decrypt(char *code)
{
	int hash = ((strlen(code) - 3) / 3) + 2;
	char *decrypt = malloc(hash);
	char *toFree = decrypt;
	char *word = code;

	for (int ch = *code; ch != '\0'; ch = *(++code))
	{
		if((code - word + 2) % 3  == 1){
			*(decrypt++) = ch - (word - code + 1) - hash;
		}
	}

	*decrypt = '\0';

	return toFree;
}


int main(void)
{
	char raw_district_list[13][12] = {"DHAKA", "FARIDPUR", "GAZIPUR", "GOPALGANJ", "KISHOREGANJ", "MADARIPUR", "MANIKGANJ", 
										"MUNSHIGANJ", "NARAYANGANJ", "NARSINGDI", "RAJBARI", "SHARIATPUR", "TANGAIL"};

	char encrypted_district_list[13][37] = {"P^I[uJYK@CcG|W:H}", "=cN[ZFndTZDHoQ@uXIw~KHeETD", "reNlnE\\y[JsGfIKNSMVSGuJ", "|TPvgURYSW=AmgIPQA``8GBBnQ;iS",
						"fbV{RQT{XzHJQZNlkN[O>Ik=KO4dZ>HH7_T", "hiV[fG?HGnrAliOvBCFEGa@IyCC||", "mxVEXGLrQo\\IFxHn@A>T8bRBPQ;KT", "@kW~T\\DpRSmTJKFKoDlg?l>6vN@BP9SB",
						"I^YgaIbkWT=CWPX{h=kPGAM=bk4in>du7gM", "f~WKVGiaUmjSLbF}jHZI>r|8mK:Fb", "P_YekEHEKMG@~U<\\rJAX>O]", "zO]__OQjE[OSAfG{b<ppLZ^ES?GaCAGp",
						"x][GtETcOYDE?Z<i^AgjA>^"};

	char *encrypted, *decrypted;

	for(int i = 0; i<13; i++)
	{
		encrypted = encrypt(raw_district_list[i]);
		printf("'%s', ", encrypted);
	}

	printf("\n\n\n");

	for(int i = 0; i<13; i++)
	{
		decrypted = decrypt(encrypted_district_list[i]);
		printf("'%s', ", decrypted);
	}

	free(encrypted);
	free(decrypted);
}
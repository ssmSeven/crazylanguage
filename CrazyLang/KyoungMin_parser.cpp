#include "stdafx.h"
#include "KyoungMin_parser.h"



char* streamParser(char* inStream){

	int count = 0 ;
	char *tmp;
	
	int charSize = strlen(inStream);
	
	tmp = (char*) malloc(sizeof(char) * charSize);
	
	memset(tmp, 0x00, sizeof(tmp));
	
	while ( *inStream )
    {
        if ( *inStream == '<' || *inStream == '>' || *inStream == '/' || *inStream == '.')
        {
			*tmp++ = *inStream++;
			count++;
            continue;
        }
        inStream++;
    }

	tmp = tmp -count;	
	int ASDF = (sizeof(char) * count);
	inStream = (char*) malloc(sizeof(char) * count +1);
	memset(inStream, 0x00, sizeof(char) * count +1);

	strncpy(inStream, tmp, sizeof(char) * count );
	
	return inStream;
}
/*int main(){

	char *ch;
	ch = "aa><a/d,a";

	int strlen ; 
	printf("input String  : %s\n", ch);
	ch = streamParser(ch);

	printf("output String : %s\n", ch);	
	getchar();

}*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void StrRevWord(const char* str)
{
	size_t sizeOfStr = strlen(str) + 1;
	char *temp = (char *)malloc((sizeOfStr)*sizeof(char));
	memset(temp, '\0', sizeOfStr);
	strlcpy(temp, str, sizeOfStr);
	char *beg = temp;
	char *runner = temp;
	char *end, t;
	while(1)
	{
		while( (*runner!='\0') && !isspace(*runner))
		{
			runner++;
		}

		end = runner - 1;
		//reverse word
		while(beg<end)
		{
			t = *beg;
			*beg = *end;
			*end = t;
			beg++;end--;
		}
		while((*runner!='\0') && isspace(*runner))
		{
			runner++;
		}
		if(*runner=='\0')
		break;
		beg = runner;
	}
	printf("\n StrRevWord %s", temp);
	free(temp);
}

void StrRevWordPlace(const char *str)
{
	size_t sizeOfStr = strlen(str)+1;

	char *temp = (char *)malloc((sizeOfStr)*sizeof(char));
	memset(temp, '\0', sizeOfStr);
	strlcpy(temp, str, sizeOfStr);
	char *temp1 = (char *)malloc((sizeOfStr)*sizeof(char));
	memset(temp1, '\0', sizeOfStr);
	char *beg = temp1;
	char *runner = temp;
	char *end, t;

	while(*runner++)
	{ }
	end = runner-1;
	while(1)
	{
		while((end!=temp) && !isspace(*end))
		{
			end--;
		}
		//write end in the temp1
		{
			runner = end;
			if(isspace(*end))
				runner = end+1;
				
			while((*runner!='\0') && !isspace(*runner))
			*beg++ = *runner++;
		}
		if(end == temp)
		break;
		while((end!=temp) && isspace(*end))
		{
			*beg++ = *end;
			end--;
		}
	}
	*beg = '\0';
	printf("\n StrRevWordPlace: %s, length=%zd", temp1, strlen(temp1));
	return;
}

int main()
{
	char str1[]="there is nothing in this string";
	char str2[]="Charu             ";
	char str3[]="            charu";
//	StrRevWord(str1);
	StrRevWordPlace(str3);
        printf("\n Original String %s, length=%zd\n", str3, strlen(str3));	
	return ;

}

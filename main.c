/*
 * main.c
 *
 *  Created on: May 8, 2013
 *      Author: emanuel
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "runlength_compress.h"
#include "runlength_decompress.h"



char* readLine(FILE*);

int main(int argc, char * argv[])
{
	char *option, *token;

	option = readLine(stdin);

	while(strcmp(option, "sair") != 0)
	{
		if(strncmp(option, "compactar run-length", 20) == 0)
		{
			token = strtok(option, " ");
			token = strtok(NULL, " ");
			token = strtok(NULL, " ");
			//token = file.pbm

			runlength_compress(token);

		}

		if(strncmp(option, "descompactar run-length", 23) == 0)
		{
			token = strtok(option, " ");
			token = strtok(NULL, " ");
			token = strtok(NULL, " ");
			//token = file.rl

			runlength_decompress(token);

		}

		if(option != NULL) free(option);

		option = readLine(stdin);
	}

	free(option);

	return 0;
}


/*
 * retorna um ponteiro (já alocado) de uma string
 * lida através de um ponteiro FILE* (ex: stdin)
 */
char* readLine(FILE* fd)
{
	char *str = NULL;
	int count = 0;
	char c;

	do{
		c = getc(fd);
		str = (char*)realloc(str, sizeof(char) * (count +1));
		if(c != '\n')str[count++] = c;
		//evita guardar enter
		//(como primeiro caracter) do buffer
		if(c == '\n' && count == 0)c = 'a';

	}while(c != '\n');

	//str[count-1] = '\n'
	str[count ] = '\0';

	return str;


}

/*
 * my_ctype.c
 *
 *  Created on: Jun 8, 2022
 *      Author: GM
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "my_ctype.h"

int totitle(char *str){
	int outcome = 0;
	int len = strlen(str);
	int i = 1;

	if(str != NULL && len>0){
		outcome = 1;
		str[0] = toupper(str[0]);
		str[1] = tolower(str[1]);
		while(str[i+1] != '\0'){
			if(str[i] == ' '){
				str[i+1] = toupper(str[i+1]);
			}else{
				str[i+1] = tolower(str[i+1]);
			}
			i++;
		}
	}
	return outcome;
}


int shortenstr(char* shorted, int size, const char* string, int max){
  int outcome = 0;
  int len = strlen(string);
  if(shorted != NULL && string != NULL && size < len && len > max && size > max){
	  outcome = 1;
	  for(int i=0; i<max; i++){
		  if(i<max-3){
			  shorted[i] = string[i];
		  }else if(i>=max-3){
			  shorted[i] = '.';
		  }
	  }
	  shorted[max] = '\0';
  }
  return outcome;
}

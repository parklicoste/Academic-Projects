#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <unistd.h>

int morph(char* number);

int main(int argc, char *argv[]){
  int number, status = 0;

  if (argc == 1){
    printf("Usage: singlePrime filename\n" );
    return(2);
  }

  FILE *fid = fopen(argv[1],"r");

  if(fid == NULL ){
    printf("file file.bin does not exist\n" );
    return(3);
  }

  else{
    fread(&number,sizeof(unsigned int),1,fid);
    printf("%d\n", number);
    fclose(fid);
    char str[10];
    //str[0] = "./isPrime";
    sprintf(str,"%d ",number);
    morph(str);
  }
}


int morph(char* number){
  char *s[3];
  char p[10] = "./isPrime";
  s[0] = p;
  s[1] = number;
  s[2] = NULL;
  execv("./isPrime",s);
  printf("tell me what it is error occured in morph\n");
  return(-1);

}

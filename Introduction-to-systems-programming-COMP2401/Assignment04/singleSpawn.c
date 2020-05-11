#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <unistd.h>
#include<sys/wait.h>

int morph(char* number);

int main(int argc, char *argv[]){

  int number,status;
  pid_t cpid;

  if (argc == 1){
    printf("Usage: singlePrime filename\n" );
    return(2);
  }

  FILE *fid = fopen(argv[1],"r");

  if(fid == NULL ){
    printf("file file.bin does not exist\n" );
    return(3);
    exit(3);
  }

  else{
    fread(&number,sizeof(unsigned int),1,fid);
    fclose(fid);
  }

  char str[12];
  sprintf(str,"%d ",number);
  cpid = fork();

  if(cpid == 0){// child process
    int x = morph(str);
    return(x);
    exit(x);

  }

  else//parent process
    wait(&status);

  status = WEXITSTATUS(status);

  if(status == 1)
    printf("The input number is a prime Number\n");
  else
    printf("The input number is not a prime Number\n");
}




int morph(char* number){
  char *s[3] = { };
  char p[10] = "./isPrime";
  s[0] = p;
  s[1] = number;
  s[2] = NULL;
  execv(s[0],s);
  return(-1);
  exit(-1);

}

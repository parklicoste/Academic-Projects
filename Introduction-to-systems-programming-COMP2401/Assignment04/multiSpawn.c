#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <unistd.h>
#include<sys/wait.h>

int morph(char* number);

int main(int argc, char *argv[]){

  int number[10], i=0, status;
  pid_t childProcessIds[10];
  pid_t cpid;
  char str[12];

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
      fread(&number,sizeof(number),1,fid);
      fclose(fid);

      while(i<10){
        sprintf(str,"%d",number[i]);
        cpid = fork();
        if(cpid == 0){// child process
          morph(str);
        }
        else{//parent one
            childProcessIds[i] = cpid;
        }
        i++;
      }
  }

  for(int j=0;j<10;j++){
    cpid = waitpid(-1,&status,0);
    status = WEXITSTATUS(status);
    if(cpid == -1){
      return 0;// no childpid left
    }
    //
    if(status == 1){
       for(int i=0; i<10;i++){
         if(cpid == childProcessIds[i]){
           printf("Number is %d\n",number[i]);
           break;
         }
       }
    }
  }


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

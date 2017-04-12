//---------------------------------------------------------------------
// mycat.c for CMPS111 : Asgn0
// Author : David J Esperanza
// CruzID : djespera
// Description :
//       cat()
// April 11th, 2017
//---------------------------------------------------------------------

#include "mycat.h"

int main(int argc, char * argv[]){
  int open_d; //Open File Descriptor
  int read_d; //Read File Descriptor
  int files;  //# of files

  //if Thre are no arguments
  if(argc == 1){
   // files = argc -1;//Should be 0 since no files were specified
    //Go into a infinite loop.
    while(1){
      char buffer2[MAX_BUF];//Create a I/O Buffer
      memset(buffer2,0,MAX_BUF);//Initalize to 0's
      read_d = read(STDIN_FILENO,buffer2,MAX_BUF);//Read from STDIN
      if(read_d < 0){//Number of Bytes is <0, then an error occured
        perror("./mycat");
        close(read_d);
        return 1;
      }
      else if(read_d == 0){//Reached EOF or Control D was struck
        close(read_d);
        return 0;
      }//Control D Key Swipe//quit
      else{//Number of Bytes > 0, Write Buffer to STDOUT
        if((write(STDOUT_FILENO,buffer2,read_d)) != read_d){
          perror(".mycat");//If read_d is not the same size as write
          close(read_d);
          return 1;
        }
      }
    }
    return 0;
  }

  //Set the Number of Files on the Command Line
  files = argc -1;//N amount of files specified on command line
  //For the Number of Files on the Command Line :
  //Open The File
  //If Cannot Open FIle
  //Then Kill Program
  //Else File can be open and read into a buffer
  //write to stdout from buffer
  for(int n = 1; n <= files; n++){
     open_d = open(argv[n],O_RDONLY);
     //Unable to Open File
     //Print Error and Exit Program
     if(open_d == -1){
       perror("./mycat: ");
       //printf(" :%s\n",argv[n]);
       close(open_d);
       return 1;
     }
     else{
       //printf("Open Sucess : %s\n",argv[n]);
       char buffer[MAX_BUF];
       memset(buffer,0,MAX_BUF);
       read_d = read(open_d,buffer,MAX_BUF);
       if( read_d < 0){//Number of Bytes is < 0, then an error occured
         perror("./mycat");
         close(read_d);
         close(open_d);
         return 1;
       }
       else{//Number of Bytes is > 0 , Write Buffer to STDOUT
         if((write(STDOUT_FILENO,buffer,read_d)) != read_d){
           perror(".mycat");
           close(open_d);
           close(read_d);
           return 1;
         }
         close(open_d);
         close(read_d);
       }

     }
  }
  return 0;
}

//UNIX Command to Count lines characters and words
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define gc getc
/*---------------------------------------------------------
-----------MAIN ROUTINE-----------------------------------
----------------------------------------------------------*/
int count[] = {0,0,0,0};
int main(int argc,char* argv[])
{
    FILE* in;
    int i;
    void countcwl(FILE*);
    if(argc==1){
       printf("Enter The Text:(To terminate press ^D)\n");
       countcwl(stdin);
       printf("\nThe number of characters: %d\n",count[0]);
       printf("The number of words:      %d\n",count[1]);
       printf("The number of lines:      %d\n",count[2]);
    }
    else if(strcmp(argv[1],"-c")==0){
       for(i=2;i<argc;i++){
           in = fopen(argv[i],"r");
           if(in==NULL){
             printf("RAGHU SAID:'%s' FILE NOT FOUND\n",argv[i]);
             exit(1);
           }
           countcwl(in);
           printf("In File: %s\n",argv[i]);
           printf("The number of characters: %d\n",count[0]);
           fclose(in);
         }
    }
    else if(strcmp(argv[1],"-w")==0){
       for(i=2;i<argc;i++){
           in = fopen(argv[i],"r");
           if(in==NULL){
             printf("RAGHU SAID:'%s' FILE NOT FOUND\n",argv[i]);
             exit(1);
           }
           countcwl(in);
           printf("In File: %s\n",argv[i]);
           printf("The number of words:      %d\n",count[1]);
           fclose(in);
         }
    }
    else if(strcmp(argv[1],"-l")==0){
       for(i=2;i<argc;i++){
           in = fopen(argv[i],"r");
           if(in==NULL){
             printf("RAGHU SAID:'%s' FILE NOT FOUND\n",argv[i]);
             exit(1);
           }
           countcwl(in);
           printf("In File: %s\n",argv[i]);
           printf("The number of lines:      %d\n",count[2]);
           fclose(in);
         }
    }
    else if(strcmp(argv[1],"--helpme")==0){
          printf("The basic syntax is\n\twcraghu [OPTIONS] <filenames>\n");
          printf("OPTIONS:\n\t-c show only number of characters\n\t");
          printf("-w show only number of words\n\t");
          printf("-l show only number of lines\n");
    }
    else{
         for(i=1;i<argc;i++){
           in = fopen(argv[i],"r");
           if(in==NULL){
             printf("RAGHU SAID:'%s' FILE NOT FOUND\n",argv[i]);
             exit(1);
           }
           countcwl(in);
           printf("In File: %s\n",argv[i]);
           printf("The number of characters: %d\n",count[0]);
           printf("The number of words:      %d\n",count[1]);
           printf("The number of lines:      %d\n",count[2]);
           fclose(in);
         }
    }
    return 0;
}
/*------------------------------------------------------------
---------THIS FUNCTION CALCULATES LINES, WORDS, LINES---------
------------------------------------------------------------*/
void countcwl(FILE* in){
    count[0] = count[1] = count[2] = count[3] =0;
    int c,temp=0;
    while((c=gc(in))!=EOF){
       count[0]++;
       if(c=='\n') count[2]++;
       if(c!='\n' && c!=' ' && c!='\t') temp = 1;
       if(temp!=0 && (c=='\n'||c==' '||c=='\t')){
          count[1]++;
          temp = 0;
       }
    }
}    

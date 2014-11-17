#include<stdio.h>

main()
{
   static int number,arr1[20],i= 19,arr2[20],n1,n2,sum[40];
   static int point1,point2,j,k;

   printf("##THIS PROGRAM ADDS BINARY NUMBERS##\n\n");
   printf("Enter The Number1:\n");
   
   //scanning two binary numbers
   while( (number = getchar())!= '\n'){
       if(number == '0'||number == '1'||number == '.'){
            arr1[i] = number-48;
            if(number == '.')
                point1= i;
            i--; 
            }
       else{ printf("Invalid Operation! not a Binary number..");
             goto amanda;
             }
       }
   n1 = i ;
   i = 19;
   printf("Enter The Number2:\n");
   while( (number = getchar())!= '\n'){
       if(number == '0' || number == '1' ||number =='.'){ 
            arr2[i] = number-48;
            if(number == '.')
                point2 = i;
            i--;
            }
       else{ printf("Invalid Operation! not a Binary number..");
             goto amanda;
             }
      }
   n2 = i;
 
   //addition starts here
   if(point1==0 && point2==0){
        if(n1<n2){
           for(i=19,j=19,k=0;i>=n1;i--,j--,k++)
              if(arr1[i] + arr2[j] ==0)
                   sum[k] = 0;
              else if(arr1[i] + arr2[j] ==1)
                   sum[k] =1;
              else if(arr1[i] + arr2[j] ==2){
                   sum[k] = 0;
                   arr1[i-1]+=1;
                   }
              else if(arr1[i] + arr2[j] ==3){
                   sum[k] =1;
                   arr1[i-1]+=1;
                   }

           printf("The Sum of the Two numbers is : ");
           for(i=k;i>=0;i--)
               printf("%d",sum[i]);
             }

         else if(n2<=n1){
                for(i=19,j=19,k=0;j>=n2;i--,j--,k++)
                    if(arr1[i] + arr2[j] ==0)
                        sum[k] =0;
                    else if(arr1[i] +arr2[j] ==1)
                        sum[k] =1;
                    else if(arr1[i] +arr2[j] ==2){
                        sum[k] = 0;
                        arr2[j-1]++;
                        }
                    else if(arr1[i] + arr2[j] ==3){
                        sum[k] = 1;
                        arr2[j-1]++;
                        }
                printf("The Sum of the Two numbers is : ");
                for(i=k;i>=0;i--)
                printf("%d",sum[i]);
          
              }
        }
     else printf("This facility will be made available in next version.");
  amanda: printf("\nThank you\n");
          
}

     
                              
   

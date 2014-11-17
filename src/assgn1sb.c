#include<stdio.h>
#include<math.h>

main()
{  
  static int a, b,c,d,e,f, arr[25], i=0,ch, base, cur_base;
  static int decimal=0, j,decimal_temp,arr_base[25],check=1,possible=0;
    
   printf("##THIS PROGRAM WORKS FINE FOR \nPOSITIVE INTEGERS ONLY##\n\n");  
   printf("Enter The No.:\n");
   while((ch=getchar())!='\n'){
       arr[i] = ch;
       if(arr[i]>='a' && arr[i]<='f' && possible<arr[i])
          possible = arr[i];
       i++;
       }
   if(possible >='a' && possible<='f'){
      printf("Enter The current base:(> %d) \n",(possible-87));
      }
   else{
      printf("Enter The current base:(eg. 10 )\n");
    }

   scanf("%d",&cur_base);
   printf("Convert to Base?\n");
   scanf("%d",&base);
   //Algorithm starts here
   for(j= 0; j<i ;j++){
       if(arr[j]>='0'&& arr[j]<='9'&& (arr[j]-48) < cur_base)
          decimal += (arr[j]-48) * pow(cur_base,i-j-1);
       else if(arr[j]>='a' && arr[j] <= (86+cur_base))
          decimal += (arr[j]-87) * pow(cur_base,i-j-1);
       else{
             printf("Invalid Operation! program exiting..");
          check = 0;
          }
       } 
 
   decimal_temp = (int)decimal;
   
   if(check==0)
      check=1;
   else if(base==10)
       printf("The No in base %d is : %d",base,decimal);
/*   else{
   //conversion from decimal
   printf("The No in base %d is : ",base);
   for(i=0;(decimal_temp % (int)pow(base,i) ) != 0 ;i++){
       arr_base[i] = (decimal_temp % (int)pow(base, i) );
       if(arr_base[i]>9){
           switch(arr_base[i]){
               case 10: arr_base[i] = 97; break;
               case 11: arr_base[i] = 98; break;
               case 12: arr_base[i] = 99; break;
               case 13: arr_base[i] = 100;break;
               case 14: arr_base[i] = 101;break;
               case 15: arr_base[i] = 102;break;
               }
            }
       }
    for(j= i-1 ; j>=0 ; j--)
       if(arr_base[j] < 'a')
          printf("%d",arr_base[j]);
       else if(arr_base[j] >= 97)
          printf("%c",arr_base[j]);
    } */
      else{
    //2nd conversion algorith
    printf("The No in the base %d is : ",base);
    for(i=0;decimal_temp!=0;i++){
        arr_base[i] = decimal_temp % base ;
        decimal_temp /= base ;
        if(arr_base[i] >=10 && arr_base[i] <=15){
            switch(arr_base[i]){
               case 10: arr_base[i] = 97; break;
               case 11: arr_base[i] = 98; break;
               case 12: arr_base[i] = 99; break;
               case 13: arr_base[i] = 100;break;
               case 14: arr_base[i] = 101;break;
               case 15: arr_base[i] = 102;break;
               }
            }
        }
    for(j= i ;j >=0 ; j--){
        if(arr_base[j] < 'a')
           printf("%d",arr_base[j]);
        else 
           printf("%c",arr_base[j]);
        }
    }
    
    printf("\n");
}
        
       

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void){
    char c, eN, eNFinal; //c is character from message & eN is is the encrypted character
    int eLibU[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90}; //library of encryption values from A to Z
    int asc[1024] = {0}; //ascii array
    int i = 0, e = 0, count = 0, j = 0;
    char array[1024] = {0};
    int encrypted[1024] = {0}; // array used to store encrypted message
    int k = 0, location = 0;
    char original[1024] = {0}; // array used to store original input characters after ithey have been read by while loop below
    int userKey[26]; //user key for encryption 
    
      
    /*Open message file and output file*/
    FILE *input, *output;        //File points to input and output
    input = fopen("input.txt", "r");   //open file name and read format
    output = fopen("output.txt", "w");
    
    if(input == NULL) {         //Error message incase input file directory not found
        perror("fopen()");
    return 0;
    }
    if(output == NULL) {         //Error message incase output file directory not found
        perror("fopen()");
    return 0;
    }
    
   
        
     /*----while loop scans input file for characters, prints them to terminal, 
     encrypts them with key value, writes this to an output, and loops until no characters are left in the input file*/   
     while(!feof(input)){ //loops until no characters are left in the input file
        fscanf(input,"%c", &c); //Scans file for characters and stores them as a variable c
         i++; //increments array pointer with every loop and assigns the input read ascii value to it, i.e. asc[0] = "first input character read from file"
       
       if(c >= 65 && c <= 90){  //if upper case
            
            asc[i] = c;     //assigns array at array point i with value c
            c = c - 65;     //A = 0
            e = c; //encryption algorithm 
            if(e >= 26){     //if array pointer value is exceeded
                e = e - 26;    //starts array pointers over again plus difference between total value (>26) and max pointer value (26)    
              }
             eN = eLibU[e]; //selects encrypted value from upper case array
             array[i] = eN;
        }  
        
        else if(c >= 97 && c <= 122){  //if lower case 
            
            asc[i] = c;     //assigns array at array point i with value c
            c = c - 32;     //a = 0
            e = c - 65; //encryption algorithm 
            if(e >= 26){     //if array pointer value is exceeded
                e = e - 26;    //starts array pointers over again plus difference between total value (>26) and max pointer value (26)    
              }
             eN = eLibU[e]; //selects ascii value from upper case array
             array[i] = eN; //stores selected ascii value in an array
        }   

        /*The following 3 'else if' statements leave common punctuation unmodified*/
        else if(c == 46){ //if full stop
            asc[i] = 46;  //sets ASCII value full stop
            eN = 46;  //sets ASCII value to full stop
        }
        else if(c == 63){ //if question mark
            asc[i] = 63;  //sets ASCII value full stop
            eN = 63;  //sets ASCII value to full stop
   }

        
         else if(c == 44){ //if comma
            asc[i] = 44;  //sets ASCII value to comma
            eN = 44;  //sets ASCII value to comma
        }
        
        else if(c == 39){ //if apostrophe 
            asc[i] = 39;  //sets ASCII value to apostrophe
            eN = 39;  //sets ASCII value to apostrophe
        }  
          else if(c == 58){ //if colon
            asc[i] = 58;  //sets ASCII value to colon
            eN = 58;  //sets ASCII value to colon
        }  
                       
        else if(c < 65 || (c >= 91 && c <= 96) || c > 122 ){ //excludes any ASCII value that isn't a letter
           
            asc[i] = 32;  //sets ASCII value to space
            eN = 32;  //sets ASCII value to space
            
        }   
        original[i-1] = eN;
    
    }
/*----------------------------END of input reading While loop----------------------*/
      
   /*------Determines frequency of character occurrence from input text for statistical analysis------*/   


    /*------------------------------------------------------------------------*/
   
    /*------------------Orders characters in an array (array[i]) in descending frequency of occurence----------------------------*/

   
 /*------------------------------------------------------------------------*/

 /*-----Creation of key for each alphabet by comparing frequency of input text character occurrence with frequency of character occurrence in the english language------------------*/
    srand(time(0)); 
    fprintf(output, "%s %s", "Key", "is:");
    for(i=0; i<= 25; i++){ 
        userKey[i] = rand() % 27;
        k = userKey[i];
        encrypted[i] = eLibU[i] + k;
        e = encrypted[i];
        if(e > 90){     //if ascii value Z is exceeded...
            e = e - 25;    //starts array value from A     
        }
        fprintf(output, " %c", e); //prints key value to output
    }
    fprintf(output, "\n"); // creates space between key value and encrypted message text in output file
 /*------------------------------------------------------------------------*/
  
/*--------------Encryption of input based on randomly generated key (i.e. userKey)------------------*/

    for(i=0; i<strlen(original); i++){
            
            location = original[i] - 65;
            k = userKey[location];
            encrypted[i] = original[i] + k;
            e = encrypted[i]; 
            if(e > 90){     //if ascii value Z is exceeded...
                e = e - 25;    //starts array value from A     
              }
             if(original[i] == 44){
                  e = 44;
              }
              
              if(original[i] == 32){
                  e = 32;
              }
              if(original[i] == 39){
                  e = 39;
              }
               if(original[i] == 46){
                  e = 46;
              }
                if(original[i] == 63){
                  e = 63;
              }
             
            eNFinal = e;
            
       
            printf("\n%c (%d) is %c (%d)", original[i], original[i], eNFinal, eNFinal);
            fputc(eNFinal, output); //prints encrypted message to output file
   
    }   
 /*------------------------------------------------------------------------*/
        
    fclose(input); //closes input file
    fclose(output); //closes output file
    
    return 0;     
}
   

    


    



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char S[2] = {'A','\0'};
char A[3] = {'a','B','\0'};
char B[3] = {'b','C','\0'};
char C[2] = {'c','\0'};

int MAXSIZE_main = 100;       
char stack_main[100];     
int top_main = -1;     

int MAXSIZE_T = 100;       
char stack_T[100];     
int top_T = -1;  

//main stack

int isempty_main() {

   if(top_main == -1)
      return 1;
   else
      return 0;
}
   
int isfull_main() {

   if(top_main == MAXSIZE_main)
      return 1;
   else
      return 0;
}

int peek_main() {
   return stack_main[top_main];
}

int pop_main() {
   int data;
	
   if(!isempty_main()) {
      data = stack_main[top_main];
      top_main = top_main - 1;   
      return data;
   } 
   else 
   {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push_main(int data) {

   if(!isfull_main())
    {
      top_main = top_main + 1;   
      stack_main[top_main] = data;
   }
    else 
   {
      printf("Could not insert data, Stack is full.\n");
   }
}

// stack alt

int isempty_T() {

   if(top_T == -1)
      return 1;
   else
      return 0;
}
   
int isfull_T() {

   if(top_T == MAXSIZE_T)
      return 1;
   else
      return 0;
}

int peek_T() {
   return stack_T[top_T];
}

int pop_T() {
   int data;
	
   if(!isempty_T()) {
      data = stack_T[top_T];
      top_T = top_T - 1;   
      return data;
   } 
   else 
   {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push_T(int data) {

   if(!isfull_T())
    {
      top_T = top_T + 1;   
      stack_T[top_T] = data;
   }
    else 
   {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main()
{
    push_main('S');
    while(!isempty_main())
    {
        if (peek_main() == 'a' || peek_main() == 'b' || peek_main() == 'c')
        {
            push_T(pop_main());
        }
        if (peek_main() == 'S')
        {
            pop_main();
            int index = strlen(S);
            printf("%d",index);
            while (index != 0)
            {
                --index;
                push_main(S[index]);
            }
        }
        if (peek_main() == 'A')
        {
            pop_main();
            int index = strlen(A);
            while (index != 0)
            {
                index--;
                push_main(A[index]);
            }

        }
        if (peek_main() == 'B')
        {
            pop_main();
            int index = strlen(B);
            while (index != 0)
            {
                index--;
                push_main(B[index]);
            }
        }
        if (peek_main() == 'C')
        {
            pop_main();
            int index = strlen(C);
            while (index != 0)
            {
                index--;
                push_main(C[index]);
            }
        }
    }
    //printf("we got here");
    while(!isempty_T())
    {
        printf("value T stack %c \n",pop_T());
    }
}
/* Write a program in C to print all the alphabets using a pointer. Go
        to the editor */
#include <stdio.h>

int main()
{
  char alpha[] = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
  char *ptr = alpha;

    printf("The Alphabets are :\n");
  for (int i = 0; i <(sizeof(alpha)/ sizeof(alpha[0])) ; ++i) {
      printf("%c",*ptr);
      ptr++;
    }

    return 0;
}

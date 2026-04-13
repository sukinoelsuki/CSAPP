#include "lab1_stu.h"
#include "lab1_ops.h"
#include "lab1_BitOps.h"

#define CHECK_STUDENT_STORAGE 1
#define CHECK_BIT_OPERATION 2
#define QUIT_THE_SYSTEM 0

student_t* beforecompress;
student_t* decompress;
char *message;        // buf

int main() {

    int SWITCHER;
    beforecompress = malloc(MAX_BYTE);
    decompress = malloc(MAX_BYTE);
    message = malloc(MAX_BYTE + 5);

    if (beforecompress == NULL || decompress == NULL || message == NULL) {
      printf("Out of memory!\n");
      free(beforecompress);
      free(decompress);
      free(message);
      return 0;
    }

    while (1) {
      if(~scanf("%d", &SWITCHER)) break;
      printf("Please input a number between 0 ~ 2. 1 for Storage_Check, 2 for BitOps_Check, and 0 to close the procedure. Any other number is invalid.\n");
        switch (SWITCHER) {

          case QUIT_THE_SYSTEM:
            printf("The system is closing...\n");
            return 0;

          case CHECK_STUDENT_STORAGE:
            do_check_compress(beforecompress, message, decompress);
            break;
        
          case CHECK_BIT_OPERATION:
            do_check_BitOps();
            break;
          
          
          default:
            printf("Invalid number!\nPlease input a valid number.\n");
            break;
      }
    }

    return 0;
}
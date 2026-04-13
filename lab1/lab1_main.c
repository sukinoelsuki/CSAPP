#include "lab1_stu.h"
#include "lab1_ops.h"
#include "lab1_BitOps.h"

#define CHECK_STUDENT_STORAGE 0
#define CHECK_BIT_OPERATION 1


student_t* s_pre;
student_t* s_after;
char *message;        // buf

int main() {

    int SWITCHER;
    s_pre = malloc(MAX_BYTE);
    s_after = malloc(MAX_BYTE);
    message = malloc(MAX_BYTE + 5);

    if (s_pre == NULL || s_after == NULL || message == NULL) {
      printf("Out of memory!\n");
      free(s_pre);
      free(s_after);
      free(message);
      return 0;
    }

    while (1) {
      if(~scanf("%d", &SWITCHER)) break;
      printf("Please input a number between 0 and 1. 0 for Storage_Check, 1 for BitOps_Check. Any other number is invalid.\n");
        switch (SWITCHER) {
          case CHECK_STUDENT_STORAGE:
            do_check_storage(&s_pre, &message, &s_after);
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
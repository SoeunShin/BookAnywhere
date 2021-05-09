#include <stdio.h>
#include "reservation.h"

int main(void){
    User ulist[30];
    int index = 0, count = 0, menu;

    while(1){
        menu = selectMenu();
        if (menu == 0) break; // 0: 종료
        if (menu == 1){ // 1: 사용자 계정 생성
            count += addUser(&ulist[index]);
            index++;
        }
        else if (menu == 2){ // 2: 입퇴실 신청 
            int no = selectNo(ulist, index);
            if (no == 0){
                printf("Cancelled!\n");
                continue;
            }
            checkinout(&ulist[no-1]);
        }
    }
}

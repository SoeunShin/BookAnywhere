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
        else if (menu == 3){ // 3: 현재 사용자 전체 목록 조회
            for (int i=0; i<30; i++){
                printf("%d's user: ",i+1);
                readUser(ulist[i]);
            }
        }
        else if (menu == 4){  // 4: 사용자 목록 삭제
            int userIndex;
            printf("which user do you want to delete?(input a user index number) ");
            scanf("%d", &userIndex);
            deleteUser(&ulist[userIndex]);
        }
    }
}

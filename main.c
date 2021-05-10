#include <stdio.h>
#include "reservation.h"

int main(void){
    User ulist[30];
    int index = 0, cnt = 0, menu;

    for (int i=0; i<30; i++){
        ulist[i].in = 0;
        ulist[i].out = 0;
        ulist[i].seat = 0;
    }

    while(1){
        menu = selectMenu();
        if (menu == 0) break; // 0: 종료
        if (menu == 1){ // 1: 사용자 계정 생성
            cnt += addUser(&ulist[index]);
            index++;
        }
        else if (menu == 2){ // 2: 입퇴실 신청 
            int no = selectNo(ulist);
            if (no == 0){
                printf("Cancelled!\n");
                continue;
            }
            checkinout(&ulist[no-1]);
        }
        else if (menu == 3){ // 3: 현재 사용자 전체 목록 조회
            listUser(ulist);
        }
        else if (menu == 4){  // 4: 사용자 목록 삭제
            int no = selectNo(ulist);
            if (no == 0){
                printf("Cancelled!\n");
                continue;
            }
            int delok;
            printf("Do you want to delete it?(Y: Yes) ");
            scanf("%c", delok);
            if (delok == 'Y'){
                deleteUser(&ulist[no-1]);
            }
            else{
                pirntf("Cancelled!\n");
                continue;
            }
        }
        else if (menu == 5){ // 5: 사용시간 조회

        }
        else if (menu == 6){ // 6: 예약 수정

        }
    }
    printf("EXIT\n");
    return 0;
}

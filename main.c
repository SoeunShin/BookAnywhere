#include <stdio.h>
#include <string.h>
#include "reservation.c"

int main(void){
    User ulist[30];
    int index = 0, cnt = 0, menu;

    for (int i=0; i<30; i++){
        strcpy(ulist[i].id, "");
        ulist[i].in = 0;
        ulist[i].out = 0;
        ulist[i].seat = 0;
    }

    while(1){
        menu = selectMenu();
        if (menu == 0) break; // 0: 종료
        if (menu == 1){ // 1: 사용자 계정 생성
            cnt += addUser(&ulist[index],ulist);
            index++;
        }
        else if (menu == 2){ // 2: 입퇴실 신청 
            int no = selectNo(ulist);
            if (no == 0){
                printf("=> Cancelled!\n");
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
                printf("=> Cancelled!\n");
                continue;
            }
            int delok;
            printf("Do you want to delete it?(Yes: 1) ");
            scanf("%d", &delok);
            if (delok == 1){
                deleteUser(&ulist[no-1]);
                printf("=> Deleted!\n");
            }
            else{
                printf("=> Cancelled!\n");
                continue;
            }
        }
        else if (menu == 5){ // 5: 사용시간 조회
            int i;
            char getname[20];
            printf("Input a user ID: ");
            scanf("%s", getname);
            for (i=0; i<30; i++){
                if(strcmp(getname, ulist[i].id)==0){
                    usingTime(ulist[i]);
                    break;
                }
            }
            if(i==30) printf("There is no matched user ID\n");
        }
        else if (menu == 6){ // 6: 예약 수정
            int i;
            char getname[20];
            printf("Input a user ID: ");
            scanf("%s", getname);
            for (int i=0; i<30; i++){
                if(strcmp(getname, ulist[i].id)==0){
                    updateSeat(&ulist[i],ulist);
                    break;
                }
            }
            if(i==30) printf("There is no matched user ID\n");
        }
        else if (menu == 7){  // 7. 이름으로 검색
            searchUser(ulist, count);
        }
        else if (menu == 8){ // 8. 사용중인 자리 조회
            searchUsing(ulist, index);
        }
        else if (menu == 9){ // 9. 빈 자리 조회
            searchEmpty(ulist, index);
        }
        else if (menu == 10){ // 10. 파일 저장 
            saveFile(ulist);
        }
    }
    printf("=> EXIT\n");
    return 0;
}

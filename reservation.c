#include <stdio.h>
#include <time.h>
#include "oss_team.h"

void readUser(User u){  // 사용자 목록 조회
        printf("%30s%20s%20s%10d\n", u.id, u.in, u.out, u.seat);
}
int deleteUser(User *u){ // 사용자 목록 삭제
        u->in = "";
        u->out = "";
        u->seat = -1;
}
void checkinout(User *u){ // 입퇴실 처리
        char answer;
        time_t checkin;
        time_t checkout;
        printf("Please enter I(In) or O(Out): ");
        scanf("%c", answer);
        
        if (answer == 'I'){
                time(&checkin);
        }
        if (answer == 'O'){
                time(&checkout);
        }
        else{
                printf("Cancelled!\n");
        }
}
/*
void searchUsing(User *u, int cnt){ // 사용중인 자리 검색

}
void searchEmpty(User *u, int cnt){ // 비어있는 자리 검색

}  
void saveFile(User *u, int cnt){ // 파일 저장

}
*/

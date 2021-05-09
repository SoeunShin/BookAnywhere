#include <stdio.h>
#include <time.h>
#include "reservation.h"

void readUser(User u){  // 사용자 목록 조회
    printf("%30s%20d%20d%10d\n", u.id, u.in, u.out, u.seat);
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

int addUser(User *u){
    printf("Input a user ID: ");
    scanf("%s", u->id);
    //searchEmpty함수 호출하여 빈자리 목록
    printf("Choose your seat(1-20): " );
    scanf("%d", &u->seat);

    printf("-------------------------");
    printf("Created!\nYour ID is %d and seat is number %d.", u->id, u->seat);
    return 1;
}

int updateSeat(User *u){
    printf("Input a user ID: ");
    //ID 있는지 확인 read
    scanf("%s", u->id);
    printf("Choose your seat(1-20): " );
    scanf("%d", &u->seat);
    printf("=> 수정성공!\n");
    return 1;
}

void usingtime(User u){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Input a user ID: ");
    //ID 있는지 확인 read
    scanf("%s", u.id);
    int usingTime;
    int presentSec=(tm.tm_hour)*3600 + (tm.tm_min)*60 + tm.tm_sec;

    if(u.in!=0 && u.out==0){ //입실처리만 ,사용중
        usingTime = presentSec - u.in;
    }
    else if(u.in==0 u.out==0){  //입퇴실 둘다 안했을때, 사용중이 아닐때(계정만 존재)
        printf("You're not using any seats now.");
    }
    else {  //입퇴실처리 모두 다 됐을때, 사용중이 아닐때 (입실안했는데 퇴실처리할 수 없도록 ckeckinout함수에서 제어)
        usingTime = u.out - u.in;
    }
    int usingHour= usingTime/3600;
    int usingMin= (usingTime-3600*usingHour)/60;
    int usingSec= usingTime-3600*usingHour-60*usingMin;
    printf("using time: %dh %dm %ds", usingHour, usingMin, usingSec);
}

/*
void readHistory(User u); // file에 저장된 히스토리 읽기
void searchUser(User *u); // 사용자 검색
*/

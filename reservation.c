#include <stdio.h>
#include <time.h>
#include <string.h>
#include "reservation.h"

void readUser(User u){  // 사용자 조회
    int InHour= u.in/3600;
    int InMin= (u.in-3600*InHour)/60;
    int InSec= u.in-3600*InHour-60*InMin;

    int outHour= u.out/3600;
    int outMin= (u.out-3600*outHour)/60;
    int outSec= u.out-3600*outHour-60*outMin;

    if(strcmp(u.id, "")!=0){
        printf("\t%s\t\t%d:%d:%d\t\t%d:%d:%d\t\t%d\n", u.id, InHour,InMin,InSec,outHour,outMin, outSec,u.seat);
    }
    else printf("\t%s\t\t%d\t\t%d\t\t%d\n", u.id, u.in, u.out, u.seat);
}

int deleteUser(User *u){ // 사용자 목록 삭제
    strcpy(u->id, "");
    u->in = 0;
    u->out = 0;
    u->seat = 0;
    return 1;
}

void checkinout(User *u){  //입퇴실 처리
    int answer, checkin, checkout;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Please enter 1(In) or 2(Out): ");
    scanf("%d", &answer);
    
    if (answer == 1){
        checkin=(tm.tm_hour)*3600 + (tm.tm_min)*60 + tm.tm_sec;
        u->in = checkin;
    }
    else if (answer == 2){
        checkout=(tm.tm_hour)*3600 + (tm.tm_min)*60 + tm.tm_sec;
        u->out = checkout;
    }
    else{
        printf("=> Cancelled!\n");
    }
}
void listUser(User *u){ // 전체 목록 출력
    printf("\nNo\tID\t\tCheck in\tCheck out\tSeat No\n");
    printf("****************************************************************\n");
    for (int i=0; i<30; i++){
        printf("%d  ", i+1);
        readUser(u[i]);
    }
}
int selectNo(User u[]){
    int no;
    listUser(u);
    printf("Select a number(Cancel:0): ");
    scanf("%d", &no);
    return no;
}

int selectMenu(){
    int menu;
    printf("\n*** Select a menu ***\n");
    printf("1. 사용자 계정 생성\n");
    printf("2. 입퇴실 신청\n");
    printf("3. 사용자 목록 조회\n");
    printf("4. 사용자 목록 삭제\n");
    printf("5. 사용시간 조회\n");
    printf("6. 예약 수정\n");
    printf("7. 사용자 검색\n");
    printf("8. 사용중인 자리 검색\n");
    printf("9. 비어있는 자리 검색\n");
    printf("10. 파일 저장\n");
    printf("0. 종료\n\n");
    printf("=> Select a menu: ");
    scanf("%d", &menu);
    return menu;
}

int addUser(User *u){
    int ck=0, i;
    printf("Input a user ID: ");
    scanf("%s", u->id);
    printf("Choose your seat(1-20): " );
    scanf("%d", &u->seat);

    while(!(0< u->seat && u->seat <=20)){ //확인 함수 짬뽕
        if(!(0< u->seat && u->seat <=20)){
            printf("Invalid seat. Try again\n");
            printf("Choose your seat(1-20): " );
            scanf("%d", &u->seat);
        }
    }
    while(checkSeat(U, u->seat)==0){  //여기서도 입력 범위 확인후 
        if(checkSeat(U, u->seat)==0){
            printf("Someone is using the seat number %d.\nChoose again\n\n", u->seat);
            printf("Choose your seat(1-20): " );
            scanf("%d", &u->seat);
        }
        else{
            printf("------------------Created!-----------------\n");
            printf("Your ID is \"%s\" and seat is number \"%d\"\n", u->id, u->seat);
        }

    }
    return 1;
}

void updateSeat(User *u){
    printf("Choose your seat(1-20): " );
    scanf("%d", &u->seat);
    printf("=> Updated!\n");
}

void usingTime(User u){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int usingTime;
    int presentSec=(tm.tm_hour)*3600 + (tm.tm_min)*60 + tm.tm_sec;
    if(u.in!=0 && u.out==0){ //입실처리만 ,사용중
        usingTime = presentSec - u.in;
        printf("You're using the seats number %d now.\n",u.seat);
    }
    else if(u.in==0 && u.out==0){  //입퇴실 둘다 안했을때, 사용중이 아닐때(계정만 존재)
        printf("You're not using any seats now.\n");
        
    }
    else {  //입퇴실처리 모두 다 됐을때, 사용중이 아닐때
        usingTime = u.out - u.in;
    }
    int usingHour= usingTime/3600;
    int usingMin= (usingTime-3600*usingHour)/60;
    int usingSec= usingTime-3600*usingHour-60*usingMin;
    printf("Your using time: %dh %dm %ds\n", usingHour, usingMin, usingSec);
}
int readHistory(User *u, int cnt){ // file에 저장된 히스토리 읽기
    int cnt=0, i=0;
    FILE *fp;
    fp=fopen("userHistory.txt","rt");
    for(i=0; i<30; i++){
        fscanf(fp, "%s", u[i].id);
        if(feof(fp)) break;
        fscanf(fp, "%d", &u[i].in);
        fscanf(fp, "%d", &u[i].out);
        fscanf(fp, "%d", &u[i].seat);
    }
    fclose(fp);
    printf("->Reading History successed!\n");
    return i;
}
void searchUser(User *u, int cnt){ // 사용자 검색
    int scnt = 0;
    char search[20];

    printf("Input a name you want to search: ");
    scanf("%s", search);

    printf("\nNo\tID\t\tCheck in\tCheck out\tSeat No\n");
    printf("****************************************************************\n");
    for (int i=0; i<cnt; i++){
        if(u[i].in == 0) continue;
        if(strstr(u[i].id, search)){
            readUser(u[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("-> no result\n");
}
int checkSeat(User u[], int select){  //자리 사용여부 확인, 자리가 겹치지 않을때 1, 겹칠때 0
    int ck=0;
    for(int i=0; i<30; i++){
            if(u[i].seat == select){
                ck ++;
            }
            else continue;
    }
    if(ck == 1) return 1;
    else return 0;
}

void searchUsing(User *u, int cnt){ // 사용중인 자리 조회
    int ucnt = 0;

    printf("This is a list of seats in use.\n");
    printf("\nNo\tID\t\tCheck in\tCheck out\tSeat No\n");
    printf("****************************************************************\n");
    for(int i=0; i<cnt; i++){
        if(u[i].seat == 0) continue;
        else{
            printf("%d", i+1);
            readUser(u[i]);
            ucnt++;
        }
    }
    if(ucnt==0)
        printf("=> All seats are empty!\n");
}
void searchEmpty(User *u, int cnt){ // 빈 자리 조회
    int emptyseat[30-cnt];
    int usingseat[cnt];
    printf("\nNumber of empty seats: %d\n", 30-cnt);
    // 빈 자리 출력
    printf("This is a list of empty seats.\n");
    int k = 0, flag = 0;
    for(int i=0; i<30; i++){
        for(int j=0; j<cnt; j++){
            if(i+1 == u[j].seat) flag = 1;
            if(flag == 1) break;
        }
        emptyseat[k] = i+1;
        if(flag == 0) k++;
        flag = 0;
    }
    for(int i=0; i<30-cnt; i++){
        printf("seat %d\n", emptyseat[i]);
    }
    if(cnt==30){
        printf("=> There are no seats available.\n");
    }
}
void saveFile(User *u){ // 파일 저장
    FILE *fp;
    fp = fopen("userHistory.txt", "w");
    for(int i=0; i<30; i++){
        fprintf("\t%s\t\t%d\t\t%d\t\t%d\n", u[i].id, u[i].in, u[i].out, u[i].seat);
    }
    fclose(fp);
    printf("=> Saved!\n");
}

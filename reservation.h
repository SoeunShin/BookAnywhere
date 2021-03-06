typedef struct{ 
  char id[20];
  int in;
  int out;
  int seat; 
} User;

int addUser(User *u, User *U); // 사용자 계정 생성
void usingTime(User u); // 사용시간 출력
void timeRemain(User u); // 잔여시간 출력
int readHistory(User *u);  // 파일에 저장된 히스토리 읽기
void updateSeat(User *u, User *U);  //자리상태 
void searchUser(User *u, int cnt);  // 사용자 이용 정보 검색
void readUser(User u); // 사용자 한 명 목록 출력
int deleteUser(User *u); // 사용자 목록 삭제
void checkinout(User *u);  // 입퇴실 처리
int selectNo(User u[]); // 번호 선택 
void listUser(User *u); // 전체 목록 출력
void searchUsing(User *u, int cnt); // 사용중인 자리 조회
void searchEmpty(User *u, int cnt); // 빈 자리 조회
int selectMenu(); // 메뉴 선택
void saveFile(User *u); // 파일 저장
int checkSeat(User u[], int select); //자리 상태 확인
int loadData(User *u); // 파일에 있는 내용을 불러오는 함수

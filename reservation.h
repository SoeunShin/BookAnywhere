typedef struct{ 
  char id[20]; 
  int in;
  int out;
  int seat; 
} User;

int addUser(User *u); // 사용자 계정 만들기
void usingTime(User u); // 사용시간 출력
void readHistory(User u); // file에 저장된 히스토리 읽기
int updateSeat(User *u); // 예약 수정
void searchUser(User *u); // 사용자 이용 정보 검색
void readUser(User u); // 사용자 목록 조회
int deleteUser(User *u); // 사용자 목록 삭제
void checkinout(User *u); // 입퇴실 처리
void searchUsing(User *u, int cnt); // 사용중인 자리 검색
void searchEmpty(User *u, int cnt); // 비어있는 자리 검색
int selectMenu(); // 메뉴 선택
void saveFile(User *u, int cnt); // 파일 저장

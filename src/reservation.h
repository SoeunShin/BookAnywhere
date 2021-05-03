int addUser(User *u); //사용자 계정 만들기
void timeRemain(User u); //잔여시간 출력
void readHistory(User u);  //file에 저장된 히스토리 읽기
//int update(User *u);  //시간 업데이트
void searchUser(User *u);  //사용자이용정보 검색
void readUser(User u); // 사용자 목록 조회
int deleteUser(User *u); // 사용자 목록 삭제
void searchUsing(User *u, int cnt); // 사용중인 자리 검색
void searchEmpty(User *u, int cnt); // 비어있는 자리 검색
void saveFile(User *u, int cnt); // 파일 저장

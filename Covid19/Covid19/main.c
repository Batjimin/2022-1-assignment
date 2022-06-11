/*소아 대상 코로나19 관련 정보를 알려주는 프로그램
선택 번호에 따라
1. 월별 확진자,위중증자, 사망자 
2. 소아용 약물 투여 가능인원
3. 지역별 소아예방접종 가능 병원 수
알 수 있도록 프로그램*/


#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h> // strchr함수 활용 위한
#include"func.h"


int main(void)
{
	INFE list[4] = {
		{23706,3,0},
		{277678,8,1},
		{1173837,15,7},
		{394388,8,2}
	};
	int choice;
	while (1) {
		printf("\n\n소아용 코로나19 관련 정보\n\n");
		printf("1. 월별 확진자, 위중증자, 사망자 현황\n");
		printf("2. 약물 투여 가능인원 파악\n");
		printf("3. 지역별 예방접종 가능 병원 수 조회\n");
		printf("필요하신 정보의 좌측 번호를 입력해주세요(종료는 0 번): ");
		scanf("%d", &choice);
		if (choice ==0) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else if (choice == 1) {
			int i;

			for (i = 0;i < 4;i++) {
				printf("\n2022년 %d월 유아 코로나 확진자 수 %d명\n", i + 1, list[i].confirmed);
				printf("2022년 %d월 유아 코로나 위중증자 수 %d명\n", i + 1, list[i].critical);
				printf("2022년 %d월 유아 코로나 사망자 수 %d명\n\n", i + 1, list[i].deaths);
			}
		}
		else if (choice == 2) {
			float drug;
			printf("현재 구비된 약물의 총 용량을 기입해주세요(㎖): ");
			scanf("%f", &drug);
			printf("%.1f㎖의 약물로 총 %d명에게 주사가 가능합니다.", drug, inject(drug));
		}
		else if(choice == 3){
			FILE* fp;  //파일 포인터
			char fname[128] = "test1.txt";
			char buffer[256]; 
			char word[256]; //찾고자 하는 지역을 워드에 저장
			int list_count = 0; // 병원 수 조회를 위한 변수

			printf("조회를 원하시는 지역을 입력해주세요(인천/서울특별시/경기/대구/광주/제주): "); // 인천,서울특별시,경기,제주,광주,대구까지 有
			scanf("%s", word);

			if ((fp = fopen(fname, "r")) == NULL)// 파일을 읽기 모드로 연다.
			{
				fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname);
				exit(1);
			}

			while (fgets(buffer, 256, fp))//한 라인씩 입력. fgets(), 즉 줄이 0이면 반복 종료. //(한 줄의 데이터가 256보다 작을 경우
			{
				if (strstr(buffer, word)) //문자열 안에 다른 문자열 있는지 검사. 
				{
					list_count++; // 반환된 문자열 위치가 NULL이 아닐 경우 list_count 1씩 증가 
				}
			}
			fclose(fp);
			printf("%s에서 소아 예방접종이 가능한 병원은 %d곳입니다",word, list_count);

		}
		else {
			printf("잘못된 입력입니다. 다시 입력해 주세요.\n");
		}
	}
	return 0;
}
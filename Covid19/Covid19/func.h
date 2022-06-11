#pragma once
struct infection {
	int confirmed, critical, deaths;
};  // infection 구조체 정의
typedef struct infection INFE; // struct infection을 typedef 통해 INFE로 지칭

int inject(float x); 

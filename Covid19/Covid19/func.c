#include <stdio.h>
#include "func.h"
//�Ҿ� ȸ�� ��� �����뷮 0.2��

int inject(float x) {
	int result;
	result = x / 0.2;
	return result; //x�� 1/5�� ��ȯ
}




/*�Ҿ� ��� �ڷγ�19 ���� ������ �˷��ִ� ���α׷�
���� ��ȣ�� ����
1. ���� Ȯ����,��������, ����� 
2. �Ҿƿ� �๰ ���� �����ο�
3. ������ �Ҿƿ������� ���� ���� ��
�� �� �ֵ��� ���α׷�*/


#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h> // strchr�Լ� Ȱ�� ����
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
		printf("\n\n�Ҿƿ� �ڷγ�19 ���� ����\n\n");
		printf("1. ���� Ȯ����, ��������, ����� ��Ȳ\n");
		printf("2. �๰ ���� �����ο� �ľ�\n");
		printf("3. ������ �������� ���� ���� �� ��ȸ\n");
		printf("�ʿ��Ͻ� ������ ���� ��ȣ�� �Է����ּ���(����� 0 ��): ");
		scanf("%d", &choice);
		if (choice ==0) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else if (choice == 1) {
			int i;

			for (i = 0;i < 4;i++) {
				printf("\n2022�� %d�� ���� �ڷγ� Ȯ���� �� %d��\n", i + 1, list[i].confirmed);
				printf("2022�� %d�� ���� �ڷγ� �������� �� %d��\n", i + 1, list[i].critical);
				printf("2022�� %d�� ���� �ڷγ� ����� �� %d��\n\n", i + 1, list[i].deaths);
			}
		}
		else if (choice == 2) {
			float drug;
			printf("���� ����� �๰�� �� �뷮�� �������ּ���(��): ");
			scanf("%f", &drug);
			printf("%.1f���� �๰�� �� %d���� �ֻ簡 �����մϴ�.", drug, inject(drug));
		}
		else if(choice == 3){
			FILE* fp;  //���� ������
			char fname[128] = "test1.txt";
			char buffer[256]; 
			char word[256]; //ã���� �ϴ� ������ ���忡 ����
			int list_count = 0; // ���� �� ��ȸ�� ���� ����

			printf("��ȸ�� ���Ͻô� ������ �Է����ּ���(��õ/����Ư����/���/�뱸/����/����): "); // ��õ,����Ư����,���,����,����,�뱸���� ��
			scanf("%s", word);

			if ((fp = fopen(fname, "r")) == NULL)// ������ �б� ���� ����.
			{
				fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname);
				exit(1);
			}

			while (fgets(buffer, 256, fp))//�� ���ξ� �Է�. fgets(), �� ���� 0�̸� �ݺ� ����. //(�� ���� �����Ͱ� 256���� ���� ���
			{
				if (strstr(buffer, word)) //���ڿ� �ȿ� �ٸ� ���ڿ� �ִ��� �˻�. 
				{
					list_count++; // ��ȯ�� ���ڿ� ��ġ�� NULL�� �ƴ� ��� list_count 1�� ���� 
				}
			}
			fclose(fp);
			printf("%s���� �Ҿ� ���������� ������ ������ %d���Դϴ�",word, list_count);

		}
		else {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n");
		}
	}
	return 0;
}
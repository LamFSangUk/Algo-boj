#include<stdio.h>
#include<string.h>
#define DIVISOR 9901

int cage[2][3];
// cage[n][0] = �̹� ĭ�� ���ڸ� ���� �ʴ� ����� ��
// cage[n][1] = �̹� ĭ�� ���ڸ� ���ʿ� �δ� ����� ��
// cage[n][2] = �̹� ĭ�� ���ڸ� �����ʿ� �δ� ����� ��

int main(void) {
	int n;

	scanf("%d", &n);

	cage[0][0] = cage[0][1] = cage[0][2] = 1;

	for (int i = 1;i < n;i++) {
		cage[1][0] = (cage[0][0] + cage[0][1] + cage[0][2]) % DIVISOR;
		cage[1][1] = (cage[0][0] + cage[0][2]) % DIVISOR;
		cage[1][2] = (cage[0][0] + cage[0][1]) % DIVISOR;
		memcpy(cage[0], cage[1], sizeof(cage[1]));
	}

	int answer = (cage[0][0] + cage[0][1] + cage[0][2]) % DIVISOR;
	printf("%d", answer);
}
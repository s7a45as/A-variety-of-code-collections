#include <stdio.h>

int main() {
    char str[100];
	int a;
	scanf("%d",&a);
	
    // ��ȡ�����ո����������
    printf("�������ַ������ɰ����ո񣬰��س�������: ");
    scanf(" %[^\n]", str);  // ע���ʽ�ַ���ǰ�Ŀո������� 99

    printf("�������������: %s\n", str);
    return 0;
}

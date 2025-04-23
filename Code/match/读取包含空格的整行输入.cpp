#include <stdio.h>

int main() {
    char str[100];
	int a;
	scanf("%d",&a);
	
    // 读取包含空格的整行输入
    printf("请输入字符串（可包含空格，按回车结束）: ");
    scanf(" %[^\n]", str);  // 注意格式字符串前的空格和最大宽度 99

    printf("你输入的内容是: %s\n", str);
    return 0;
}

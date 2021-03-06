// Encrypto-tool.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "encrypto.h"
#include "stdio.h"
#include <iostream>

using namespace std;
int main()
{
	DES des;
	int sel;
	unsigned char plaintext[8];
	unsigned char cipher[8];
	unsigned char key[8];
	while (1)
	{
		printf("请输入功能：\n");
		printf("1.	加密\n");
		printf("2.	解密\n");
		printf("3.	设置秘钥\n");
		cin >> sel;
		switch (sel)
		{
		case 1:	printf("请输入16位16进制数加密内容：");
			scanf_s("%2x%2x%2x%2x%2x%2x%2x%2x", &plaintext[0], &plaintext[1], &plaintext[2], &plaintext[3], &plaintext[4], &plaintext[5], &plaintext[6], &plaintext[7]);
			des.encrypt(plaintext, cipher);
			printf("\n加密结果：%02x%02x%02x%02x%02x%02x%02x%02x\n", cipher[0], cipher[1], cipher[2], cipher[3], cipher[4], cipher[5], cipher[6], cipher[7]);
			break;
		case 2:	printf("请输入16位16进制数解密内容：");
			scanf_s("%2x%2x%2x%2x%2x%2x%2x%2x", &cipher[0], &cipher[1], &cipher[2], &cipher[3], &cipher[4], &cipher[5], &cipher[6], &cipher[7]);
			des.decrypt(cipher, plaintext);
			printf("\n解密结果：%02x%02x%02x%02x%02x%02x%02x%02x\n", plaintext[0], plaintext[1], plaintext[2], plaintext[3], plaintext[4], plaintext[5], plaintext[6], plaintext[7]);
			break;
		case 3:	printf("请输入16位16进制数秘钥：");
			scanf_s("%2x%2x%2x%2x%2x%2x%2x%2x", &key[0], &key[1], &key[2], &key[3], &key[4], &key[5], &key[6], &key[7]);
			des.setkey(key);
			printf("\n设置成功！\n");
			break;
		}
	}
    return 0;
}


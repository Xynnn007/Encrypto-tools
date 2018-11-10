#pragma once
//DES�㷨��

class DES
{
public:
	~DES() {};

	void setkey(const unsigned char*);
	void encrypt(const unsigned char*, unsigned char*);
	void decrypt(const unsigned char*, unsigned char*);

private:
	unsigned char KEY[16][48];

	//��ʼ�û�	Initial Permutation
	const static int IP[64];
	//�����û� IP-1
	const static int IP_1[64];
		//���ź��� E
	const static int E[48];
		//P�û�
	const static int P[32];
	//ѡ���û�1 PC-1
	//��
	const static int PC_1L[28];
	//��
	const static int PC_1R[28];
	//ѡ���û�2 PC-2
	const static int PC_2[48];
	//������λ˳��
	const static int shift_en[16];
	//������λ˳��
	const static int shift_de[16];
	//�û�S��
	const static unsigned char S[8][4][16];
	
};
const int DES::IP[64] = {
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21,13, 5,
	63, 55, 47, 39, 31, 23, 15, 7 };

const int DES::IP_1[64] = {
	40, 8, 48, 16, 56, 24, 64, 32,
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41, 9, 49, 17, 57, 25
};

const int DES::E[48] = {
	32, 1, 2, 3, 4, 5,
	4, 5, 6, 7, 8, 9,
	8, 9, 10, 11, 12, 13,
	12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21,
	20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29,
	28, 29, 30, 31, 32, 1
};

const int DES::P[32] = {
	16, 7, 20, 21,
	29, 12, 28, 17,
	1, 15, 23, 26,
	5, 18, 31, 10,
	2, 8, 24, 14,
	32, 27, 3, 9,
	19, 13, 30, 6,
	22, 11, 4, 25
};

const int DES::PC_1L[28] = {
	57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36,
};

const int DES::PC_1R[28] = {
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4
};

const int DES::PC_2[48] = {
	14, 17, 11, 24, 1, 5,
	3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8,
	16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55,
	30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53,
	46, 42, 50, 36, 29, 32
};

const int DES::shift_en[16] = {
	1, 1, 2, 2, 2, 2, 2, 2,
	1, 2, 2, 2, 2, 2, 2, 1
};

const unsigned char DES::S[8][4][16] = {

	//S1
	14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
	0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
	4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
	15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13,
	//S2
	15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
	3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
	0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
	13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9,
	//S3
	10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
	13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
	13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
	1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,
	//S4
	7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
	13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
	10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
	3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,
	//S5
	2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
	14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
	4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
	11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3,
	//S6
	12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
	10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
	9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
	4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13,
	//S7
	4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
	13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
	1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
	6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,
	//S8
	13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
	1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
	7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
	2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
};

void DES::encrypt(const unsigned char* plaintext, unsigned char* cipher)
{
	unsigned char plain_array[64], new_array[64], output_array[64];
	unsigned char L0[32], R0[32], L1[32], R1[32];
	unsigned char R_extern[48]; //��չR���
	unsigned char R_s[32];		//S�滻���
	unsigned char R_p[32];		//P�û����
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			plain_array[i * 8 + j] = (plaintext[i] >> (7 - j)) & 0x01;
		}
	}
	//������ĵ�ÿ��λ�ϵ��������� plain_array[64]
	//�����û������new_array[64]
	for (int i = 0; i < 64; i++)
	{
		new_array[i] = plain_array[IP[i] - 1];
	}
	//�ѳ����û���Ľ�����в�֣��γ�L R�����֣��ֱ���64λ��ǰ32λ�ͺ�32λ
	for (int i = 0; i < 32; i++)
	{
		L0[i] = new_array[i];
		R0[i] = new_array[i + 32];
	}
	//����������16����ͬ������
	for (int n = 0; n < 16; n++)
	{
		for (int i = 0; i < 32; i++)L1[i] = R0[i];
		//L(n) = R(n-1)

		for (int i = 0; i < 48; i++)R_extern[i] = R0[E[i] - 1];
		//R��չ
		for (int i = 0; i < 48; i++)R_extern[i] = KEY[n][i] ^ R_extern[i];
		//R����Կ�����
		
		//��������S�д��棬��48λ��չR�ֳ�8��6λ���飬ÿ�������һ������
		
		for (int group = 0; group < 8; group++)
		{
			int row, column;
			unsigned char s;
			row = R_extern[6 * group] * 2 + R_extern[6 * group + 5];
			column = R_extern[6 * group + 1] * 8 + R_extern[6 * group + 2] * 4 + R_extern[6 * group + 3] * 2 + R_extern[6 * group + 4];
			s = S[group][row][column];
			R_s[group * 4] = (s >> 3 )& 0x1;
			R_s[group * 4 + 1] = (s >> 2 ) & 0x1;
			R_s[group * 4 + 2] = (s >> 1 ) & 0x1;
			R_s[group * 4 + 3] = s & 0x1;
		}
		//��ʱR_sΪ����S�滻�Ľ����Ȼ�����P�û�

		for (int i = 0; i < 32; i++)R_p[i] = R_s[P[i] - 1];
		
		for (int i = 0; i < 32; i++)R1[i] = R_p[i] ^ L0[i];
		//Rn = L(n - 1)��F(Rn-1,Kn-1)

		//ѭ������
		//printf("����n=%d:",n);
		for (int i = 0; i < 32; i++) {
			L0[i] = L1[i]; 
			//printf("%1x", L0[i]);
		}
		//printf(" ");
		for (int i = 0; i < 32; i++) 
		{ 
			R0[i] = R1[i]; 
			//printf("%1x", R0[i]); 
		}
		//printf("\n");
	}
	//�õ���L16��R16����ƴ�ӣ���P-1���û����浽new_array[64]��
	for (int i = 0; i < 32; i++)
	{
		new_array[i + 32] = L1[i];
		new_array[i] = R1[i];
	}
	for (int i = 0; i < 64; i++)
	{
		output_array[i] = new_array[IP_1[i] - 1];
	}

	unsigned char byte;
	for (int i = 0; i < 8 ; i++)
	{
		byte = 0;
		for (int j = 0; j < 8; j++)
		{
			byte = byte << 1;
			byte = output_array[i * 8 + j] | byte;
		}
		//printf("byte=%02x\n",byte);
		cipher[i] = byte;
	}

}

void DES::decrypt(const unsigned char* cipher, unsigned char* plaintext)
{
	unsigned char plain_array[64], new_array[64], output_array[64];
	unsigned char L0[32], R0[32], L1[32], R1[32];
	unsigned char R_extern[48]; //��չR���
	unsigned char R_s[32];		//S�滻���
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			plain_array[i * 8 + j] = (cipher[i] >> (7 - j)) & 0x01;
		}
	}
	//������ĵ�ÿ��λ�ϵ��������� plain_array[64]
	//�����û������new_array[64]
	for (int i = 0; i < 64; i++)
	{
		new_array[i] = plain_array[IP[i] - 1];
	}
	//�ѳ����û���Ľ�����в�֣��γ�L R�����֣��ֱ���64λ��ǰ32λ�ͺ�32λ
	for (int i = 0; i < 32; i++)
	{
		L0[i] = new_array[i];
		R0[i] = new_array[i + 32];
	}
	//����������16����ͬ������
	for (int n = 0; n < 16; n++)
	{
		for (int i = 0; i < 32; i++)L1[i] = R0[i];
		//L(n) = R(n-1)

		for (int i = 0; i < 48; i++)R_extern[i] = R0[E[i] - 1];
		//R��չ
		for (int i = 0; i < 48; i++)R_extern[i] ^= KEY[15-n][i];
		//R����Կ�����

		//��������S�д��棬��48λ��չR�ֳ�8��6λ���飬ÿ�������һ������

		for (int group = 0; group < 8; group++)
		{
			int row, column;
			row = R_extern[6 * group] * 2 + R_extern[6 * group + 5];
			column = R_extern[6 * group + 1] * 8 + R_extern[6 * group + 2] * 4 + R_extern[6 * group + 3] * 2 + R_extern[6 * group + 4];
			R_s[group * 4] = (S[group][row][column] >> 3) & 0x1;
			R_s[group * 4 + 1] = (S[group][row][column] >> 2) & 0x1;
			R_s[group * 4 + 2] = (S[group][row][column] >> 1) & 0x1;
			R_s[group * 4 + 3] = (S[group][row][column]) & 0x1;
		}
		//��ʱR_sΪ����S�滻�Ľ����Ȼ�����P�û���ͬʱ�����

		for (int i = 0; i < 32; i++)R1[i] = R_s[P[i] - 1] ^ L0[i];
		//Rn = L(n - 1)��F(Rn-1,Kn-1)
		//printf("����n=%d:", n);
		//ѭ������
		for (int i = 0; i < 32; i++) 
		{ 
			L0[i] = L1[i]; 
			//printf("%x", L0[i]); 
		}
		//printf(" ");
		for (int i = 0; i < 32; i++)
		{
			R0[i] = R1[i]; 
			//printf("%x", R0[i]);
		}
		//printf("\n");
	}
	//�õ���L16��R16����ƴ�ӣ���P-1���û����浽new_array[64]��
	for (int i = 0; i < 32; i++)
	{
		new_array[i + 32] = L1[i];
		new_array[i] = R1[i];
	}
	for (int i = 0; i < 64; i++)
	{
		output_array[i] = new_array[IP_1[i] - 1];
	}
	unsigned char byte;
	for (int i = 0; i < 8; i++)
	{
		byte = 0;
		for (int j = 0; j < 8; j++)
		{
			byte = byte << 1;
			byte = output_array[i * 8 + j] | byte;
		}
		//printf("byte=%02x\n", byte);
		plaintext[i] = byte;
	}
}

void DES::setkey(const unsigned char* key_ori)
{
	unsigned char key_cpy[8];
	unsigned char key[64], C0[28], D0[28], C1[28], D1[28], M[56];

	//����ԭ��Կ��key_cpy[8]
	for (int i = 0; i < 8; i++)key_cpy[i] = key_ori[i];

	//��ȡ��Կ����λ������key[64]
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			key[i * 8 + j] = key_cpy[i] & 0x01;
			//��ĩβ��ʼȡÿһλ
			key_cpy[i] = key_cpy[i] >> 1;
			//����һλ
		}
	}

	//����PC_1L��PC_1R�û������C0[28]��D0[28]
	for (int i = 0; i < 28; i++)
	{
		C0[i] = key[PC_1L[i] - 1];
		D0[i] = key[PC_1R[i] - 1 ];
		//���C0��D0
	}
	for (int n = 0; n < 16; n++)
	{
		//�����C0��D0ѭ�����Ʊ��ϵ�λ�õ�C1��D1
		for (int i = 0; i < 28; i++)
		{
			C1[i] = C0[(i + shift_en[n] )% 28];
			D1[i] = D0[(i + shift_en[n]) % 28];
		}

		//���ΪM=C1||D1
		for (int i = 0; i < 28; i++)
		{
			M[i] = C1[i];
			C0[i] = C1[i];
			D0[i] = D1[i];
			M[i + 28] = D1[i];
		}
		//Ȼ�����PC_2����K1���洢��������
		for (int i = 0; i < 48; i++)
		{
			KEY[n][i] = M[PC_2[i] - 1];
		}
	}
}

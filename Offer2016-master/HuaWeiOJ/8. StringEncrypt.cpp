/************************************************************************/
/* 
����
��һ�ּ��ɿ��Զ����ݽ��м��ܣ���ʹ��һ��������Ϊ�����ܳס����������Ĺ���ԭ�����ȣ�ѡ��һ��������Ϊ�ܳף���TRAILBLAZERS����������а������ظ�����ĸ��ֻ������1�������༸�����������ڣ��޸Ĺ����Ǹ�����������ĸ������棬������ʾ��
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
T R A I L B Z E S C D F G H J K M N O P Q U V W X Y
������������ĸ����ʣ�����ĸ����������ڶ���Ϣ���м���ʱ����Ϣ�е�ÿ����ĸ���̶��ڶ������У������������еĶ�Ӧ��ĸһһȡ��ԭ�ĵ���ĸ(��ĸ�ַ��Ĵ�Сд״̬Ӧ�ñ���)����ˣ�ʹ������ܳף�Attack AT DAWN(����ʱ����)�ͻᱻ����ΪTpptad TP ITVH��
��ʵ�������ӿڣ�ͨ��ָ�����ܳ׺����ĵõ����ġ�
��ϸ������
�ӿ�˵��
ԭ�ͣ�
voidencrypt(char * key,char * data,char * encrypt);
���������
char * key���ܳ�
char * data������
���������
char * encrypt������
����ֵ��
void

֪ʶ��	�ַ���
����ʱ������	10M
�ڴ�����	128
����
������key��Ҫ���ܵ��ַ���
���
���ؼ��ܺ���ַ���
��������	nihao ni
�������	le
*/
/************************************************************************/

#include <iostream>
#include <cstdlib>
#include <unordered_set>

using namespace std;

void encrypt(char *key, char *data, char *encrypt)
{
	unordered_set<int> levels;
	int idx = 0;
	while (levels.size() < 26 && key[idx] != '\0')
	{
		/*�Դ�д�ķ�ʽ�洢��Կ*/
		if (key[idx] >= 'a' && key[idx] <= 'z')
		{
			key[idx] = key[idx] - 'a' + 'A';
		}//if

		if (levels.find(key[idx]) != levels.end())
		{
			++idx;
			continue;
		}
		else
		{
			levels.insert(key[idx]);
			++idx;
		}//else
	}//while

	idx = 0;
	while (levels.size() < 26 && idx < 26)
	{
		if (levels.find('A' + idx) != levels.end() || levels.find('a' + idx) != levels.end())
		{
			++idx;
			continue;
		}//if
		else
		{
			levels.insert('A' + idx);
			++idx;
		}//else
	}//while

	vector<char> tmpLevels(levels.begin(), levels.end());
	for (int i = 0; data[i] != '\0'; ++i)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			encrypt[i] = tmpLevels[data[i] - 'A'];
		}
		else{
			encrypt[i] = tmpLevels[data[i] - 'a'] - 'A' + 'a';
		}//else
	}//for
	encrypt[strlen(data)] = '\0';
}

//int main()
//{
//	char key[10000], data[10000], ret[10000];
//	
//	cin >> key;
//	cin >> data;
//	
//	/*����*/
//	encrypt(key, data, ret);
//
//	cout << ret << endl;
//
//	system("pause");
//	return 0;
//}
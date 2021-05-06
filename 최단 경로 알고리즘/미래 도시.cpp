#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

int N; // ȸ���� ���� 1 <= N,M <= 100
int M; // ����� ���� 

int graph[101][101];

int main()
{
	cin >> N >> M;
		
	for (int i = 0; i < 101; i++)
	{
		fill(graph[i], graph[i] + 101, INF);
	}

	// �ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ����� 0���� �ʱ�ȭ
	for (int a = 1; a <= N; a++)
	{
		for (int b = 1; b <= N; b++)
		{
			if (a == b) graph[a][b] = 0;
		}
	}

	// �� ������ ���� ������ �Է� �޾�, �� ������ �ʱ�ȭ
	for (int i = 0; i < M; i++)
	{
		// A���� B�� ���ο��� ���� ����� 1�̶�� ����
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// ��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
	for (int k = 1; k <= N; k++)
	{
		for (int a = 1; a <= N; a++)
		{
			for (int b = 1; b <= N; b++)
			{
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	// ���İ� ��� K ���� ������ ��� X�� �Է¹ޱ�
	int X, K;
	cin >> X >> K; // K�� ȸ�縦 ���ļ� X�� ȸ��� ���� �ּ��̵��ð� ���϶� , �Ұ����ϸ� -1���

	int nCount = graph[1][K] + graph[K][X];

	if (nCount >= INF)
	{
		nCount = -1;
	}
 
	cout << nCount << '\n';

	return 0;
}
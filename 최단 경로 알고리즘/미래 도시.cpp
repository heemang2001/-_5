#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

int N; // 회사의 개수 1 <= N,M <= 100
int M; // 경로의 개수 

int graph[101][101];

int main()
{
	cin >> N >> M;
		
	for (int i = 0; i < 101; i++)
	{
		fill(graph[i], graph[i] + 101, INF);
	}

	// 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
	for (int a = 1; a <= N; a++)
	{
		for (int b = 1; b <= N; b++)
		{
			if (a == b) graph[a][b] = 0;
		}
	}

	// 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
	for (int i = 0; i < M; i++)
	{
		// A에서 B로 서로에게 가는 비용은 1이라고 설정
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	// 점화식에 따라 플로이드 워셜 알고리즘을 수행
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

	// 거쳐갈 노드 K 최종 목적지 노드 X를 입력받기
	int X, K;
	cin >> X >> K; // K번 회사를 거쳐서 X번 회사로 가는 최소이동시간 구하라 , 불가능하면 -1출력

	int nCount = graph[1][K] + graph[K][X];

	if (nCount >= INF)
	{
		nCount = -1;
	}
 
	cout << nCount << '\n';

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

int N; // 도시의 개수 1 <= N <= 30,000
int M; // 통로의 개수 1 <= M <= 200,000
int C; // 메세지를 보내고자 하는 도시 1 <= C <= N

// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int> > graph[30001];
// 최단 거리 테이블 만들기
int d[30001];

void dijkstra(int start)
{
	priority_queue<pair<int, int> > pq;
	// 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
	pq.push({ 0, start });
	d[start] = 0;

	// 큐가 비어있지 않다면
	while (!pq.empty())
	{ 
		// 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
		int dist = -pq.top().first; // 현재 노드까지의 비용 
		int now = pq.top().second; // 현재 노드
		pq.pop();

		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시
		if (d[now] < dist)
		{
			continue;
		}

		// 현재 노드와 연결된 다른 인접한 노드들을 확인
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second;

			// 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
			if (cost < d[graph[now][i].first])
			{
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main()
{
	cin >> N >> M >> C;

	// 모든 간선 정보를 입력받기
	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		// X번 노드에서 Y번 노드로 가는 비용이 Z라는 의미
		graph[x].push_back({ y,z });
	}

	// 최단거리 테이블을 모두 INF로 초기화
	fill(d, d + 30001, INF);

	// 다익스트라 알고리즘 수행
	dijkstra(C);

	// 도달할 수 있는 노드의 개수
	int count = 0;

	// 도달할 수 있는 노드 중에서, 가장 멀리있는 노드와의 최단거리
	int maxDistance = 0;

	for (int i = 1; i <= N; i++)
	{
		// 도달할 수 있는 노드인 경우
		if (d[i] != INF)
		{
			count += 1;
			maxDistance = max(maxDistance, d[i]);
		}
	}

	// 시작 노드는 제외해야 하므로 count - 1을 출력
	cout << count - 1 << ' ' << maxDistance << '\n';


	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 987654321

using namespace std;

vector<vector<pair<int, int>>> adj;
int i, V, E, K, u, v, w;
typedef pair<int, int> node;
struct cmp
{
  bool operator()(node x, node y)
  {
    return x.second > y.second;
  }
};

void dijkstra(int K)
{
  priority_queue<node, vector<node>, cmp> pq;
  vector<int> dist(V + 1, INF);
  dist[K] = 0;
  pq.push({K, 0});
  while (!pq.empty())
  {
    int u = pq.top().first;
    int d = pq.top().second;
    pq.pop();
    if (d > dist[u])
      continue;
    for (i = 0; i < adj[u].size(); i++)
    {
      int v = adj[u][i].first;
      int w = adj[u][i].second;
      if (dist[v] > dist[u] + w)
      {
        dist[v] = dist[u] + w;
        pq.push({v, dist[v]});
      }
    }
  }
  for (i = 1; i <= V; i++)
  {
    if (dist[i] == INF)
      cout << "INF\n";
    else
      cout << dist[i] << "\n";
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> V >> E >> K;
  adj.resize(V + 1);
  for (i = 0; i < E; i++)
  {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  dijkstra(K);
  return 0;
}

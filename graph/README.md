## graph 그래프 ##

그래프와 트리의 관계
- 트리는 순환(cycle) 없는 그래프

그래프 용어
> vertex, node, 꼭짓점
> edge, 변
> G = (V, E)
	> 그래프 G = (꼭짓점의 집합 V, 변의 집합 E)
> 발생incident, 인접adjacent
> 병렬(parallel) 변
> 루프 loop
> 고립 (isolated)

--------

방향 그래프 directed graph
- 변 edge 가 방향을 가지고 있는 그래프
- 리스트나 트리와 같은 자료 구조를 도식화 하는데 유용

무향 그래프 undiredted graph
- 변 edge 가 방향을 가지고 있지 않은 그래프
- 꼭짓점 사이에 전후 관계가 없을 때 이를 도식화 하는 용도에 유용

--------

단순 그래프 simple graph
- 루프나 병렬 변을 가지지 않는 무향 그래프

부분 그래프 subgraph
- 그래프 H 와 G 가 있을때 H의 모든 꼭짓점이 G의 꼭짓점이고 H의 모든 변이 G의 변일 경우 H를 G의 부분그래프라고 한다.

신장 부분 그래프 spanning subgraph
- H가 G의 부분그래프 일때 H의 꼭짓점과 G의 꼭지점이 완전히 일치하면 H는 G의 신장 부분 그래프라 한다.

---------

차수
- 그래프 G의 꼭짓점 v에 대해 v에 인접한 변의 수
- 변이 루프일 경우 2를 더한다.
- 진입차수
- 진출차수

워크 walk
- 꼭짓점에서 edge 를 거쳐 인접한 꼭짓점으로 향하는 순서쌍
- v0 e1 v1 e2 v2 e2 v1 e3 v3 e4 v3

트레일 trail
- 워크 W 의 변들이 모두 서로 다른 경우, W는 트레일이다.

경로 path
- 변과 꼭짓점 모두 다름
- 트레일 W의 꼭지점들 모두 서로 다른 경우, W는 경로이다.

-----------

그래프의 종류

완전 그래프 comlete graph

이분 그래프 bipartite graph

완전 이분 그래프 complete bipartite graph

정규 그래프 regular graph

----------

그래프의 표현

발생행렬 incidence matrix 

인접행렬 adjacency matrix //arraygraph

인접리스트 adjacency list  //linkedgraph

---------

평면 그래프 planar graph

오일러 트레일
- 모든 변들을 각 한번만 지나는 트레일
오일러 투어
- 시작점과 종점이 같은 오일러 트레일

해밀턴 경로
- 그래프의 모든 꼭지점을 한 번씩만 지나는 경로
해밀턴 투어
- 시작점과 종점이 같은 해밀턴 경로

----------

가중 그래프 weighted graph

- 최단경로 문제
- 최소 신장트리 문제



## 그래프의 dfs bfs ##


link
- https://www.zerocho.com/category/Algorithm/post/5870153c37e1c80018b64eb0
- https://velog.io/@falling_star3/2.-깊이우선탐색DFS과-넓이우선탐색BFS

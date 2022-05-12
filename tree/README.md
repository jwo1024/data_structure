## tree 트리 ##


#### 용어 ####
* edge 간선
* root node 루트 노드
* leaf node (terminal node) 리프 노드 (단말 노드)
* internal node(nonterminal node) 비단말 노드

* parent node 부모 노드
* child node 자식 노드
* cibling node 형제 노드
* ancestor nodet 선조 노드
	- 해당 노드에서부터 루트 노드에 이르는 경로상에 있는 모든 노드
* descendant node 후손 노드
	- 해당 노드에서부터 단말 노드에 이르는 경로상에 있는 모든 노드

* level 레벨
	- 루트 노드로부터의 거리. 따라서 루트 노드 자체는 거리가 0이기 때문에 레벨 또한 0이다.
* height 높이 / depth 깊이
	- 그 트리에 속하는 노드의 최대 레벨에 1을 더한 것
* dgree 차수 / 분기수
	- 노드의 서브트리 개수

* subtree
* forest
	- n(>=0)개의 분리된 트리의 집합. 트리에서 루트 노드를 제거하면 숲이 된다.

* orderd tree 순서 트리
	- 노드의 배열 순서, 특히 레벨이 같은 노드의 좌우 위치가 중요한 의미를 갖는 트리. 그렇지 않은 트리는 비순서 트리라고 한다.
* binary tree 이진 트리
	- 각 노드의 차수가 2 이하인 순서 트리.


#### binary tree 이진 트리 ####

* 이진 트리
	- 각 노드의 차수가 2 이하인 순서 트리.
	- 이진 트리는 0개의 노드를 가진 공백도 포함된다.
	- 자식의 순서를 구분하여 왼쪽 서브트리와 오른쪽 서브트리로 나뉜다.
	- 스레드 이진 트리, 힙, 이진 탐색트리 등의 형태로 응용하여 사용된다.
* 포화(perfect) 이진 트리
* 전(full) 이진 트리
* 완전(complete) 이진 트리
* 균형(balanced) 이진 트리

* Preorder Traversal 전위 순회
* Inorder Traversal 중위 순회
* Postorder Traversal 후위 순회
* Level Traversal 레벨 순회



* root 노드는 1 부터 시작
* 접근 방법
	- 부모 --> 자식  i * 2 (+ 1)
	- 자식 --> 부모	 i / 2 
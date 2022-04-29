#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// �������� �̵�. 북
	{1, 0},			// ���������� �̵�.동
	{0, 1},			// �Ʒ������� �̵�.남
	{-1, 0}			// �������� �̵�.서
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

typedef struct MapPositionType // 스택에 쌓이는 노드
{
	int x;				// ���� ��ġ x��ǥ.
	int y;				// ���� ��ġ y��ǥ.
	int direction;		// ���� ��ġ�� �̵� ����. // 찾았던 곳은 안찾도록! 
} MapPosition;

#endif
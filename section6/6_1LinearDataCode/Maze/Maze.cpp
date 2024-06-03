#include "Vector.h"
#include "pch.h"
#include "Board.h"
#include "Player.h"
#include "Stack.h"

Board board;
Player player;

int main()
{
	Stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	int a = st.top();
	
	st.pop();


	::srand(static_cast<uint32>(time(nullptr)));

	board.Init(25, &player);
	player.Init(&board);


	uint64 lastTick = 0;

	while (true)
	{
#pragma region ������ ����
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		lastTick = currentTick;
#pragma endregion

		// �Է�

		// ����
		player.Update(deltaTick);
		// ������
		board.Render();
	}
}
#include <iostream>
#include <crtdbg.h>

using namespace std;
//
//#if _DEBUG
//#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
//#define malloc(s) _malloc_dbg(s,_NORAMAL_BLOCK,__FILE__,__LINE__)
//#endif

class Item
{
public: 
	Item() {}
	~Item() {}
};

void LeakFinder()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

int main3()
{
	LeakFinder();	// Ãß°¡

	//while (true)
	//{
		Item* item = new Item();
		//delete item;
	
	/*}*/

	return 0;
}
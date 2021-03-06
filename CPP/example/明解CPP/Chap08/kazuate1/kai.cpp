// 猜數字遊戲 (第1版：遊戲部份)

#include <ctime>
#include <cstdlib>
using namespace std;

static int kotae = 0;
extern int max_no;

//--- 初始化 ---//
void initialize()
{
	srand(time(NULL));
}

//--- 產生答案 ---//
void gen_no()
{
	kotae = rand() % (max_no + 1);
}

//--- 判斷  ---//
int judge(int cand)
{
	int diff = cand - kotae;

	if (diff == 0)		// 正確答案
		return 0;
	else if (diff > 0)	                // 太大了
		return 1;
	else		                // 太小了
		return -1;
}

#include <iostream> 
#include <math.h>  
using namespace std;

struct Tree
{
	int topLeft_x;
	int topLeft_y;
	int botRight_x;
	int botRight_y;
	int count;
	char sign;
	Tree *topLtree;
	Tree *topRtree;
	Tree *botLtree;
	Tree *botRtree;
	Tree(int topLx, int topLy, int botRx, int botRy)
	{
		topLeft_x = topLx;
		topLeft_y = topLy;
		botRight_x = botRx;
		botRight_y = botRy;
		topLtree = NULL;
		topRtree = NULL;
		botLtree = NULL;
		botRtree = NULL;
		sign = '2';
		count = 1;
	}
	void clean()
	{
		if (topLtree != NULL && topRtree != NULL&&botLtree != NULL&&botRtree != NULL)
		{
			topLtree->clean();
			topRtree->clean();
			botLtree->clean();
			botRtree->clean();
			delete topLtree;
			delete topRtree;
			delete botLtree;
			delete botRtree;
		}

	}
	void Insert(int pos_x, int pos_y, char n)
	{
		if (botRight_x - topLeft_x == 0 && botRight_y - topLeft_y == 0)
		{
			if (sign == '2')
				sign = n;
			return;
		}
		else
		{
			if ((topLeft_y + botRight_y) / 2 >= pos_y)//left
			{
				if ((topLeft_x + botRight_x) / 2 >= pos_x)//left top
				{
					if (topLtree == NULL)
					{
						topLtree = new Tree(topLeft_x, topLeft_y, (topLeft_x + botRight_x) / 2, (topLeft_y + botRight_y) / 2);
					}
					topLtree->Insert(pos_x, pos_y, n);
				}
				else
				{
					if (botLtree == NULL)
					{
						botLtree = new Tree((topLeft_x + botRight_x) / 2 + 1, topLeft_y, botRight_x, (topLeft_y + botRight_y) / 2);
					}
					botLtree->Insert(pos_x, pos_y, n);
				}
			}
			else
			{
				if ((topLeft_x + botRight_x) / 2 >= pos_x)
				{
					if (topRtree == NULL)
					{
						topRtree = new Tree(topLeft_x, (topLeft_y + botRight_y) / 2 + 1, (topLeft_x + botRight_x) / 2, botRight_y);
					}
					topRtree->Insert(pos_x, pos_y, n);
				}
				else
				{
					if (botRtree == NULL)
					{
						botRtree = new Tree((topLeft_x + botRight_x) / 2 + 1, (topLeft_y + botRight_y) / 2 + 1, botRight_x, botRight_y);
					}
					botRtree->Insert(pos_x, pos_y, n);
				}
			}
		}
	}
	int findNode(int pos_x, int pos_y)
	{
		if (botRight_x - topLeft_x == 0 && botRight_y - topLeft_y == 0)
		{
			if (sign == '0')
				sign = '1';
			else
				sign = '0';
		}
		else
		{
			if ((topLeft_y + botRight_y) / 2 >= pos_y)//left
			{
				if ((topLeft_x + botRight_x) / 2 >= pos_x)//left top
				{
					if (topLtree != NULL)
					{
						topLtree->findNode(pos_x, pos_y);
						update();
					}
				}
				else
				{
					if (botLtree != NULL)
					{
						botLtree->findNode(pos_x, pos_y);
						update();
					}
				}
			}
			else
			{
				if ((topLeft_x + botRight_x) / 2 >= pos_x)
				{
					if (topRtree != NULL)
					{
						topRtree->findNode(pos_x, pos_y);
						update();
					}
				}
				else
				{
					if (botRtree != NULL)
					{
						botRtree->findNode(pos_x, pos_y);
						update();
					}
				}
			}
		}
		return count;
	}

	int update()
	{
		if (topLtree != NULL&& topRtree != NULL && botLtree != NULL && botRtree != NULL)
		{
			int num;
			num = topLtree->count + topRtree->count + botLtree->count + botRtree->count;
			if ((topLtree->sign == '0' || topLtree->sign == '1') && topLtree->sign == topRtree->sign && topLtree->sign == botLtree->sign && topLtree->sign == botRtree->sign)
			{
				count = 1;
				sign = topLtree->sign;
				return count;
			}
			else
			{
				count = 1 + num;
				sign = '2';
				return count;
			}
		}
		else
			return 1;
	}

	int countNode()
	{
		if (topLtree != NULL&& topRtree != NULL && botLtree != NULL && botRtree != NULL)
		{
			int num = topLtree->countNode() + topRtree->countNode() + botLtree->countNode() + botRtree->countNode();
			if ((topLtree->sign == '0' || topLtree->sign == '1') && topLtree->sign == topRtree->sign && topLtree->sign == botLtree->sign && topLtree->sign == botRtree->sign)
			{
				count = 1;
				sign = topLtree->sign;
				return count;
			}
			else
			{
				count = 1 + num;
				return count;
			}
		}
		else
			return 1;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		int size = pow(2, k);
		char a;
		Tree *quad = new Tree(0, 0, size - 1, size - 1);
		for (int i = 0; i < size; i++)
		{
			for (int k = 0; k < size; k++)
			{
				cin >> a;
				quad->Insert(i, k, a);
			}
		}
		int act, r, c;
		quad->countNode();
		cin >> act;
		for (int i = 0; i < act; i++)
		{
			cin >> r >> c;
			cout << quad->findNode(r - 1, c - 1) << endl;
		}
		quad->clean();
		delete quad;
	}
	return 0;
}
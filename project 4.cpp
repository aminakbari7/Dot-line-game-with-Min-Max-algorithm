#include <iostream>
#include <stdlib.h>
#include <string>
#include<iomanip>
using namespace std;
struct Line
{
	int a = -1, b = -1;
};
struct valuse
{
	Line* l;
	int boxpc = 0;
	int boxme = 0;
	int sum = 0;
};
//---------------------------------------
struct box
{
	string owner = "";
	int numberlines = 0;
	int numberbox = 0;
	Line* up = 0;
	Line* down = 0;
	Line* east = 0;
	Line* west = 0;
};
box map[9];
void setmap()
{

	int j = 0, i = 0;
	for (int i = 0; j < 9; i++)
	{
		if (((i + 1) % 4) != 0)
		{
			box* t1 = new box;
			Line* lu = new Line;
			Line* lw = new Line;
			Line* le = new Line;
			Line* ld = new Line;
			t1->numberbox = j;
			t1->owner = "";

			lu->a = i;
			lu->b = i + 1;

			t1->up = lu;

			lw->a = i;
			lw->b = i + 4;
			t1->west = lw;

			ld->a = i + 4;
			ld->b = i + 5;
			t1->down = ld;

			le->a = i + 1;
			le->b = i + 5;
			t1->east = le;
			map[j] = *t1;
			j++;
		}

	}
}
class Game
{
public:
	box* tabel[9];
	int boxme = 0;
	int boxpc = 0;
	Game()
	{
		for (int i = 0; i < 9; i++)
		{
			box* t = new box;
			t->numberbox = i;
			t->numberlines = 0;
			t->down = 0;
			t->east = 0;
			t->up = 0;
			t->west = 0;
			tabel[i] = t;
		}
	}
	void human()
	{
		//system("cls");
		printtabel();
		cout << "player me:" << boxme << endl;
		cout << "player pc:" << boxpc << endl;
		Line* lm;
		int number1, number2, boxnumber;
		while (true) {

			cout << "from number :"; cin >> number1;
			cout << "to   number :"; cin >> number2;
			lm = new Line;
			lm->a = number1;
			lm->b = number2;
			if (lm->a > lm->b)
			{
				int t = lm->a;
				lm->a = lm->b;
				lm->b = t;
			}
			if (checkline(lm))break;
		}
		playeraddline(lm, "m");
		//system("cls");
		printtabel();
		boxme = countbox(tabel, "m");
		boxpc = countbox(tabel, "p");
		cout << "player me:" << boxme << endl;
		cout << "player pc:" << boxpc << endl;
	}
	void initialtabel()
	{
		for (int i = 0; i < 3; i++)
		{
			Line* l = new Line;
			l->a = i;
			l->b = i + 1;
			playeraddline(l, "");
		}
		int j = 6;
		for (int i = 12; i < 15; i++)
		{
			Line* l = new Line;
			l->a = i;
			l->b = i + 1;
			playeraddline(l, "");
			j++;
		}

		Line* l = new Line;
		l->a = 0;
		l->b = 4;
		playeraddline(l, "");

		Line* l1 = new Line;
		l1->a = 4;
		l1->b = 8;
		playeraddline(l1, "");

		Line* l2 = new Line;
		l2->a = 8;
		l2->b = 12;
		playeraddline(l2, "");



		//---------
		Line* l3 = new Line;
		l3->a = 3;
		l3->b = 7;
		playeraddline(l3, "");


		Line* l4 = new Line;
		l4->a = 7;
		l4->b = 11;
		playeraddline(l4, "");

		Line* l5 = new Line;
		l5->a = 11;
		l5->b = 15;
		playeraddline(l5, "");


	}
	bool checkline(Line* l)
	{
		for (int boxnumber = 0; boxnumber < 9; boxnumber++)
		{
			if (tabel[boxnumber]->down)
				if (l->a == tabel[boxnumber]->down->a && l->b == tabel[boxnumber]->down->b) return false;
			if (tabel[boxnumber]->up)
				if (l->a == tabel[boxnumber]->up->a && l->b == tabel[boxnumber]->up->b)return false;
			if (tabel[boxnumber]->east)
				if (l->a == tabel[boxnumber]->east->a && l->b == tabel[boxnumber]->east->b)return false;
			if (tabel[boxnumber]->west)
				if (l->a == tabel[boxnumber]->west->a && l->b == tabel[boxnumber]->west->b)return false;
		}
		return true;
	}
	void playeraddline(Line* l, string s)
	{
		//0-1
		if (l->a == 0 && l->b == 1)
		{
			tabel[0]->up = l;
			tabel[0]->numberlines += 1;
			if (tabel[0]->numberlines == 4)
				tabel[0]->owner = s;
		}
		//1-2
		if (l->a == 1 && l->b == 2)
		{
			tabel[1]->up = l;
			tabel[1]->numberlines += 1;
			if (tabel[1]->numberlines == 4)
				tabel[1]->owner = s;

		}
		//2-3
		if (l->a == 2 && l->b == 3)
		{
			tabel[2]->up = l;
			tabel[2]->numberlines += 1;
			if (tabel[2]->numberlines == 4)
				tabel[2]->owner = s;
		}
		//0-4
		if (l->a == 0 && l->b == 4)
		{
			tabel[0]->west = l;
			tabel[0]->numberlines += 1;
			if (tabel[0]->numberlines == 4)
				tabel[0]->owner = s;
		}

		//1-5
		if (l->a == 1 && l->b == 5)
		{
			tabel[0]->east = l;
			tabel[1]->west = l;
			tabel[1]->numberlines += 1;
			if (tabel[1]->numberlines == 4)
				tabel[1]->owner = s;
			tabel[0]->numberlines += 1;
			if (tabel[0]->numberlines == 4)
				tabel[0]->owner = s;

		}

		//2-6
		if (l->a == 2 && l->b == 6)
		{
			tabel[1]->east = l;
			tabel[2]->west = l;
			tabel[1]->numberlines += 1;
			tabel[2]->numberlines += 1;
			if (tabel[1]->numberlines == 4)
				tabel[1]->owner = s;
			if (tabel[2]->numberlines == 4)
				tabel[2]->owner = s;

		}

		//3-7
		if (l->a == 3 && l->b == 7)
		{
			tabel[2]->east = l;
			tabel[2]->numberlines += 1;
			if (tabel[2]->numberlines == 4)
				tabel[2]->owner = s;

		}
		//4-5
		if (l->a == 4 && l->b == 5)
		{
			tabel[0]->down = l;
			tabel[3]->up = l;
			tabel[0]->numberlines += 1;
			if (tabel[0]->numberlines == 4)
				tabel[0]->owner = s;
			tabel[3]->numberlines += 1;
			if (tabel[3]->numberlines == 4)
				tabel[3]->owner = s;
		}
		//5-6
		if (l->a == 5 && l->b == 6)
		{
			tabel[1]->down = l;
			tabel[4]->up = l;
			tabel[1]->numberlines += 1;
			tabel[4]->numberlines += 1;
			if (tabel[1]->numberlines == 4)
				tabel[1]->owner = s;
			if (tabel[4]->numberlines == 4)
				tabel[4]->owner = s;
		}


		//6-7
		if (l->a == 6 && l->b == 7)
		{
			tabel[2]->down = l;
			tabel[5]->up = l;
			tabel[2]->numberlines += 1;
			tabel[5]->numberlines += 1;
			if (tabel[2]->numberlines == 4)
				tabel[2]->owner = s;
			if (tabel[5]->numberlines == 4)
				tabel[5]->owner = s;
		}
		//4-8
		if (l->a == 4 && l->b == 8)
		{
			tabel[3]->west = l;
			tabel[3]->numberlines += 1;
			if (tabel[3]->numberlines == 4)
				tabel[3]->owner = s;

		}


		//5-9
		if (l->a == 5 && l->b == 9)
		{
			tabel[3]->east = l;
			tabel[4]->west = l;
			tabel[3]->numberlines += 1;
			tabel[4]->numberlines += 1;
			if (tabel[3]->numberlines == 4)
				tabel[3]->owner = s;
			if (tabel[4]->numberlines == 4)
				tabel[4]->owner = s;

		}
		//6-10
		if (l->a == 6 && l->b == 10)
		{
			tabel[4]->east = l;
			tabel[5]->west = l;
			tabel[4]->numberlines += 1;
			tabel[5]->numberlines += 1;
			if (tabel[4]->numberlines == 4)
				tabel[4]->owner = s;
			if (tabel[5]->numberlines == 4)
				tabel[5]->owner = s;

		}

		//7-11
		if (l->a == 7 && l->b == 11)
		{
			tabel[5]->east = l;
			tabel[5]->numberlines += 1;
			if (tabel[5]->numberlines == 4)
				tabel[5]->owner = s;

		}
		//8-9
		if (l->a == 8 && l->b == 9)
		{
			tabel[3]->down = l;
			tabel[6]->up = l;
			tabel[3]->numberlines += 1;
			tabel[6]->numberlines += 1;
			if (tabel[3]->numberlines == 4)
				tabel[3]->owner = s;
			if (tabel[6]->numberlines == 4)
				tabel[6]->owner = s;
		}


		//9-10
		if (l->a == 9 && l->b == 10)
		{
			tabel[4]->down = l;
			tabel[7]->up = l;
			tabel[4]->numberlines += 1;
			tabel[7]->numberlines += 1;
			if (tabel[4]->numberlines == 4)
				tabel[4]->owner = s;
			if (tabel[7]->numberlines == 4)
				tabel[7]->owner = s;
		}

		//10-11
		if (l->a == 10 && l->b == 11)
		{
			tabel[5]->down = l;
			tabel[8]->up = l;
			tabel[5]->numberlines += 1;
			tabel[8]->numberlines += 1;
			if (tabel[5]->numberlines == 4)
				tabel[5]->owner = s;
			if (tabel[8]->numberlines == 4)
				tabel[8]->owner = s;

		}
		//8-12
		if (l->a == 8 && l->b == 12)
		{
			tabel[6]->west = l;
			tabel[6]->numberlines += 1;
			if (tabel[6]->numberlines == 4)
				tabel[6]->owner = s;
		}

		//9-13
		if (l->a == 9 && l->b == 13)
		{
			tabel[6]->east = l;
			tabel[7]->west = l;
			tabel[6]->numberlines += 1;
			tabel[7]->numberlines += 1;
			if (tabel[6]->numberlines == 4)
				tabel[6]->owner = s;
			if (tabel[7]->numberlines == 4)
				tabel[7]->owner = s;

		}
		//10-14
		if (l->a == 10 && l->b == 14)
		{
			tabel[7]->east = l;
			tabel[8]->west = l;
			tabel[7]->numberlines += 1;
			tabel[8]->numberlines += 1;
			if (tabel[7]->numberlines == 4)
				tabel[7]->owner = s;
			if (tabel[8]->numberlines == 4)
				tabel[8]->owner = s;

		}

		//11-15
		if (l->a == 11 && l->b == 15)
		{
			tabel[8]->east = l;
			tabel[8]->numberlines += 1;
			if (tabel[8]->numberlines == 4)
				tabel[8]->owner = s;


		}
		//12-13
		if (l->a == 12 && l->b == 13)
		{
			tabel[6]->down = l;
			tabel[6]->numberlines += 1;
			if (tabel[6]->numberlines == 4)
				tabel[6]->owner = s;

		}

		//13-14
		if (l->a == 13 && l->b == 14)
		{
			tabel[7]->down = l;
			tabel[7]->numberlines += 1;
			if (tabel[7]->numberlines == 4)
				tabel[7]->owner = s;

		}

		//14-15
		if (l->a == 14 && l->b == 15)
		{
			tabel[8]->down = l;
			tabel[8]->numberlines += 1;
			if (tabel[8]->numberlines == 4)
				tabel[8]->owner = s;

		}

	}
	void printtabel()
	{
		int j = 0;

		for (int i = 0; i < 3; i++)
		{
			cout << "(" << j << " )";
			if (tabel[i]->up)cout << " -- ";
			else cout << setw(5);
			j++;
		}
		cout << "(" << j << " )";
		j++;
		cout << endl;



		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				if (tabel[i]->west)cout << "|" << setw(1) << tabel[i]->owner;

			}
			else
			{
				if (tabel[i]->west)cout << setw(8) << "|" << tabel[i]->owner;
				else
					cout << setw(8) << " ";
			}
		}
		if (tabel[2]->east)cout << setw(8) << "|";
		cout << endl;


		///////-------------------------------------

		for (int i = 3; i < 6; i++)
		{
			cout << "(" << j << " )";
			if (tabel[i]->up)cout << " -- ";
			else cout << setw(5);
			j++;
		}
		cout << "(" << j << " )";
		j++;
		cout << endl;

		for (int i = 3; i < 6; i++)
		{
			if (i == 3)
			{
				if (tabel[i]->west)cout << "|" << setw(1) << tabel[i]->owner;
			}
			else
			{
				if (tabel[i]->west)cout << setw(8) << "|" << tabel[i]->owner;
				else
					cout << setw(8) << " ";
			}
		}
		if (tabel[5]->east)cout << setw(8) << "|";
		cout << endl;


		///////-------------------------------------
		for (int i = 6; i < 9; i++)
		{
			if (j < 10)
				cout << "(" << j << " )";
			else
				cout << "(" << j << ")";
			if (tabel[i]->up)cout << " -- ";
			else cout << setw(5);
			j++;
		}
		cout << "(" << j << ")";
		j++;
		cout << endl;

		for (int i = 6; i < 9; i++)
		{
			if (i == 6)
			{
				if (tabel[i]->west)cout << "|" << setw(1) << tabel[i]->owner;
			}
			else
			{
				if (tabel[i]->west)cout << setw(8) << "|" << tabel[i]->owner;
				else
					cout << setw(8) << " ";
			}
		}
		if (tabel[8]->east)cout << setw(8) << "|";
		cout << endl;


		for (int i = 6; i < 9; i++)
		{
			cout << "(" << j << ")";
			if (tabel[i]->down)cout << " -- ";
			else cout << setw(5);
			j++;
		}
		cout << "(" << j << ")";
		j++;
		cout << endl;


		cout << "--------------------------------" << endl;
	}
	void printt2(box** t)
	{
		int j = 0;

		for (int i = 0; i < 3; i++)
		{
			cout << "(" << j << " )";
			if (t[i]->up)cout << " -- ";
			else cout << setw(5);
			j++;
		}
		cout << "(" << j << " )";
		j++;
		cout << endl;



		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				if (t[i]->west)cout << "|" << setw(1) << t[i]->owner;

			}
			else
			{
				if (t[i]->west)cout << setw(8) << "|" << t[i]->owner;
				else
					cout << setw(8) << " ";
			}
		}
		if (t[2]->east)cout << setw(8) << "|";
		cout << endl;


		///////-------------------------------------

		for (int i = 3; i < 6; i++)
		{
			cout << "(" << j << " )";
			if (t[i]->up)cout << " -- ";
			else cout << setw(5);
			j++;
		}
		cout << "(" << j << " )";
		j++;
		cout << endl;

		for (int i = 3; i < 6; i++)
		{
			if (i == 3)
			{
				if (t[i]->west)cout << "|" << setw(1) << t[i]->owner;
			}
			else
			{
				if (t[i]->west)cout << setw(8) << "|" << t[i]->owner;
				else
					cout << setw(8) << " ";
			}
		}
		if (t[5]->east)cout << setw(8) << "|";
		cout << endl;


		///////-------------------------------------
		for (int i = 6; i < 9; i++)
		{
			if (j < 10)
				cout << "(" << j << " )";
			else
				cout << "(" << j << ")";
			if (t[i]->up)cout << " -- ";
			else cout << setw(5);
			j++;
		}
		cout << "(" << j << ")";
		j++;
		cout << endl;

		for (int i = 6; i < 9; i++)
		{
			if (i == 6)
			{
				if (t[i]->west)cout << "|" << setw(1) << t[i]->owner;
			}
			else
			{
				if (t[i]->west)cout << setw(8) << "|" << t[i]->owner;
				else
					cout << setw(8) << " ";
			}
		}
		if (t[8]->east)cout << setw(8) << "|";
		cout << endl;


		for (int i = 6; i < 9; i++)
		{
			cout << "(" << j << ")";
			if (t[i]->down)cout << " -- ";
			else cout << setw(5);
			j++;
		}
		cout << "(" << j << ")";
		j++;
		cout << endl;


		cout << "--------------------------------" << endl;
	}
	bool emptytabel()
	{
		for (int i = 0; i < 9; i++)
		{
			if (tabel[i]->numberlines < 4)
				return true;
		}
		return false;
	}
	void freetabel()
	{
		for (int i = 0; i < 9; i++)
			delete tabel[i];
	}
	int  countbox(box** b, string s)
	{
		int u = 0;
		for (int i = 0; i < 9; i++)
		{
			if (b[i]->owner == s)
				u++;
		}
		return u;
	}
	void playeraddline2(box** b, Line* l, string s)
	{
		//0-1
		if (l->a == 0 && l->b == 1)
		{
			b[0]->up = l;
			b[0]->numberlines += 1;
			if (b[0]->numberlines == 4)
				b[0]->owner = s;
		}
		//1-2
		if (l->a == 1 && l->b == 2)
		{
			b[1]->up = l;
			b[1]->numberlines += 1;
			if (b[1]->numberlines == 4)
				b[1]->owner = s;

		}
		//2-3
		if (l->a == 2 && l->b == 3)
		{
			b[2]->up = l;
			b[2]->numberlines += 1;
			if (b[2]->numberlines == 4)
				b[2]->owner = s;
		}
		//0-4
		if (l->a == 0 && l->b == 4)
		{
			b[0]->west = l;
			b[0]->numberlines += 1;
			if (b[0]->numberlines == 4)
				b[0]->owner = s;
		}

		//1-5
		if (l->a == 1 && l->b == 5)
		{
			b[0]->east = l;
			b[1]->west = l;
			b[1]->numberlines += 1;
			if (b[1]->numberlines == 4)
				b[1]->owner = s;
			b[0]->numberlines += 1;
			if (b[0]->numberlines == 4)
				b[0]->owner = s;

		}

		//2-6
		if (l->a == 2 && l->b == 6)
		{
			b[1]->east = l;
			b[2]->west = l;
			b[1]->numberlines += 1;
			b[2]->numberlines += 1;
			if (b[1]->numberlines == 4)
				b[1]->owner = s;
			if (b[2]->numberlines == 4)
				b[2]->owner = s;

		}

		//3-7
		if (l->a == 3 && l->b == 7)
		{
			b[2]->east = l;
			b[2]->numberlines += 1;
			if (b[2]->numberlines == 4)
				b[2]->owner = s;

		}
		//4-5
		if (l->a == 4 && l->b == 5)
		{
			b[0]->down = l;
			b[3]->up = l;
			b[0]->numberlines += 1;
			if (b[0]->numberlines == 4)
				b[0]->owner = s;
			b[3]->numberlines += 1;
			if (b[3]->numberlines == 4)
				b[3]->owner = s;
		}
		//5-6
		if (l->a == 5 && l->b == 6)
		{
			b[1]->down = l;
			b[4]->up = l;
			b[1]->numberlines += 1;
			b[4]->numberlines += 1;
			if (b[1]->numberlines == 4)
				b[1]->owner = s;
			if (b[4]->numberlines == 4)
				b[4]->owner = s;
		}


		//6-7
		if (l->a == 6 && l->b == 7)
		{
			b[2]->down = l;
			b[5]->up = l;
			b[2]->numberlines += 1;
			b[5]->numberlines += 1;
			if (b[2]->numberlines == 4)
				b[2]->owner = s;
			if (b[5]->numberlines == 4)
				b[5]->owner = s;
		}
		//4-8
		if (l->a == 4 && l->b == 8)
		{
			b[3]->west = l;
			b[3]->numberlines += 1;
			if (b[3]->numberlines == 4)
				b[3]->owner = s;

		}


		//5-9
		if (l->a == 5 && l->b == 9)
		{
			b[3]->east = l;
			b[4]->west = l;
			b[3]->numberlines += 1;
			b[4]->numberlines += 1;
			if (b[3]->numberlines == 4)
				b[3]->owner = s;
			if (b[4]->numberlines == 4)
				b[4]->owner = s;

		}
		//6-10
		if (l->a == 6 && l->b == 10)
		{
			b[4]->east = l;
			b[5]->west = l;
			b[4]->numberlines += 1;
			b[5]->numberlines += 1;
			if (b[4]->numberlines == 4)
				b[4]->owner = s;
			if (b[5]->numberlines == 4)
				b[5]->owner = s;

		}

		//7-11
		if (l->a == 7 && l->b == 11)
		{
			b[5]->east = l;
			b[5]->numberlines += 1;
			if (b[5]->numberlines == 4)
				b[5]->owner = s;

		}
		//8-9
		if (l->a == 8 && l->b == 9)
		{
			b[3]->down = l;
			b[6]->up = l;
			b[3]->numberlines += 1;
			b[6]->numberlines += 1;
			if (b[3]->numberlines == 4)
				b[3]->owner = s;
			if (b[6]->numberlines == 4)
				b[6]->owner = s;
		}


		//9-10
		if (l->a == 9 && l->b == 10)
		{
			b[4]->down = l;
			b[7]->up = l;
			b[4]->numberlines += 1;
			b[7]->numberlines += 1;
			if (b[4]->numberlines == 4)
				b[4]->owner = s;
			if (b[7]->numberlines == 4)
				b[7]->owner = s;
		}

		//10-11
		if (l->a == 10 && l->b == 11)
		{
			b[5]->down = l;
			b[8]->up = l;
			b[5]->numberlines += 1;
			b[8]->numberlines += 1;
			if (b[5]->numberlines == 4)
				b[5]->owner = s;
			if (b[8]->numberlines == 4)
				b[8]->owner = s;

		}
		//8-12
		if (l->a == 8 && l->b == 12)
		{
			b[6]->west = l;
			b[6]->numberlines += 1;
			if (b[6]->numberlines == 4)
				b[6]->owner = s;
		}

		//9-13
		if (l->a == 9 && l->b == 13)
		{
			b[6]->east = l;
			b[7]->west = l;
			b[6]->numberlines += 1;
			b[7]->numberlines += 1;
			if (b[6]->numberlines == 4)
				b[6]->owner = s;
			if (b[7]->numberlines == 4)
				b[7]->owner = s;

		}
		//10-14
		if (l->a == 10 && l->b == 14)
		{
			b[7]->east = l;
			b[8]->west = l;
			b[7]->numberlines += 1;
			b[8]->numberlines += 1;
			if (b[7]->numberlines == 4)
				b[7]->owner = s;
			if (b[8]->numberlines == 4)
				b[8]->owner = s;

		}

		//11-15
		if (l->a == 11 && l->b == 15)
		{
			b[8]->east = l;
			b[8]->numberlines += 1;
			if (b[8]->numberlines == 4)
				b[8]->owner = s;


		}
		//12-13
		if (l->a == 12 && l->b == 13)
		{
			b[6]->down = l;
			b[6]->numberlines += 1;
			if (b[6]->numberlines == 4)
				b[6]->owner = s;

		}

		//13-14
		if (l->a == 13 && l->b == 14)
		{
			b[7]->down = l;
			b[7]->numberlines += 1;
			if (b[7]->numberlines == 4)
				b[7]->owner = s;

		}

		//14-15
		if (l->a == 14 && l->b == 15)
		{
			b[8]->down = l;
			b[8]->numberlines += 1;
			if (b[8]->numberlines == 4)
				b[8]->owner = s;

		}

	}

	Line* minmax()
	{
		valuse* p = minv(tabel, 0);
		//Line* o = chck3(tabel);
		//if (o)return o;
		return p->l;
	}
	valuse* maxv(box** newtabel, Line* ln)
	{
		cout << "maxv" << endl;
		//printt2(newtabel);
		//cout << countbox(newtabel, "m") << "/max/" << countbox(newtabel, "p") << endl;
		if ((countbox(newtabel, "m") + countbox(newtabel, "p")) == 9)
		{
			//cout << "iam in max " << endl;
			valuse* v = new valuse;
			v->l = ln;
			v->boxpc = countbox(newtabel, "p");
			v->boxme = countbox(newtabel, "m");
			v->sum = v->boxpc - v->boxme;
			return v;
		}
		int v = -1000;
		valuse* local = new valuse;
		local = 0;
		valuse* best = new valuse;
		best = 0;
		for (int i = 0; i < 9; i++)
		{
			if (!newtabel[i]->up)
			{
				Line* l = map[i].up;
				playeraddline2(newtabel, l, "p");
				if (!local)
					local = minv(newtabel, l);
				else
				{
					if (local->sum >= v)
					{
						best = local;
						v = best->sum;
					}
				}
				removeline(newtabel, l);
			}
			//
			if (!newtabel[i]->down)
			{
				Line* l = map[i].down;
				playeraddline2(newtabel, l, "p");
				if (!local)
					local = minv(newtabel, l);
				else
				{
					if (local->sum >= v)
					{
						best = local;
						v = best->sum;
					}
				}
				removeline(newtabel, l);
			}
			//
			if (!newtabel[i]->east)
			{
				Line* l = map[i].east;
				playeraddline2(newtabel, l, "p");
				if (!local)
					local = minv(newtabel, l);
				else
				{
					if (local->sum >= v)
					{
						best = local;
						v = best->sum;
					}
				}
				removeline(newtabel, l);
			}
			//
			if (!newtabel[i]->west)
			{
				Line* l = map[i].west;
				playeraddline2(newtabel, l, "p");
				if (!local)
					local = minv(newtabel, l);
				else
				{
					if (local->sum >= v)
					{
						best = local;
						v = best->sum;
					}
				}
				removeline(newtabel, l);
			}

		}
		return best;

	}
	valuse* minv(box** newtabel, Line* ln)
	{
		cout << "minv" << endl;
		//cout << countbox(newtabel, "m") << "/min/" << countbox(newtabel, "p") << endl;
		//printt2(newtabel);
		if (countbox(newtabel, "m") + countbox(newtabel, "p") == 9)
		{
			//cout << "iam in min " << endl;
			valuse* v = new valuse;
			v->l = ln;
			v->boxpc = countbox(newtabel, "p");
			v->boxme = countbox(newtabel, "m");
			//cout << v->boxme << "       " << v->boxpc <<endl;
			return v;
		}
		int v = 1000;
		valuse* local = new valuse;
		valuse* best = new valuse;
		local = 0;
		best = 0;
		for (int i = 0; i < 9; i++)
		{
			if (!newtabel[i]->up)
			{
				Line* l = map[i].up;
				playeraddline2(newtabel, l, "m");
				if (!local)
					local = maxv(newtabel, l);
				else
				{
					if (local->sum <= v)
					{
						best = local;
						v = best->sum;
					}
				}
				removeline(newtabel, l);
			}
			//
			if (!newtabel[i]->down)
			{
				Line* l = map[i].down;
				playeraddline2(newtabel, l, "m");
				if (!local)
					local = maxv(newtabel, l);
				else
				{
					if (local->sum <= v)
					{
						best = local;
						v = best->sum;
					}
				}
				removeline(newtabel, l);
			}



			//
			if (!newtabel[i]->east)
			{
				Line* l = map[i].east;
				playeraddline2(newtabel, l, "m");
				if (!local)
					local = maxv(newtabel, l);
				else
				{
					if (local->sum <= v)
					{
						best = local;
						v = best->sum;
					}
				}
				removeline(newtabel, l);
			}





			//
			if (!newtabel[i]->west)
			{
				Line* l = map[i].west;
				playeraddline2(newtabel, l, "m");
				if (!local)
					local = maxv(newtabel, l);
				else
				{
					if (local->sum <= v)
					{
						best = local;
						v = best->sum;
					}
				}
				removeline(newtabel, l);
			}

		}
		return best;
	}
	void removeline(box** b, Line* l)
	{

		for (int i = 0; i < 9; i++)
		{
			if (b[i]->up)
				if (b[i]->up->a == l->a && b[i]->up->b == l->b)
				{
					b[i]->up = NULL;
					b[i]->owner = "";
					b[i]->numberlines--;
					//printt2(b);
				}
			if (b[i]->down)
				if (b[i]->down->a == l->a && b[i]->down->b == l->b)
				{
					b[i]->owner = "";
					b[i]->numberlines--;
					b[i]->down = NULL;
					// printt2(b);
				}
			if (b[i]->east)
				if (b[i]->east->a == l->a && b[i]->east->b == l->b)
				{
					b[i]->owner = "";
					b[i]->numberlines--;
					b[i]->east = NULL;
					// printt2(b);
				}
			if (b[i]->west)
				if (b[i]->west->a == l->a && b[i]->west->b == l->b)
				{
					b[i]->owner = "";
					b[i]->numberlines--;
					b[i]->west = NULL;
					// printt2(b);
				}
		}

	}
	Line* chck3(box** b)
	{
		for(int i=0;i<9;i++)
			if (b[i]->numberlines == 3)
			{
				if (!b[i]->up)return map[i].up;
				if (!b[i]->down)return map[i].down;
				if (!b[i]->east)return map[i].east;
				if (!b[i]->west)return map[i].west;
			}


		/// <summary>
		for (int i = 0; i < 9; i++)
			if (b[i]->numberlines == 1|| b[i]->numberlines == 0)
			{
				if (i == 0)
				{
					if (!b[i]->up)return map[i].up;
					if (!b[i]->west)return map[i].west;
				}
				if (i == 1)
				{
					if (!b[i]->up)return map[i].up;
					if (b[i - 1]->numberlines != 2)if (!b[i]->west)return map[i].west;
					if (b[i+3]->numberlines != 2)if (!b[i]->down)return map[i].down;
					if (b[i +1]->numberlines != 2)if (!b[i]->east)return map[i].east;

				}


				if (i == 2)
				{
					if (!b[i]->up)return map[i].up;
					if (!b[i]->east)return map[i].east;
					if (b[i - 1]->numberlines != 2)if (!b[i]->west)return map[i].west;
					if (b[i + 3]->numberlines != 2)if (!b[i]->down)return map[i].down;

				}
				if (i == 3)
				{
					if (!b[i]->west)return map[i].west;
					if (b[i + 1]->numberlines != 2)if (!b[i]->east)return map[i].east;
					if (b[i -3]->numberlines != 2)if (!b[i]->up)return map[i].up;
					if (b[i +3]->numberlines != 2)if (!b[i]->down)return map[i].down;

				}
				if (i == 4)
				{
					if (b[i -1]->numberlines != 2)if (!b[i]->west)return map[i].west;
					if (b[i +1 ]->numberlines != 2)if (!b[i]->east)return map[i].east;
					if (b[i - 3]->numberlines != 2)if (!b[i]->up)return map[i].up;
					if (b[i + 3]->numberlines != 2)if (!b[i]->down)return map[i].down;

				}
				if (i == 5)
				{
					if (!b[i]->east)return map[i].east;
					if (b[i - 1]->numberlines != 2)if (!b[i]->west)return map[i].west;
					if (b[i - 3]->numberlines != 2)if (!b[i]->up)return map[i].up;
					if (b[i + 3]->numberlines != 2)if (!b[i]->down)return map[i].down;

				}
				if (i == 6)
				{
					if (!b[i]->down)return map[i].down;
					if (!b[i]->west)return map[i].west;
					if (b[i + 1]->numberlines != 2)if (!b[i]->east)return map[i].east;
					if (b[i - 3]->numberlines != 2)if (!b[i]->up)return map[i].up;

				}
				if (i == 7)
				{
					if (!b[i]->down)return map[i].down;
					if (b[i - 1]->numberlines != 2)if (!b[i]->west)return map[i].west;
					if (b[i + 1]->numberlines != 2)if (!b[i]->east)return map[i].east;
					if (b[i - 3]->numberlines != 2)if (!b[i]->up)return map[i].up;

				}
				if (i == 8)
				{
					if (!b[i]->down)return map[i].down;
					if (!b[i]->east)return map[i].east;
					if (b[i - 1]->numberlines != 2)if (!b[i]->west)return map[i].west;
					if (b[i - 3]->numberlines != 2)if (!b[i]->up)return map[i].up;
				}
			}
	
		for (int i = 0; i < 9; i++)
			if (b[i]->numberlines == 2)
			{
				if (!b[i]->up)return map[i].up;
				if (!b[i]->down)return map[i].down;
				if (!b[i]->east)return map[i].east;
				if (!b[i]->west)return map[i].west;
			}
		return 0;
	}
};
int main()
{
	Game g;
	//g.initialtabel();
	setmap();
	Line* lp;
	while (g.boxme + g.boxpc < 9)
	{	
		g.human();
		lp = g.minmax();
		if (lp)
			g.playeraddline(lp, "p");
		g.boxme = g.countbox(g.tabel, "m");
		g.boxpc = g.countbox(g.tabel, "p");
	}
	system("cls");
	g.printtabel();
	cout << "player me:" << g.boxme << endl;
	cout << "player pc:" << g.boxpc << endl;
	cout << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 6;
vector<vector<string>> table(N);

class Game
{
	private:
		int x;
		int y;

	public:
		void createTable(vector<vector<string>>& table)
		{
			table.assign(N, vector<string>(N, "."));
		}
		void checkCoordinates(vector<vector<string>>& table)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cout << "(" + to_string(i) + "," + to_string(j) + ")" << " ";
				}
				cout << endl;
			}
		}
		void showTable(vector<vector<string>>& table)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cout.width(4); cout << table[i][j] << " ";
				}
				cout << endl;
			}
		}
		void move(vector<vector<string>> &table)
		{
			cout << "x: "; cin >> x;
			cout << "\ny: "; cin >> y;
			if (x <= -6 || x >= 6 || y <= -6 || y >= 6)
			{
				cout << "Out of bounds. You lose!" << endl;
				exit(0);
			}
			else
			{
				table[x][y] = "P";
			}
		}
};
int main()
{
	Game game;
	game.createTable(table);
	game.showTable(table);
	while (true)
	{
		cout << "Coordinates: " << endl;
		game.checkCoordinates(table);
		game.move(table);
		game.showTable(table);
		game.createTable(table);
	}
}


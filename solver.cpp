#include <bits/stdc++.h>
using namespace std;

map<vector<vector< int >>, int> m1;
map<int, vector<vector< int>>> m2;
int counter = 0;
int head[100000] = { 0 };
int t1 = 1;
bool found = false;

struct twoVal
{
	int first;
	int second;

	twoVal(int a, int b)
	{
		first = a;
		second = b;
	}
};
vector<vector < int>> initial_state = {
		{ 1, 2, 3 },
	{ 8, -1, 4 },
	{ 7, 6, 5 }
};
vector<vector < int>> prev_state = initial_state;
vector<vector < int>> goal_state = {
		{ 2, 8, 1 },
	{-1, 4, 3
	},
	{ 7, 6, 5 }
};

queue<pair<vector< vector< int >>, twoVal>> visited;

void print(vector<vector < int>> temp)
{
  
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << temp[i][j] << " ";
		}

		cout << endl;
	}

	cout << "....................................................." << endl;
}

bool check(vector<vector < int>> inp)
{
	if (inp == goal_state) return true;
	else return false;
}

void swap(vector<vector < int>> inp, twoVal bi, int a, int b)
{
	int temp;
	temp = inp[bi.first + a][bi.second + b];
	inp[bi.first + a][bi.second + b] = inp[bi.first][bi.second];
	inp[bi.first][bi.second] = temp;

	bi.first += a;
	bi.second += b;

	if (inp != prev_state)
	{
		head[::counter] = t1;

		m1.insert({ inp, ::counter });
		m2.insert({::counter, inp });
		visited.push({ inp, bi });
		if (check(inp) == true)
		{
			print(inp);
			found = true;
			return;
		}
		else
		{::counter++;

		}
	}
}

void bfs(vector<vector < int>> inp, twoVal bi)
{
	t1 = m1.at(inp);
	prev_state = inp;

	if ((bi.first - 1) >= 0)
	{
		swap(inp, bi, -1, 0);
		if (found == true) return;

	}

	if ((bi.first + 1) <= 2)
	{
		swap(inp, bi, 1, 0);
		if (found == true) return;
	}

	if ((bi.second + 1) <= 2)
	{
		swap(inp, bi, 0, 1);
		if (found == true) return;

	}

	if ((bi.second - 1) >= 0)
	{
		swap(inp, bi, 0, -1);
		if (found == true) return;

	}

	if (visited.empty() == true) return;
	pair<vector<vector< int >>, twoVal> tempvec = { visited.front().first, visited.front().second
	};
	visited.pop();
	bfs(tempvec.first, tempvec.second);

}

int main()
{
	m1.insert({ initial_state, 0 });
	m2.insert({ 0, initial_state });::counter = 1;
	bfs(initial_state,{1, 1 });

	if (found == false)
	{
		cout << "not possible";

	}
	else
	{
		while (true)
		{
			print(m2.at(::counter));
      ::counter = head[::counter];
			if (::counter == 0) break;
		}

		print(m2.at(0));
	}

	return 0;

}

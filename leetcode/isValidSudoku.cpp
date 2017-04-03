#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board){
	set<char> hori_numbers;
	set<char> vert_numbers;
	set<char> grid_numbers;

	for(int i = 0; i < board.size(); ++i){
		for(int j = 0; j < board[0].size(); ++j){
			if(hori_numbers.find(board[i][j]) != hori_numbers.end() && board[i][j] != '.') return false;
			else hori_numbers.insert(board[i][j]);

			if(vert_numbers.find(board[j][i]) != vert_numbers.end() && board[j][i] != '.') return false;
			else vert_numbers.insert(board[j][i]);

		}
		hori_numbers.clear();
		vert_numbers.clear();
	}

	for(int row = 3; row <= board.size(); row += 3){
		for(int col = 3; col <= board[0].size(); col +=3){
			for(int i = row - 3; i < row; ++i){
				for (int j = col - 3; j < col; ++j){
					cout << i << " " << j << endl;
					if(board[i][j] == '.') continue;
					if(grid_numbers.find(board[i][j]) != grid_numbers.end()) return false;
					else grid_numbers.insert(board[i][j]);
				}
			}
			grid_numbers.clear();
		}
	}
	return true;
}

int main(){
	vector<string> input = {"......5..",".........",".........","93..2.4..","..7...3..",".........","...34....",".....3...",".....52.."};
	vector<vector<char>> board;
	for(auto s:input)
		cout << s << endl;
	for (auto s:input){
		vector<char> str;
		for(auto c : s){
			str.push_back(c);
		}
		board.push_back(str);
	}
	cout << isValidSudoku(board) << endl;
	return 0;
}

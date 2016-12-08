#pragma once
#include <vector>
#include <string>

using namespace std;

class Puzzle
{
	//Button commands
	static const int NOTHING=0, MOVE_U=1, MOVE_R=2, MOVE_D=3, MOVE_L=4, JUMP_U=5, JUMP_D=6, ROT_R=7, ROT_L=8, REV=9, SET_U=10, SET_R=11, SET_D=12, SET_L=13,
		MOVE_S=14, HIDE_U=15, HIDE_R=16, HIDE_D=17, HIDE_L=18, SHOW=19, MOVE_UL=20, MOVE_UR=21;
	//Square commands
	static const int SQ_NOTHING=0, SQ_FREEZE=1, SQ_ROT_R=2, SQ_REV=3, SQ_ROT_L=4, SQ_JUMP_U=5, SQ_JUMP_D=6, SQ_SET_U=7, SQ_SET_R=8, SQ_SET_D=9, SQ_SET_L=10, SQ_FLIP_X=11, SQ_FLIP_Y=12;

	//Puzzle number
	int number;

	//Movement details
	int rot, jump, min_jump, max_jump, set;
	
	//Level details
	int redx, redy, bluex, bluey;

	//0,1,2,3=up, right, down, left
	int commands[4];
	int fixed_jumps[4];

	//Level mechanics
	bool jump_cycle, rot_on_move_r, rot_on_move_l, rot_on_press_r, rot_on_press_l, rev_on_move, rev_on_press, command_rotate, jump_u_on_move, jump_d_on_move, wrapping;
	int col_adjust, row_adjust;
	bool light_puzzle, dark_puzzle, dark, xhit, solved, frozen;
	
	//Squares
	vector<pair<int, int>> ysq, psq, gsq;
	int yellow_cmd, grey_cmd, pink_cmd;
	
	//Position
	int circle_x, circle_y, hide_x, hide_y;

	string message, message2;
	bool no_more_puzzles;

	//Called when setting/resetting level
	void default_all()
	{
		no_more_puzzles = false;
		rot = 0;
		jump = 1;
		min_jump = 1;
		max_jump = 4;
		set = 0;
		redx = 1;
		redy = 7;
		bluex = 7;
		bluey = 1;
		ysq.clear();
		psq.clear();
		gsq.clear();
		for(int i=0; i<4; i++)
		{
			fixed_jumps[i]=0;
			commands[i]=0;
		}
		jump_cycle = false;
		rot_on_move_r = false;
		rot_on_move_l = false;
		rot_on_press_l = false;
		rot_on_press_r = false;
		rev_on_move = false;
		rev_on_press = false;
		command_rotate = false;
		jump_u_on_move = false;
		jump_d_on_move = false;
		wrapping = false;
		col_adjust = 0;
		row_adjust = 0;
		ysq.clear();
		psq.clear();
		gsq.clear();
		yellow_cmd = 0;
		grey_cmd = 0;
		pink_cmd = 0;
		circle_x = 4;
		circle_y = 4;
		hide_x = 4;
		hide_y = 4;
		light_puzzle = false;
		dark_puzzle = false;
		dark = false;
		xhit = false;
		solved = false;
		frozen = false;
		message = "";
		message2 = "";
	}

	//Contains control for all button presses based on level mechanics
	void button_pressed(int command, int key_num);
	//Contains control for all square hits, called from button_pressed
	void square_hit(int command);

	void load_square_pattern(int pattern);

public:
	Puzzle(int n)
	{
		number = n;
	}

	void set_number(int n)
	{
		number = n;
	}

	void next_puzzle()
	{
		number++;
	}

	//Called every time a puzzle is reset/set
	void set_puzzle();

	//Called from main to tell when a button is pressed
	void press_up() {button_pressed(commands[0], 0);}
	void press_right() {button_pressed(commands[1], 1);}
	void press_down() {button_pressed(commands[2], 2);}
	void press_left() {button_pressed(commands[3], 3);}

	//Getters for display
	int get_circle_x() {return circle_x;}
	int get_circle_y() {return circle_y;}
	bool get_xhit() {return xhit;}
	bool get_solved() {return solved;}
	bool get_dark() {return dark;}
	vector<pair<int,int>> get_ysq() {return ysq;}
	vector<pair<int,int>> get_psq() {return psq;}
	vector<pair<int,int>> get_gsq() {return gsq;}
	int get_redx() {return redx;}
	int get_redy() {return redy;}
	int get_bluex() {return bluex;}
	int get_bluey() {return bluey;}
	string get_message() {return message;}
	string get_message2() { return message2; }
	bool are_no_more_puzzles() {return no_more_puzzles;}
};

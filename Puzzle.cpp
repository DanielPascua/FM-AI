#include "Puzzle.h"


void Puzzle::set_puzzle()
{
	default_all();
	int temp_int(0), int2(0), int3(0), int4(0);
	switch(number)
	{
	case 1:
		commands[0] = Puzzle::MOVE_L;
		commands[1] = Puzzle::MOVE_U;
		commands[2] = Puzzle::MOVE_R;
		commands[3] = Puzzle::MOVE_D;
		message = "Level 1-1. Introductory level. Use the arrows to move from the red x to the blue x.";
		message2 = "Press R to reset. Skip puzzles with 0 (not recommended).";
		break;

	case 2:
		commands[0] = Puzzle::MOVE_D;
		commands[1] = Puzzle::MOVE_L;
		commands[2] = Puzzle::MOVE_U;
		commands[3] = Puzzle::MOVE_R;
		message = "Level 1-2. Introductory level.";
		message2 = "Use the arrows to move from the red x to the blue x.";
		break;

	case 3:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::ROT_R;
		commands[2] = Puzzle::MOVE_D;
		commands[3] = Puzzle::ROT_L;
		message = "Level 2-1. Key concepts.";
		message2 = "The arrow keys function differently than in level 1.";
		break;

	case 4:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::MOVE_R;
		commands[2] = Puzzle::ROT_R;
		commands[3] = Puzzle::MOVE_L;
		redx = 7;
		redy = 7;
		bluex = 1;
		bluey = 1;
		message = "Level 2-2. Key concepts.";
		message2 = "";
		break;

	case 5:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::JUMP_U;
		commands[2] = Puzzle::ROT_R;
		commands[3] = Puzzle::JUMP_D;
		jump = 2;
		redx = 7;
		redy = 1;
		bluex = 1;
		bluey = 7;
		message = "Level 2-3. Key concepts - the first hurdle.";
		message2 = "Many people struggle here. Good luck!";
		break;

	case 6:
		commands[0] = Puzzle::NOTHING;
		commands[1] = Puzzle::ROT_L;
		commands[2] = Puzzle::ROT_R;
		commands[3] = Puzzle::MOVE_D;
		message = "Level 3-1.";
		message2 = "If you understood level 2, this level shouldn't be much problem.";
		break;

	case 7:
		commands[0] = Puzzle::ROT_R;
		commands[1] = Puzzle::MOVE_L;
		commands[2] = Puzzle::MOVE_R;
		commands[3] = Puzzle::MOVE_U;
		message = "Level 3-2.";
		message2 = "";
		break;

	case 8:
		commands[0] = Puzzle::JUMP_U;
		commands[1] = Puzzle::JUMP_D;
		commands[2] = Puzzle::MOVE_L;
		commands[3] = Puzzle::ROT_R;
		jump = 2;
		min_jump = 2;
		max_jump = 3;
		redx = 7;
		redy = 7;
		bluex = 1;
		bluey = 1;
		message = "Level 3-3.";
		message2 = "";
		break;

	case 9:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::NOTHING;
		commands[2] = Puzzle::MOVE_U;
		commands[3] = Puzzle::NOTHING;
		fixed_jumps[0] = 1;
		fixed_jumps[2] = 2;
		rot_on_move_r = true;
		message = "Level 4-1. Alternative movement.";
		message2 = "This level has movement that is harder to understand.";
		break;

	case 10:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::MOVE_R;
		commands[2] = Puzzle::MOVE_D;
		commands[3] = Puzzle::MOVE_L;
		row_adjust = true;
		message = "Level 4-2. Alternative movement.";
		message2 = "";
		break;

	case 11:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::NOTHING;
		commands[2] = Puzzle::JUMP_U;
		commands[3] = Puzzle::JUMP_U;
		yellow_cmd = Puzzle::SQ_ROT_L;
		grey_cmd = Puzzle::SQ_JUMP_D;
		pink_cmd = Puzzle::SQ_ROT_R;
		load_square_pattern(1);
		jump = 3;
		message = "Level 5-1. Colored squares. Landing on a colored square may affect your movement.";
		message2 = "Squares of the same color all have the same effect.";
		break;

	case 12:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::JUMP_D;
		commands[2] = Puzzle::JUMP_D;
		commands[3] = Puzzle::NOTHING;
		yellow_cmd = Puzzle::SQ_ROT_R;
		grey_cmd = Puzzle::SQ_JUMP_U;
		pink_cmd = Puzzle::SQ_ROT_L;
		load_square_pattern(1);
		jump = 2;
		message = "Level 5-2. Colored squares.";
		message2 = "";
		break;

	case 13:
		commands[0] = Puzzle::NOTHING;
		commands[1] = Puzzle::MOVE_R;
		commands[2] = Puzzle::MOVE_D;
		commands[3] = Puzzle::NOTHING;
		yellow_cmd = Puzzle::SQ_REV;
		grey_cmd = Puzzle::SQ_FREEZE;
		pink_cmd = Puzzle::SQ_JUMP_U;
		load_square_pattern(1);
		message = "Level 5-3. Colored squares. All 3 levels used the same square layout.";
		message2 = "Did you notice?";
		break;

	case 14:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::JUMP_D;
		commands[2] = Puzzle::NOTHING;
		commands[3] = Puzzle::JUMP_U;
		yellow_cmd = Puzzle::SQ_ROT_L;
		grey_cmd = Puzzle::SQ_ROT_R;
		ysq.push_back(make_pair(0, 7));
		ysq.push_back(make_pair(0, 8));
		ysq.push_back(make_pair(1, 8));
		ysq.push_back(make_pair(2, 5));
		ysq.push_back(make_pair(4, 5));
		ysq.push_back(make_pair(5, 0));
		ysq.push_back(make_pair(6, 7));
		gsq.push_back(make_pair(0, 5));
		gsq.push_back(make_pair(1, 6));
		gsq.push_back(make_pair(2, 1));
		gsq.push_back(make_pair(3, 0));
		gsq.push_back(make_pair(4, 1));
		gsq.push_back(make_pair(4, 7));
		gsq.push_back(make_pair(6, 8));
		gsq.push_back(make_pair(7, 6));
		gsq.push_back(make_pair(7, 7));
		gsq.push_back(make_pair(8, 0));
		gsq.push_back(make_pair(8, 8));
		message = "Level 5-4. Colored squares.";
		message2 = "";
		break;

	case 15:
		commands[0] = Puzzle::ROT_L;
		commands[1] = Puzzle::MOVE_R;
		commands[2] = Puzzle::MOVE_D;
		commands[3] = Puzzle::MOVE_L;
		dark_puzzle = true;
		redx = 1;
		redy = 1;
		bluex = 7;
		bluey = 7;
		message = "Level 6-1. Introduction to dark puzzles. The first level of dark puzzles.";
		message2 = "Your location is hidden every other button press.";
		break;

	case 16:
		commands[0] = Puzzle::MOVE_D;
		commands[1] = Puzzle::MOVE_U;
		commands[2] = Puzzle::MOVE_L;
		commands[3] = Puzzle::MOVE_R;
		dark_puzzle = true;
		redx = 7;
		redy = 7;
		bluex = 1;
		bluey = 1;
		message = "Level 6-2. Introduction to dark puzzles.";
		message2 = "";
		break;

	case 17:
		commands[0] = Puzzle::MOVE_U;
		commands[2] = Puzzle::NOTHING;
		commands[1] = Puzzle::MOVE_U;
		commands[3] = Puzzle::NOTHING;
		fixed_jumps[0] = 2;
		fixed_jumps[1] = 1;
		rot_on_move_l = true;
		dark_puzzle = true;
		redx = 7;
		redy = 1;
		bluex = 1;
		bluey = 7;
		message = "Level 6-3. Introduction to dark puzzles.";
		message2 = "";
		break;

	case 18:
		commands[0] = Puzzle::NOTHING;
		commands[1] = Puzzle::ROT_L;
		commands[2] = Puzzle::MOVE_L;
		commands[3] = Puzzle::JUMP_U;
		jump = 2;
		max_jump = 4;
		jump_cycle = true;
		dark_puzzle = true;
		message = "Level 6-4. Introduction to dark puzzles.";
		message2 = "";
		break;

	case 19:
		commands[0] = Puzzle::JUMP_U;
		commands[1] = Puzzle::ROT_R;
		commands[2] = Puzzle::MOVE_U;
		commands[3] = Puzzle::JUMP_D;
		light_puzzle = true;
		ysq.push_back(make_pair(4, 4));
		ysq.push_back(make_pair(4, 8));
		ysq.push_back(make_pair(0, 8));
		yellow_cmd = Puzzle::SQ_NOTHING;
		jump = 2;
		message = "Level 7-1. Introduction to light puzzles. The first level of light puzzles.";
		message2 = "If you are not on a yellow square, your location is hidden.";
		break;

	case 20:
		commands[0] = Puzzle::REV;
		commands[1] = Puzzle::MOVE_L;
		commands[2] = Puzzle::MOVE_U;
		commands[3] = Puzzle::JUMP_U;
		jump_cycle = true;
		light_puzzle = true;
		max_jump = 2;
		ysq.push_back(make_pair(0, 0));
		ysq.push_back(make_pair(0, 8));
		ysq.push_back(make_pair(3, 3));
		ysq.push_back(make_pair(3, 5));
		ysq.push_back(make_pair(4, 4));
		ysq.push_back(make_pair(5, 3));
		ysq.push_back(make_pair(5, 5));
		ysq.push_back(make_pair(8, 0));
		ysq.push_back(make_pair(8, 8));
		yellow_cmd = Puzzle::SQ_NOTHING;

		gsq.push_back(make_pair(0, 5));
		gsq.push_back(make_pair(0, 3));
		gsq.push_back(make_pair(1, 5));
		gsq.push_back(make_pair(1, 3));
		gsq.push_back(make_pair(2, 5));
		gsq.push_back(make_pair(2, 3));
		gsq.push_back(make_pair(3, 0));
		gsq.push_back(make_pair(3, 1));
		gsq.push_back(make_pair(3, 2));
		gsq.push_back(make_pair(3, 6));
		gsq.push_back(make_pair(3, 7));
		gsq.push_back(make_pair(3, 8));
		gsq.push_back(make_pair(8, 5));
		gsq.push_back(make_pair(8, 3));
		gsq.push_back(make_pair(7, 5));
		gsq.push_back(make_pair(7, 3));
		gsq.push_back(make_pair(6, 5));
		gsq.push_back(make_pair(6, 3));
		gsq.push_back(make_pair(5, 0));
		gsq.push_back(make_pair(5, 1));
		gsq.push_back(make_pair(5, 2));
		gsq.push_back(make_pair(5, 6));
		gsq.push_back(make_pair(5, 7));
		gsq.push_back(make_pair(5, 8));
		grey_cmd = Puzzle::SQ_FREEZE;
		message = "Level 7-2. Introduction to light puzzles.";
		message2 = "";
		break;

	case 21:
		commands[0] = Puzzle::SET_L;
		commands[1] = Puzzle::MOVE_S;
		commands[2] = Puzzle::SET_R;
		commands[3] = Puzzle::SET_D;
		light_puzzle = true;
		ysq.push_back(make_pair(4, 4));
		ysq.push_back(make_pair(4, 8));
		ysq.push_back(make_pair(0, 8));
		yellow_cmd = Puzzle::SQ_NOTHING;
		message = "Level 7-3. Introduction to light puzzles.";
		message2 = "";
		break;

	case 22:
		commands[0] = Puzzle::MOVE_D;
		commands[1] = Puzzle::MOVE_L;
		commands[2] = Puzzle::MOVE_R;
		commands[3] = Puzzle::MOVE_U;
		light_puzzle = true;
		ysq.push_back(make_pair(4, 4));
		ysq.push_back(make_pair(4, 1));
		ysq.push_back(make_pair(4, 5));
		yellow_cmd = Puzzle::SQ_NOTHING;

		gsq.push_back(make_pair(0, 4));
		gsq.push_back(make_pair(1, 4));
		gsq.push_back(make_pair(3, 4));
		gsq.push_back(make_pair(5, 4));
		gsq.push_back(make_pair(6, 4));
		gsq.push_back(make_pair(7, 4));
		gsq.push_back(make_pair(8, 4));
		gsq.push_back(make_pair(4, 0));
		gsq.push_back(make_pair(4, 2));
		gsq.push_back(make_pair(4, 3));
		gsq.push_back(make_pair(6, 1));
		grey_cmd = Puzzle::SQ_FREEZE;
		message = "Level 7-4. Introduction to light puzzles.";
		message2 = "";
		break;

	case 23:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::MOVE_U;
		commands[2] = Puzzle::MOVE_U;
		commands[3] = Puzzle::MOVE_U;
		fixed_jumps[0] = 2;
		fixed_jumps[1] = 3;
		fixed_jumps[2] = 4;
		fixed_jumps[3] = 1;
		dark_puzzle = true;
		rot_on_move_r = true;
		gsq.push_back(make_pair(1, 3));
		gsq.push_back(make_pair(1, 4));
		gsq.push_back(make_pair(1, 5));
		gsq.push_back(make_pair(2, 2));
		gsq.push_back(make_pair(2, 6));
		gsq.push_back(make_pair(3, 1));
		gsq.push_back(make_pair(3, 7));
		gsq.push_back(make_pair(4, 1));
		gsq.push_back(make_pair(4, 7));
		gsq.push_back(make_pair(5, 1));
		gsq.push_back(make_pair(5, 7));
		gsq.push_back(make_pair(6, 2));
		gsq.push_back(make_pair(6, 6));
		gsq.push_back(make_pair(7, 3));
		gsq.push_back(make_pair(7, 4));
		gsq.push_back(make_pair(7, 5));
		grey_cmd = Puzzle::SQ_FREEZE;
		redx = 7;
		redy = 7;
		bluex = 1;
		bluey = 1;
		message = "Level 8-1. Intermediate dark puzzles.";
		message2 = "In an older version, this was the final level.";
		break;

	case 24:
		commands[0] = Puzzle::MOVE_D;
		commands[1] = Puzzle::MOVE_L;
		commands[2] = Puzzle::MOVE_U;
		commands[3] = Puzzle::MOVE_R;
		dark_puzzle = true;
		rev_on_press = true;
		psq.push_back(make_pair(0, 0));
		psq.push_back(make_pair(0, 8));
		psq.push_back(make_pair(2, 3));
		psq.push_back(make_pair(2, 4));
		psq.push_back(make_pair(2, 5));
		psq.push_back(make_pair(3, 2));
		psq.push_back(make_pair(3, 6));
		psq.push_back(make_pair(4, 0));
		psq.push_back(make_pair(4, 8));
		psq.push_back(make_pair(5, 2));
		psq.push_back(make_pair(5, 6));
		psq.push_back(make_pair(6, 3));
		psq.push_back(make_pair(6, 4));
		psq.push_back(make_pair(6, 5));
		psq.push_back(make_pair(8, 0));
		psq.push_back(make_pair(8, 8));
		psq.push_back(make_pair(2, 7));
		psq.push_back(make_pair(2, 1));
		psq.push_back(make_pair(6, 7));
		psq.push_back(make_pair(6, 1));
		pink_cmd = Puzzle::SQ_FREEZE;
		message = "Level 8-2. Intermediate dark puzzles.";
		message2 = "";
		break;

	case 25:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::ROT_L;
		commands[2] = Puzzle::JUMP_U;
		commands[3] = Puzzle::NOTHING;
		light_puzzle = true;
		jump_cycle = true;
		jump = 2;
		min_jump = 2;
		max_jump = 3;

		ysq.push_back(make_pair(3, 4));
		ysq.push_back(make_pair(4, 3));
		ysq.push_back(make_pair(4, 5));
		ysq.push_back(make_pair(4, 8));
		ysq.push_back(make_pair(5, 4));
		yellow_cmd = Puzzle::SQ_NOTHING;

		gsq.push_back(make_pair(1, 4));
		gsq.push_back(make_pair(4, 1));
		gsq.push_back(make_pair(7, 4));
		grey_cmd = Puzzle::SQ_FREEZE;

		redx = 7;
		redy = 7;
		bluex = 1;
		bluey = 1;
		message = "Level 9-1. Challenge light puzzles.";
		message2 = "";
		break;

	case 26:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::MOVE_U;
		commands[2] = Puzzle::MOVE_U;
		commands[3] = Puzzle::MOVE_U;
		fixed_jumps[0] = 1;
		fixed_jumps[1] = 4;
		fixed_jumps[2] = 3;
		fixed_jumps[3] = 2;
		light_puzzle = true;
		rot_on_move_r = true;
		
		ysq.push_back(make_pair(4, 4));
		yellow_cmd = Puzzle::SQ_NOTHING;

		gsq.push_back(make_pair(7, 7));
		grey_cmd = Puzzle::SQ_FREEZE;
		message = "Level 9-2. Challenge light puzzles.";
		message2 = "";
		break;

	case 27:
		commands[0] = Puzzle::MOVE_R;
		commands[1] = Puzzle::MOVE_R;
		commands[2] = Puzzle::MOVE_U;
		commands[3] = Puzzle::MOVE_U;
		fixed_jumps[0] = 1;
		fixed_jumps[1] = 2;
		fixed_jumps[2] = 1;
		fixed_jumps[3] = 2;
		light_puzzle = true;
		rev_on_press = true;

		ysq.push_back(make_pair(4, 4));
		ysq.push_back(make_pair(3, 4));
		ysq.push_back(make_pair(3, 6));
		ysq.push_back(make_pair(4, 3));
		ysq.push_back(make_pair(6, 3));
		yellow_cmd = Puzzle::SQ_NOTHING;

		redx = 7;
		redy = 7;
		bluex = 1;
		bluey = 1;
		message = "Level 9-3. Challenge light puzzles.";
		message2 = "";
		break;

	case 28:
		commands[0] = Puzzle::ROT_R;
		commands[1] = Puzzle::HIDE_U;
		commands[2] = Puzzle::SHOW;
		commands[3] = Puzzle::ROT_L;
		dark_puzzle = true;

		load_square_pattern(2);
		yellow_cmd = Puzzle::SQ_FREEZE;

		redx = 7;
		redy = 1;
		bluex = 1;
		bluey = 7;
		message = "Level 10-1. Challenge dark puzzles.";
		message2 = "";
		break;

	case 29:
		commands[0] = Puzzle::JUMP_U;
		commands[1] = Puzzle::MOVE_U;
		commands[2] = Puzzle::JUMP_U;
		commands[3] = Puzzle::MOVE_U;
		jump_u_on_move = true;
		jump_cycle = true;
		rot_on_move_l = true;
		redx = 1;
		redy = 1;
		bluex = 7;
		bluey = 7;
		dark_puzzle = true;

		load_square_pattern(2);
		yellow_cmd = Puzzle::SQ_FREEZE;

		message = "Level 10-2. Challenge dark puzzles.";
		message2 = "";
		break;

	case 30:
		commands[0] = Puzzle::JUMP_U;
		commands[1] = Puzzle::MOVE_UR;
		commands[2] = Puzzle::ROT_R;
		commands[3] = Puzzle::MOVE_UL;
		light_puzzle = true;

		ysq.push_back(make_pair(0, 4));
		ysq.push_back(make_pair(8, 4));
		ysq.push_back(make_pair(4, 4));

		gsq.push_back(make_pair(0, 0));
		gsq.push_back(make_pair(0, 8));
		gsq.push_back(make_pair(8, 0));
		gsq.push_back(make_pair(8, 8));
		grey_cmd = Puzzle::SQ_FREEZE;

		circle_x = 4;
		circle_y = 0;

		message = "Level 11-1. The unexpected. Strange things may happen here.";
		message2 = "You may not even start in the middle of the board.";
		break;

	case 31:
		commands[0] = Puzzle::JUMP_U;
		commands[1] = Puzzle::MOVE_D;
		commands[2] = Puzzle::MOVE_R;
		commands[3] = Puzzle::REV;
		light_puzzle = true;

		ysq.push_back(make_pair(3, 3));
		ysq.push_back(make_pair(4, 3));
		ysq.push_back(make_pair(5, 3));
		ysq.push_back(make_pair(3, 4));
		ysq.push_back(make_pair(4, 4));
		ysq.push_back(make_pair(5, 4));
		ysq.push_back(make_pair(3, 5));
		ysq.push_back(make_pair(4, 5));
		ysq.push_back(make_pair(5, 5));

		circle_x = 4;
		circle_y = 6;

		min_jump = 2;
		max_jump = 3;
		jump = 2;

		message = "Level 11-2. The unexpected.";
		message2 = "";
		break;

	case 32:
		commands[0] = Puzzle::MOVE_L;
		commands[1] = Puzzle::MOVE_U;
		commands[2] = Puzzle::MOVE_D;
		commands[3] = Puzzle::MOVE_R;
		jump = 2;
		light_puzzle = true;

		load_square_pattern(3);
		grey_cmd = Puzzle::SQ_FREEZE;

		wrapping = true;

		message = "Level 11-3. The unexpected.";
		message2 = "";
		break;

	case 33:
		commands[0] = Puzzle::MOVE_D;
		commands[1] = Puzzle::MOVE_L;
		commands[2] = Puzzle::MOVE_R;
		commands[3] = Puzzle::MOVE_U;
		fixed_jumps[0] = 3;
		fixed_jumps[1] = 3;
		fixed_jumps[2] = 2;
		fixed_jumps[3] = 2;
		light_puzzle = true;

		load_square_pattern(3);
		grey_cmd = Puzzle::SQ_FREEZE;

		circle_x = 0;
		circle_y = 0;

		message = "Level 11-4. The unexpected.";
		message2 = "";
		break;

	case 34:
		commands[0] = Puzzle::MOVE_U;
		commands[1] = Puzzle::MOVE_R;
		commands[2] = Puzzle::MOVE_R;
		commands[3] = Puzzle::MOVE_U;
		jump = 2;
		dark_puzzle = true;

		ysq.push_back(make_pair(0, 8));
		ysq.push_back(make_pair(2, 0));
		ysq.push_back(make_pair(4, 6));
		ysq.push_back(make_pair(4, 8));
		ysq.push_back(make_pair(6, 1));
		ysq.push_back(make_pair(6, 2));
		ysq.push_back(make_pair(6, 8));
		ysq.push_back(make_pair(7, 0));
		ysq.push_back(make_pair(8, 0));
		ysq.push_back(make_pair(8, 5));
		yellow_cmd = Puzzle::SQ_FLIP_Y;

		gsq.push_back(make_pair(0, 0));
		gsq.push_back(make_pair(8, 8));
		grey_cmd = Puzzle::SQ_JUMP_D;

		psq.push_back(make_pair(0, 2));
		psq.push_back(make_pair(1, 1));
		psq.push_back(make_pair(2, 6));
		psq.push_back(make_pair(3, 8));
		psq.push_back(make_pair(6, 4));
		psq.push_back(make_pair(8, 6));
		pink_cmd = Puzzle::SQ_FLIP_X;

		message = "Level 11-5. The unexpected.";
		message2 = "One of the former final boss puzzles.";
		break;

	case 35:
		commands[0] = Puzzle::MOVE_UL;
		commands[1] = Puzzle::ROT_R;
		commands[2] = Puzzle::ROT_L;
		commands[3] = Puzzle::NOTHING;

		rot = rand() % 4;

		light_puzzle = true;

		gsq.push_back(make_pair(1,6));
		gsq.push_back(make_pair(2,5));
		gsq.push_back(make_pair(2,6));
		gsq.push_back(make_pair(2,7));
		gsq.push_back(make_pair(3,6));
		grey_cmd = Puzzle::SQ_FREEZE;

		psq.push_back(make_pair(2,2));
		psq.push_back(make_pair(6,2));
		psq.push_back(make_pair(6,6));
		pink_cmd = Puzzle::SQ_ROT_R;

		ysq.push_back(make_pair(1,3));
		ysq.push_back(make_pair(1,5));
		ysq.push_back(make_pair(3,3));
		ysq.push_back(make_pair(3,5));
		ysq.push_back(make_pair(5,3));
		ysq.push_back(make_pair(5,5));
		ysq.push_back(make_pair(7,3));
		ysq.push_back(make_pair(7,5));
		ysq.push_back(make_pair(3,1));
		ysq.push_back(make_pair(5,1));
		ysq.push_back(make_pair(3,7));
		ysq.push_back(make_pair(5,7));
		yellow_cmd = Puzzle::SQ_NOTHING;
		message = "Level 12-1. Randomness. Something is random every time you reset.";
		message2 = "A reasonably solvable puzzle to introduce the randomness concept.";
		break;

	case 36:
		commands[0] = Puzzle::MOVE_D;
		commands[1] = Puzzle::MOVE_D;
		commands[2] = Puzzle::MOVE_R;
		commands[3] = Puzzle::MOVE_R;

		light_puzzle = true;

		temp_int = rand()%3;
		circle_x = 3+temp_int;
		circle_y = 3+temp_int;

		ysq.push_back(make_pair(0,3));
		ysq.push_back(make_pair(1,6));
		ysq.push_back(make_pair(2,7));
		ysq.push_back(make_pair(2,5));
		ysq.push_back(make_pair(3,0));
		ysq.push_back(make_pair(3,6));
		ysq.push_back(make_pair(5,2));
		ysq.push_back(make_pair(5,8));
		ysq.push_back(make_pair(6,1));
		ysq.push_back(make_pair(6,3));
		ysq.push_back(make_pair(7,2));
		ysq.push_back(make_pair(8,5));
		yellow_cmd = Puzzle::SQ_NOTHING;

		psq.push_back(make_pair(4,2));
		psq.push_back(make_pair(7,0));
		psq.push_back(make_pair(8,1));
		pink_cmd = Puzzle::SQ_ROT_L;

		gsq.push_back(make_pair(0,7));
		gsq.push_back(make_pair(1,8));
		gsq.push_back(make_pair(6,4));
		grey_cmd = Puzzle::SQ_ROT_R;
		message = "Level 12-2. Randomness.";
		message2 = "A hard puzzle that might require lots of testing and retesting.";
		break;

	case 37:
		int4 = rand()%2;
		int2 = 1-int4;
		int3 = rand()%2;
		temp_int = 3-int3;
		int3 += 2;
		commands[int4] = Puzzle::MOVE_U;
		commands[int2] = Puzzle::MOVE_D;
		commands[int3] = Puzzle::JUMP_U;
		commands[temp_int] = Puzzle::JUMP_D;

		max_jump = 2;
		jump = 2;

		circle_x = 6;
		circle_y = 2;

		light_puzzle = true;

		gsq.push_back(make_pair(2,1));
		gsq.push_back(make_pair(2,4));
		gsq.push_back(make_pair(2,8));
		gsq.push_back(make_pair(5,1));
		gsq.push_back(make_pair(5,3));
		grey_cmd = Puzzle::SQ_ROT_L;

		psq.push_back(make_pair(6,0));
		psq.push_back(make_pair(6,4));
		psq.push_back(make_pair(6,7));
		psq.push_back(make_pair(3,7));
		psq.push_back(make_pair(3,5));
		pink_cmd = Puzzle::SQ_ROT_R;

		ysq.push_back(make_pair(4,0));
		ysq.push_back(make_pair(0,4));
		ysq.push_back(make_pair(4,8));
		ysq.push_back(make_pair(8,4));
		yellow_cmd = Puzzle::SQ_NOTHING;

		message = "Level 12-3. Randomness.";
		message2 = "A considerably difficult random puzzle.";
		break;

	default:
		no_more_puzzles = true;
		break;
	}
	if(light_puzzle)
	{
		dark = true;
		for(int i=0; i<ysq.size(); i++)
		{
			if(circle_x == ysq[i].first && circle_y == ysq[i].second)
			{
				dark = false;
				break;
			}
		}
	}
}

void Puzzle::load_square_pattern(int pattern)
{
	switch (pattern)
	{
	case 1:
		ysq.push_back(make_pair(0, 0));
		ysq.push_back(make_pair(0, 6));
		ysq.push_back(make_pair(0, 8));
		ysq.push_back(make_pair(2, 6));
		ysq.push_back(make_pair(4, 8));
		ysq.push_back(make_pair(5, 0));
		ysq.push_back(make_pair(5, 1));
		ysq.push_back(make_pair(8, 0));
		ysq.push_back(make_pair(8, 1));
		ysq.push_back(make_pair(8, 6));
		ysq.push_back(make_pair(8, 8));
		gsq.push_back(make_pair(0, 5));
		gsq.push_back(make_pair(3, 8));
		gsq.push_back(make_pair(4, 1));
		gsq.push_back(make_pair(8, 2));
		gsq.push_back(make_pair(8, 3));
		gsq.push_back(make_pair(8, 4));
		gsq.push_back(make_pair(8, 5));
		gsq.push_back(make_pair(8, 7));
		psq.push_back(make_pair(1, 1));
		psq.push_back(make_pair(1, 7));
		psq.push_back(make_pair(7, 6));
		psq.push_back(make_pair(7, 7));
		break;

	case 2:
		ysq.push_back(make_pair(0, 4));
		ysq.push_back(make_pair(1, 3));
		ysq.push_back(make_pair(1, 5));
		ysq.push_back(make_pair(2, 2));
		ysq.push_back(make_pair(2, 4));
		ysq.push_back(make_pair(2, 6));
		ysq.push_back(make_pair(3, 1));
		ysq.push_back(make_pair(3, 3));
		ysq.push_back(make_pair(3, 5));
		ysq.push_back(make_pair(3, 7));
		ysq.push_back(make_pair(4, 1));
		ysq.push_back(make_pair(4, 3));
		ysq.push_back(make_pair(4, 5));
		ysq.push_back(make_pair(4, 7));
		ysq.push_back(make_pair(5, 1));
		ysq.push_back(make_pair(5, 3));
		ysq.push_back(make_pair(5, 5));
		ysq.push_back(make_pair(5, 7));
		ysq.push_back(make_pair(6, 2));
		ysq.push_back(make_pair(6, 4));
		ysq.push_back(make_pair(6, 6));
		ysq.push_back(make_pair(7, 3));
		ysq.push_back(make_pair(7, 5));
		ysq.push_back(make_pair(8, 4));
		break;

	case 3:
		ysq.push_back(make_pair(0, 4));
		ysq.push_back(make_pair(4, 0));
		ysq.push_back(make_pair(4, 8));
		ysq.push_back(make_pair(8, 4));

		gsq.push_back(make_pair(1, 4));
		gsq.push_back(make_pair(2, 3));
		gsq.push_back(make_pair(2, 5));
		gsq.push_back(make_pair(3, 2));
		gsq.push_back(make_pair(3, 4));
		gsq.push_back(make_pair(3, 6));
		gsq.push_back(make_pair(4, 1));
		gsq.push_back(make_pair(4, 3));
		gsq.push_back(make_pair(4, 5));
		gsq.push_back(make_pair(4, 7));
		gsq.push_back(make_pair(7, 4));
		gsq.push_back(make_pair(6, 3));
		gsq.push_back(make_pair(6, 5));
		gsq.push_back(make_pair(5, 2));
		gsq.push_back(make_pair(5, 4));
		gsq.push_back(make_pair(5, 6));

	default:
		break;
	}
}

/*
First, the command is used to determine shift amount or parameter changes.
The shift is used to move the circle appropriately, and parameters are checked to make sure they are in allowed ranges.
Squares are tested, and if a square is hit, the square_hit function is called.
Dark is set and if an x is hit, xhit and solved are updated.
*/
void Puzzle::button_pressed(int button, int key_num)
{
	if(dark_puzzle && !solved)
		dark = !dark;

	if(frozen||solved)
		return;

	if(command_rotate)
	{
		int temp = commands[0];
		commands[0]=commands[1];
		commands[1]=commands[2];
		commands[2]=commands[3];
		commands[3] = temp;
	}

	int shift_y=0, shift_x=0, hshift_y=0, hshift_x=0;
	int prior_x = circle_x, prior_y = circle_y;

	//Handle commands////////////////////////////////////////////////////////////////
	switch(button)
	{
	case Puzzle::MOVE_U:
		if(fixed_jumps[key_num]>0)
			shift_y = fixed_jumps[key_num];
		else
			shift_y = jump;
		break;

	case Puzzle::MOVE_R:
		if(fixed_jumps[key_num]>0)
			shift_x = fixed_jumps[key_num];
		else
			shift_x = jump;
		break;

	case Puzzle::MOVE_D:
		if(fixed_jumps[key_num]>0)
			shift_y = -fixed_jumps[key_num];
		else
			shift_y = -jump;
		break;

	case Puzzle::MOVE_L:
		if(fixed_jumps[key_num]>0)
			shift_x = -fixed_jumps[key_num];
		else
			shift_x = -jump;
		break;

	case Puzzle::MOVE_UL:
		if(fixed_jumps[key_num]>0)
		{
			shift_x = -fixed_jumps[key_num];
			shift_y = fixed_jumps[key_num];
		}
		else
		{
			shift_x = -jump;
			shift_y = jump;
		}
		break;

	case Puzzle::MOVE_UR:
		if (fixed_jumps[key_num]>0)
		{
			shift_x = fixed_jumps[key_num];
			shift_y = fixed_jumps[key_num];
		}
		else
		{
			shift_x = jump;
			shift_y = jump;
		}
		break;

	case Puzzle::JUMP_U:
		jump++;
		break;

	case Puzzle::JUMP_D:
		jump--;
		break;

	case Puzzle::ROT_R:
		rot++;
		break;

	case Puzzle::ROT_L:
		rot--;
		break;

	case Puzzle::REV:
		rot+=2;
		break;

	case Puzzle::SET_U:
		set = 0;
		break;

	case Puzzle::SET_R:
		set = 1;
		break;

	case Puzzle::SET_D:
		set = 2;
		break;

	case Puzzle::SET_L:
		set = 3;
		break;

	case Puzzle::MOVE_S:
		if(set == 0)
			shift_y = jump;
		if(set == 1)
			shift_x = jump;
		if(set == 2)
			shift_y = -jump;
		if(set == 3)
			shift_x = -jump;
		break;

	case Puzzle::HIDE_U:
		if(fixed_jumps[0]>0)
			hshift_y = fixed_jumps[0];
		else
			hshift_y = jump;
		break;

	case Puzzle::HIDE_R:
		if(fixed_jumps[1]>0)
			hshift_x = fixed_jumps[1];
		else
			hshift_x = jump;
		break;

	case Puzzle::HIDE_D:
		if(fixed_jumps[2]>0)
			hshift_y = -fixed_jumps[2];
		else
			hshift_y = -jump;
		break;

	case Puzzle::HIDE_L:
		if(fixed_jumps[3]>0)
			hshift_x = -fixed_jumps[3];
		else
			hshift_x = -jump;
		break;

	case Puzzle::SHOW:
		circle_x = hide_x;
		circle_y = hide_y;
		break;

	default:
		break;
	}

	//Check limits and rotation///////////////////////////////////////////////////////////////////////
	while(rot>3)
		rot-=4;

	while(rot<0)
		rot+=4;
	int true_rot = rot;
	true_rot += col_adjust * circle_x;
	true_rot += row_adjust * circle_y;

	while (true_rot >= 4)
		true_rot -= 4;
	while (true_rot < 0)
		true_rot += 4;

	if(true_rot == 0)
	{
		circle_x += shift_x;
		circle_y += shift_y;
		hide_x += hshift_x;
		hide_y += hshift_y;
	}

	if(true_rot == 1)
	{
		circle_x += shift_y;
		circle_y -= shift_x;
		hide_x += hshift_y;
		hide_y -= hshift_x;
	}

	if(true_rot == 2)
	{
		circle_x -= shift_x;
		circle_y -= shift_y;
		hide_x -= hshift_x;
		hide_y -= hshift_y;
	}

	if(true_rot == 3)
	{
		circle_x -= shift_y;
		circle_y += shift_x;
		hide_x -= hshift_y;
		hide_y += hshift_x;
	}

	if(rot_on_move_r && (shift_x != 0 || shift_y != 0))
		rot++;

	if(rot_on_move_l && (shift_x != 0 || shift_y != 0))
		rot--;

	if(rev_on_move && (shift_x != 0 || shift_y != 0))
		rot+=2;

	if(rot_on_press_r)
		rot++;

	if(rot_on_press_l)
		rot--;

	if(rev_on_press)
		rot+=2;

	if(rot > 3)
		rot-=4;
	if(rot < 0)
		rot+=4;

	if(jump_u_on_move && (shift_x != 0 || shift_y != 0))
		jump++;

	if(jump_d_on_move && (shift_x != 0 || shift_y != 0))
		jump--;

	if(!wrapping)
	{
		if(circle_x > 8)
			circle_x = 8;
		if(circle_x < 0)
			circle_x = 0;
		
		if(circle_y > 8)
			circle_y = 8;
		if(circle_y < 0)
			circle_y = 0;

		if(hide_x > 8)
			hide_x = 8;
		if(hide_x < 0)
			hide_x = 0;
		
		if(hide_y > 8)
			hide_y = 8;
		if(hide_y < 0)
			hide_y = 0;
	}else{
		if(circle_x > 8)
			circle_x -= 9;
		if(circle_x < 0)
			circle_x += 9;

		if(circle_y > 8)
			circle_y -= 9;
		if(circle_y < 0)
			circle_y += 9;

		if(hide_x > 8)
			hide_x -= 9;
		if(hide_x < 0)
			hide_x += 9;
		
		if(hide_y > 8)
			hide_y -= 9;
		if(hide_y < 0)
			hide_y += 9;
	}

	//Handle squares///////////////////////////////////////////////////////////
	bool yellow_hit = false, pink_hit = false, grey_hit = false, light_hit = false;
	for(int i=0; i<ysq.size(); i++)
	{
		if(circle_x == ysq[i].first && circle_y == ysq[i].second)
		{
			yellow_hit = true;
			light_hit = true;
			break;
		}
	}

	for(int i=0; i<psq.size(); i++)
	{
		if(circle_x == psq[i].first && circle_y == psq[i].second)
		{
			pink_hit = true;
			break;
		}
	}

	for(int i=0; i<gsq.size(); i++)
	{
		if(circle_x == gsq[i].first && circle_y == gsq[i].second)
		{
			grey_hit = true;
			break;
		}
	}

	if(prior_x != circle_x || prior_y != circle_y)
	{
		if(yellow_hit)
			square_hit(yellow_cmd);
		if(pink_hit)
			square_hit(pink_cmd);
		if(grey_hit)
			square_hit(grey_cmd);
	}

	if (yellow_hit)
	{
		yellow_hit = false;
	}
	else
	{
		for (int i = 0; i < ysq.size(); i++)
		{
			if (circle_x == ysq[i].first && circle_y == ysq[i].second)
			{
				yellow_hit = true;
				break;
			}
		}
	}

	if (pink_hit)
	{
		pink_hit = false;
	}
	else
	{
		for (int i = 0; i < psq.size(); i++)
		{
			if (circle_x == psq[i].first && circle_y == psq[i].second)
			{
				pink_hit = true;
				break;
			}
		}
	}

	if (grey_hit)
	{
		grey_hit = false;
	}
	else
	{
		for (int i = 0; i < gsq.size(); i++)
		{
			if (circle_x == gsq[i].first && circle_y == gsq[i].second)
			{
				grey_hit = true;
				break;
			}
		}
	}

	if (prior_x != circle_x || prior_y != circle_y)
	{
		if (yellow_hit)
			square_hit(yellow_cmd);
		if (pink_hit)
			square_hit(pink_cmd);
		if (grey_hit)
			square_hit(grey_cmd);
	}

	if (jump_cycle)
	{
		if (jump > max_jump)
		{
			jump = min_jump + (jump - max_jump - 1) % (max_jump - min_jump);
		}
		if (jump < min_jump)
		{
			jump = max_jump - ((min_jump - jump - 1) % (max_jump - min_jump));
		}
	}
	else{
		if (jump > max_jump)
			jump = max_jump;
		if (jump < min_jump)
			jump = min_jump;
	}

	while (rot>3)
		rot -= 4;

	while (rot<0)
		rot += 4;

	if(light_puzzle)
	{
		if(!light_hit)
			dark = true;
		else
			dark = false;
	}

	if(circle_x == redx && circle_y == redy)
		xhit=true;

	if(circle_x == bluex && circle_y == bluey && xhit)
		solved=true;
}

void Puzzle::square_hit(int command)
{
	switch(command)
	{
	case Puzzle::SQ_NOTHING:
		break;

	case Puzzle::SQ_FREEZE:
		frozen = true;
		break;

	case Puzzle::SQ_ROT_R:
		rot++;
		break;

	case Puzzle::SQ_ROT_L:
		rot--;
		break;

	case Puzzle::SQ_REV:
		rot+=2;
		break;

	case Puzzle::SQ_JUMP_U:
		jump++;
		break;

	case Puzzle::SQ_JUMP_D:
		jump--;
		break;

	case Puzzle::SQ_SET_U:
		set = 0;
		break;

	case Puzzle::SQ_SET_R:
		set = 1;
		break;

	case Puzzle::SQ_SET_D:
		set = 2;
		break;

	case Puzzle::SQ_SET_L:
		set = 3;
		break;

	case Puzzle::SQ_FLIP_X:
		circle_x = 8-circle_x;
		break;

	case Puzzle::SQ_FLIP_Y:
		circle_y = 8-circle_y;
		break;

	default:
		break;
	}
}

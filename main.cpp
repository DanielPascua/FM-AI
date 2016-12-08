#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>
#include <vector>
#include <string>
#include "Puzzle.h"

using namespace std;

int main()
{
	//Screen setup
	sf::RenderWindow App(sf::VideoMode(800, 600), "Fluid Motion");
	App.setFramerateLimit(60);
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return 1;
	sf::Text text("Move to the red x, then to the blue x", font), red_x("X", font), blue_x("X", font), text2("Red x hit!", font),
		last_text("Last pressed: ", font), last2_text("2nd to last: ", font), last3_text("3rd to last: ", font), message_text("", font, 20),
		message2_text("", font, 20);
	text2.setColor(sf::Color::Black);
	last_text.setColor(sf::Color::Black);
	last2_text.setColor(sf::Color::Black);
	last3_text.setColor(sf::Color::Black);
	message_text.setColor(sf::Color::Black);
	message2_text.setColor(sf::Color::Black);
	red_x.setColor(sf::Color::Red);
	blue_x.setColor(sf::Color::Blue);
	last_text.setPosition(400,150);
	last2_text.setPosition(400,120);
	last3_text.setPosition(400,90);
	text2.setPosition(15,40);
	message_text.setPosition(15,420);
	message2_text.setPosition(15, 450);
	text.setColor(sf::Color::Black);
	text.setPosition(15,10);
	string last="", last2="", last3="";

	sf::RectangleShape v_lines[10];
	sf::RectangleShape h_lines[10];
	sf::CircleShape circle = sf::CircleShape(13);
	circle.setFillColor(sf::Color::Green);
	vector<sf::RectangleShape> squares;
	for(int i=0; i<10; i++)
	{
		v_lines[i] = sf::RectangleShape(sf::Vector2f(3.f,33*9+2));
		h_lines[i] = sf::RectangleShape(sf::Vector2f(33*9+2, 3.f));
		v_lines[i].setPosition(50 + 33 * i, 100);
		h_lines[i].setPosition(50, 100 + 33 * i);
		v_lines[i].setFillColor(sf::Color::Black);
		h_lines[i].setFillColor(sf::Color::Black);
	}

	//Puzzle setup
	Puzzle puzzle(0);
	int next_puzzle;
	bool use_next = false;

	for(int pnum = 1; ; pnum++)
	{
		if (use_next)
			pnum = next_puzzle;
		puzzle.set_number(pnum);
		use_next = false;
		puzzle.set_puzzle();
		if(puzzle.are_no_more_puzzles())
			break;

		squares.clear();
		for(int i=0; i<puzzle.get_ysq().size(); i++)
		{
			int x=puzzle.get_ysq()[i].first;
			int y=puzzle.get_ysq()[i].second;
			sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(33, 33));
			square.setFillColor(sf::Color::Yellow);
			square.setPosition(50 + x * 33, 100 + (8 - y) * 33);
			squares.push_back(square);
		}
		for(int i=0; i<puzzle.get_psq().size(); i++)
		{
			int x=puzzle.get_psq()[i].first;
			int y=puzzle.get_psq()[i].second;
			sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(33, 33));
			square.setFillColor(sf::Color::Color(199,21,133));
			square.setPosition(50 + x * 33, 100 + (8 - y) * 33);
			squares.push_back(square);
		}
		for(int i=0; i<puzzle.get_gsq().size(); i++)
		{
			int x=puzzle.get_gsq()[i].first;
			int y=puzzle.get_gsq()[i].second;
			sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(33, 33));
			square.setFillColor(sf::Color::Color(130, 130, 130));
			square.setPosition(50 + x * 33, 100 + (8 - y) * 33);
			squares.push_back(square);
		}

		red_x.setPosition(56+33*puzzle.get_redx(), 98+33*(8-puzzle.get_redy()));
		blue_x.setPosition(56+33*puzzle.get_bluex(), 98+33*(8-puzzle.get_bluey()));
		message_text.setString(puzzle.get_message());
		message2_text.setString(puzzle.get_message2());

		last=last2=last3="";

		while(App.isOpen())
		{
			sf::Event e;
			bool next = false;
			while(App.pollEvent(e))
			{
				if(e.type == sf::Event::Closed)
				{
					App.close();
					return 0;
				}
				if(e.type == sf::Event::KeyPressed)
				{
					if(e.key.code == sf::Keyboard::Escape)
					{
						App.close();
						return 0;
					}

					if(puzzle.get_solved() && e.key.code == sf::Keyboard::Return)
						next = true;

					if(e.key.code == sf::Keyboard::R)
					{
						puzzle.set_puzzle();
						last=last2=last3="";
					}

					if (!puzzle.get_solved())
					{
						if (e.key.code == sf::Keyboard::Left)
						{
							puzzle.press_left();
							last3 = last2;
							last2 = last;
							last = "Left";
						}

						if (e.key.code == sf::Keyboard::Up)
						{
							puzzle.press_up();
							last3 = last2;
							last2 = last;
							last = "Up";
						}

						if (e.key.code == sf::Keyboard::Right)
						{
							puzzle.press_right();
							last3 = last2;
							last2 = last;
							last = "Right";
						}

						if (e.key.code == sf::Keyboard::Down)
						{
							puzzle.press_down();
							last3 = last2;
							last2 = last;
							last = "Down";
						}
					}

					if(e.key.code == sf::Keyboard::Num0)
					{
						next=true;
					}

					if (e.key.code == sf::Keyboard::Num9)
					{
						next = true;
						use_next = true;
						next_puzzle = pnum - 1;
						if (next_puzzle < 1)
							next_puzzle = 1;
					}
				}
			}

			if(next)
				break;

			circle.setPosition(55.5+puzzle.get_circle_x()*33,105.5+8*33-puzzle.get_circle_y()*33);
			if(puzzle.get_xhit())
				text2.setString("Red x hit! Now go to the blue x...");
			else
				text2.setString("");

			last_text.setString("Last pressed: " + last);
			last2_text.setString("2nd to last: " + last2);
			last3_text.setString("3rd to last: " + last3);

			if(puzzle.get_solved())
				text2.setString("Puzzle cleared!!!");

			App.clear(sf::Color::White);
			for(int i=0; i<squares.size(); i++)
			{
				App.draw(squares[i]);
			}
			for(int i=0; i<10; i++)
			{
				App.draw(v_lines[i]);
				App.draw(h_lines[i]);
			}

			App.draw(text);
			App.draw(text2);
			App.draw(last_text);
			App.draw(last2_text);
			App.draw(last3_text);
			App.draw(red_x);
			App.draw(blue_x);
			if(!puzzle.get_dark())
				App.draw(circle);
			App.draw(message_text);
			App.draw(message2_text);
			App.display();
		}
	}
	return 0;
}
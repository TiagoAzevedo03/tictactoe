#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace sf;

int count;
std::vector<Text> squares;

std::vector<RectangleShape> setLines(){
	std::vector<RectangleShape> lines;
	
    RectangleShape line1(Vector2f(5, 580));
    line1.setPosition(200, 10);
    lines.push_back(line1);
    
    RectangleShape line2(Vector2f(5, 580));
    line2.setPosition(400, 10);
    lines.push_back(line2);
    
    RectangleShape line3(Vector2f(580, 5));
    line3.setPosition(10, 200);
    lines.push_back(line3);
    
    RectangleShape line4(Vector2f(580, 5));
    line4.setPosition(10, 400);
    lines.push_back(line4);
    
    return lines;
}

void set0(){
	
	Text text;
	for (int i = 0; i < 9; i++){
		squares.push_back(text);
		squares[i].setCharacterSize(70);
		squares[i].setFillColor(Color::Blue);
	} 
	
	squares[0].setString("a");
	squares[0].setPosition(40, 40);
	
	squares[1].setString("b");
	squares[1].setPosition(240, 40);
	
	squares[2].setString("c");
	squares[2].setPosition(440, 40);
	
	squares[3].setString("d");
	squares[3].setPosition(40, 240);
	
	squares[4].setString("e");
	squares[4].setPosition(240, 240);
	
	squares[5].setString("f");
	squares[5].setPosition(440, 240);
	
	squares[6].setString("g");
	squares[6].setPosition(40, 440);
	
	squares[7].setString("h");
	squares[7].setPosition(240, 440);
	
	squares[8].setString("i");
	squares[8].setPosition(440, 440);
	
	count = 0;
}

void setSquare(int i){
	if (count % 2 == 0)
    	squares[i].setString("X");
	else {
		squares[i].setString("O");
		squares[i].setFillColor(Color::Red);
	}
	count++;
}

int testWin(){
	if (squares[0].getString() == squares[4].getString() && squares[0].getString() == squares[8].getString() && squares[0].getString() == "X")
		return 1;
	else if (squares[0].getString() == squares[1].getString() && squares[0].getString() == squares[2].getString() && squares[0].getString() == "X")
		return 1;
	else if (squares[2].getString() == squares[4].getString() && squares[2].getString() == squares[6].getString() && squares[2].getString() == "X")
		return 1;
	else if (squares[3].getString() == squares[4].getString() && squares[3].getString() == squares[5].getString() && squares[3].getString() == "X")
		return 1;
	else if (squares[6].getString() == squares[7].getString() && squares[6].getString() == squares[8].getString() && squares[6].getString() == "X")
		return 1;
	else if (squares[0].getString() == squares[3].getString() && squares[0].getString() == squares[6].getString() && squares[0].getString() == "X")
		return 1;
	else if (squares[1].getString() == squares[4].getString() && squares[1].getString() == squares[7].getString() && squares[1].getString() == "X")
		return 1;
	else if (squares[2].getString() == squares[5].getString() && squares[2].getString() == squares[8].getString() && squares[2].getString() == "X")
		return 1;
	else if (squares[0].getString() == squares[4].getString() && squares[0].getString() == squares[8].getString() && squares[0].getString() == "O")
		return 2;
	else if (squares[0].getString() == squares[1].getString() && squares[0].getString() == squares[2].getString() && squares[0].getString() == "O")
		return 2;
	else if (squares[2].getString() == squares[4].getString() && squares[2].getString() == squares[6].getString() && squares[2].getString() == "O")
		return 2;
	else if (squares[3].getString() == squares[4].getString() && squares[3].getString() == squares[5].getString() && squares[3].getString() == "O")
		return 2;
	else if (squares[6].getString() == squares[7].getString() && squares[6].getString() == squares[8].getString() && squares[6].getString() == "O")
		return 2;
	else if (squares[0].getString() == squares[3].getString() && squares[0].getString() == squares[6].getString() && squares[0].getString() == "O")
		return 2;
	else if (squares[1].getString() == squares[4].getString() && squares[1].getString() == squares[7].getString() && squares[1].getString() == "O")
		return 2;
	else if (squares[2].getString() == squares[5].getString() && squares[2].getString() == squares[8].getString() && squares[2].getString() == "O")
		return 2;
	else return 0;
}

void multiplayer(){
	RenderWindow window(VideoMode(600, 600), "Multiplayer Tic Tac Toe");
	
	std::vector<RectangleShape> lines = setLines();
	
	Font font;
	font.loadFromFile("arial.ttf");
	
	set0();
	    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed){
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed){
            	if (event.mouseButton.button == Mouse::Left){
            		Vector2i position = Mouse::getPosition(window);
            		if (position.x >= 0 && position.x <= 195 && position.y >= 0 && position.y <= 195 && squares[0].getString() == "a"){
	            		setSquare(0);
					}
					else if (position.x >= 205 && position.x <= 395 && position.y >= 0 && position.y <= 195 && squares[1].getString() == "b"){
						setSquare(1);
					}
					else if (position.x >= 405 && position.x <= 595 && position.y >= 0 && position.y <= 195 && squares[2].getString() == "c"){
						setSquare(2);
					}
					else if (position.x >= 0 && position.x <= 195 && position.y >= 205 && position.y <= 395 && squares[3].getString() == "d"){
						setSquare(3);
					}
					else if (position.x >= 205 && position.x <= 395 && position.y >= 205 && position.y <= 395 && squares[4].getString() == "e"){
						setSquare(4);
					}
					else if (position.x >= 405 && position.x <= 595 && position.y >= 205 && position.y <= 395 && squares[5].getString() == "f"){
						setSquare(5);
					}
					else if (position.x >= 0 && position.x <= 195 && position.y >= 405 && position.y <= 595 && squares[6].getString() == "g"){
						setSquare(6);
					}
					else if (position.x >= 205 && position.x <= 395 && position.y >= 405 && position.y <= 595 && squares[7].getString() == "h"){
						setSquare(7);
					}
					else if (position.x >= 405 && position.x <= 595 && position.y >= 405 && position.y <= 595 && squares[8].getString() == "i"){
						setSquare(8);
					}
				}
			}
        }
        window.clear();
        for (int i = 0; i < 4; i++){
    		window.draw(lines[i]);
		}
		
		bool empty = false;
		
		for(int i = 0; i < 9; i++){
			if(squares[i].getString() == "X" || squares[i].getString() == "O"){
				squares[i].setFont(font);
				window.draw(squares[i]);	
			}
			else empty = true;
		}
		
		RectangleShape end(Vector2f(300, 300));
    	end.setPosition(150, 150);
    	
    	Text message;
		message.setFillColor(Color::Black);
		message.setFont(font);
    	
		
		if(testWin() == 1){
    		window.draw(end);
    		message.setCharacterSize(25);
			message.setPosition(Vector2f(210, 280));
    		message.setString("PLAYER 1 WINS");
		}
		else if(testWin() == 2){
    		window.draw(end);
    		message.setCharacterSize(25);
			message.setPosition(Vector2f(210, 280));
    		message.setString("PLAYER 2 WINS");
		}
		else if (!empty){
			window.draw(end);
			message.setCharacterSize(50);
			message.setPosition(Vector2f(230, 280));
			message.setString("DRAW");
		}
		
		if (testWin() || !empty) 
		{
			window.draw(message);
		}
		
		window.display();
    }
}

int main()
{
    RenderWindow window(VideoMode(600, 600), "Tic Tac Toe");
    
    Font font;
	font.loadFromFile("arial.ttf");
    
    RectangleShape option1(Vector2f (400, 120));
    option1.setPosition(100, 120);
    
    Text op1;
	op1.setFillColor(Color::Black);
	op1.setFont(font);
	op1.setCharacterSize(25);
	op1.setPosition(Vector2f(200, 160));
    op1.setString("SINGLE PLAYER");
    
    RectangleShape option2(Vector2f (400, 120));
    option2.setPosition(100, 360);
    
    Text op2;
	op2.setFillColor(Color::Black);
	op2.setFont(font);
	op2.setCharacterSize(25);
	op2.setPosition(Vector2f(210, 400));
    op2.setString("MULTIPLAYER");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::MouseButtonPressed){
            	if (event.mouseButton.button == Mouse::Left){
            		Vector2i position = Mouse::getPosition(window);
            		if (position.x >= 100 && position.x <= 500 && position.y >= 120 && position.y <= 240){
            			option1.setFillColor(Color::Green);
					}
					else if (position.x >= 100 && position.x <= 500 && position.y >= 360 && position.y <= 480){
						window.close();
						multiplayer();
					}
				}
			}
        }
        window.clear();
        window.draw(option1);
        window.draw(option2);
        window.draw(op1);
        window.draw(op2);
        window.display();
    }

    return 0;
}



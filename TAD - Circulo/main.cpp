#include <bits/stdc++.h>
#include "Ponto.h"
#include "Circulo.h"
using namespace std;

int main() {
	vector <Circulo> circulos;
	
	while(true) {
		string cmd;
		getline(cin, cmd);

		std::stringstream ss{ cmd };
		vector<string> tokens;
		string word;

		while(ss >> word) 
			tokens.push_back(word);

		if(tokens[0] == "exit") {
			circulos.clear();
			break;
		}
		// cria [raio] [x] [y]
		else if(tokens[0] == "cria") {
			double x = std::stod(tokens[2]);
			double y = std::stod(tokens[3]);
			Ponto centro(x,y);
			double raio = std::stod(tokens[1]);
			Circulo circ(centro, raio);
			circulos.push_back(circ);
		}
		// imprime [int]
		else if(tokens[0] == "imprime") {
			Circulo& circ = circulos.at(std::stoi(tokens[1]));
			cout << "[raio:" << circ.getRadius() << ", X:" <<
				    circ.getCenter().getX() << ", Y:" << circ.getCenter().getY() << "]" << endl;
		}
		// imprime_todos
		else if(tokens[0] == "imprime_todos") {
			for(int i = 0; i < circulos.size(); ++i) {
				Circulo& c = circulos[i];
				cout << "[raio:" << c.getRadius() << ", X:" <<
				    	c.getCenter().getX() << ", Y:" << c.getCenter().getY() << "]" << endl;
			}
		}
		// getx [int] 
		else if(tokens[0] == "getx") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));
			cout << "X: " << c.getCenter().getX() << endl;
		}
		// gety [int] 
		else if(tokens[0] == "gety") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));
			cout << "Y: " << c.getCenter().getY() << endl;
		}
		// setx [int] [novo X]
		else if(tokens[0] == "setx") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));
			double novoX = std::stoi(tokens[2]);
			c.getCenter().setX( novoX );
		}
		// sety [int] [novo Y]
		else if(tokens[0] == "sety") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));
			double novoY = std::stoi(tokens[2]);
			c.getCenter().setY( novoY );
		}
		// getarea [int] 
		else if(tokens[0] == "getarea") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));
			cout << "area: " << c.area() << endl;
		}
		// getraio [int] 
		else if(tokens[0] == "getraio") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));
			cout << "raio: " << c.getRadius() << endl;
		}
		// getcentro [int] 
		else if(tokens[0] == "getcentro") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));			
			cout << "centro: (" << c.getCenter().getX() << "," << c.getCenter().getY() << ")" << endl;
		}
		else if(tokens[0] == "setraio") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));
			double rad = std::stoi(tokens[2]);
			c.setRadius( rad );
		}
		// setcentro [int] [X] [Y]
		else if(tokens[0] == "setcentro") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));
			double x = std::stod(tokens[2]);
			double y = std::stod(tokens[3]);	
			Ponto pt( x, y );		
			c.setCenter( pt );
		}
		// interior [int] [X] [Y]
		else if(tokens[0] == "interior") {
			Circulo& c = circulos.at(std::stoi(tokens[1]));
			double x = std::stod(tokens[2]);
			double y = std::stod(tokens[3]);	
			Ponto pt( x, y );
			if( c.contains(pt) ) 
				cout << "true" << endl;
			else 
				cout << "false" << endl;
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	
	return 0;
}
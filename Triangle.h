#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#pragma once

class Triangle {
private:
	sf::CircleShape triangle;
	float x;
	float y;
	int life;
	Bullet bullets;
public:
	Triangle() {
		x = 300;
		y = 280;
		life = 5;
		triangle.setPointCount(3);
		triangle.setRadius(20);
		triangle.setFillColor(sf::Color(139, 0, 0));
		triangle.setPosition(x, y);
		triangle.setOrigin(20, 20);
		bullets.setX(x-2);
		bullets.setY(y-26);
		bullets.line.setPosition(bullets.getX(), bullets.getY());
	}
	float getX() { return x; }
	float getY() { return y; }
	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void move(float);
	void draw(sf::RenderWindow* window);
	bool MapCollision();
	void SetRotation(sf::RenderWindow* window);
	void generationBullets() {
		if (bullets.MapCollision()) {
			bullets.setX(x - 2);
			bullets.setY(y - 26);
		}
	}
	void Shoot(sf::RenderWindow* window, float time);
	void drawShoot(sf::RenderWindow* window) {
		window->draw(bullets.line);
	}
	/*void Transposition();*/
};

#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

void input(sf::Vector2f& pos)
{
	std::cout << "Input Update" << std::endl;
	pos.x += 5;
}
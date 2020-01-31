#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

void render(sf::Vector2f& pos)
{
	std::cout << "Render" << std::endl;
	pos.x += 1;
}

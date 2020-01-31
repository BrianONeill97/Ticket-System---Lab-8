#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

void phys(sf::Vector2f& pos)
{
	std::cout << "Physics Update" << std::endl;
	pos.y += 5;
}
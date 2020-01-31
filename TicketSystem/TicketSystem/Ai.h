#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

void AiUpdate(sf::Vector2f& pos)
{
	std::cout << "Ai Update" << std::endl;
	pos.x += 50;
}
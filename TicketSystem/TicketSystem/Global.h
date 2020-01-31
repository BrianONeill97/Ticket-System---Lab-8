#pragma once
#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Physics.h"
#include "Render.h"
#include "Ai.h"

// Used to prevent data race problem 
//	Data race: A data race is a situation, in which at least two threads access a shared variable at the same time.
std::atomic_int ticketNumber;
std::atomic_int nextThread;
std::atomic_int thisTurn[10];
int threadCount;
std::mutex myMutex;

sf::Vector2f playerPos = { 0,0 };
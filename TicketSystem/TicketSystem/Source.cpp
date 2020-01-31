#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "Global.h"


void Tickets() {
	//increments Thread Count
	// This increases the index of the turnlist to make it continuely run.
	int i = threadCount++;

	while (true)
	{

		//Take a ticket
		thisTurn[i] = ticketNumber.fetch_add(1);

		std::this_thread::sleep_for(std::chrono::seconds(2)); // Slow Down

		// If Values are not equal continue
		while (thisTurn[i] != nextThread) 
		{
			continue;
		}

		//Locks for the thread
		myMutex.lock();
		std::cout << "\_________________________________________" << std::endl;
		std::cout << "Thread : " << i << " Critical Section: " << std::endl;
		myMutex.unlock();
		//Unlocks Thread


		//critical section
		//Seperated so each thread performs a different Funtion
		if (i == 0)
		{
			phys(playerPos);
		}

		if (i == 1)
		{
			input(playerPos);
		}

		if (i == 2)
		{
			render(playerPos);
		}

		if (i == 3)
		{
			AiUpdate(playerPos);
		}

		std::this_thread::sleep_for(std::chrono::seconds(3)); // Slow Down
		nextThread += 1; // Increments Thread

		myMutex.lock();
		std::cout << "\---------------------" << std::endl;
		std::cout << "Player Pos: " << "\n X: " <<playerPos.x << "\n Y: " << playerPos.y << std::endl;
		std::cout << "\---------------------" << std::endl;
		std::cout << "\_________________________________________" << std::endl;
		myMutex.unlock();

		myMutex.lock();
		std::cout << "\t Total Turns: " << thisTurn[i] << std::endl; // Total amount of times thread have changed the players pos 

		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		myMutex.unlock();

		std::this_thread::sleep_for(std::chrono::seconds(5)); // Slow Down
	}
}


int main()
{
	threadCount = 0; // Number of threads present
	ticketNumber = 1; // Starting Ticket
	nextThread = 1; // Since the first thread is zero the next one is one

	// A thread of execution is a sequence of instructions that can be executed concurrently with other such sequences in multithreading environments,
	// while sharing a same address space.
	std::thread ThreadOne = std::thread(Tickets);
	std::thread ThreadTwo = std::thread(Tickets);
	std::thread ThreadThree = std::thread(Tickets);
	std::thread ThreadFour = std::thread(Tickets);

	// The function returns when the thread execution has completed.
	ThreadOne.join();
	ThreadTwo.join();
	ThreadThree.join();
	ThreadFour.join();

	return 0;
}
#pragma once
#include <chrono>

using namespace std::chrono;

//Tracks time passing in the application
class Timer
{
public:
	Timer();
	~Timer();

	float GetDeltaTime();	//Request time since last frame
	void Tick();			//Store time of last frame


private:
	steady_clock::time_point lastFrame; //std::chrono::steady_clock

};


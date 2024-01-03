#include "Time.h"

Time* Time::instance = nullptr;

Time::Time() {
    startTime = std::chrono::steady_clock::now();
    lastFrameTime = startTime;
    time = 0.00001;
    deltaTime = 0.00001;
}

inline double Time::ValidTest(double value) {
    return instance != nullptr ? value : 0.00001;
}

void Time::Init() {
    delete instance;
    instance = new Time();
}

void Time::Delete() {
    delete instance;
    instance = nullptr;
}

void Time::Update() {
    if (instance == nullptr)
        return;

    auto t = std::chrono::steady_clock::now();
    instance->time = std::chrono::duration<double>(t - instance->startTime).count();
    instance->deltaTime = std::chrono::duration<double>(t - instance->lastFrameTime).count();
    instance->lastFrameTime = t;
}

double Time::GetTime() {
    return ValidTest(instance->time);
}

double Time::GetDelta() {
    return ValidTest(instance->deltaTime);
}

#pragma once
#include <chrono>

class Time {
private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point lastFrameTime;
    double time;      // ����� � ������� ���������
    double deltaTime;  // ����� � ���������� �����
    static Time* instance;

    // ������������� ������
    Time();

    static inline double ValidTest(double value);

public:
    static void Init();
    static void Delete();

    // ���������� ����������
    static void Update();

    static double GetTime();
    static double GetDelta();
};

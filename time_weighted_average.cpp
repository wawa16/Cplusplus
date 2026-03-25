/**
Software License Agreement (public)
\authors   Waleed Uddin <mwaleed2018@gmail.com>

\Description:
Template function for calculating time-weighted average of data. Important where duration for data elements must be considered
*/

#include <iostream>
#include <vector>
#include <deque>

struct TimedValue
{
    int value;
    double timestamp;
};

double calculateTimeWeightedAverage(const std::deque<TimedValue>& data, double& session_end_time)
{
    double weighted_sum = 0;
    double total_time = 0;
    for (size_t i = 0; i < data.size(); ++i)
    {
        const double start = data[i].timestamp;
        const double end = (i + 1) < data.size() ? data[i + 1].timestamp : session_end_time;
        const double duration = end - start;
        weighted_sum += duration * data[i].value;
        total_time += duration;
    }
    
    if (total_time > 0) return (weighted_sum / total_time);
    return 0;
}

int main() {
    std::vector<int> data = {10, 15, 30, 90, 25};  // % data
    std::vector<double> timestamps = {0, 1, 2, 3, 20};  // (secs)
    double session_end_time = 22.0;
    std::deque<TimedValue> timed_data;
    
    for (size_t t = 0; t < data.size(); t++) {
        timed_data.push_back({ data.at(t), timestamps.at(t) });
    }
    
    double result = calculateTimeWeightedAverage(timed_data, session_end_time);
    
    std::cout << result;

    return 0;
}

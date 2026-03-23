// Example of a container-data-agonostic cache that can be used to log as a single string
// Vectors and queues of integers or strings both are welcome!


#include <iostream>
#include <deque>
#include <vector>
#include <sstream>

constexpr int DEFAULT_CACHE_SIZE = 5;

std::deque<int> my_scores_cache;

void fillCache(int score) {
    if (my_scores_cache.size() >= DEFAULT_CACHE_SIZE) {
        my_scores_cache.pop_front();
    }
    my_scores_cache.push_back(score);
}

template<typename Container>
std::string getArrayAsString(const Container arr) {
    std::ostringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        if (i) ss << ", ";
        ss << arr[i];
    }
    ss << "]";
    return ss.str();
}

int main() {
    // Example scores and results
    for (int i = 1; i <= 10; i++) {
        fillCache(i);
    }
    std::vector<int> my_game_results({1, 2, 3});

    
    std::cout << getArrayAsString(my_scores_cache) << std::endl;
    std::cout << getArrayAsString(my_game_results);
    
    return 0;
}

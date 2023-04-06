#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "stockfish_internal_wrapper.h"

class BestMoveEventHandler {
public:
    void subscribe(const Callback& callback) {
        listeners.push_back(callback);
    }

    void notify(const char* bestMove) {
        for (const auto& listener : listeners) {
            listener(bestMove);
        }
    }

private:
    std::vector<Callback> listeners;
};

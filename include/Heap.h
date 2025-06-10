#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
struct EnemyDistance {
    EnemyCharacter* enemy;
    float distance;

    
    bool operator<(const EnemyDistance& other) const {
        return distance < other.distance;
    }
    bool operator>(const EnemyDistance& other) const {
        return distance > other.distance;
    }
};

class Heap {
private:
    std::vector<EnemyDistance> data;

    void heapify_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[index].distance < data[parent].distance) {
                std::swap(data[index], data[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void heapify_down(int index) {
        int size = data.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && data[left].distance < data[smallest].distance) {
                smallest = left;
            }
            if (right < size && data[right].distance < data[smallest].distance) {
                smallest = right;
            }

            if (smallest != index) {
                std::swap(data[index], data[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }

public:
    void insert(const EnemyDistance& ed) {
        data.push_back(ed);
        heapify_up(data.size() - 1);
    }

    EnemyDistance extract() {
        if (data.empty()) {
            throw std::out_of_range("Heap vacío");
        }
        EnemyDistance top = data[0];
        data[0] = data.back();
        data.pop_back();
        heapify_down(0);
        return top;
    }

    EnemyDistance peek() const {
        if (data.empty()) {
            throw std::out_of_range("Heap vacío");
        }
        return data[0];
    }

    bool is_empty() const {
        return data.empty();
    }
};

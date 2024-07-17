#include <iostream>
#include <string>

template <typename T>
class Queue {
private:
    T* arr;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    Queue(int capacity) : capacity(capacity), frontIndex(0), rearIndex(0), count(0) {
        arr = new T[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    T first() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return arr[frontIndex];
    }

    void push(const T& value) {
        if (isFull()) {
            throw std::runtime_error("Queue is full");
        }
        arr[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        ++count;
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        frontIndex = (frontIndex + 1) % capacity;
        --count;
    }

    void show() const {
        for (int i = 0; i < count; ++i) {
            std::cout << arr[(frontIndex + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }

    int size() const {
        return count;
    }
};

int main() {
    Queue<std::string> queue(10);

    queue.push("one");
    queue.push("two");
    queue.push("three");
    queue.push("four");
    queue.push("five");
    queue.push("six");

    std::cout << "Initial queue: ";
    queue.show();

    queue.pop();
    queue.pop();

    queue.push("seven");

    std::cout << "Queue after pop and push: ";
    queue.show();

    int count = 0;
    for (int i = 0; i < queue.size(); ++i) {
        std::string current = queue.first();
        queue.pop();
        queue.push(current);

        if (current[0] == 'f' || current[0] == 't') {
            ++count;
        }
    }

    std::cout << "Number of strings starting with 'f' or 't': " << count << std::endl;

    return 0;
}

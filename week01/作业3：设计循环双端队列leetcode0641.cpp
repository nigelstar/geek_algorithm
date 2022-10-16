#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> buffer_;
    int start_;
    int end_;

public:
    MyCircularDeque(int k) {
        buffer_ = vector(k + 1, 0);
        start_ = 0;
        end_ = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        start_ = (start_ == 0) ? (buffer_.size() - 1) : (start_ - 1);
        buffer_[start_] = value;

        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        buffer_[end_] = value;
        end_ = (end_ + 1) % buffer_.size();

        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        start_ = (start_ + 1) % buffer_.size();

        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        end_ = (end_ == 0) ? (buffer_.size() - 1) : (end_ - 1);

        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : buffer_[start_];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        int index = (end_ == 0) ? (buffer_.size() - 1) : (end_ - 1);
        return buffer_[index];
    }
    
    bool isEmpty() {
        return (start_ == end_);
    }
    
    bool isFull() {
        return ((end_ + 1) % buffer_.size() == start_);
    }
};
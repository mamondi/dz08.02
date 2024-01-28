#include <iostream>

template <typename T>
class MyUniquePtr {
private:
    T* ptr;

public:
    MyUniquePtr(T* p) : ptr(p) {}

    ~MyUniquePtr() {
        delete ptr;
    }

    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    MyUniquePtr(MyUniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T* get() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }
};

template <typename T>
class MySharedPtr {
private:
    T* ptr;
    int* count;

public:
    MySharedPtr(T* p) : ptr(p), count(new int(1)) {}

    ~MySharedPtr() {
        release();
    }

    MySharedPtr(const MySharedPtr& other) : ptr(other.ptr), count(other.count) {
        (*count)++;
    }

    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            (*count)++;
        }
        return *this;
    }

    MySharedPtr(MySharedPtr&& other) noexcept : ptr(other.ptr), count(other.count) {
        other.ptr = nullptr;
        other.count = nullptr;
    }

    MySharedPtr& operator=(MySharedPtr&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            count = other.count;
            other.ptr = nullptr;
            other.count = nullptr;
        }
        return *this;
    }

    T* get() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    int use_count() const {
        return (count != nullptr) ? *count : 0;
    }

private:
    void release() {
        if (count != nullptr) {
            (*count)--;
            if (*count == 0) {
                delete ptr;
                delete count;
            }
        }
    }
};


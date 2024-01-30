#include "else.h"

int main() {
    //тестування написав чатом гпт
    MyUniquePtr<int> uniquePtr(new int(42));
    std::cout << "MyUniquePtr value: " << *uniquePtr << std::endl;

    MySharedPtr<int> sharedPtr1(new int(23));
    MySharedPtr<int> sharedPtr2 = sharedPtr1;
    std::cout << "SharedPtr value: " << *sharedPtr1 << ", Use count: " << sharedPtr1.use_count() << std::endl;
    std::cout << "SharedPtr value: " << *sharedPtr2 << ", Use count: " << sharedPtr2.use_count() << std::endl;

    return 0;
}

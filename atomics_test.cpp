#include <cstdio>
#include <atomic>

int main() {
    std::atomic_uint32_t x = 0;
    uint32_t y = 0;
    void* voidPtr = nullptr;
    std::uint32_t* ptr;
    
    auto atomic_ptr0 = static_cast<std::atomic_uint32_t*>(voidPtr);

    // wont compile
    // auto atomic_ptr1 = static_cast<std::atomic_uint32_t*>(ptr); 


}
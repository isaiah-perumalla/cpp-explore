#include <cstdio>
#include <utility>

struct Tracer {
    Tracer(const char* name): name{name} {
        printf("constructed %s \n", name);
    }

    Tracer(const Tracer& other) : name {other.name} {
        printf("copy constructor %s \n", name);

    }

    Tracer(Tracer&& other): name {other.name} {
        other.name = nullptr;
        printf("move constructor %s \n", name);
    }

    ~Tracer() {
        printf("destroyed %s \n", name);
    }
    public:
        const char* name;

};

void my_func(Tracer& tracer) {
    printf("pass by ref my_func called %s \n", tracer.name);
}

void my_func(Tracer&& tracer) {
    printf("moved param my_func called %s \n", tracer.name);
}


int main() {

    auto a = Tracer{"A"};
    auto b = Tracer{"B"};

    auto a_copy = a;
    // not move constructor defined so will call copy constructor
    auto c = std::move(a);

    my_func(b);
    my_func(a); // a is moved from state obj a.name it is null
    my_func(std::move(b)); // moved version of func will be called

    my_func(b); //b is now moved from state and b.name be null
    return 0;
    
}




/*
output
constructed A 
copy constructor A 
move constructor A 
destroyed A 
destroyed A 
destroyed (null) 

*/

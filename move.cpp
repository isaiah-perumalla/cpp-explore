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

    auto a = Tracer{"A"}; //constructed A
    auto b = Tracer{"B"}; // constructed B 

    auto a_copy = a; // copy constructor A 
    // not move constructor defined so will call copy constructor
    
    auto c = std::move(a); // move constructor A

    my_func(b); //pass by ref my_func called B
    my_func(a); // pass by ref my_func called (null) , a is moved from state obj a.name it is null
    my_func(std::move(b)); // moved param my_func called B , moved version of func will be called

    my_func(b); //pass by ref my_func called B 
    return 0;
    
}




/*
output


constructed A  
constructed B 
copy constructor A 
move constructor A 
pass by ref my_func called B 
pass by ref my_func called (null) 
moved param my_func called B 
pass by ref my_func called B 
destroyed A 
destroyed A 
destroyed B 
destroyed (null) 

*/

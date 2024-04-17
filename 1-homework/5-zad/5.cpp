#include <iostream>

class B{
public:
    virtual int __cdecl prva()=0;
    virtual int __cdecl druga(int)=0;
};

class D: public B{
public:
    virtual int __cdecl prva(){return 42;}
    virtual int __cdecl druga(int x){return prva()+x;}
};

void callMethods(B* b){
    void **vtable = *(void***)b;
    std::cout<<((int(__cdecl*)(B*))vtable[0])(b)<<"\n";
    std::cout<<((int(__cdecl*)(B*, int))vtable[1])(b, 42)<<"\n";
}

int main(){
    D b;
    callMethods(&b);
}
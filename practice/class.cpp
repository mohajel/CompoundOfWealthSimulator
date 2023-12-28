#include <iostream>

using namespace std;


class A
{
private:
    /* data */
public:
    A(/* args */) {}
    ~A() {}

    virtual void f() = 0;
};

 void A::f()
{
    cout << "A" << endl;
}

class B : public A
{
private:
    /* data */
public:
    B(/* args */) {}
    ~B() {}

    void f() override;
};

void B::f()
{
    cout << "B" << endl;
}


class C : public A
{
private:
    /* data */
public:
    C(/* args */) {}
    ~C() {}

    void f() override;
};

void C::f()
{
    cout << "C" << endl;
}


int main(int argc, char const *argv[])
{


    A *a = new B();
    a->f();

    return 0;
}

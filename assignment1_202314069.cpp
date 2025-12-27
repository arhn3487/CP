#include<bits/stdc++.h>
using namespace std;

class animal
{
    public:
        virtual void makesound()
        {
            cout<<"Animal make sound\n";
        }
};

class dog : public animal
{
    public:
        void makesound()
        {
            cout<<"Dog barks\n";
        }
};

class cat : public animal
{
    public:
        void makesound()
        {
            cout<<"Cat meow\n";
        }
};

void playsound(animal &b)
{
    b.makesound();
}

int main()
{
    animal *ptr;
    animal a;
    dog d;
    cat c;

    //using pointer
    ptr=&a;
    ptr->makesound();
    ptr= &d;
    ptr->makesound();
    ptr=&c;
    ptr->makesound();

    playsound(a);
    playsound(d);
    playsound(c);
}

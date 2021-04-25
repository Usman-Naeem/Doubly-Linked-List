#include "List.cpp"

int main()
{
    List lst;
    lst.append(0);
    lst.append(1);
    lst.append(2);

    lst.prepend(10);
    lst.prepend(11);

    lst.prepend(10);
    lst.prepend(11);

    lst.insert(2, 21);

    lst.display();
}

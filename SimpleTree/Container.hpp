#ifndef CONTAINER_H
#define CONTAINER_H

// Интерфейс
class Container
{

public:
    // Виртуальные методы, будут реализованы далее
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;
    // Это потом заменим на перегруженный оператор <<
    virtual void print() = 0;

    // Виртуальный деструктор
    virtual ~Container();
};

#endif

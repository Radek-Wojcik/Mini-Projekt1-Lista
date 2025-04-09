#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList {
private:
    int* array;      
    int capacity;    
    int length;      

    void resize();
public:
    ArrayList(int initCapacity = 10);  
    ~ArrayList();

    void push_back(const int& value);
};

#endif // ARRAYLIST_H
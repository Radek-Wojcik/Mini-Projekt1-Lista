#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList {
private:
    int* array;      
    int capacity;    
    int length;      

public:
    ArrayList(int initCapacity = 10);  
    ~ArrayList();
};

#endif // ARRAYLIST_H
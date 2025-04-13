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

    ArrayList(const ArrayList& other);
    ArrayList& operator=(const ArrayList& other);

    void push_back(const int& value);
    void push_front(const int& value);
    void insert_random(const int& value);
    void remove(int index);
    int find(int value) const;
    int& operator[](int index) const;
    int size() const;                      
    int getCapacity() const;   

};

#endif // ARRAYLIST_H
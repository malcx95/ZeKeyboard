#ifndef LIST_H
#define LIST_H
// Simple linked list implementation

template<typename T>
struct ListElem {
    
    T value;
    ListElem* next;

};

template<typename X>
class List {

    public:

        List();
        ~List();
        
        void add(const X& elem);

        void insert(const X& elem);

        void remove(const unsigned index);

        void remove(const X& elem);

        unsigned length() const;

        /*
         * Indexes the list. Should not be used
         * for iteration.
         */
        X& operator[](int i);

        void set_cursor(const unsigned index);

        void reset_cursor();

    private:

        unsigned size;

        X* current;

        ListElem<X>* start;
        ListElem<X>* end;

};

#endif

#include "list.h"

template<typename X>
List<X>::List() {
    start = nullptr;
    end = nullptr;
}

template<typename X>
void List<X>::add(const X& elem) {
    ListElem<X>* el = new ListElem<X>();
    el->value = elem;
    el->next = nullptr;

    if (start == nullptr) {
        start = el;
        end = el;
    } else {
        start->next = el;
        end = el;
    }
}

template<typename X>
unsigned List<X>::length() const {
    return size;
}


#include "list.h"

List::List() {
    start = nullptr;
    end = nullptr;
}

List::add(const X& elem) {
    ListElem* el = new ListElem;
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

unsigned List::size() {
    return size;
}


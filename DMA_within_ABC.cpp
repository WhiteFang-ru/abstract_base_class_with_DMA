#include "DMA_within_Abstract-base-class.h"
#include <cstring>

// ABCGeneral methods
ABCGeneral::ABCGeneral(const char *lbl, int rtg) {
    label = new char[strlen(lbl) + 1];
    strcpy(label, lbl);
    rating = rtg;
}

ABCGeneral::ABCGeneral(const ABCGeneral &ag) {
    label = new char[strlen(ag.label) + 1];
    strcpy(label, ag.label);
    rating = ag.rating;
}

ABCGeneral::~ABCGeneral() {
    delete[] label;
}

ABCGeneral &ABCGeneral::operator=(const ABCGeneral &ag) {
    if(this == &ag) {
        return *this;
    }
    delete[] label;
    label = new char[strlen(ag.label) + 1];
    strcpy(label, ag.label);
    rating = ag.rating;
    return *this;
}

// firstDerived methods:
firstDerived::firstDerived(const char *lbl, int rtg, int sz)
        : ABCGeneral(lbl, rtg) {
    size = sz;
}

firstDerived::firstDerived(int sz, const ABCGeneral &ag)
        : ABCGeneral(ag) {
    size = sz;
}

void firstDerived::View() const {
    cout << "\nView Shirt object:"s << endl;
    cout << "Label:"s << Label() << endl;
    cout << "Rating:"s << Rating() << endl;
    cout << "Size:"s << size << endl;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char *col, const char *lbl, int rtg)
        : ABCGeneral(lbl, rtg) {
    color = col;
}

lacksDMA::lacksDMA(const char *col, const ABCGeneral &ag)
    : ABCGeneral(ag) {
    color = col;
}

void lacksDMA::View() const {
    cout << "\nView Baloon object:"s << endl;
    cout << "Label:"s << Label() << endl;
    cout << "Rating:"s << Rating() << endl;
    cout << "Color:"s << color << endl; 
}

// hasDMA methods
hasDMA::hasDMA(const char *stl, const char *lbl, int rtg)
    : ABCGeneral(lbl, rtg) {
    style = new char[strlen(stl) + 1];
    strcpy(style, stl);
}

hasDMA::hasDMA(const char *stl, const ABCGeneral &ag)
    : ABCGeneral(ag) {
    style = new char[strlen(stl) + 1];
    strcpy(style, stl);
}

hasDMA::hasDMA(const hasDMA &hs)
    : ABCGeneral(hs) { // invoke ABC copy constructor
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA() {
    delete[] style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs) {
    if (this == &hs)
        return *this;
    ABCGeneral::operator=(hs); // copy ABC portion
    delete[] style;         // prepare for new style
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    return *this;
}

void hasDMA::View() const {
    cout << "\nView Map object:"s << endl;
    cout << "Label:"s << Label() << endl;
    cout << "Rating:"s << Rating() << endl;
    cout << "Style:"s << style << endl;
}
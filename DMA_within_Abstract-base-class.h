
#include <iostream>
using namespace std;

const char * readInput(string & temp) {
    cin >> temp;
    return temp.c_str();
}

// Abstract Base Class Using Dynamic memory allocation
class ABCGeneral {
private:
    char *label;
    int rating;

protected:
    char * Label() const { return label; }
    int Rating() const { return rating; }

public:
    ABCGeneral(const char *lbl = "null", int rtg = 0);
    ABCGeneral(const ABCGeneral &ag); 
    virtual ~ABCGeneral();
    ABCGeneral &operator=(const ABCGeneral &ag);
    virtual void View() const = 0;
    // pure virtual function needed for ABC to be genuine
};

// firstDerived is a derived class without DMA
// if class is without DMA: 1.no destructor needed
// 2.uses implicit copy constructor
// 3.uses implicit assignment operator
// class is used for item "shirt"
 class firstDerived : public ABCGeneral {
 private:
     int size;

 public:
     firstDerived(const char *lbl = "null", int rtg = 0, int sz = 0);
     firstDerived(int sz, const ABCGeneral &ag);
     firstDerived &operator=(const firstDerived &fd);
     virtual void View() const;
 };

// lacksDMA is a derived class without DMA
// class is used for item "baloon"
class lacksDMA : public ABCGeneral { 
private:
    string color;
public:
    lacksDMA(const char *col = "blank", const char *lbl = "null",
             int rtg = 0);
    lacksDMA(const char *col, const ABCGeneral &ag);
    virtual void View() const;
};

// hasDMA is a derived class with DMA
// class is used for item "map"
class hasDMA : public ABCGeneral { 
private:
    char *style;

public:
    hasDMA(const char *stl = "none", const char *lbl = "null", int rtg = 0);
    hasDMA(const char *stl, const ABCGeneral &ag);
    hasDMA(const hasDMA &hd);
    virtual ~hasDMA();
    hasDMA &operator=(const hasDMA &hd);
    virtual void View() const;
};

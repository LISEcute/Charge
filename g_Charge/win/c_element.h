#ifndef ELEMENT_H
#define ELEMENT_H
typedef struct {
        const char *Element;
        int Z;
        } _Elem_Z;

_Elem_Z AvailableTarget[]={
 {"Be",4},
 {"C", 6},
 {"N", 7},
 {"Al",13},
 {"Si",14},
 {"Ar",18},
 {"Ti",22},
 {"Fe",26},
 {"Ni",28},
 {"Cu",29},
 {"Ge",32},
 {"Kr",36},
 {"Ag",47},
 {"Xe",54},
 {"Gd",64},
 {"Ta",73},
 {"W", 74},
 {"Au",79},
 {"Pb",82},
 {"U", 92},
 {nullptr, 0}
 };

#endif // ELEMENT_H

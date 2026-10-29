/* HSTMATCH module=EBOOT.BIN start=0x0028ae30 end=0x0028aeb4 symbol=FUN_0028ae30 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: added empty Tag temporary parameter to sub-object init calls; readability pass; exact match verified; names and types await human review. */
#include "hst/vec_triple.h"

struct Tag {};

extern "C" {
void FUN_0028c6e8(void *, int, Tag);
void FUN_0028c7a4(void *, int, Tag);
void FUN_0028c860(void *, int, Tag);

/* Constructor: clears the three arrays and runs each array's init helper. */
VecTriple *FUN_0028ae30(VecTriple *obj)
{
    obj->first.data = 0;
    obj->first.size = 0;
    obj->first.capacity = 0;
    obj->second.data = 0;
    obj->second.size = 0;
    obj->second.capacity = 0;
    obj->third.data = 0;
    obj->third.size = 0;
    obj->third.capacity = 0;
    FUN_0028c6e8(obj, obj->first.size, Tag());
    FUN_0028c7a4(&obj->second, obj->second.size, Tag());
    FUN_0028c860(&obj->third, obj->third.size, Tag());
    obj->unk24 = 0;
    return obj;
}
}

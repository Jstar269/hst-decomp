/* HSTMATCH module=hstp_trans_main.prx start=0x000d7e04 end=0x000d7f4c symbol=FUN_000d7e04 lang=c++ */
/* Clone of src/eboot/detach_slots_000d4140.cpp (hstclone.py tag s10181937g11r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idioms used here:
//  - `Slot *slots` is a POINTER member (offset 0x48), not an array.  Retail reloads it every pass
//    (`lw v0,72(s0); sll v1,i,4; addu s1,v0,v1`) because the virtual call can modify it; as an array
//    member MWCC folds the base into the addressing (84(s0)) and the element pointer is formed much later.
//  - cases 22 and 14 share ONE loop body (fall-through labels): that is what gives retail two entries to
//    the same loop - case 14 branches into the body with `move s2,zero` in its `beql` delay slot, case 22
//    into the `move s2,zero` that precedes the body.  Writing the loop twice emits three bodies (102 words).
//  - the case list is in the REVERSE of retail's dispatch chain (0,1,22,14,8,9,10,11,12 -> 12,11,10,9,8,14,22,1,0).
//  - matching idiom: the `if (!s->obj) continue;` plus the redundant nested `if (s->obj)` are what produce
//    retail's three tests and its two `obj = 0` stores (the store is duplicated into the skip branch's
//    delay slot).  A single guard gives one test and one store.
//  - `#pragma opt_strength_reduction off` is required, otherwise the index becomes a walking pointer and
//    only s1/s0 are saved (retail saves s2/s1/s0).
#pragma opt_strength_reduction off

struct Obj {
    virtual void m0(int);
    virtual void m1();
};

struct Slot {
    char pad[0xc];
    Obj *obj;
};

struct Owner {
    char pad[0x48];
    Slot *slots;
};

extern "C" int FUN_000d7e04(Owner *p, int mode)
{
    int i;

    switch (mode) {
    case 0:
        break;
    case 1:
        break;
    case 22:
    case 14:
        for (i = 0; i < 4; i++) {
            Slot *s = p->slots + i;
            if (!s->obj) continue;
            if (s->obj) { if (s->obj) s->obj->m0(1); s->obj = 0; }
        }
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        for (i = 0; i < 4; i++) {
            Slot *s = p->slots + i;
            if (!s->obj) continue;
            if (s->obj) { if (s->obj) s->obj->m0(1); s->obj = 0; }
        }
        break;
    }
    return 0;
}

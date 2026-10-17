/* HSTMATCH module=hstp_trans_main.prx start=0x000ed818 end=0x000ed8d4 symbol=FUN_000ed818 lang=c++ */
/* Clone of src/eboot/vec_dtor_000e8744.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
    extern void FUN_00000a00(void *);
    extern int FUN_0005c688(void *, int);
}

typedef struct Elem {
    char pad0[0x30];
    char sub[0x2c0];
} Elem;

struct Alloc {};

struct Vec {
    Elem *data;
    int size;

    inline Elem *cut(int n, Alloc) {
        Elem *p = data + size;
        size -= n;
        return p;
    }
};

extern "C" Vec *FUN_000ed818(Vec *self, short flag)
{
    if (self != 0) {
        int n = self->size;
        Elem *last = self->cut(n, Alloc());
        for (; n != 0; --n) {
            --last;
            if (last != 0) {
                FUN_0005c688(last->sub, -1);
            }
        }
        if (self->data != 0) {
            FUN_00000a00(self->data);
        }
        if (0 < flag) {
            FUN_00000a00(self);
        }
    }
    return self;
}

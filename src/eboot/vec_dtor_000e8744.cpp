/* HSTMATCH module=EBOOT.BIN start=0x000e8744 end=0x000e8800 symbol=FUN_000e8744 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
    extern void FUN_00000a00(void *);
    extern int FUN_0005ba00(void *, int);
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

extern "C" Vec *FUN_000e8744(Vec *self, short flag)
{
    if (self != 0) {
        int n = self->size;
        Elem *last = self->cut(n, Alloc());
        for (; n != 0; --n) {
            --last;
            if (last != 0) {
                FUN_0005ba00(last->sub, -1);
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

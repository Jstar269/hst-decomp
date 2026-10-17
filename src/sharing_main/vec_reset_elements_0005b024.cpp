/* HSTMATCH module=hstp_trans_main.prx start=0x0005b024 end=0x0005b0f4 symbol=FUN_0005b024 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#pragma opt_strength_reduction off

struct Alloc {};

struct Elem {
    Elem();
};

extern "C" void FUN_0005bc80(void *vec, int cap);

struct Vec {
    Elem **data;
    unsigned int size;
    unsigned int cap;
};

extern Vec DAT_003da6a4;
extern "C" {
    extern unsigned int DAT_003da6ac;
}

static inline void shrink(Alloc) {
    int n = DAT_003da6a4.size;
    DAT_003da6a4.size -= n;
}

extern "C" void FUN_0005b024(void) {
    if (DAT_003da6ac == 0) {
        if (DAT_003da6a4.cap < 1024) {
            FUN_0005bc80(&DAT_003da6a4, 1024);
        }
    }
    unsigned int i = 0;
    if (DAT_003da6a4.size != 0) {
        do {
            Elem *p = DAT_003da6a4.data[i];
            if (p != 0) {
                delete[] p;
                DAT_003da6a4.data[i] = 0;
            }
            i++;
        } while (i < DAT_003da6a4.size);
    }
    shrink(Alloc());
}

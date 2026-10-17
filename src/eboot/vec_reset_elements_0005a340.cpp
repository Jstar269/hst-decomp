/* HSTMATCH module=EBOOT.BIN start=0x0005a340 end=0x0005a410 symbol=FUN_0005a340 lang=c++ */
/* Clone of src/sharing_main/vec_reset_elements_0005b024.cpp (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#pragma opt_strength_reduction off

struct Alloc {};

struct Elem {
    Elem();
};

extern "C" void FUN_0005aff8(void *vec, int cap);

struct Vec {
    Elem **data;
    unsigned int size;
    unsigned int cap;
};

extern Vec DAT_00331364;
extern "C" {
    extern unsigned int DAT_0033136c;
}

static inline void shrink(Alloc) {
    int n = DAT_00331364.size;
    DAT_00331364.size -= n;
}

extern "C" void FUN_0005a340(void) {
    if (DAT_0033136c == 0) {
        if (DAT_00331364.cap < 1024) {
            FUN_0005aff8(&DAT_00331364, 1024);
        }
    }
    unsigned int i = 0;
    if (DAT_00331364.size != 0) {
        do {
            Elem *p = DAT_00331364.data[i];
            if (p != 0) {
                delete[] p;
                DAT_00331364.data[i] = 0;
            }
            i++;
        } while (i < DAT_00331364.size);
    }
    shrink(Alloc());
}

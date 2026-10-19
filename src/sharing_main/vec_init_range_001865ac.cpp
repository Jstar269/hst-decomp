/* HSTMATCH module=hstp_trans_main.prx start=0x001865ac end=0x001866a4 symbol=FUN_001865ac lang=c++ */
/* Clone of src/eboot/vec_init_range_00179eb8.cpp (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#pragma inline_depth(8)

extern "C" {
struct Reent_001865ac { int pad[3]; void *err; };
void FUN_000043b4(void);
void *FUN_000111c0(void *dst, const void *src, unsigned n);
Reent_001865ac *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d24f0[];
}

typedef void *Elem_001865ac;
struct Alloc_001865ac {
    Elem_001865ac *allocate(unsigned n) { return (Elem_001865ac *)FUN_00000bcc(n * sizeof(Elem_001865ac)); }
};

struct Vec_001865ac {
    Elem_001865ac *data;
    int size;
    unsigned capacity;
    void reserve(unsigned n, Alloc_001865ac al) {
        if (n > 0x3fffffffu)
            FUN_000043b4();
        Elem_001865ac *p = al.allocate(n);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d24f0);
            FUN_0000d530();
        }
        data = p;
        capacity = n;
    }
};

extern "C" void FUN_001865ac(Vec_001865ac *v, Elem_001865ac *first, Elem_001865ac *last) {
    int n = ((char *)last - (char *)first) / (int)sizeof(Elem_001865ac);
    if (n != 0) {
        v->reserve(n, Alloc_001865ac());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_001865ac));
        v->size += n;
    }
}

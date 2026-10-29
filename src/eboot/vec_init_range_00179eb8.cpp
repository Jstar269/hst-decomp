/* HSTMATCH module=EBOOT.BIN start=0x00179eb8 end=0x00179fb0 symbol=FUN_00179eb8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#pragma inline_depth(8)

extern "C" {
struct Reent_00179eb8 { int pad[3]; void *err; };
void FUN_000043b4(void);
void *FUN_000111c0(void *dst, const void *src, unsigned n);
Reent_00179eb8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c1ff8[];
}

typedef void *Elem_00179eb8;
struct Alloc_00179eb8 {
    Elem_00179eb8 *allocate(unsigned n) { return (Elem_00179eb8 *)FUN_00000bcc(n * sizeof(Elem_00179eb8)); }
};

struct Vec_00179eb8 {
    Elem_00179eb8 *data;
    int size;
    unsigned capacity;
    void reserve(unsigned n, Alloc_00179eb8 al) {
        if (n > 0x3fffffffu)
            FUN_000043b4();
        Elem_00179eb8 *p = al.allocate(n);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1ff8);
            FUN_0000d518();
        }
        data = p;
        capacity = n;
    }
};

/* Initialise the vector from the range [first, last): reserve exactly the range size, then copy. */
extern "C" void FUN_00179eb8(Vec_00179eb8 *v, Elem_00179eb8 *first, Elem_00179eb8 *last) {
    int n = ((char *)last - (char *)first) / (int)sizeof(Elem_00179eb8);
    if (n != 0) {
        v->reserve(n, Alloc_00179eb8());
        FUN_000111c0(v->data + v->size, first, (last - first) * sizeof(Elem_00179eb8));
        v->size += n;
    }
}

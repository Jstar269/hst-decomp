/* HSTMATCH module=EBOOT.BIN start=0x0005f230 end=0x0005f300 symbol=FUN_0005f230 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Bit-vector storage reserve: allocate ((n - 1) / 32 + 1) words, report allocation failure on newlib stderr
   and abort, move the words in use (size counts bits) into the new block, free the old one. Names provisional. */
extern "C" {
struct Reent { int pad[3]; void *err; };
Reent *FUN_0000fe3c(void);
void FUN_0005f300(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);                          /* operator new */
void FUN_00000a00(void *p);                                 /* operator delete */
void *FUN_000111c0(void *dst, const void *src, unsigned n); /* memmove */
extern char DAT_002bc5e0[]; /* "Memory allocation failure" */
}

struct BitVec {
    unsigned *data;
    unsigned size; /* bits */
    unsigned cap;  /* words */
};

extern "C" void FUN_0005f230(BitVec *v, unsigned n)
{
    unsigned words = (n - 1) / 32 + 1;
    unsigned *p = (unsigned *)FUN_00000bcc(words * 4);
    if (p == 0) {
        FUN_0005f300(FUN_0000fe3c()->err, DAT_002bc5e0);
        FUN_0000d518();
    }
    if (v->data != 0) {
        if (v->size != 0) {
            unsigned *end = v->data + (v->size - 1) / 32 + 1;
            FUN_000111c0(p, v->data, (end - v->data) * 4);
        }
        FUN_00000a00(v->data);
    }
    v->data = p;
    v->cap = words;
}

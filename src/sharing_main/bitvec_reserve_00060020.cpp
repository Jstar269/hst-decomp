/* HSTMATCH module=hstp_trans_main.prx start=0x00060020 end=0x000600f0 symbol=FUN_00060020 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Bit-vector storage reserve: allocate ((n - 1) / 32 + 1) words, report allocation failure on newlib stderr
   and abort, move the words in use (size counts bits) into the new block, free the old one. Names provisional. */
extern "C" {
struct Reent { int pad[3]; void *err; };
Reent *FUN_0000fe3c(void);
void FUN_000600f0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);                          /* operator new */
void FUN_00000a00(void *p);                                 /* operator delete */
void *FUN_000111c0(void *dst, const void *src, unsigned n); /* memmove */
extern char DAT_002cc430[]; /* "Memory allocation failure" */
}

struct BitVec {
    unsigned *data;
    unsigned size; /* bits */
    unsigned cap;  /* words */
};

extern "C" void FUN_00060020(BitVec *v, unsigned n)
{
    unsigned words = (n - 1) / 32 + 1;
    unsigned *p = (unsigned *)FUN_00000bcc(words * 4);
    if (p == 0) {
        FUN_000600f0(FUN_0000fe3c()->err, DAT_002cc430);
        FUN_0000d530();
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

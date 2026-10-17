/* HSTMATCH module=hstp_trans_main.prx start=0x001b4534 end=0x001b45e4 symbol=FUN_001b4534 lang=c++ */
/* Clone of src/eboot/vec_reset_reserve_0014a7bc.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Word vector re-reserve: clear the size through `int n = size; shrink(n, Alloc());` (unfolded size - size;
   the empty allocator temporary gives the 16-byte frame slot), free the old block, then the inline reserve(n)
   (length check through 0x43b4, allocate, report failure on newlib stderr and abort). The second argument
   is unused. Names provisional. */
extern "C" {
struct Reent_001b4534 { int pad[3]; void *err; };
Reent_001b4534 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002cc2a0[];
}
struct Alloc_001b4534 { void **allocate(unsigned n) { return (void **)FUN_00000bcc(n << 2); } };
struct Vec_001b4534 {
    void **data; int size; unsigned capacity;
    void shrink(int n, Alloc_001b4534) { size -= n; }
    void reserve(unsigned n)
    {
        if (n > 0x3fffffff)
            FUN_000043b4();
        void **p = Alloc_001b4534().allocate(n);
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc2a0);
            FUN_0000d530();
        }
        data = p;
        capacity = n;
    }
};
extern "C" void FUN_001b4534(Vec_001b4534 *v, int x, unsigned n)
{
    int k = v->size;
    v->shrink(k, Alloc_001b4534());
    if (v->data) {
        operator delete(v->data);
        v->data = 0;
        v->capacity = 0;
    }
    v->reserve(n);
}

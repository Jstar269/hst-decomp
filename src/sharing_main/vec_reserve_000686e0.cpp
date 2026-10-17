/* HSTMATCH module=hstp_trans_main.prx start=0x000686e0 end=0x00068788 symbol=FUN_000686e0 lang=c++ */
/* Clone of src/eboot/vec_reserve_0005e954.cpp (hstclone.py tag x10): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000686e0 { int pad[3]; void *err; };
Reent_000686e0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037717c[];
extern char DAT_002cc484[];
}
struct Elem_000686e0 { int w[3]; };
struct Alloc_000686e0 { Elem_000686e0 *allocate(unsigned n) { return (Elem_000686e0 *)FUN_00000bcc(n * sizeof(Elem_000686e0)); } };
struct Vec_000686e0 { Elem_000686e0 *data; int size; unsigned capacity; };
extern "C" void FUN_000686e0(Vec_000686e0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000686e0)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037717c);
        FUN_0000d530();
    }
    Elem_000686e0 *p = Alloc_000686e0().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc484);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

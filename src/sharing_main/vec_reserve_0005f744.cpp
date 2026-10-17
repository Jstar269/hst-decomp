/* HSTMATCH module=hstp_trans_main.prx start=0x0005f744 end=0x0005f7ec symbol=FUN_0005f744 lang=c++ */
/* Clone of src/eboot/vec_reserve_0005e954.cpp (hstclone.py tag x10): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0005f744 { int pad[3]; void *err; };
Reent_0005f744 *FUN_0000fe3c(void);
int FUN_0005dfc0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00376dd8[];
extern char DAT_002cc3f8[];
}
struct Elem_0005f744 { int w[3]; };
struct Alloc_0005f744 { Elem_0005f744 *allocate(unsigned n) { return (Elem_0005f744 *)FUN_00000bcc(n * sizeof(Elem_0005f744)); } };
struct Vec_0005f744 { Elem_0005f744 *data; int size; unsigned capacity; };
extern "C" void FUN_0005f744(Vec_0005f744 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0005f744)) {
        FUN_0005dfc0(FUN_0000fe3c()->err, DAT_00376dd8);
        FUN_0000d530();
    }
    Elem_0005f744 *p = Alloc_0005f744().allocate(n);
    if (p == 0) {
        FUN_0005dfc0(FUN_0000fe3c()->err, DAT_002cc3f8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

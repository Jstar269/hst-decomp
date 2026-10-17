/* HSTMATCH module=hstp_trans_main.prx start=0x000db7ac end=0x000db848 symbol=FUN_000db7ac lang=c++ */
/* Clone of src/eboot/vec_reserve_00091764.cpp (hstclone.py tag x17): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 32-byte element type: length check against max_size (0xffffffff / 32), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_000db7ac { int pad[3]; void *err; };
Reent_000db7ac *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_0037d344[];
extern char DAT_002d0800[];
}
struct Elem_000db7ac { int w[8]; };
struct Alloc_000db7ac { Elem_000db7ac *allocate(unsigned n) { return (Elem_000db7ac *)FUN_00000bcc(n * sizeof(Elem_000db7ac)); } };
struct Vec_000db7ac { Elem_000db7ac *data; int size; unsigned capacity; };
extern "C" void FUN_000db7ac(Vec_000db7ac *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_000db7ac)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0037d344);
        FUN_0000d530();
    }
    Elem_000db7ac *p = Alloc_000db7ac().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d0800);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

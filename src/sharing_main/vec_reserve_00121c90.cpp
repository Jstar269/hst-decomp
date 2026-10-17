/* HSTMATCH module=hstp_trans_main.prx start=0x00121c90 end=0x00121d38 symbol=FUN_00121c90 lang=c++ */
/* Clone of src/eboot/vec_reserve_0005e954.cpp (hstclone.py tag x10): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_00121c90 { int pad[3]; void *err; };
Reent_00121c90 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003801bc[];
extern char DAT_002d15f8[];
}
struct Elem_00121c90 { int w[3]; };
struct Alloc_00121c90 { Elem_00121c90 *allocate(unsigned n) { return (Elem_00121c90 *)FUN_00000bcc(n * sizeof(Elem_00121c90)); } };
struct Vec_00121c90 { Elem_00121c90 *data; int size; unsigned capacity; };
extern "C" void FUN_00121c90(Vec_00121c90 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00121c90)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003801bc);
        FUN_0000d530();
    }
    Elem_00121c90 *p = Alloc_00121c90().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d15f8);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

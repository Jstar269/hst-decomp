/* HSTMATCH module=hstp_trans_main.prx start=0x00248740 end=0x002487d0 symbol=FUN_00248740 lang=c++ */
/* Clone of src/eboot/vec_reserve_t_00238608.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 28-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00248740 { int pad[3]; void *err; };
Reent_00248740 *FUN_0000fe3c(void);
int FUN_002448c4(void *stream, const char *format, ...);
void FUN_0000d530(void);
void FUN_000043b4(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002da4c4[];
}
struct Elem_00248740 { int w[7]; };
struct Alloc_00248740 { Elem_00248740 *allocate(unsigned n) { return (Elem_00248740 *)FUN_00000bcc(n * sizeof(Elem_00248740)); } };
struct Vec_00248740 { Elem_00248740 *data; int size; unsigned capacity; };
extern "C" void FUN_00248740(Vec_00248740 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00248740))
        FUN_000043b4();
    Elem_00248740 *p = Alloc_00248740().allocate(n);
    if (p == 0) {
        FUN_002448c4(FUN_0000fe3c()->err, DAT_002da4c4);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

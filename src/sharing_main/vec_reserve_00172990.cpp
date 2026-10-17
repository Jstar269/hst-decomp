/* HSTMATCH module=hstp_trans_main.prx start=0x00172990 end=0x00172a38 symbol=FUN_00172990 lang=c++ */
/* Clone of src/eboot/vec_reserve_001667cc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 20-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00172990 { int pad[3]; void *err; };
Reent_00172990 *FUN_0000fe3c(void);
int FUN_001701e0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003879a4[];
extern char DAT_002d21cc[];
}
struct Elem_00172990 { int w[5]; };
struct Alloc_00172990 { Elem_00172990 *allocate(unsigned n) { return (Elem_00172990 *)FUN_00000bcc(n * sizeof(Elem_00172990)); } };
struct Vec_00172990 { Elem_00172990 *data; int size; unsigned capacity; };
extern "C" void FUN_00172990(Vec_00172990 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00172990)) {
        FUN_001701e0(FUN_0000fe3c()->err, DAT_003879a4);
        FUN_0000d530();
    }
    Elem_00172990 *p = Alloc_00172990().allocate(n);
    if (p == 0) {
        FUN_001701e0(FUN_0000fe3c()->err, DAT_002d21cc);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

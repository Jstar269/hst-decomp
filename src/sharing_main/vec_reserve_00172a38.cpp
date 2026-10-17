/* HSTMATCH module=hstp_trans_main.prx start=0x00172a38 end=0x00172ad4 symbol=FUN_00172a38 lang=c++ */
/* Clone of src/eboot/vec_reserve_00166874.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 2-byte element type (template instance, hsttmpl.py tag t1): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00172a38 { int pad[3]; void *err; };
Reent_00172a38 *FUN_0000fe3c(void);
int FUN_001701e0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003879a4[];
extern char DAT_002d21b0[];
}
struct Elem_00172a38 { char b[2]; };
struct Alloc_00172a38 { Elem_00172a38 *allocate(unsigned n) { return (Elem_00172a38 *)FUN_00000bcc(n * sizeof(Elem_00172a38)); } };
struct Vec_00172a38 { Elem_00172a38 *data; int size; unsigned capacity; };
extern "C" void FUN_00172a38(Vec_00172a38 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00172a38)) {
        FUN_001701e0(FUN_0000fe3c()->err, DAT_003879a4);
        FUN_0000d530();
    }
    Elem_00172a38 *p = Alloc_00172a38().allocate(n);
    if (p == 0) {
        FUN_001701e0(FUN_0000fe3c()->err, DAT_002d21b0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

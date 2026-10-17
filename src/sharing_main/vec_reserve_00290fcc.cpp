/* HSTMATCH module=hstp_trans_main.prx start=0x00290fcc end=0x00291074 symbol=FUN_00290fcc lang=c++ */
/* Clone of src/eboot/vec_reserve_0006d828.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 40-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_00290fcc { int pad[3]; void *err; };
Reent_00290fcc *FUN_0000fe3c(void);
int FUN_002901fc(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003a76ac[];
extern char DAT_002daffc[];
}
struct Elem_00290fcc { int w[10]; };
struct Alloc_00290fcc { Elem_00290fcc *allocate(unsigned n) { return (Elem_00290fcc *)FUN_00000bcc(n * sizeof(Elem_00290fcc)); } };
struct Vec_00290fcc { Elem_00290fcc *data; int size; unsigned capacity; };
extern "C" void FUN_00290fcc(Vec_00290fcc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_00290fcc)) {
        FUN_002901fc(FUN_0000fe3c()->err, DAT_003a76ac);
        FUN_0000d530();
    }
    Elem_00290fcc *p = Alloc_00290fcc().allocate(n);
    if (p == 0) {
        FUN_002901fc(FUN_0000fe3c()->err, DAT_002daffc);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

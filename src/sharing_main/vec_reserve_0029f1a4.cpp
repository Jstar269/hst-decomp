/* HSTMATCH module=hstp_trans_main.prx start=0x0029f1a4 end=0x0029f24c symbol=FUN_0029f1a4 lang=c++ */
/* Clone of src/eboot/vec_reserve_00238964.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 28-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0029f1a4 { int pad[3]; void *err; };
Reent_0029f1a4 *FUN_0000fe3c(void);
int FUN_0029baf0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003a7e44[];
extern char DAT_002db190[];
}
struct Elem_0029f1a4 { int w[7]; };
struct Alloc_0029f1a4 { Elem_0029f1a4 *allocate(unsigned n) { return (Elem_0029f1a4 *)FUN_00000bcc(n * sizeof(Elem_0029f1a4)); } };
struct Vec_0029f1a4 { Elem_0029f1a4 *data; int size; unsigned capacity; };
extern "C" void FUN_0029f1a4(Vec_0029f1a4 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0029f1a4)) {
        FUN_0029baf0(FUN_0000fe3c()->err, DAT_003a7e44);
        FUN_0000d530();
    }
    Elem_0029f1a4 *p = Alloc_0029f1a4().allocate(n);
    if (p == 0) {
        FUN_0029baf0(FUN_0000fe3c()->err, DAT_002db190);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

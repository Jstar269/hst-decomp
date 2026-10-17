/* HSTMATCH module=hstp_trans_main.prx start=0x0028caf0 end=0x0028cb98 symbol=FUN_0028caf0 lang=c++ */
/* Clone of src/eboot/vec_reserve_0014b2b0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Container reserve for a 48-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0028caf0 { int pad[3]; void *err; };
Reent_0028caf0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003a73d4[];
extern char DAT_002daf8c[];
}
struct Elem_0028caf0 { int w[12]; };
struct Alloc_0028caf0 { Elem_0028caf0 *allocate(unsigned n) { return (Elem_0028caf0 *)FUN_00000bcc(n * sizeof(Elem_0028caf0)); } };
struct Vec_0028caf0 { Elem_0028caf0 *data; int size; unsigned capacity; };
extern "C" void FUN_0028caf0(Vec_0028caf0 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0028caf0)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003a73d4);
        FUN_0000d530();
    }
    Elem_0028caf0 *p = Alloc_0028caf0().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002daf8c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

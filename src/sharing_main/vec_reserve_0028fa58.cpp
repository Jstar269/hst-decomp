/* HSTMATCH module=hstp_trans_main.prx start=0x0028fa58 end=0x0028fb08 symbol=FUN_0028fa58 lang=c++ data=0x003a7588 */
/* Clone of src/eboot/vec_reserve_0027e614.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a7588-0x003a759c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve for a 104-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_0028fa58 { int pad[3]; void *err; };
Reent_0028fa58 *FUN_0000fe3c(void);
int FUN_0028f3ac(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dafe0[];
}
struct Elem_0028fa58 { int w[26]; };
struct Alloc_0028fa58 { Elem_0028fa58 *allocate(unsigned n) { return (Elem_0028fa58 *)FUN_00000bcc(n * sizeof(Elem_0028fa58)); } };
struct Vec_0028fa58 { Elem_0028fa58 *data; int size; unsigned capacity; };
extern "C" void FUN_0028fa58(Vec_0028fa58 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0028fa58)) {
        FUN_0028f3ac(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    Elem_0028fa58 *p = Alloc_0028fa58().allocate(n);
    if (p == 0) {
        FUN_0028f3ac(FUN_0000fe3c()->err, DAT_002dafe0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

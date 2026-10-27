/* HSTMATCH module=hstp_trans_main.prx start=0x002c4794 end=0x002c4844 symbol=FUN_002c4794 lang=c++ data=0x003ac338 */
/* Clone of src/eboot/vec_reserve_002b4cd4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003ac338-0x003ac34c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve for a 100-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_002c4794 { int pad[3]; void *err; };
Reent_002c4794 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dc7c0[];
}
struct Elem_002c4794 { int w[25]; };
struct Alloc_002c4794 { Elem_002c4794 *allocate(unsigned n) { return (Elem_002c4794 *)FUN_00000bcc(n * sizeof(Elem_002c4794)); } };
struct Vec_002c4794 { Elem_002c4794 *data; int size; unsigned capacity; };
extern "C" void FUN_002c4794(Vec_002c4794 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002c4794)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    Elem_002c4794 *p = Alloc_002c4794().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dc7c0);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

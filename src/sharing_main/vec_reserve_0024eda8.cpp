/* HSTMATCH module=hstp_trans_main.prx start=0x0024eda8 end=0x0024ee50 symbol=FUN_0024eda8 lang=c++ data=0x0039de80 */
/* Clone of src/eboot/vec_reserve_0005e954.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0039de80-0x0039de94) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve for a 12-byte element type: length check against max_size (0xffffffff / 12), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0024eda8 { int pad[3]; void *err; };
Reent_0024eda8 *FUN_0000fe3c(void);
int FUN_0024e66c(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002daa5c[];
}
struct Elem_0024eda8 { int w[3]; };
struct Alloc_0024eda8 { Elem_0024eda8 *allocate(unsigned n) { return (Elem_0024eda8 *)FUN_00000bcc(n * sizeof(Elem_0024eda8)); } };
struct Vec_0024eda8 { Elem_0024eda8 *data; int size; unsigned capacity; };
extern "C" void FUN_0024eda8(Vec_0024eda8 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0024eda8)) {
        FUN_0024e66c(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    Elem_0024eda8 *p = Alloc_0024eda8().allocate(n);
    if (p == 0) {
        FUN_0024e66c(FUN_0000fe3c()->err, DAT_002daa5c);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

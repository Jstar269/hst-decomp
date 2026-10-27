/* HSTMATCH module=hstp_trans_main.prx start=0x0015babc end=0x0015bb58 symbol=FUN_0015babc lang=c++ data=0x00383848 */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383848-0x0038385c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0015babc { int pad[3]; void *err; };
Reent_0015babc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d1e70[];
}
struct Elem_0015babc { int w[2]; };
struct Alloc_0015babc { Elem_0015babc *allocate(unsigned n) { return (Elem_0015babc *)FUN_00000bcc(n * sizeof(Elem_0015babc)); } };
struct Vec_0015babc { Elem_0015babc *data; int size; unsigned capacity; };
extern "C" void FUN_0015babc(Vec_0015babc *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0015babc)) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    Elem_0015babc *p = Alloc_0015babc().allocate(n);
    if (p == 0) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1e70);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

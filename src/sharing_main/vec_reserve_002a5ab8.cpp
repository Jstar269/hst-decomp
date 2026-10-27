/* HSTMATCH module=hstp_trans_main.prx start=0x002a5ab8 end=0x002a5b60 symbol=FUN_002a5ab8 lang=c++ data=0x003a8b4c */
/* Clone of src/eboot/vec_reserve_002944ac.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a8b4c-0x003a8b60) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Container reserve for a 10-byte element type (template instance, hsttmpl.py tag t2): length check
   against max_size, allocate n elements through an allocator temporary, report failures on newlib stderr
   and abort. Names provisional. */
extern "C" {
struct Reent_002a5ab8 { int pad[3]; void *err; };
Reent_002a5ab8 *FUN_0000fe3c(void);
int FUN_002a5a8c(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002db278[];
}
struct Elem_002a5ab8 { char b[10]; };
struct Alloc_002a5ab8 { Elem_002a5ab8 *allocate(unsigned n) { return (Elem_002a5ab8 *)FUN_00000bcc(n * sizeof(Elem_002a5ab8)); } };
struct Vec_002a5ab8 { Elem_002a5ab8 *data; int size; unsigned capacity; };
extern "C" void FUN_002a5ab8(Vec_002a5ab8 *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_002a5ab8)) {
        FUN_002a5a8c(FUN_0000fe3c()->err, "vector length error");
        FUN_0000d530();
    }
    Elem_002a5ab8 *p = Alloc_002a5ab8().allocate(n);
    if (p == 0) {
        FUN_002a5a8c(FUN_0000fe3c()->err, DAT_002db278);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

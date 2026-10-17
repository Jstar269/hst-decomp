/* HSTMATCH module=hstp_trans_main.prx start=0x0029f24c end=0x0029f2e8 symbol=FUN_0029f24c lang=c++ */
/* Clone of src/eboot/vec_reserve_0010984c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Container reserve for a 8-byte element type: length check against max_size (0xffffffff / 8), allocate
   n elements through an allocator temporary (32-byte frame), report failures on newlib stderr and abort.
   Names provisional. */
extern "C" {
struct Reent_0029f24c { int pad[3]; void *err; };
Reent_0029f24c *FUN_0000fe3c(void);
int FUN_0029baf0(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_003a7e44[];
extern char DAT_002db174[];
}
struct Elem_0029f24c { int w[2]; };
struct Alloc_0029f24c { Elem_0029f24c *allocate(unsigned n) { return (Elem_0029f24c *)FUN_00000bcc(n * sizeof(Elem_0029f24c)); } };
struct Vec_0029f24c { Elem_0029f24c *data; int size; unsigned capacity; };
extern "C" void FUN_0029f24c(Vec_0029f24c *v, unsigned n)
{
    if (n > 0xffffffffu / sizeof(Elem_0029f24c)) {
        FUN_0029baf0(FUN_0000fe3c()->err, DAT_003a7e44);
        FUN_0000d530();
    }
    Elem_0029f24c *p = Alloc_0029f24c().allocate(n);
    if (p == 0) {
        FUN_0029baf0(FUN_0000fe3c()->err, DAT_002db174);
        FUN_0000d530();
    }
    v->data = p;
    v->capacity = n;
}

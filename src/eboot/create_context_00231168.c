/* HSTMATCH module=EBOOT.BIN start=0x00231168 end=0x002311cc symbol=FUN_00231168 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct, shared assignment join; exact match verified; names and types await human review. */

extern char DAT_002f3650[];
extern char DAT_0030ebf4[];

extern void *FUN_00000bcc(unsigned int size);
extern void FUN_0001cad0(void *lock, int mode, void *name);
extern void FUN_0001cb88(void *lock);
extern void *FUN_0022cdd0(void *p, unsigned char flag);

struct Obj_00231168 {
    void *ptr0;               // +0
    int pad4;                 // +4
    unsigned char flag8;      // +8
};

void FUN_00231168(struct Obj_00231168 *self)
{
    void *p;

    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002f3650);
    p = FUN_00000bcc(0x418);
    if (p != 0) {
        p = FUN_0022cdd0(p, self->flag8);
    }
    self->ptr0 = p;
    FUN_0001cb88(&DAT_0030ebf4);
}

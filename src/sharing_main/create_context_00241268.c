/* HSTMATCH module=hstp_trans_main.prx start=0x00241268 end=0x002412cc symbol=FUN_00241268 lang=c99 */
/* Clone of src/eboot/create_context_00231168.c (hstclone.py tag u5fr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct, shared assignment join; exact match verified; names and types await human review. */

extern char DAT_0039bf14[];
extern char DAT_003b7ebc[];

extern void *FUN_00000bcc(unsigned int size);
extern void FUN_0001c684(void *lock, int mode, void *name);
extern void FUN_0001c73c(void *lock);
extern void *FUN_0023ced0(void *p, unsigned char flag);

struct Obj_00241268 {
    void *ptr0;               // +0
    int pad4;                 // +4
    unsigned char flag8;      // +8
};

void FUN_00241268(struct Obj_00241268 *self)
{
    void *p;

    FUN_0001c684(&DAT_003b7ebc, 1, DAT_0039bf14);
    p = FUN_00000bcc(0x418);
    if (p != 0) {
        p = FUN_0023ced0(p, self->flag8);
    }
    self->ptr0 = p;
    FUN_0001c73c(&DAT_003b7ebc);
}

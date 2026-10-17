/* HSTMATCH module=hstp_trans_main.prx start=0x002af39c end=0x002af3f0 symbol=FUN_002af39c lang=c99 */
/* Clone of src/eboot/state_cleanup_002a0058.c (hstclone.py tag u6cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_002dbbc4[];
extern int FUN_002c7748(int);
extern void FUN_002ad710(const char *, int);
struct Obj { char pad[0x28]; int state; };
void FUN_002af39c(struct Obj *self)
{
    int state = self->state;
    if (state < 0)
        return;
    int result = FUN_002c7748(state);
    if (result != 0)
        FUN_002ad710(DAT_002dbbc4, result);
    self->state = -1;
}

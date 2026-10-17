/* HSTMATCH module=hstp_trans_main.prx start=0x0022d130 end=0x0022d170 symbol=FUN_0022d130 lang=c99 */
/* Clone of src/eboot/cleanup_handle_20c_0021dbbc.c (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_0022d130.c (tag: a1) */
struct Obj {
    char pad[0x20c];
    int handle;
};

extern unsigned int DAT_003eaad8;
extern int FUN_001c0018(void *, int *);

void FUN_0022d130(struct Obj *param_1)
{
    if (param_1->handle >= 0) {
        FUN_001c0018(&DAT_003eaad8, &param_1->handle);
        param_1->handle = -1;
    }
}

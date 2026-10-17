/* HSTMATCH module=hstp_trans_main.prx start=0x00203184 end=0x002031c4 symbol=FUN_00203184 lang=c99 */
/* Clone of src/eboot/cleanup_handle_5b4_001f4bbc.c (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_00203184.c (tag: a1) */
struct Obj {
    char pad[0x5b4];
    int handle;
};

extern unsigned int DAT_003eaad8;
extern int FUN_001c0018(void *, int *);

void FUN_00203184(struct Obj *param_1)
{
    if (param_1->handle >= 0) {
        FUN_001c0018(&DAT_003eaad8, &param_1->handle);
        param_1->handle = -1;
    }
}

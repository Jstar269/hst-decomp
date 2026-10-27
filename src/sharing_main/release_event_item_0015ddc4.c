/* HSTMATCH module=hstp_trans_main.prx start=0x0015ddc4 end=0x0015de48 symbol=FUN_0015ddc4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same shape as src/eboot/FUN_00151ce4.c (EBOOT 0x00151ce4, only addresses differ). When the debug flag
   is set, passes the argument to FUN_00158b2c and logs "ReleaseEventItem[%s]
" with "soon" (flag at +8
   set) or ""; then FUN_0023b9b0(0) and FUN_002352c8(DAT_003f3610, 0, flag == 0). */
extern char DAT_00383928[];
extern char DAT_00383ac0[];
extern unsigned char DAT_003e9630;
extern void *DAT_003f3610;
extern char DAT_00383aa8[];
extern void FUN_00158b2c(int);
extern void FUN_0015bb68(char *, char *);
extern void FUN_002352c8(void *, int, int);
extern void FUN_0023b9b0(int);

typedef struct {
    char pad0[8];
    unsigned char f8;
} Obj;

int FUN_0015ddc4(Obj *self, int arg)
{
    char *msg;

    if (DAT_003e9630 != 0) {
        FUN_00158b2c(arg);
        if (self->f8 != 0) {
            msg = DAT_00383ac0;
        } else {
            msg = DAT_00383928;
        }
        FUN_0015bb68(DAT_00383aa8, msg);
    }
    FUN_0023b9b0(0);
    FUN_002352c8(DAT_003f3610, 0, (self->f8 != 0) ^ 1);
    return 0;
}

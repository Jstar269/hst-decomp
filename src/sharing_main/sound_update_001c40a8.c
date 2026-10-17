/* HSTMATCH module=hstp_trans_main.prx start=0x001c40a8 end=0x001c412c symbol=FUN_001c40a8 lang=c99 */
/* Clone of src/eboot/sound_update_001b63e8.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: switch on DAT_003f39a8, struct member access, symbol address DAT_003eaad8; exact match verified; names and types await human review. */

struct Obj {
    char pad[0x90];
    char f90;
    char pad1[2];
    char f93;
};

extern int DAT_003eaafc;
extern int DAT_003f39a8;
extern const char DAT_00391580;
extern void *DAT_003eaad8;
extern void FUN_00000020(const void *);
extern void FUN_00000028(void);
extern void FUN_001c1d7c(const void *);
extern void FUN_001c2a10(int);
extern void FUN_001c412c(struct Obj *);
extern char FUN_0023c334(void);

void FUN_001c40a8(struct Obj *param_1)
{
  FUN_00000020(&DAT_00391580);
  param_1->f90 = 0;
  param_1->f93 = 0;
  switch (DAT_003f39a8) {
  case 0x2a:
    param_1->f90 = 1;
    param_1->f93 = FUN_0023c334();
    break;
  }
  FUN_001c2a10(DAT_003eaafc);
  FUN_001c412c(param_1);
  FUN_001c1d7c(&DAT_003eaad8);
  FUN_00000028();
}

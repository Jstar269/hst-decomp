/* HSTMATCH module=EBOOT.BIN start=0x00154854 end=0x001548e0 symbol=FUN_00154854 lang=c99 */
extern unsigned char DAT_003402f0;
extern int DAT_002dc93c[];
extern int DAT_002dc954[];
extern int DAT_002dc440[];
extern void FUN_0014d044(int);
extern void FUN_0014fd94(int *, int, int, int *);
extern void FUN_0028797c(int, int);

int FUN_00154854(int param_1, int param_2)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    int *msg = *(unsigned char *)(param_1 + 0x10) != 0 ? DAT_002dc954
                                                        : DAT_002dc440;
    FUN_0014fd94(DAT_002dc93c, *(int *)(param_1 + 8), *(int *)(param_1 + 0xc), msg);
  }
  if (*(int *)(param_2 + 0xc) != 0)
    FUN_0028797c(*(int *)(param_1 + 8), *(int *)(param_1 + 0xc));
  return 0;
}

// NEAR MISS: 35 words retail (37 ours), 26 differ.
// Ours emits `addiu a0,s1,8` / `addiu v1,s1,12` (addresses of the two fields) plus a second
// `beqz v0` around the ternary arm, so the arg setup and the whole tail shift by 2 words; retail
// tests the byte flag once (`beqzl v0`) and picks the message with `lui a3,0x2e; b; addiu -13996`
// vs `addiu -15296`. Ruled out: the ternary inline, a named `int *msg` local before the call.
// Note: the three string symbols are 0x2dc93c/0x2dc954/0x2dc440 (lui 0x2e + negative addiu).
// near miss from lane fm2 (unreviewed)

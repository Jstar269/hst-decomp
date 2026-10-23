/* HSTMATCH module=EBOOT.BIN start=0x001f9f70 end=0x001fa018 symbol=FUN_001f9f70 lang=c99 */
extern int DAT_0034a678;
extern unsigned char DAT_003418bc[];
extern int DAT_003386b0;
extern unsigned char DAT_00341954;
extern void FUN_0008882c(int);
extern int FUN_001fb524(int);
extern void FUN_0024e07c(int, int);
extern void FUN_0024e0ec(int, int);

void FUN_001f9f70(int param_1, int param_2)
{
    int uVar1;

    if (DAT_0034a678 != 0x31 || DAT_003418bc[*(int *)(param_1 + 0x3cc) * 0x120] != 0) {
        return;
    }
    FUN_0008882c(DAT_003386b0);
    uVar1 = FUN_001fb524(param_1);
    FUN_0024e07c(param_2, uVar1);
    if (*(unsigned char *)(param_1 + 0x521) != 0) {
        FUN_0024e0ec(param_2, DAT_00341954);
    }
}
// NEAR MISS (lane fm3): 13 of 42 words; the body, every call, the 0x120-strided DAT_003418bc
// lookup and the DAT_00341954 tail all match. Retail's block order is
//   [test1: lw DAT_0034a678; li 49; beq a0,v1,L_test2 (delay move s0,a1)]
//   [b exit ; lw ra in the delay]
//   [L_test2: lw a1,972(s1); lui/addiu 0x3418bc; idx*288; lbu; bnez v1,exit ; nop]
//   [body ...] [exit: epilogue]
// ours always emits `bne a0,v1,exit` with the body inline after test2, i.e. the exit block ends up
// last instead of between the two tests.
// Ruled out: `if (A && B) {body}` (13 words), two guard-clause returns (13), a single
// `if (A != 49 || B != 0) return;` (13), nested ifs (33). The remaining difference is only which
// side of the first test is out of line.
// near miss from lane fm3 (unreviewed)

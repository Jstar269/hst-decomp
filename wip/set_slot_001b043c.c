/* HSTMATCH module=EBOOT.BIN start=0x001b043c end=0x001b04d0 symbol=FUN_001b043c lang=c99 */
extern void FUN_001b0610();
extern void FUN_001b0ef8(int, int, int, int, int);

void FUN_001b043c(int param_1, int param_2, int param_3, int param_4)
{
    int *piVar1;
    int uVar2;
    int iVar2;

    piVar1 = (int *)(param_2 * 4 + param_1 + 0x778);
    if (*piVar1 != 0) {
        FUN_001b0610();
    }
    iVar2 = param_3 + 0x15b;
    if (param_4 != 0) {
        uVar2 = 1;
    } else {
        uVar2 = 2;
    }
    FUN_001b0ef8(param_1, iVar2, uVar2, 0, 0);
    *piVar1 = *(int *)(param_1 + iVar2 * 4);
}
// NEAR MISS (lane fm3): ONE word of 37 - and it is `addu v0,s3,v0` vs retail's `addu v0,v0,s3`
// (operand order when adding param_1 to param_2*4). Keep: the field address is a POINTER local
// `int *p = (int *)(param_2 * 4 + param_1 + 0x778);` used as `*p` for both the test and the final
// store (that alone fixed ~20 words), `iVar2 = param_3 + 0x15b;` is computed ONCE before the
// if/else, and the constant select is `if (param_4 != 0) uVar2 = 1; else uVar2 = 2;`
// (retail puts the ==0/2 case out of line: beqz s1 -> li a2,2). Tried for the last word:
// `param_1 + param_2*4 + 0x778` (same), `param_2*4 + 0x778 + param_1` (worse: constant folded first,
// 4 words off).
// near miss from lane fm3 (unreviewed)

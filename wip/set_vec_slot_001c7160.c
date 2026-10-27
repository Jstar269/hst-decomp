/* HSTMATCH module=EBOOT.BIN start=0x001c7160 end=0x001c725c symbol=FUN_001c7160 lang=c99 */
extern void FUN_001ce7b0(int, unsigned int, int *, signed char);
extern void FUN_000009e4(void);
extern int FUN_00014a40(int);
extern int FUN_00000a90(int);
extern void FUN_000149a8(int, int);

void FUN_001c7160(int param_1, unsigned int param_2, int param_3)
{
    unsigned int uVar5;
    unsigned int uVar1;
    int iVar2;
    int iVar3;
    int uVar4;
    int local_4;

    if (param_2 >= *(unsigned int *)(param_1 + 0x68)) {
        local_4 = 0;
        uVar5 = *(unsigned int *)(param_1 + 0x68);
        uVar1 = param_2 + 1;
        if (uVar5 < uVar1) {
            FUN_001ce7b0(param_1 + 100, uVar1 - uVar5, &local_4, 0);
            iVar2 = *(int *)(param_1 + 100);
            goto L;
        }
        if (uVar1 < uVar5) {
            *(unsigned int *)(param_1 + 0x68) = uVar5 - uVar1;
        }
    }
    iVar2 = *(int *)(param_1 + 100);
L:
    if (*(int *)(iVar2 + param_2 * 4) != 0) {
        FUN_000009e4();
        *(int *)(*(int *)(param_1 + 100) + param_2 * 4) = 0;
    }
    iVar2 = *(int *)(param_1 + 100);
    iVar3 = FUN_00014a40(param_3);
    uVar4 = FUN_00000a90(iVar3 + 1);
    *(int *)(iVar2 + param_2 * 4) = uVar4;
    FUN_000149a8(*(int *)(*(int *)(param_1 + 100) + param_2 * 4), param_3);
}
// NEAR MISS (lane fm3): 60/63 words, 53 differ. Open gaps:
//  - retail's 4th argument to FUN_001ce7b0 is `move v0,zero; seb a3,v0` (a signed-char conversion
//    of a value mwcc knows is zero) -- we always get `move a3,zero`. Tried: literal 0, `local_4`,
//    `(signed char)local_4`, `*(signed char *)&local_4`, a `signed char z = 0;` local, with the
//    callee parameter declared both `int` and `signed char`;
//  - retail's `if (uVar1 < uVar5)` arm emits `subu v0,v1,v0` TWICE then `sw v0,104(s2)` with no
//    address temp, while we fold the base into a register (`addiu a0,s2,104`) and emit one subu;
//  - retail keeps param_2 in s1 and param_3 in s0 (we get the opposite), and the tail uses
//    `sll v1,s1,0x2; addu v0,v0,v1` (index materialised once) instead of our per-use `sll`.
// Structure that does match: the `if (param_2 >= *(uint*)(param_1+0x68))` guard with a goto out of
// the growth arm, one shared `iVar2 = *(int*)(param_1+100)` after the if/else, and the element
// null-test arm as `beqzl a0` over a shared iVar2 reload.
// near miss from lane fm3 (unreviewed)
// improved by lane dsm1 (unreviewed): no comparable result -> 53 differing words

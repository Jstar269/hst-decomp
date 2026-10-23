/* HSTMATCH module=EBOOT.BIN start=0x00294564 end=0x00294684 symbol=FUN_00294564 lang=c99 */
/* Hand-written reconstruction (external matching lane). Notes: Ghidra's `iVar2 = 0;` in the null arm of
   the 0x14-byte allocation does NOT exist in retail - dropping it is what removes the extra block
   (retail happily falls through to `*(int *)(iVar2 + 0x10) = 0` with a null iVar2). Both allocation
   guards are written with the non-null arm first (`if (puVar1 != 0)`) so the null case is the
   out-of-line block, and the null arm stores the pointer variable itself (`param_1[0xf] = (int)puVar1;`)
   rather than a literal 0, which is what puts `sw s0,60(s1)` in the beqzl delay slot.
   Exact match verified; names and types await human review. */
extern int DAT_00309e48;
extern char DAT_002cac84[];
extern int *DAT_0034a850;
extern int FUN_0001f06c();
extern int FUN_00000bcc(int);
extern void FUN_00294684(char *);
extern int FUN_000ff4fc(int, int);
extern int FUN_00010184(int, int);
extern void FUN_000114c0(int, int, int);

int *FUN_00294564(int *param_1)
{
    int *puVar1;
    int iVar2;
    int uVar3;

    FUN_0001f06c();
    *param_1 = (int)&DAT_00309e48;
    param_1[0xf] = 0;
    DAT_0034a850 = param_1;
    puVar1 = (int *)FUN_00000bcc(0xeb48);
    if (puVar1 != 0) {
        puVar1[0] = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        puVar1[4] = 0x7fffffff;
        puVar1[5] = 0x7fffffff;
        puVar1[6] = 0;
        puVar1[7] = 0;
        *(unsigned char *)(puVar1 + 8) = 0;
        *(unsigned char *)((int)puVar1 + 0x21) = 0;
        puVar1[9] = -1;
        puVar1[0xca] = 0;
        puVar1[0xcb] = -1;
        *(unsigned char *)(puVar1 + 0xcc) = 0;
        *(unsigned char *)((int)puVar1 + 0x331) = 1;
        puVar1[0xcd] = 0;
        puVar1[0x1dce] = 0;
        puVar1[0x3acf] = 0;
        puVar1[0x3ad0] = 0;
        FUN_00294684(DAT_002cac84);
        iVar2 = FUN_00000bcc(0x14);
        if (iVar2 != 0) {
            iVar2 = FUN_000ff4fc(iVar2, 0x40000);
            puVar1[0xcd] = iVar2;
        } else {
            puVar1[0xcd] = iVar2;
        }
        *(int *)(iVar2 + 0x10) = 0;
        *(int *)(iVar2 + 0xc) = 0;
        uVar3 = FUN_00010184(0x40, 0x200000);
        puVar1[1] = uVar3;
        FUN_000114c0(uVar3, 0, 0x200000);
        param_1[0xf] = (int)puVar1;
    } else {
        param_1[0xf] = (int)puVar1;
    }
    return param_1;
}

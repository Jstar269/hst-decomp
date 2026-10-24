/* HSTMATCH module=EBOOT.BIN start=0x0019d4a0 end=0x0019d6e0 symbol=FUN_0019d4a0 lang=c99 */
extern int DAT_00331c30;
extern int DAT_0034a678;
extern char DAT_00341d10;
extern char DAT_002e1b50[];
extern char DAT_002e1b5c[];
extern int FUN_00000bcc(int);
extern void FUN_000149a8(char *, char *);
extern int FUN_00193118(char *);
extern void FUN_0019335c(int *, int *, void *);
extern void FUN_0019346c(int *, int *, void *);
extern int FUN_00194030(int);
extern int FUN_00194348(void);
extern int FUN_001943ac(void);
extern int FUN_001943bc(void);
extern void FUN_0019dd0c(int, unsigned char *, int, int, int, int, int);

void FUN_0019d4a0(int param_1)
{
    int local_4;
    int local_8;
    int iVar3;
    int iVar1;
    unsigned char *puVar2;

    DAT_00331c30 = 0xbc75c28f;
    local_4 = 0;
    local_8 = 0;
    puVar2 = (unsigned char *)0x0;
    iVar3 = 0;
    switch (DAT_0034a678) {
    case 0x29:
        iVar1 = FUN_00194348();
        if (iVar1 == 0) {
            FUN_00194030(1);
        }
        puVar2 = (unsigned char *)&DAT_00341d10;
        FUN_0019335c(&local_4, &local_8, &DAT_00341d10);
        break;
    case 0x30:
        iVar1 = FUN_001943bc();
        if (iVar1 == 0) {
            FUN_001943ac();
        }
        puVar2 = (unsigned char *)&DAT_00341d10;
        FUN_0019346c(&local_4, &local_8, &DAT_00341d10);
        break;
    case 0x56:
        break;
    default:
        iVar3 = FUN_00194348();
        if (iVar3 == 0) {
            FUN_00194030(1);
        }
        iVar3 = 1;
        puVar2 = (unsigned char *)FUN_00193118(DAT_002e1b50);
        break;
    }
    if (iVar3 == 0) {
        param_1 = 0;
    }
    if (param_1 == 2) {
        puVar2[0x28] = 1;
        if (local_4 == 0) {
            puVar2[0x33] = 1;
            FUN_000149a8((char *)(puVar2 + 0x3e), DAT_002e1b5c);
            *(short *)(puVar2 + 0x36) = 0;
            *(short *)(puVar2 + 0x38) = 0;
        }
        if (local_8 == 0) {
            puVar2[0x34] = 1;
            FUN_000149a8((char *)(puVar2 + 0x4e), DAT_002e1b5c);
            *(short *)(puVar2 + 0x3a) = 0;
            *(short *)(puVar2 + 0x3c) = 0;
        }
        if (local_4 == 0 || local_8 == 0) {
            FUN_0019335c(&local_4, &local_8, puVar2);
        }
    } else if (param_1 == 1) {
        puVar2[0x28] = 0;
        if (local_4 == 0) {
            puVar2[0x33] = 1;
            FUN_000149a8((char *)(puVar2 + 0x3e), DAT_002e1b5c);
            *(short *)(puVar2 + 0x36) = 0;
            *(short *)(puVar2 + 0x38) = 0;
            FUN_0019335c(&local_4, &local_8, puVar2);
        }
    }
    iVar1 = FUN_00000bcc(0x490);
    if (iVar1 != 0) {
        FUN_0019dd0c(iVar1, puVar2, iVar3, 0, 0, local_4, local_8);
    }
}
// NEAR (142/144 words, 87 differ). One root cause: retail keeps the object pointer puVar2 in s0
// and the flag iVar3 in s1; this build has them the other way round, so every puVar2 access differs
// (and the tail call's a1/a2 moves). Declaration order (puVar2 first/last, initialiser vs statement),
// the zero-init statement order, `char *` vs `unsigned char *`, and a ternary `mode` local were all
// tried: the prologue can be made byte-identical (move s1,zero / move s0,zero) while the later
// allocation still rotates.
// The switch form is required for the dispatch: cases written 0x29, 0x30, 0x56 (empty body) + default
// give retail's `beq 0x56 / beq 0x30 / beq 0x29 / b default` chain in that test order; the
// equivalent if/else chain comes out as a bnel chain with the bodies reordered.
// Also: retail selects `if (iVar3 == 0) param_1 = 0;` into a0 (move a0,zero then beqzl s1 with
// move a0,s2), ours materialises it in s2 with a bnezl.
// near miss from lane fm8 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x00170a08 end=0x00170b30 symbol=FUN_00170a08 lang=c99 */
extern char *DAT_00341518;
extern int DAT_0034a77c;
extern int FUN_0024dd40(float, int);
extern int FUN_0024de88(int, int, int);

unsigned int FUN_00170a08(int param_1, unsigned int param_2, int param_3, int param_4)
{
    int i = 0;
    int uVar2;
    int iVar3;
    int uVar4;
    unsigned int uVar6 = param_2;

    uVar2 = (*(int (**)(int))(param_1 + 0x558))(param_1);
    iVar3 = (*(int (**)(int))(DAT_00341518 + 0x3e8))(uVar2);
    uVar2 = FUN_0024dd40(*(float *)(iVar3 + 4), DAT_0034a77c);
    if (FUN_0024de88(DAT_0034a77c, 0xf, uVar2) != 0) {
        uVar4 = 4;
    } else if (FUN_0024de88(DAT_0034a77c, 4, uVar2) != 0) {
        uVar4 = 3;
    } else {
        uVar4 = 2;
    }
    do {
        uVar6 = uVar6 + param_3;
        if ((int)uVar6 < 0) {
            if (param_4 != 0) {
                uVar6 = 3;
            } else {
                uVar6 = param_2;
                break;
            }
        } else if (3 < (int)uVar6) {
            if (param_4 != 0) {
                uVar6 = 0;
            } else {
                uVar6 = param_2;
                break;
            }
        }
        if ((int)uVar6 < uVar4) {
            break;
        }
        i = i + 1;
        if (10000 < i) {
            uVar6 = param_2;
            break;
        }
    } while (1);
    return uVar6;
}
// NEAR MISS (lane fm3): 74/74 words -- every instruction's opcode and operand shape matches retail;
// the only difference is which callee-saved register each variable landed in (retail: param_2 s0,
// uVar2 s1, i s2, uVar6 s3, param_4 s4, param_3 s5; ours: uVar2 s0, uVar6 s1, i s2, param_4 s3,
// param_3 s4, param_2 s5 -> 27 words differ, all register renames).
// Findings worth keeping: the 3rd argument of FUN_0024dd40 is a FLOAT loaded with lwc1 from
// *(float *)(iVar3 + 4); the three-way uVar4 pick prefers the `if (x != 0) {...} else if (y != 0)
// {...} else {...}` arm order (retail's beqzl/li pairs), and every early return is
// `uVar6 = param_2; break;` out of a `do { } while (1)` (which is what puts `move sN,s0` in the
// branch delay slots). Ruled out for the colouring: declaration order, initialising uVar6 before
// vs after i = 0, hoisting the float into a local.
// near miss from lane fm3 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x00049094 end=0x00049194 symbol=FUN_00049094 lang=c99 */
extern int DAT_002d072c;
extern unsigned char DAT_002d0730;
extern int DAT_002d0734;
extern int DAT_002d0738;
extern unsigned char DAT_00311140;
extern char DAT_00311170[];
extern void FUN_00050d8c(void *a, int b);
extern void FUN_002b7910(int a, int b);
extern void FUN_002b7928(int a, int b, int c);
extern int FUN_002b7940(int a, int b);
extern int FUN_002b79a8(int a);

int FUN_00049094(int param_1)
{
    if (DAT_002d0730 != 0)
        return 1;
    if (DAT_00311140 != 0) {
        if (param_1 != 0) {
            FUN_00050d8c(DAT_00311170, 0);
            FUN_002b7910(DAT_002d072c, 1);
            FUN_002b7928(DAT_002d0734, 1, 0);
            FUN_002b7928(DAT_002d072c, 1, 0);
        } else {
            int s = DAT_002d0734;
            s = FUN_002b7940(s, 1) ? -1 : s;
            if (DAT_002d0734 != s)
                return 0;
        }
        DAT_00311140 = 0;
    }
    if (FUN_002b79a8(DAT_002d0738) != 0)
        return 0;
    DAT_002d0738 = -1;
    DAT_002d0730 = 1;
    return 1;
}

// PARKED (dsn2). 64/65 words; ONE spot differs (0x4912c-0x49134): retail is the conditional-execute
// form `bnel v0,<next>; li s0,-1` (if (ret != 0) s = -1;), ours `beqz v0,<next>; nop; li s0,-1`.
// Everything else is word-identical, including the calls block, the shared DAT_00311140 = 0 join and
// the final `if (FUN_002b79a8(DAT_002d0738) != 0) return 0; ... return 1;` (beqzl polarity right).
// Tried for that one if (all compile to beqz+nop+li in isolation too): `if (F(ret,1)) s=-1;`,
// `!= 0`, `== 0 {} else {}`, empty-then, `s = F(...) ? -1 : s;`, `int e = F(...); if (e) s = -1;`,
// `bool e = ...`, pointer/unsigned return types, `else s = s`. Not found; the trigger is likely
// a contextual branch-prediction choice. Next: read the MWCC digest on likely-if heuristics.
// near miss from lane dsn2 (unreviewed)

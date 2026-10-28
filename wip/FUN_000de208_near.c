/* HSTMATCH module=EBOOT.BIN start=0x00000de208 end=0x00000de238 symbol=FUN_00000de208 lang=c99 */
struct S { char pad[134]; unsigned char f86; char pad2[156 - 134 - 1]; int f9c; };

int FUN_00000de208(struct S *s, int a1)
{
    int ok = (s->f86 != 0);
    if (!ok)
        return 0;
    if (a1 < 0)
        return 0;
    return s->f9c == a1;
}

// NEAR (1 structural word, 48 bytes; 0xde238/0xde268 are byte-offset twins at +135/+136).
// Retail: lbu 134(a0); sltu v0,zero,v0; beqz v0,RET0; slt v0,a1,zero; bnez v0,RET0; lw/xor/sltiu; jr ra;
// RET0 at the END (move v0,zero; jr ra). Ours always inverts the guards (bnez to the body / bgezl) because
// every spelling tried puts the body in the fall-through with the zero return first. Tried: && chain,
// early returns, nested if with else, `int ok = (f != 0); if (!ok) return 0;`, a1 >= 0 vs a1 < 0.
// near miss from lane dsn3 (unreviewed)

/* HSTMATCH module=hstp_trans_main.prx start=0x0023a6f8 end=0x0023a750 symbol=FUN_0023a6f8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* True when FUN_0023a2b0(a, b, 0) lies in [4, 7): in C the && keeps the first compare as the int return value (slti/xori, beqzl to the epilogue). Names provisional. */
extern int FUN_0023a2b0(int, int, int);

int FUN_0023a6f8(int a, int b)
{
    return FUN_0023a2b0(a, b, 0) >= 4 && FUN_0023a2b0(a, b, 0) < 7;
}

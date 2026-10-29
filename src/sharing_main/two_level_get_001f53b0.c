/* HSTMATCH module=hstp_trans_main.prx start=0x001f53b0 end=0x001f53dc symbol=FUN_001f53b0 lang=c99 */
/* Clone of src/eboot/two_level_get_001e7198.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: assignment inside the `&&` chain (`(b = *(...)) != 0`) — it keeps the second level in b
   and emits retail's `beqzl`/`beqz` pair with the lone `li v0,-1` used twice. The if/goto spelling with a
   single `return -1` is also exact; the two-`return -1` if-chain spelling is 7 words off. */
int FUN_001f53b0(int self)
{
    int a = *(int *)(self + 0x1d64);
    int b;
    if (a != 0 && (b = *(int *)(a + 0x16c)) != 0)
        return *(int *)(b + 0x6c);
    return -1;
}

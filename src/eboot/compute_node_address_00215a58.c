/* HSTMATCH module=EBOOT.BIN start=0x00215a58 end=0x00215ab8 symbol=FUN_00215a58 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (inputs/pseudocode/ram-0x00215a58.c, no hstgen tag) corrected by hand: the sign-extending byte field held in an int so no seb is emitted; readability pass; exact match verified; names and types await human review. */
enum { NODE_SIZE = 0x230, ENTRY_SIZE = 0x20 };

extern char *DAT_0034a6a8;
extern int FUN_000b3c68();
extern int FUN_0020b62c(int);

/* Address of node number id in the node array whose base is stored (at +0x14) in the 0x20-byte table entry picked by the byte at +0x14 of FUN_000b3c68()'s result (1-based). */
int FUN_00215a58(int id)
{
  int c = *(signed char *)(FUN_000b3c68() + 0x14);
  int n = FUN_0020b62c(id);

  return *(int *)(DAT_0034a6a8 + (c + -1) * ENTRY_SIZE + 0x14) + n * NODE_SIZE;
}

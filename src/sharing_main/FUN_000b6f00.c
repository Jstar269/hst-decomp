/* HSTMATCH module=hstp_trans_main.prx start=0x000b6f00 end=0x000b6f40 symbol=FUN_000b6f00 lang=c99 */
/* Clone of src/eboot/FUN_000b3ca0.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
extern void FUN_000007f4();
extern void FUN_00089f2c();
extern void FUN_000b6f40();

/* Construct the two 12-byte elements of the array (element constructor and destructor are passed in). */
int FUN_000b6f00(int array)
{
  FUN_000007f4(array,FUN_000b6f40,FUN_00089f2c,0xc,2);
  return array;
}

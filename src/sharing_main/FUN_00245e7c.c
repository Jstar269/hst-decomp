/* HSTMATCH module=hstp_trans_main.prx start=0x00245e7c end=0x00245ebc symbol=FUN_00245e7c lang=c99 */
/* Clone of src/eboot/FUN_00235d50.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_000007f4();
extern void FUN_00089e74();
extern void FUN_00245ebc();

enum { ELEM_SIZE = 0xc, ELEM_COUNT = 3 };

/* Constructs an array of ELEM_COUNT elements of ELEM_SIZE bytes (element constructor and destructor passed in). */
int FUN_00245e7c(int array)
{
  FUN_000007f4(array,FUN_00245ebc,FUN_00089e74,ELEM_SIZE,ELEM_COUNT);
  return array;
}

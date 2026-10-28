/* HSTMATCH module=EBOOT.BIN start=0x000baaa4 end=0x000baac8 symbol=FUN_000baaa4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64d); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_002b7ef8();

bool FUN_000baaa4(void)
{
  int iVar1;
  
  iVar1 = FUN_002b7ef8();
  return iVar1 == 1;
}

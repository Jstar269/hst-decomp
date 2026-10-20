/* HSTMATCH module=EBOOT.BIN start=0x002973a4 end=0x002973ec symbol=FUN_002973a4 lang=c99 */
/* WIP: 18 words differ (whole function). Retail spills all three parameters through an s8 frame pointer
   (`move s8,sp; sw a0,0(s8)..; lw a0,0(s8)`) and fills the jal delay slot with `lw t1,8(s8)`: unoptimised
   (-O0, frame-pointer) code from the original build. MWCC -O4,p tail-calls (`j 0x2973ec`); #pragma opt_level 0
   and cc=gcc171-O2 give other shapes. Needs an O0 profile we do not have. */

extern void FUN_002973ec(int a, int b, int c, int d, int e, int f);

void FUN_002973a4(int param_1, int param_2, int param_3)
{
  FUN_002973ec(param_1, param_2, 0, 0, param_2, param_3);
}
// near miss from lane ds6 (unreviewed)

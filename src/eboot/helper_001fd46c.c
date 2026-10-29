/* HSTMATCH module=EBOOT.BIN start=0x001fd46c end=0x001fd50c symbol=FUN_001fd46c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a/v1) corrected by hand: modelled the zero block as two four-word arrays and typed the float arguments; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Regulation screen: only the fields this function writes. */
typedef struct RegulationScreen {
  char pad00[0x1290];
  char enabled;          /* 0x1290 */
  char pad1291;
  u8 mode;               /* 0x1292 */
} RegulationScreen;

extern u32 DAT_00331b84;
extern void FUN_0001f1fc();
extern void FUN_00063830(float param_1,float param_2,u32 param_3,u32 *param_4,u32 *param_5,int param_6,int param_7,int param_8);
extern void FUN_001fd50c();

/* Stores the enabled flag and mode, runs the one-time init and, when enabled, calls FUN_00063830 with zeroed blocks. */
void FUN_001fd46c(RegulationScreen *self,u8 mode,int enabled)
{
  struct ZeroBlocks {
    u32 first[4];
    u32 second[4];
  } zeroBlocks;
  
  self->enabled = (char)enabled;
  self->mode = mode;
  FUN_001fd50c();
  if (enabled != 0) {
    zeroBlocks.first[0] = 0;
    zeroBlocks.first[1] = 0;
    zeroBlocks.first[2] = 0;
    zeroBlocks.first[3] = 0;
    zeroBlocks.second[0] = 0;
    zeroBlocks.second[1] = 0;
    zeroBlocks.second[2] = 0;
    zeroBlocks.second[3] = 0;
    FUN_00063830(65535.0f,-1.0f,DAT_00331b84,zeroBlocks.second,zeroBlocks.first,0,0,0);
  }
  FUN_0001f1fc(self,0);
  return;
}

/* HSTMATCH module=EBOOT.BIN start=0x001258bc end=0x00125c4c symbol=FUN_001258bc lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: signed u8 tables and mode bounds were matched; shared table pointers and branch layout were reconstructed; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_002da1f4;
extern u8 DAT_0033b584;
extern u8 DAT_0033b5a0;
extern u8 DAT_0033b5ca;
extern char DAT_0033b5d2;
extern u8 DAT_0033b5d3;
extern char DAT_0033b5d4;
extern u32 DAT_00340284;
extern void FUN_00124bf8(int param_1,int param_2,float *param_3);
extern int FUN_001252fc();
extern void FUN_00125c4c(float param_1,int param_2);
extern void FUN_0013096c();
extern void FUN_00130b3c();
extern int FUN_00131a78();
extern u8 * FUN_00132124();

void FUN_001258bc(char *param_1,int param_2)
{
  short sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  if (param_2 == *(int *)(param_1 + 0x58)) return;
    *(int *)(param_1 + 0x58) = param_2;
    *(u32 *)(param_1 + 0x5c) = 0;
    FUN_00125c4c(0.0f,(int)param_1);
    if ((*(int *)(param_1 + 0x58) >= 0x80) && (*(int *)(param_1 + 0x58) < 0xc0)) {
      if (*(int *)(param_1 + 0x90) < DAT_002da1f4) {
        piVar2 = (int *)&DAT_002da1f4;
      }
      else {
        piVar2 = (int *)(param_1 + 0x90);
      }
      *(float *)(param_1 + 100) = (float)*piVar2;
    }
    else {
      *(u32 *)(param_1 + 100) = 0;
    }
    if ((&DAT_0033b5d4)[*(int *)(param_1 + 0x58) * 0x58] == '\a') {
      FUN_0013096c(DAT_00340284,1);
    }
    else {
      FUN_0013096c(DAT_00340284,0);
    }
    iVar3 = FUN_00131a78(DAT_00340284,(int)(char)(&DAT_0033b5d3)[*(int *)(param_1 + 0x58) * 0x58]);
    iVar4 = *(int *)(param_1 + 0x58) * 0x58;
    iVar3 = (int)((*(float *)(&DAT_0033b5a0 + iVar4) + (float)iVar3) -
                 (float)*(int *)(param_1 + 0x90));
    if ((&DAT_0033b5d4)[iVar4] == '\x06') {
      *(float *)(param_1 + 0x6c) = (float)iVar3;
      *(float *)(param_1 + 0x70) = (float)iVar3;
    }
    else {
      *(u32 *)(param_1 + 0x6c) = 0xbf800000;
    }
    iVar4 = *(int *)(param_1 + 0x58) * 0x58;
    if ((&DAT_0033b5d2)[iVar4] == '\0') {
      *(u32 *)(param_1 + 0x84) = 0xbf800000;
      *(u32 *)(param_1 + 0x88) = 0;
      float *table = (float *)(&DAT_0033b584 + *(int *)(param_1 + 0x58) * 0x58);
      *(float **)(param_1 + 0x48) = table;
      FUN_00124bf8((int)param_1,0,table);
    }
    else {
      sVar1 = *(short *)(&DAT_0033b5ca + iVar4);
      FUN_00132124((int)sVar1,&local_4);
      iVar4 = FUN_001252fc(param_1,local_4);
      if (iVar3 > 0) {
        float *current_table = (float *)(&DAT_0033b584 + *(int *)(param_1 + 0x58) * 0x58);
        *(u32 *)(param_1 + 0x48) = 0;
        FUN_00124bf8((int)param_1,1,current_table);
        FUN_00124bf8((int)param_1,2,(float *)(&DAT_0033b584 + iVar4 * 0x58));
        *(u32 *)(param_1 + 0x84) = 0;
        *(float *)(param_1 + 0x88) = (float)iVar3;
        if ((&DAT_0033b5d4)[*(int *)(param_1 + 0x58) * 0x58] == '\a') {
          FUN_00130b3c(DAT_00340284,iVar3);
        }
      
      }
      else {
        if ((*(unsigned char *)(param_1 + 0x94) == '\0') &&
           (((*(int *)(param_1 + 0x58) == 4 || (*(int *)(param_1 + 0x58) == 7)) || (sVar1 == 0x3c)))
           ) {
          *(u32 *)(param_1 + 0x84) = 0xbf800000;
          *(u32 *)(param_1 + 0x88) = 0;
          float *fallback_table = (float *)(&DAT_0033b584 + *(int *)(param_1 + 0x58) * 0x58);
          *(float **)(param_1 + 0x48) = fallback_table;
          FUN_00124bf8((int)param_1,0,fallback_table);
        }
        else {
          FUN_001258bc(param_1,iVar4);
        }
      
      }
    }
}

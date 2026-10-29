/* HSTMATCH module=EBOOT.BIN start=0x001258bc end=0x00125c4c symbol=FUN_001258bc lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: signed u8 tables and mode bounds were matched; shared table pointers and branch layout were reconstructed; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/actor_state.h"

/* State ids from STATE_GROUP_FIRST up to (not including) STATE_GROUP_END start the actor with its unk90 timing. */
#define STATE_GROUP_FIRST 0x80
#define STATE_GROUP_END 0xc0

extern int DAT_002da1f4; /* lower limit for the timing value */
extern StateRow DAT_0033b584[]; /* state table */
/* The same table seen field by field through the pre-scaled row offset (typed row indexing changes the float
   register order): row.unk1c, row.unk46, row.unk4e, row.unk50. */
extern u8 DAT_0033b5a0;
extern u8 DAT_0033b5ca;
extern char DAT_0033b5d2;
extern char DAT_0033b5d4;
extern u32 DAT_00340284; /* host object */
extern void FUN_00124bf8(ActorState *self,int slot,StateRow *row);
extern int FUN_001252fc();
extern void FUN_00125c4c(float param_1,ActorState *self);
extern void FUN_0013096c();
extern void FUN_00130b3c();
extern int FUN_00131a78();
extern u8 * FUN_00132124();

/* Switches the actor to a new state: resets its timers, picks the state row (or a blend between two rows) and starts it. */
void FUN_001258bc(ActorState *self,int new_state)
{
  short link;
  int *timing;
  int iVar3;
  int iVar4;
  int local_4;
  
  if (new_state == self->stateIdx) return;
    self->stateIdx = new_state;
    self->unk5c = 0;
    FUN_00125c4c(0.0f,self);
    if ((self->stateIdx >= STATE_GROUP_FIRST) && (self->stateIdx < STATE_GROUP_END)) {
      if (self->unk90 < DAT_002da1f4) {
        timing = &DAT_002da1f4;
      }
      else {
        timing = &self->unk90;
      }
      self->unk64 = (float)*timing;
    }
    else {
      self->unk64 = 0;
    }
    if (DAT_0033b584[self->stateIdx].unk50 == 7) {
      FUN_0013096c(DAT_00340284,1);
    }
    else {
      FUN_0013096c(DAT_00340284,0);
    }
    iVar3 = FUN_00131a78(DAT_00340284,(int)DAT_0033b584[self->stateIdx].unk4f);
    iVar4 = self->stateIdx * 0x58;
    iVar3 = (int)((*(float *)(&DAT_0033b5a0 + iVar4) + (float)iVar3) -
                 (float)self->unk90);
    if ((&DAT_0033b5d4)[iVar4] == 6) {
      self->unk6c = (float)iVar3;
      self->unk70 = (float)iVar3;
    }
    else {
      self->unk6c = -1.0f;
    }
    iVar4 = self->stateIdx * 0x58;
    if ((&DAT_0033b5d2)[iVar4] == 0) {
      self->unk84 = -1.0f;
      self->unk88 = 0;
      StateRow *row = &DAT_0033b584[self->stateIdx];
      self->slotA = row;
      FUN_00124bf8(self,0,row);
    }
    else {
      link = *(short *)(&DAT_0033b5ca + iVar4);
      FUN_00132124((int)link,&local_4);
      iVar4 = FUN_001252fc(self,local_4);
      if (iVar3 > 0) {
        StateRow *current_row = &DAT_0033b584[self->stateIdx];
        self->slotA = 0;
        FUN_00124bf8(self,1,current_row);
        FUN_00124bf8(self,2,&DAT_0033b584[iVar4]);
        self->unk84 = 0;
        self->unk88 = (float)iVar3;
        if (DAT_0033b584[self->stateIdx].unk50 == 7) {
          FUN_00130b3c(DAT_00340284,iVar3);
        }
      
      }
      else {
        if ((self->unk94 == 0) &&
           (((self->stateIdx == 4 || (self->stateIdx == 7)) || (link == 0x3c)))
           ) {
          self->unk84 = -1.0f;
          self->unk88 = 0;
          StateRow *fallback_row = &DAT_0033b584[self->stateIdx];
          self->slotA = fallback_row;
          FUN_00124bf8(self,0,fallback_row);
        }
        else {
          FUN_001258bc(self,iVar4);
        }
      
      }
    }
}

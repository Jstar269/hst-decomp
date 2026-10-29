/* HSTMATCH module=hstp_trans_main.prx start=0x000df888 end=0x000df92c symbol=FUN_000df888 lang=c99 */
/* Clone of src/eboot/FUN_000db868.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rule_obj.h"

/* Clear the per-point state flags of the rule object. */
void FUN_000df888(RuleObj *self)
{
  self->unk5c[0] = 0;
  self->unk5c[1] = 0;
  self->unk5c[2] = 0;
  self->unk5c[3] = 0;
  self->unk84[0] = 0;
  self->unk84[1] = 0;
  self->unk84[2] = 0;
  self->unk84[3] = 0;
  self->unk84[4] = 0;
  self->unk8c = 0;
  self->unk90 = 0;
  self->unk94 = RULE_NO_TEAM;
  self->unk98 = RULE_NO_TEAM;
  self->unkac = 0;
  self->unk64[0] = 0;
  self->unk64[1] = 0;
  self->unk64[2] = 0;
  self->unk64[3] = 0;
  self->unk68 = 3;
  self->unk6c = 0xd;
  self->unk70 = 0;
  self->unk78 = -1;
  self->unk7c = 0;
  self->unk80 = 0;
  self->unk60[0] = 0;
  self->unk60[1] = 0;
  self->unk60[2] = 0;
  self->unk60[3] = 0;
  self->unk71[0] = 0;
  self->unk71[1] = 0;
  self->unk71[2] = 0;
  self->unk71[3] = 0;
  self->unk71[4] = 0;
  self->unk9c = RULE_NO_TEAM;
  self->unka0 = RULE_NO_TEAM;
  self->unka4 = RULE_NO_TEAM;
  self->unka8 = RULE_NO_TEAM;
}

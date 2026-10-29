/* HSTMATCH module=EBOOT.BIN start=0x000b3f20 end=0x000b4024 symbol=FUN_000b3f20 lang=c++ data=0x002d47b4 */
/* Hand-written reconstruction from the disassembly (the two name probes are `!= 0` tests that leave `kind` undefined on the no-match path as retail does; the skip loop must stay inline as `while (!FUN_0000fe64(*name))` so MWCC emits sltu/xori and the rotated loop; the row offset is hoisted into a local (read through the raw vector array) so the load schedules after the index multiply); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d47b4-0x002d47ba) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/npc_voice.h"

extern "C" char DAT_002d47ac[];
extern "C" int FUN_00014d64(char *, char *);
extern "C" int FUN_0000fe64(int);
extern "C" int FUN_0000d62c(char *);

/* Voice byte (minus 1) for the NPC named `name` ("NPC_w.." or "NPC_m.."): row from the digits of the name, then group * 3 + sub. */
extern "C" int FUN_000b3f20(NpcVoiceVec *voices, char *name, int group, int sub)
{
    int kind;
    int number;
    int row_off;

    if (FUN_00014d64(name, DAT_002d47ac) != 0)
        kind = NPC_KIND_W;
    else if (FUN_00014d64(name, "NPC_m") != 0)
        kind = NPC_KIND_M;
    while (!FUN_0000fe64(*name))
        name++;
    number = FUN_0000d62c(name);
    row_off = *(int *)((char *)voices + kind * sizeof(NpcVoiceVec)) + number * NPC_VOICE_ROW_SIZE;
    return *(char *)(sub + row_off + group * NPC_VOICE_COLS) - 1;
}

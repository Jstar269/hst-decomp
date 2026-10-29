/* Definition table rows of the 0x1b1000 sources: a slot id and a name, looked up through the slot table. */
#ifndef HST_SLOT_LOOKUP_H
#define HST_SLOT_LOOKUP_H

#include "hst/slot_table.h"

#define DEF_COURT_FIRST 0x1d /* first definition whose slot id is offset by the court sound index */
#define DEF_COURT_LAST 0x74  /* last such definition */

typedef struct SlotDef {
  int id;     /* 0x00 slot id, plus SlotTable.court_sound for the court definitions */
  int name;   /* 0x04 passed to the load calls */
} SlotDef;

#endif

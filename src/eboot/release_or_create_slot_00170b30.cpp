/* HSTMATCH module=EBOOT.BIN start=0x00170b30 end=0x00170c24 symbol=FUN_00170b30 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6, variant v17) corrected by hand: flag byte typed unsigned char (lbu) and the new-then-construct store shared (p = alloc; if (p) p = ctor(p); *slot = p); readability pass (names, structs, constants); exact match verified; names and types await human review. */

struct SlotObj { virtual ~SlotObj(); };  /* object kept per slot in DAT_0034b340 */

struct NameList { char pad0[4]; int cur; char **names; };  /* names[cur] is the current entry */

struct MenuObj {
  char pad0[0x4d];
  unsigned char useSlotObj;
  char pad4e[0x178 - 0x4e];
  NameList *nameList;
};

extern SlotObj *DAT_0034b340[];
extern "C" {
extern void *FUN_00000bcc(int);
extern SlotObj *FUN_00091830(void *);
extern void FUN_0009191c(SlotObj *, char *);
extern void FUN_00091c48(SlotObj *, int);
extern void FUN_00092ff8(SlotObj *);
extern bool FUN_0017c344(NameList *);
}

/* Drops the slot's object when the name list has nothing for it, otherwise creates it if absent and binds the current name. */
extern "C" void FUN_00170b30(MenuObj *menu,int slot)
{
  SlotObj *obj;
  SlotObj **entry;
  NameList *list;
  
  if (menu->useSlotObj != 0) {
    if (FUN_0017c344(menu->nameList) == 0) {
      entry = &DAT_0034b340[slot];
      obj = *entry;
      if (obj != 0) {
        delete obj;
        *entry = 0;
      }
    }
    else {
      entry = &DAT_0034b340[slot];
      if (*entry == 0) {
        obj = (SlotObj *)FUN_00000bcc(0xe0);
        if (obj != 0) {
          obj = FUN_00091830(obj);
        }
        *entry = obj;
      }
      list = menu->nameList;
      FUN_0009191c(*entry,list->names[list->cur] + 0x10);
      FUN_00091c48(*entry,0);
      FUN_00092ff8(*entry);
    }
  }
}

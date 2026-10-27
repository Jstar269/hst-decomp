/* HSTMATCH module=EBOOT.BIN start=0x0018ca94 end=0x0018cb28 symbol=FUN_0018ca94 lang=c++ data=0x002e0e54 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 21 strings, 0x002e0e54-0x002e11b0) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
extern "C" void FUN_0018cb28();
extern "C" void FUN_000fcb7c();
extern "C" void *FUN_00000a90(int size);
extern "C" void *FUN_000008d8(void *a0, void *a1, void *a2, int a3, int a4);
extern "C" void FUN_0010ae20(void *dst, const char *src);
extern char *DAT_003415b0;
const char *DAT_002e115c[] = {
    "data/menu/text/CommonText_Acce.to",
    "data/menu/text/CommonText_Body.to",
    "data/menu/text/CommonText_Court.to",
    "data/menu/text/CommonText_Head.to",
    "data/menu/text/CommonText_Item.to",
    "data/menu/text/CommonText_Judge.to",
    "data/menu/text/CommonText_Lobby.to",
    "data/menu/text/CommonText_Npc.to",
    "data/menu/text/CommonText_ObjItem.to",
    "data/menu/text/CommonText_Other.to",
    "data/menu/text/CommonText_P_Set.to",
    "data/menu/text/CommonText_Param.to",
    "data/menu/text/CommonText_Pc.to",
    "data/menu/text/CommonText_Racket.to",
    "data/menu/text/CommonText_Rank.to",
    "data/menu/text/CommonText_Stamp.to",
    "data/menu/text/CommonText_TitleHS.to",
    "data/menu/text/MenuText_Generic_Dialog.to",
    "data/menu/text/MenuText_Menu_Help.to",
    "data/menu/text/MenuText_Menu_Help_2.to",
    "data/menu/text/MenuText_Top_Lady.to",
};

extern "C" void FUN_0018ca94(void)
{
  DAT_003415b0 = (char *)FUN_000008d8(FUN_00000a90(0x160), (void *)FUN_0018cb28, (void *)FUN_000fcb7c, 0x10, 0x15);
  for (unsigned int n = 0; n < 0x15; n++) {
    FUN_0010ae20(DAT_003415b0 + n * 0x10, DAT_002e115c[n]);
  }
}

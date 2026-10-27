/* HSTMATCH module=EBOOT.BIN start=0x002a2434 end=0x002a2488 symbol=FUN_002a2434 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Picks a menu state from two lobby flags: state 5 when lobby 7 is flagged and lobby 8 is not, else 0.
   FUN_0022c988 is the lobby_helper.cpp flag query (its hstp_trans_main twin FUN_0023c5e0 asserts `0 <= lobbyID && lobbyID < BULK_OF(LSD()->lobbyStat)`),
   FUN_002a2488 the menu_lady.cpp state setter (stores the state at +0x1b0 and switches on it). */
extern int FUN_0022c988(int lobbyID);
extern void FUN_002a2488(void *menu, int state);

void FUN_002a2434(void *menu)
{
    FUN_002a2488(menu, (FUN_0022c988(7) && !FUN_0022c988(8)) ? 5 : 0);
}

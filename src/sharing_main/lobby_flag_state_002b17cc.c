/* HSTMATCH module=hstp_trans_main.prx start=0x002b17cc end=0x002b1820 symbol=FUN_002b17cc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Picks a menu state from two lobby flags: state 5 when lobby 7 is flagged and lobby 8 is not, else 0.
   FUN_0023c5e0 is the lobby_helper.cpp flag query (asserts `0 <= lobbyID && lobbyID < BULK_OF(LSD()->lobbyStat)`),
   FUN_002b1820 the menu_lady.cpp state setter (stores the state at +0x1b0 and switches on it). */
extern int FUN_0023c5e0(int lobbyID);
extern void FUN_002b1820(void *menu, int state);

void FUN_002b17cc(void *menu)
{
    FUN_002b1820(menu, (FUN_0023c5e0(7) && !FUN_0023c5e0(8)) ? 5 : 0);
}

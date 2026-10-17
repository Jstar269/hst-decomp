/* HSTMATCH module=hstp_trans_main.prx start=0x00298b14 end=0x00298b5c symbol=FUN_00298b14 lang=c99 */
/* Clone of src/eboot/node_flag_test_00287418.c (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed Wrap/List/Node views, and the redundant inner null test is a carried flag (matching idiom: eq = (n != 0) ^ 1; if (eq == 0) eq = (compare); if (eq ^ 1) r = 1); exact match verified; names and types await human review. */
typedef struct Node { int f0; int f4; } Node;
typedef struct List { int f0; Node *head; char pad[12]; Node *f14; } List;
typedef struct Wrap { int f0; int f4; List *list; } Wrap;

int FUN_00298b14(Wrap *w)
{
  List *l = w->list;
  Node *n = l->head;
  int r = 0;
  int eq;

  if (n != 0) {
    eq = (n != 0) ^ 1;
    if (eq == 0) {
      eq = l->f14 == (Node *)((char *)n + 4);
    }
    if (eq ^ 1) {
      r = 1;
    }
  }
  return r;
}

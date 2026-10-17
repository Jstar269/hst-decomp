/* HSTMATCH module=hstp_trans_main.prx start=0x0015b064 end=0x0015b0cc symbol=FUN_0015b064 lang=c++ */
/* Clone of src/eboot/list_insert_range_0014f064.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: list nodes typed, loop over first/last wrapped in a one-pointer iterator class with a converting ctor and a free operator!= (the guard then compares the incoming argument registers), out-iterator slots declared in reverse order; exact match verified; names and types await human review. */
struct Node { Node *prev; Node *next; int value; };
struct List;
extern "C" void FUN_0015b0cc(Node **out, List *l);
extern "C" int FUN_0015b5e0(Node **out, List *l, Node **pos, int *val);
struct It { Node *p; It(Node *n) : p(n) {} };
inline bool operator!=(It a, It b) { return a.p != b.p; }
extern "C" void FUN_0015b064(List *l, Node *first, Node *last)
{
  Node *b, *a;
  It f(first), e(last);
  for (; f != e; f.p = f.p->next) {
    FUN_0015b0cc(&a, l);
    FUN_0015b5e0(&b, l, &a, &f.p->value);
  }
}

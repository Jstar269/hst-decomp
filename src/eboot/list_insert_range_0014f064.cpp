/* HSTMATCH module=EBOOT.BIN start=0x0014f064 end=0x0014f0cc symbol=FUN_0014f064 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: list nodes typed, loop over first/last wrapped in a one-pointer iterator class with a converting ctor and a free operator!= (the guard then compares the incoming argument registers), out-iterator slots declared in reverse order; exact match verified; names and types await human review. */
struct Node { Node *prev; Node *next; int value; };
struct List;
extern "C" void FUN_0014f0cc(Node **out, List *l);
extern "C" int FUN_0014f5e0(Node **out, List *l, Node **pos, int *val);
struct It { Node *p; It(Node *n) : p(n) {} };
inline bool operator!=(It a, It b) { return a.p != b.p; }
extern "C" void FUN_0014f064(List *l, Node *first, Node *last)
{
  Node *b, *a;
  It f(first), e(last);
  for (; f != e; f.p = f.p->next) {
    FUN_0014f0cc(&a, l);
    FUN_0014f5e0(&b, l, &a, &f.p->value);
  }
}

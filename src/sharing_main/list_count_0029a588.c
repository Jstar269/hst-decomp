/* HSTMATCH module=hstp_trans_main.prx start=0x0029a588 end=0x0029a5ec symbol=FUN_0029a588 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Node count of the list behind the object's +0xc pointer, 0 when it has no header node or is empty.
   FUN_001588c0 walks the nodes from f4->f8 to f14 and returns 0 when f14 == f4 + 4. The two predicates are
   static inline helpers combined in value context (`int ok = A && !B;`), which gives retail's
   `sltu; xori; bnezl` and `li a1,1; beqzl a1` flag code. */
typedef struct List {
    int f0;
    char *head;
    char pad8[0xc];
    char *last;
} List;

typedef struct Obj {
    char pad0[0xc];
    List *list;
} Obj;

extern int FUN_001588c0(List *l);

static inline int HasHeader(List *l) { return l->head != 0; }
static inline int IsEmpty(List *l) { return !HasHeader(l) || l->last == l->head + 4; }

int FUN_0029a588(Obj *o)
{
    List *l = o->list;
    int ok = HasHeader(l) && !IsEmpty(l);
    if (ok) return FUN_001588c0(l);
    return 0;
}

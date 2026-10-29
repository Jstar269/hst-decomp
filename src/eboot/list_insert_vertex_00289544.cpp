/* HSTMATCH module=EBOOT.BIN start=0x00289544 end=0x00289654 symbol=FUN_00289544 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned size);
struct Reent { int pad[3]; void *err; };   /* per-thread library state: the error stream sits at 0x0c */
Reent *FUN_0000fe3c(void);
void FUN_00286acc(void *err, char *msg);
void FUN_0000d518(void);
void FUN_00000a00(void *);
extern char DAT_002cab00[];   /* out-of-memory message */
}
#define NODE_SIZE 0x20
inline void *operator new(unsigned, void *p) { return p; }
struct Vec6 { float x, y, z, w, u, v; };
struct Node { Node *next; Node *prev; Vec6 v; };
/* Frees the node again if constructing its value does not finish. */
struct Guard { int *p; Node *n; ~Guard() { if (n) FUN_00000a00(n); } };
/* Insert a new node holding *src after the node *pos in a circular list; sets *result to the node and bumps *size. */
extern "C" int FUN_00289544(Node **result, int *size, Node **pos, const Vec6 *src)
{
    int *cp = size + 1;
    Node *n = (Node *)FUN_00000bcc(NODE_SIZE);
    if (n == 0) {
        FUN_00286acc(FUN_0000fe3c()->err, DAT_002cab00);
        FUN_0000d518();
    }
    Guard g;
    g.p = cp;
    g.n = n;
    new (&n->v) Vec6(*src);
    g.n = 0;
    Node *h = *pos;
    h->next->prev = n;
    n->next = h->next;
    h->next = n;
    n->prev = h;
    *size = *size + 1;
    *result = n;
    return 0;
}

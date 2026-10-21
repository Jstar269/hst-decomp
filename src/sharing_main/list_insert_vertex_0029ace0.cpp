/* HSTMATCH module=hstp_trans_main.prx start=0x0029ace0 end=0x0029adf0 symbol=FUN_0029ace0 lang=c++ */
/* Clone of src/eboot/list_insert_vertex_00289544.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned size);
struct Reent_0029ace0 { int pad[3]; void *err; };
Reent_0029ace0 *FUN_0000fe3c(void);
void FUN_00297e90(void *err, char *msg);
void FUN_0000d530(void);
void FUN_00000a00(void *);
extern char DAT_002db134[];
}
inline void *operator new(unsigned, void *p) { return p; }
struct Vec6_0029ace0 { float x, y, z, w, u, v; };
struct Node_0029ace0 { Node_0029ace0 *next; Node_0029ace0 *prev; Vec6_0029ace0 v; };
struct Guard_0029ace0 { int *p; Node_0029ace0 *n; ~Guard_0029ace0() { if (n) FUN_00000a00(n); } };
extern "C" int FUN_0029ace0(Node_0029ace0 **out, int *count, Node_0029ace0 **head, const Vec6_0029ace0 *src)
{
    int *cp = count + 1;
    Node_0029ace0 *n = (Node_0029ace0 *)FUN_00000bcc(0x20);
    if (n == 0) {
        FUN_00297e90(FUN_0000fe3c()->err, DAT_002db134);
        FUN_0000d530();
    }
    Guard_0029ace0 g;
    g.p = cp;
    g.n = n;
    new (&n->v) Vec6_0029ace0(*src);
    g.n = 0;
    Node_0029ace0 *h = *head;
    h->next->prev = n;
    n->next = h->next;
    h->next = n;
    n->prev = h;
    *count = *count + 1;
    *out = n;
    return 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x000d5ca8 end=0x000d5d04 symbol=__dt__13Tree_000d5ca8Fv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_000d5ca8;
struct Tree_000d5ca8 {
    int header;
    Node_000d5ca8 *root;
    ~Tree_000d5ca8();
};
extern "C" void FUN_000d71a8(Tree_000d5ca8 *t, Node_000d5ca8 *x);
Tree_000d5ca8::~Tree_000d5ca8()
{
    if (root)
        FUN_000d71a8(this, root);
}

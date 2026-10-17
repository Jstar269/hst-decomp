/* HSTMATCH module=EBOOT.BIN start=0x0006b69c end=0x0006b6f8 symbol=__dt__13Tree_0006b69cFv lang=c++ */
/* Clone of src/eboot/tree_dtor_000d5ca8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_0006b69c;
struct Tree_0006b69c {
    int header;
    Node_0006b69c *root;
    ~Tree_0006b69c();
};
extern "C" void FUN_0006c16c(Tree_0006b69c *t, Node_0006b69c *x);
Tree_0006b69c::~Tree_0006b69c()
{
    if (root)
        FUN_0006c16c(this, root);
}

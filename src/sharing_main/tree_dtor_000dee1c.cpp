/* HSTMATCH module=hstp_trans_main.prx start=0x000dee1c end=0x000dee78 symbol=__dt__13Tree_000dee1cFv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_000dee1c;
struct Tree_000dee1c {
    int header;
    Node_000dee1c *root;
    ~Tree_000dee1c();
};
extern "C" void FUN_000df18c(Tree_000dee1c *t, Node_000dee1c *x);
Tree_000dee1c::~Tree_000dee1c()
{
    if (root)
        FUN_000df18c(this, root);
}

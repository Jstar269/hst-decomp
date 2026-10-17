/* HSTMATCH module=EBOOT.BIN start=0x000dae5c end=0x000daeb8 symbol=__dt__13Tree_000dae5cFv lang=c++ */
/* Clone of src/eboot/tree_dtor_000d5ca8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_000dae5c;
struct Tree_000dae5c {
    int header;
    Node_000dae5c *root;
    ~Tree_000dae5c();
};
extern "C" void FUN_000db1cc(Tree_000dae5c *t, Node_000dae5c *x);
Tree_000dae5c::~Tree_000dae5c()
{
    if (root)
        FUN_000db1cc(this, root);
}

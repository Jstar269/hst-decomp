/* HSTMATCH module=EBOOT.BIN start=0x0006bacc end=0x0006bb28 symbol=__dt__13Tree_0006baccFv lang=c++ */
/* Clone of src/eboot/tree_dtor_000d5ca8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_0006bacc;
struct Tree_0006bacc {
    int header;
    Node_0006bacc *root;
    ~Tree_0006bacc();
};
extern "C" void FUN_0006c934(Tree_0006bacc *t, Node_0006bacc *x);
Tree_0006bacc::~Tree_0006bacc()
{
    if (root)
        FUN_0006c934(this, root);
}

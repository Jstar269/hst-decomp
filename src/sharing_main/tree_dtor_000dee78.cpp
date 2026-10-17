/* HSTMATCH module=hstp_trans_main.prx start=0x000dee78 end=0x000deed4 symbol=__dt__13Tree_000dee78Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_000dee78;
struct Tree_000dee78 {
    int header;
    Node_000dee78 *root;
    ~Tree_000dee78();
};
extern "C" void FUN_000deed4(Tree_000dee78 *t, Node_000dee78 *x);
Tree_000dee78::~Tree_000dee78()
{
    if (root)
        FUN_000deed4(this, root);
}

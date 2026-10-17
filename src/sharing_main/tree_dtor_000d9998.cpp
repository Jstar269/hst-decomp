/* HSTMATCH module=hstp_trans_main.prx start=0x000d9998 end=0x000d99f4 symbol=__dt__13Tree_000d9998Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_00066338.cpp (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_000d9998;
struct Tree_000d9998 {
    int header;
    Node_000d9998 *root;
    ~Tree_000d9998();
};
extern "C" void FUN_000dae98(Tree_000d9998 *t, Node_000d9998 *x);
Tree_000d9998::~Tree_000d9998()
{
    if (root)
        FUN_000dae98(this, root);
}

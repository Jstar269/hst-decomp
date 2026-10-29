/* HSTMATCH module=hstp_trans_main.prx start=0x0022b474 end=0x0022b498 symbol=FUN_0022b474 lang=c99 */
/* Clone of src/eboot/FUN_0021bf00.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Stores a screen position (x, y) minus a fixed offset into the object. */
void FUN_0022b474(float x,float y,int obj)
{
  *(float *)(obj + 0xe0) = x - 150.0f;
  *(float *)(obj + 0xe4) = y - 200.0f;
}

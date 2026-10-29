/* HSTMATCH module=hstp_trans_main.prx start=0x00227fc8 end=0x00227ffc symbol=FUN_00227fc8 lang=c99 */
/* Clone of src/eboot/FUN_00218ab0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Divides by ten; the value 500 maps to bucket 9. */
int FUN_00227fc8(int value)
{
  int bucket;
  
  if (value == 500) {
    bucket = 9;
  }
  else {
    bucket = value / 10;
  }
  return bucket;
}

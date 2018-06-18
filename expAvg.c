// ----------------------------------------------------------------------------
//
//
// ----------------------------------------------------------------------------
#include "expAvg.h"

// ----------------------------------------------------------------------------
int32_t expAvg_init(expAvg_t* ptr, float kF)
{
  if((kF > 0.0) && (kF < 1.0))
  {
    ptr->kF = kF;
    ptr->output = 0;
    return 0;
  }
  return -1;
}

// ----------------------------------------------------------------------------
float expAvg_iterate(expAvg_t* ptr, float inp)
{
  ptr->input = inp;

  ptr->output = (ptr->input * (1.0 - ptr->kF)) + (ptr->output * ptr->kF);

  return (ptr->output);
}

// ----------------------------------------------------------------------------
void expAvg_reset(expAvg_t* ptr, float resetVal)
{
  ptr->output = resetVal;
}

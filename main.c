// ----------------------------------------------------------------------------
//
//
// ----------------------------------------------------------------------------
#include "expAvg.h"
#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------
int main()
{
  // Send your greetings
  printf("Exponential average simulation started.\n");

  // Create exponential average filters
  expAvg_t filt0;
  expAvg_t filt1;
  expAvg_t filt2;

  // Initialise them with different smoothing factors
  if(expAvg_init(&filt0, 0.500) != 0)
  {
    printf("Invalid coefficient!\n");
    return -1;
  }

  if(expAvg_init(&filt1, 0.990) != 0)
  {
    printf("Invalid coefficient!\n");
    return -1;
  }

  if(expAvg_init(&filt2, 0.999) != 0)
  {
    printf("Invalid coefficient!\n");
    return -1;
  }

  // Try to create the log file
  FILE* fp = fopen("expAvg_log.csv", "w+");
  if(fp == NULL)
  {
    printf("File create problem!\n");
    return -1;
  }

  // Simulation parameters
  float t = 0;
  float input = 0;
  float sim_tick_ms = 1;
  float sim_totalTime_ms = 8000;
  float sim_filt2_resetTime = 2500;
  float sim_impulseArriveTime_ms = 500;

  // Run the simulation
  for(t = 0; t < sim_totalTime_ms; t += sim_tick_ms)
  {
    // Create impulse response
    if(t < sim_impulseArriveTime_ms)
    {
      input = 0.0;
    }
    else
    {
      input = 1.0;
    }

#if 0
    // Reset filter2 at certain time frame
    if((t <= sim_filt2_resetTime) &&
       ((t + sim_tick_ms) > sim_filt2_resetTime))
    {
      expAvg_reset(&filt2, 0.5);
    }
#endif

    // Iterate filter
    expAvg_iterate(&filt0, input);
    expAvg_iterate(&filt1, input);
    expAvg_iterate(&filt2, input);

    // Log the outputs
    fprintf(fp, "%f,%f,%f,%f,%f\n",
      t, input, filt0.output, filt1.output, filt2.output
    );
  }

  // Close the log file
  fclose(fp);
  printf("Exponential average simulation finished.\n");
  return 0;
}
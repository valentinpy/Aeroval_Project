/*
 * IMU_Simulation_data.c
 *
 * Code generation for model "IMU_Simulation".
 *
 * Model version              : 1.103
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Mon Oct 29 11:02:51 2012
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "IMU_Simulation.h"
#include "IMU_Simulation_private.h"

/* Block parameters (auto storage) */
Parameters_IMU_Simulation IMU_Simulation_P = {
  0.001,                               /* Expression: 1e-3
                                        * Referenced by: '<S55>/Gain6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Constant'
                                        */

  /*  Expression: Kz
   * Referenced by: '<S79>/Gain6'
   */
  { 0.0004, -4.0E-5 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S79>/Constant'
                                        */
  0.001,                               /* Expression: Ts
                                        * Referenced by: '<S79>/Gain7'
                                        */

  /*  Expression: Kz
   * Referenced by: '<S80>/Gain6'
   */
  { 0.0004, -4.0E-5 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S80>/Constant'
                                        */
  0.001,                               /* Expression: Ts
                                        * Referenced by: '<S80>/Gain7'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<Root>/added Bias to test for large bias'
                                        */
  0.255859375,                         /* Expression: 80/2048*6.55
                                        * Referenced by: '<S5>/Gyro Y gain'
                                        */
  -18.0,                               /* Expression: -18
                                        * Referenced by: '<S5>/Biais '
                                        */
  1.0,                                 /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S84>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S84>/Discrete-Time Integrator'
                                        */

  /*  Expression: [-500 -195 195]
   * Referenced by: '<S84>/Lookup Table'
   */
  { -500.0, -195.0, 195.0 },

  /*  Expression: [+360 0 -360]
   * Referenced by: '<S84>/Lookup Table'
   */
  { 360.0, 0.0, -360.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S96>/Constant'
                                        */
  -13632.0,                            /* Expression: -13632
                                        * Referenced by: '<S5>/Bias1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S4>/Gain1'
                                        */
  -13054.0,                            /* Expression: -13054
                                        * Referenced by: '<S5>/Bias2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S4>/Gain4'
                                        */
  200.0,                               /* Expression: const
                                        * Referenced by: '<S76>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S80>/Unit Delay2'
                                        */

  /*  Expression: Az
   * Referenced by: '<S80>/Gain1'
   */
  { 1.0, 0.0, -0.001, 1.0 },
  1.0,                                 /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                        * Referenced by: '<S13>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Discrete-Time Integrator'
                                        */
  0.99950012496875784,                 /* Computed Parameter: DiscreteZeroPole_A
                                        * Referenced by: '<S7>/Discrete Zero-Pole'
                                        */
  0.00049975009371875983,              /* Computed Parameter: DiscreteZeroPole_C
                                        * Referenced by: '<S7>/Discrete Zero-Pole'
                                        */
  0.00024993751562109475,              /* Computed Parameter: DiscreteZeroPole_D
                                        * Referenced by: '<S7>/Discrete Zero-Pole'
                                        */
  0.99950012496875784,                 /* Computed Parameter: DiscreteZeroPole_A_l
                                        * Referenced by: '<S11>/Discrete Zero-Pole'
                                        */
  0.00099790862662949833,              /* Computed Parameter: DiscreteZeroPole_C_k
                                        * Referenced by: '<S11>/Discrete Zero-Pole'
                                        */
  0.0036837924276892564,               /* Computed Parameter: DiscreteZeroPole_D_b
                                        * Referenced by: '<S11>/Discrete Zero-Pole'
                                        */
  1.0,                                 /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                        * Referenced by: '<S34>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S34>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Discrete Transfer Fcn'
                                        */

  /*  Expression: numd
   * Referenced by: '<S32>/Discrete Transfer Fcn'
   */
  { 0.00019996500599897516, 9.99800034993004E-9, -0.00019995500799862523 },

  /*  Expression: dend
   * Referenced by: '<S32>/Discrete Transfer Fcn'
   */
  { 1.0, -1.9996000599900015, 0.99960007998600231 },

  /*  Computed Parameter: DiscreteZeroPole_A_a
   * Referenced by: '<S29>/Discrete Zero-Pole'
   */
  { 1.9996000399960003, -0.99980001999800017, 0.99980001999800017 },
  1.0,                                 /* Computed Parameter: DiscreteZeroPole_B
                                        * Referenced by: '<S29>/Discrete Zero-Pole'
                                        */

  /*  Computed Parameter: DiscreteZeroPole_C_g
   * Referenced by: '<S29>/Discrete Zero-Pole'
   */
  { 0.00099960008998400225, -0.00099980004999200133 },
  0.00049990001499800019,              /* Computed Parameter: DiscreteZeroPole_D_e
                                        * Referenced by: '<S29>/Discrete Zero-Pole'
                                        */
  1.0,                                 /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                        * Referenced by: '<S58>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S58>/Discrete-Time Integrator'
                                        */

  /*  Expression: [-500 -195 195]
   * Referenced by: '<S58>/Lookup Table'
   */
  { -500.0, -195.0, 195.0 },

  /*  Expression: [+360 0 -360]
   * Referenced by: '<S58>/Lookup Table'
   */
  { 360.0, 0.0, -360.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S70>/Constant'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Gain4'
                                        */
  200.0,                               /* Expression: const
                                        * Referenced by: '<S51>/Constant'
                                        */
  0.82773960091290621,                 /* Computed Parameter: DiscreteZeroPole_A_ai
                                        * Referenced by: '<S59>/Discrete Zero-Pole'
                                        */
  0.15742357654027139,                 /* Computed Parameter: DiscreteZeroPole_C_gl
                                        * Referenced by: '<S59>/Discrete Zero-Pole'
                                        */
  0.086130199543546893,                /* Computed Parameter: DiscreteZeroPole_D_p
                                        * Referenced by: '<S59>/Discrete Zero-Pole'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Unit Delay2'
                                        */
  0.001,                               /* Expression: Ts
                                        * Referenced by: '<S55>/Gain7'
                                        */
  0.091796875,                         /* Expression: 80/2048*2.35
                                        * Referenced by: '<S5>/Gyro X gain'
                                        */
  13.0,                                /* Expression: 13
                                        * Referenced by: '<S5>/Bias4'
                                        */
  1.0,                                 /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                        * Referenced by: '<S83>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S83>/Discrete-Time Integrator'
                                        */

  /*  Expression: [-500 -195 195]
   * Referenced by: '<S83>/Lookup Table'
   */
  { -500.0, -195.0, 195.0 },

  /*  Expression: [+360 0 -360]
   * Referenced by: '<S83>/Lookup Table'
   */
  { 360.0, 0.0, -360.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S89>/Constant'
                                        */
  -9027.0,                             /* Expression: -9027
                                        * Referenced by: '<S5>/Bias'
                                        */
  200.0,                               /* Expression: const
                                        * Referenced by: '<S75>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S79>/Unit Delay2'
                                        */

  /*  Expression: Az
   * Referenced by: '<S79>/Gain1'
   */
  { 1.0, 0.0, -0.001, 1.0 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain4'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain6'
                                        */
  0.0,                                 /* Expression: ICPrevInput
                                        * Referenced by: '<S18>/UD'
                                        */
  180.0,                               /* Expression: const
                                        * Referenced by: '<S15>/Constant'
                                        */
  -180.0,                              /* Expression: const
                                        * Referenced by: '<S16>/Constant'
                                        */

  /*  Expression: [-500 -195 195]
   * Referenced by: '<S13>/Lookup Table'
   */
  { -500.0, -195.0, 195.0 },

  /*  Expression: [+360 0 -360]
   * Referenced by: '<S13>/Lookup Table'
   */
  { 360.0, 0.0, -360.0 },
  0.0,                                 /* Expression: ICPrevInput
                                        * Referenced by: '<S25>/UD'
                                        */
  180.0,                               /* Expression: const
                                        * Referenced by: '<S22>/Constant'
                                        */
  -180.0,                              /* Expression: const
                                        * Referenced by: '<S23>/Constant'
                                        */

  /*  Computed Parameter: DiscreteZeroPole_A_h
   * Referenced by: '<S30>/Discrete Zero-Pole'
   */
  { 1.9996000399960003, -0.99980001999800017, 0.99980001999800017 },
  1.0,                                 /* Computed Parameter: DiscreteZeroPole_B_m
                                        * Referenced by: '<S30>/Discrete Zero-Pole'
                                        */

  /*  Computed Parameter: DiscreteZeroPole_C_e
   * Referenced by: '<S30>/Discrete Zero-Pole'
   */
  { 0.00099832658672286854, -0.00099852641936780482 },
  0.0036839765436476836,               /* Computed Parameter: DiscreteZeroPole_D_m
                                        * Referenced by: '<S30>/Discrete Zero-Pole'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Gain4'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain6'
                                        */
  0.0,                                 /* Expression: ICPrevInput
                                        * Referenced by: '<S39>/UD'
                                        */
  180.0,                               /* Expression: const
                                        * Referenced by: '<S36>/Constant'
                                        */
  -180.0,                              /* Expression: const
                                        * Referenced by: '<S37>/Constant'
                                        */

  /*  Expression: [-500 -195 195]
   * Referenced by: '<S34>/Lookup Table'
   */
  { -500.0, -195.0, 195.0 },

  /*  Expression: [+360 0 -360]
   * Referenced by: '<S34>/Lookup Table'
   */
  { 360.0, 0.0, -360.0 },
  0.0,                                 /* Expression: ICPrevInput
                                        * Referenced by: '<S46>/UD'
                                        */
  180.0,                               /* Expression: const
                                        * Referenced by: '<S43>/Constant'
                                        */
  -180.0,                              /* Expression: const
                                        * Referenced by: '<S44>/Constant'
                                        */
  200.0,                               /* Expression: const
                                        * Referenced by: '<S50>/Constant'
                                        */
  0.0,                                 /* Expression: ICPrevInput
                                        * Referenced by: '<S64>/UD'
                                        */
  180.0,                               /* Expression: const
                                        * Referenced by: '<S61>/Constant'
                                        */
  -180.0,                              /* Expression: const
                                        * Referenced by: '<S62>/Constant'
                                        */
  0.0,                                 /* Expression: ICPrevInput
                                        * Referenced by: '<S71>/UD'
                                        */
  180.0,                               /* Expression: const
                                        * Referenced by: '<S68>/Constant'
                                        */
  -180.0,                              /* Expression: const
                                        * Referenced by: '<S69>/Constant'
                                        */
  0.0,                                 /* Expression: ICPrevInput
                                        * Referenced by: '<S90>/UD'
                                        */
  180.0,                               /* Expression: const
                                        * Referenced by: '<S87>/Constant'
                                        */
  -180.0,                              /* Expression: const
                                        * Referenced by: '<S88>/Constant'
                                        */
  0.0,                                 /* Expression: ICPrevInput
                                        * Referenced by: '<S97>/UD'
                                        */
  180.0,                               /* Expression: const
                                        * Referenced by: '<S94>/Constant'
                                        */
  -180.0,                              /* Expression: const
                                        * Referenced by: '<S95>/Constant'
                                        */
  0U,                                  /* Computed Parameter: UnitDelay_X0
                                        * Referenced by: '<S80>/Unit Delay'
                                        */
  0U,                                  /* Computed Parameter: UnitDelay_X0_h
                                        * Referenced by: '<S79>/Unit Delay'
                                        */
  0,                                   /* Computed Parameter: DelayInput1_X0
                                        * Referenced by: '<S85>/Delay Input1'
                                        */
  0,                                   /* Computed Parameter: DelayInput1_X0_b
                                        * Referenced by: '<S86>/Delay Input1'
                                        */

  /* Start of '<S84>/unwrap1' */
  {
    360.0                              /* Expression: -360
                                        * Referenced by: '<S99>/Bias2'
                                        */
  }
  /* End of '<S84>/unwrap1' */
  ,

  /* Start of '<S84>/unwrap' */
  {
    -360.0                             /* Expression: -360
                                        * Referenced by: '<S98>/Bias2'
                                        */
  }
  /* End of '<S84>/unwrap' */
  ,

  /* Start of '<S83>/unwrap1' */
  {
    360.0                              /* Expression: -360
                                        * Referenced by: '<S92>/Bias2'
                                        */
  }
  /* End of '<S83>/unwrap1' */
  ,

  /* Start of '<S83>/unwrap' */
  {
    -360.0                             /* Expression: -360
                                        * Referenced by: '<S91>/Bias2'
                                        */
  }
  /* End of '<S83>/unwrap' */
  ,

  /* Start of '<S4>/Compute ArcTan2 b' */
  {
    57.295779513082323                 /* Expression: 180/pi
                                        * Referenced by: '<S78>/Gain1'
                                        */
  }
  /* End of '<S4>/Compute ArcTan2 b' */
  ,

  /* Start of '<S4>/Compute ArcTan2' */
  {
    57.295779513082323                 /* Expression: 180/pi
                                        * Referenced by: '<S77>/Gain1'
                                        */
  }
  /* End of '<S4>/Compute ArcTan2' */
  ,

  /* Start of '<S58>/unwrap1' */
  {
    360.0                              /* Expression: -360
                                        * Referenced by: '<S73>/Bias2'
                                        */
  }
  /* End of '<S58>/unwrap1' */
  ,

  /* Start of '<S58>/unwrap' */
  {
    -360.0                             /* Expression: -360
                                        * Referenced by: '<S72>/Bias2'
                                        */
  }
  /* End of '<S58>/unwrap' */
  ,

  /* Start of '<S57>/unwrap1' */
  {
    360.0                              /* Expression: -360
                                        * Referenced by: '<S66>/Bias2'
                                        */
  }
  /* End of '<S57>/unwrap1' */
  ,

  /* Start of '<S57>/unwrap' */
  {
    -360.0                             /* Expression: -360
                                        * Referenced by: '<S65>/Bias2'
                                        */
  }
  /* End of '<S57>/unwrap' */
  ,

  /* Start of '<S3>/Compute ArcTan2 b' */
  {
    57.295779513082323                 /* Expression: 180/pi
                                        * Referenced by: '<S53>/Gain1'
                                        */
  }
  /* End of '<S3>/Compute ArcTan2 b' */
  ,

  /* Start of '<S3>/Compute ArcTan2' */
  {
    57.295779513082323                 /* Expression: 180/pi
                                        * Referenced by: '<S52>/Gain1'
                                        */
  }
  /* End of '<S3>/Compute ArcTan2' */
  ,

  /* Start of '<S35>/unwrap1' */
  {
    360.0                              /* Expression: -360
                                        * Referenced by: '<S48>/Bias2'
                                        */
  }
  /* End of '<S35>/unwrap1' */
  ,

  /* Start of '<S35>/unwrap' */
  {
    -360.0                             /* Expression: -360
                                        * Referenced by: '<S47>/Bias2'
                                        */
  }
  /* End of '<S35>/unwrap' */
  ,

  /* Start of '<S34>/unwrap1' */
  {
    360.0                              /* Expression: -360
                                        * Referenced by: '<S41>/Bias2'
                                        */
  }
  /* End of '<S34>/unwrap1' */
  ,

  /* Start of '<S34>/unwrap' */
  {
    -360.0                             /* Expression: -360
                                        * Referenced by: '<S40>/Bias2'
                                        */
  }
  /* End of '<S34>/unwrap' */
  ,

  /* Start of '<S14>/unwrap1' */
  {
    360.0                              /* Expression: -360
                                        * Referenced by: '<S27>/Bias2'
                                        */
  }
  /* End of '<S14>/unwrap1' */
  ,

  /* Start of '<S14>/unwrap' */
  {
    -360.0                             /* Expression: -360
                                        * Referenced by: '<S26>/Bias2'
                                        */
  }
  /* End of '<S14>/unwrap' */
  ,

  /* Start of '<S13>/unwrap1' */
  {
    360.0                              /* Expression: -360
                                        * Referenced by: '<S20>/Bias2'
                                        */
  }
  /* End of '<S13>/unwrap1' */
  ,

  /* Start of '<S13>/unwrap' */
  {
    -360.0                             /* Expression: -360
                                        * Referenced by: '<S19>/Bias2'
                                        */
  }
  /* End of '<S13>/unwrap' */
};

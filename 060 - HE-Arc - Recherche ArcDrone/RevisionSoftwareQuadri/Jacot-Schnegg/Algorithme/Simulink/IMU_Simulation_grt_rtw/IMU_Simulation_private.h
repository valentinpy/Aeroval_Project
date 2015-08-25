/*
 * IMU_Simulation_private.h
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
#ifndef RTW_HEADER_IMU_Simulation_private_h_
#define RTW_HEADER_IMU_Simulation_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern real_T rt_atan2d_snf(real_T u0, real_T u1);

/* Exported functions */
/* Exported functions */
void BINARYSEARCH_real_T_iL(uint32_T *piLeft, real_T u, const real_T *pData,
  uint32_T iHi);
extern void IMU_Simulation_unwrap(uint8_T rtu_0, real_T rtu_In1, real_T
  *rty_Out1, rtP_unwrap_IMU_Simulation *localP);
extern void IMU_Simulation_unwrap2(boolean_T rtu_0, real_T rtu_1, real_T
  *rty_Out1);
extern void IMU_Simu_ComputeArcTan2_Disable(rtDW_ComputeArcTan2_IMU_Simulat
  *localDW);
extern void IMU_Simulation_ComputeArcTan2TID0(real_T rtu_Force1, real_T
  rtu_Force2, rtB_ComputeArcTan2_IMU_Simulati *localB,
  rtDW_ComputeArcTan2_IMU_Simulat *localDW, rtP_ComputeArcTan2_IMU_Simulati
  *localP);
extern void IMU_Simulation_ComputeArcTan2TID1(boolean_T rtu_0,
  rtDW_ComputeArcTan2_IMU_Simulat *localDW);

#endif                                 /* RTW_HEADER_IMU_Simulation_private_h_ */

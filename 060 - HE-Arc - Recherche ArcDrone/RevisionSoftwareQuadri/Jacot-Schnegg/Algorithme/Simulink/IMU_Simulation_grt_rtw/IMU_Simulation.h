/*
 * IMU_Simulation.h
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
#ifndef RTW_HEADER_IMU_Simulation_h_
#define RTW_HEADER_IMU_Simulation_h_
#ifndef IMU_Simulation_COMMON_INCLUDES_
# define IMU_Simulation_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* IMU_Simulation_COMMON_INCLUDES_ */

#include "IMU_Simulation_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define IMU_Simulation_rtModel         RT_MODEL_IMU_Simulation

/* Block signals for system '<S3>/Compute ArcTan2' */
typedef struct {
  real_T Gain1;                        /* '<S52>/Gain1' */
} rtB_ComputeArcTan2_IMU_Simulati;

/* Block states (auto storage) for system '<S3>/Compute ArcTan2' */
typedef struct {
  boolean_T ComputeArcTan2_MODE;       /* '<S3>/Compute ArcTan2' */
} rtDW_ComputeArcTan2_IMU_Simulat;

/* Block signals (auto storage) */
typedef struct {
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T AccelZ;                       /* '<S4>/Gain1' */
  real_T AccelX;                       /* '<S4>/Gain4' */
  real_T MultiportSwitch1[2];          /* '<S80>/Multiport Switch1' */
  real_T DiscreteTimeIntegrator;       /* '<S13>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_l;     /* '<S34>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_i;     /* '<S58>/Discrete-Time Integrator' */
  real_T AccelZ_g;                     /* '<S3>/Gain1' */
  real_T AccelX_k;                     /* '<S3>/Gain4' */
  real_T Sum4;                         /* '<S55>/Sum4' */
  real_T UnbiasedAccelY;               /* '<S5>/Sum' */
  real_T MultiportSwitch1_k[2];        /* '<S79>/Multiport Switch1' */
  real_T Gain3;                        /* '<S1>/Gain3' */
  real_T Gain6;                        /* '<S1>/Gain6' */
  real_T Merge;                        /* '<S13>/Merge' */
  real_T Sum2;                         /* '<S13>/Sum2' */
  real_T Merge_g;                      /* '<S14>/Merge' */
  real_T Gain3_h;                      /* '<S2>/Gain3' */
  real_T Gain6_o;                      /* '<S2>/Gain6' */
  real_T Merge_o;                      /* '<S34>/Merge' */
  real_T Sum2_j;                       /* '<S34>/Sum2' */
  real_T Merge_j;                      /* '<S35>/Merge' */
  real_T Merge_k;                      /* '<S57>/Merge' */
  real_T Merge_gw;                     /* '<S58>/Merge' */
  real_T Sum2_n;                       /* '<S58>/Sum2' */
  real_T Merge_a;                      /* '<S83>/Merge' */
  real_T Sum2_l;                       /* '<S83>/Sum2' */
  real_T Merge_a3;                     /* '<S84>/Merge' */
  real_T Sum2_lh;                      /* '<S84>/Sum2' */
  uint8_T Compare;                     /* '<S15>/Compare' */
  uint8_T Compare_a;                   /* '<S16>/Compare' */
  uint8_T Compare_p;                   /* '<S22>/Compare' */
  uint8_T Compare_o;                   /* '<S23>/Compare' */
  uint8_T Compare_k;                   /* '<S36>/Compare' */
  uint8_T Compare_ov;                  /* '<S37>/Compare' */
  uint8_T Compare_n;                   /* '<S43>/Compare' */
  uint8_T Compare_h;                   /* '<S44>/Compare' */
  uint8_T Compare_i;                   /* '<S61>/Compare' */
  uint8_T Compare_j;                   /* '<S62>/Compare' */
  uint8_T Compare_of;                  /* '<S68>/Compare' */
  uint8_T Compare_oh;                  /* '<S69>/Compare' */
  uint8_T FixPtRelationalOperator;     /* '<S85>/FixPt Relational Operator' */
  uint8_T FixPtRelationalOperator_f;   /* '<S86>/FixPt Relational Operator' */
  uint8_T Compare_pp;                  /* '<S87>/Compare' */
  uint8_T Compare_ph;                  /* '<S88>/Compare' */
  uint8_T Compare_o1;                  /* '<S94>/Compare' */
  uint8_T Compare_hj;                  /* '<S95>/Compare' */
  boolean_T Compare_m;                 /* '<S76>/Compare' */
  boolean_T LogicalOperator1;          /* '<S4>/Logical Operator1' */
  boolean_T Compare_f;                 /* '<S51>/Compare' */
  boolean_T Compare_oa;                /* '<S75>/Compare' */
  boolean_T LogicalOperator;           /* '<S4>/Logical Operator' */
  boolean_T LogicalOperator_b;         /* '<S13>/Logical Operator' */
  boolean_T LogicalOperator_m;         /* '<S14>/Logical Operator' */
  boolean_T LogicalOperator_h;         /* '<S34>/Logical Operator' */
  boolean_T LogicalOperator_i;         /* '<S35>/Logical Operator' */
  boolean_T Compare_ad;                /* '<S50>/Compare' */
  boolean_T LogicalOperator_o;         /* '<S57>/Logical Operator' */
  boolean_T LogicalOperator_ml;        /* '<S58>/Logical Operator' */
  boolean_T LogicalOperator_g;         /* '<S83>/Logical Operator' */
  boolean_T LogicalOperator_p;         /* '<S84>/Logical Operator' */
  rtB_ComputeArcTan2_IMU_Simulati ComputeArcTan2b_h;/* '<S4>/Compute ArcTan2 b' */
  rtB_ComputeArcTan2_IMU_Simulati ComputeArcTan2_n;/* '<S4>/Compute ArcTan2' */
  rtB_ComputeArcTan2_IMU_Simulati ComputeArcTan2b;/* '<S3>/Compute ArcTan2 b' */
  rtB_ComputeArcTan2_IMU_Simulati ComputeArcTan2;/* '<S3>/Compute ArcTan2' */
} BlockIO_IMU_Simulation;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S84>/Discrete-Time Integrator' */
  real_T UnitDelay2_DSTATE[2];         /* '<S80>/Unit Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S13>/Discrete-Time Integrator' */
  real_T DiscreteZeroPole_DSTATE;      /* '<S7>/Discrete Zero-Pole' */
  real_T DiscreteZeroPole_DSTATE_c;    /* '<S11>/Discrete Zero-Pole' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S34>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_DSTATE[2];/* '<S32>/Discrete Transfer Fcn' */
  real_T DiscreteZeroPole_DSTATE_l[2]; /* '<S29>/Discrete Zero-Pole' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S58>/Discrete-Time Integrator' */
  real_T DiscreteZeroPole_DSTATE_f;    /* '<S59>/Discrete Zero-Pole' */
  real_T UnitDelay2_DSTATE_b;          /* '<S55>/Unit Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S83>/Discrete-Time Integrator' */
  real_T UnitDelay2_DSTATE_f[2];       /* '<S79>/Unit Delay2' */
  real_T UD_DSTATE;                    /* '<S18>/UD' */
  real_T UD_DSTATE_j;                  /* '<S25>/UD' */
  real_T DiscreteZeroPole_DSTATE_n[2]; /* '<S30>/Discrete Zero-Pole' */
  real_T UD_DSTATE_d;                  /* '<S39>/UD' */
  real_T UD_DSTATE_k;                  /* '<S46>/UD' */
  real_T UD_DSTATE_k1;                 /* '<S64>/UD' */
  real_T UD_DSTATE_l;                  /* '<S71>/UD' */
  real_T UD_DSTATE_o;                  /* '<S90>/UD' */
  real_T UD_DSTATE_lk;                 /* '<S97>/UD' */
  real_T DiscreteTransferFcn_tmp;      /* '<S32>/Discrete Transfer Fcn' */
  struct {
    void *PrevTimePtr;
  } usecondsrecord_PWORK;              /* '<Root>/28 seconds record' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_e;                    /* '<S2>/Scope4' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_l;                    /* '<S4>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_g;                    /* '<S4>/Scope2' */

  uint8_T UnitDelay_DSTATE;            /* '<S80>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_h;          /* '<S79>/Unit Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S85>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S86>/Delay Input1' */
  rtDW_ComputeArcTan2_IMU_Simulat ComputeArcTan2b_h;/* '<S4>/Compute ArcTan2 b' */
  rtDW_ComputeArcTan2_IMU_Simulat ComputeArcTan2_n;/* '<S4>/Compute ArcTan2' */
  rtDW_ComputeArcTan2_IMU_Simulat ComputeArcTan2b;/* '<S3>/Compute ArcTan2 b' */
  rtDW_ComputeArcTan2_IMU_Simulat ComputeArcTan2;/* '<S3>/Compute ArcTan2' */
} D_Work_IMU_Simulation;

/* Backward compatible GRT Identifiers */
#define rtB                            IMU_Simulation_B
#define BlockIO                        BlockIO_IMU_Simulation
#define rtXdot                         IMU_Simulation_Xdot
#define StateDerivatives               StateDerivatives_IMU_Simulation
#define tXdis                          IMU_Simulation_Xdis
#define StateDisabled                  StateDisabled_IMU_Simulation
#define rtP                            IMU_Simulation_P
#define Parameters                     Parameters_IMU_Simulation
#define rtDWork                        IMU_Simulation_DWork
#define D_Work                         D_Work_IMU_Simulation

/* Parameters for system: '<S13>/unwrap' */
struct rtP_unwrap_IMU_Simulation_ {
  real_T Bias2_Value;                  /* Expression: -360
                                        * Referenced by: '<S19>/Bias2'
                                        */
};

/* Parameters for system: '<S3>/Compute ArcTan2' */
struct rtP_ComputeArcTan2_IMU_Simulati_ {
  real_T Gain1_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S52>/Gain1'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_IMU_Simulation_ {
  real_T Gain6_Gain;                   /* Expression: 1e-3
                                        * Referenced by: '<S55>/Gain6'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Gain6_Gain_n[2];              /* Expression: Kz
                                        * Referenced by: '<S79>/Gain6'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T Gain7_Gain;                   /* Expression: Ts
                                        * Referenced by: '<S79>/Gain7'
                                        */
  real_T Gain6_Gain_b[2];              /* Expression: Kz
                                        * Referenced by: '<S80>/Gain6'
                                        */
  real_T Constant_Value_ej;            /* Expression: 0
                                        * Referenced by: '<S80>/Constant'
                                        */
  real_T Gain7_Gain_l;                 /* Expression: Ts
                                        * Referenced by: '<S80>/Gain7'
                                        */
  real_T addedBiastotestforlargebias_Val;/* Expression: 4
                                          * Referenced by: '<Root>/added Bias to test for large bias'
                                          */
  real_T GyroYgain_Gain;               /* Expression: 80/2048*6.55
                                        * Referenced by: '<S5>/Gyro Y gain'
                                        */
  real_T Biais_Value;                  /* Expression: -18
                                        * Referenced by: '<S5>/Biais '
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S84>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S84>/Discrete-Time Integrator'
                                        */
  real_T LookupTable_XData[3];         /* Expression: [-500 -195 195]
                                        * Referenced by: '<S84>/Lookup Table'
                                        */
  real_T LookupTable_YData[3];         /* Expression: [+360 0 -360]
                                        * Referenced by: '<S84>/Lookup Table'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S96>/Constant'
                                        */
  real_T Bias1_Value;                  /* Expression: -13632
                                        * Referenced by: '<S5>/Bias1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Bias2_Value;                  /* Expression: -13054
                                        * Referenced by: '<S5>/Bias2'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * Referenced by: '<S76>/Constant'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S80>/Unit Delay2'
                                        */
  real_T Gain1_Gain_o[4];              /* Expression: Az
                                        * Referenced by: '<S80>/Gain1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                          * Referenced by: '<S13>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_i;  /* Expression: 0
                                        * Referenced by: '<S13>/Discrete-Time Integrator'
                                        */
  real_T DiscreteZeroPole_A;           /* Computed Parameter: DiscreteZeroPole_A
                                        * Referenced by: '<S7>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_C;           /* Computed Parameter: DiscreteZeroPole_C
                                        * Referenced by: '<S7>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_D;           /* Computed Parameter: DiscreteZeroPole_D
                                        * Referenced by: '<S7>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_A_l;         /* Computed Parameter: DiscreteZeroPole_A_l
                                        * Referenced by: '<S11>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_C_k;         /* Computed Parameter: DiscreteZeroPole_C_k
                                        * Referenced by: '<S11>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_D_b;         /* Computed Parameter: DiscreteZeroPole_D_b
                                        * Referenced by: '<S11>/Discrete Zero-Pole'
                                        */
  real_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                          * Referenced by: '<S34>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_f;  /* Expression: 0
                                        * Referenced by: '<S34>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S32>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn_NumCoef[3];/* Expression: numd
                                         * Referenced by: '<S32>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_DenCoef[3];/* Expression: dend
                                         * Referenced by: '<S32>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteZeroPole_A_a[3];      /* Computed Parameter: DiscreteZeroPole_A_a
                                        * Referenced by: '<S29>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_B;           /* Computed Parameter: DiscreteZeroPole_B
                                        * Referenced by: '<S29>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_C_g[2];      /* Computed Parameter: DiscreteZeroPole_C_g
                                        * Referenced by: '<S29>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_D_e;         /* Computed Parameter: DiscreteZeroPole_D_e
                                        * Referenced by: '<S29>/Discrete Zero-Pole'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                          * Referenced by: '<S58>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S58>/Discrete-Time Integrator'
                                        */
  real_T LookupTable_XData_c[3];       /* Expression: [-500 -195 195]
                                        * Referenced by: '<S58>/Lookup Table'
                                        */
  real_T LookupTable_YData_i[3];       /* Expression: [+360 0 -360]
                                        * Referenced by: '<S58>/Lookup Table'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: -1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Gain4_Gain_o;                 /* Expression: -1
                                        * Referenced by: '<S3>/Gain4'
                                        */
  real_T Constant_Value_i;             /* Expression: const
                                        * Referenced by: '<S51>/Constant'
                                        */
  real_T DiscreteZeroPole_A_ai;        /* Computed Parameter: DiscreteZeroPole_A_ai
                                        * Referenced by: '<S59>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_C_gl;        /* Computed Parameter: DiscreteZeroPole_C_gl
                                        * Referenced by: '<S59>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_D_p;         /* Computed Parameter: DiscreteZeroPole_D_p
                                        * Referenced by: '<S59>/Discrete Zero-Pole'
                                        */
  real_T UnitDelay2_X0_d;              /* Expression: 0
                                        * Referenced by: '<S55>/Unit Delay2'
                                        */
  real_T Gain7_Gain_a;                 /* Expression: Ts
                                        * Referenced by: '<S55>/Gain7'
                                        */
  real_T GyroXgain_Gain;               /* Expression: 80/2048*2.35
                                        * Referenced by: '<S5>/Gyro X gain'
                                        */
  real_T Bias4_Value;                  /* Expression: 13
                                        * Referenced by: '<S5>/Bias4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;/* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                          * Referenced by: '<S83>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_p;  /* Expression: 0
                                        * Referenced by: '<S83>/Discrete-Time Integrator'
                                        */
  real_T LookupTable_XData_e[3];       /* Expression: [-500 -195 195]
                                        * Referenced by: '<S83>/Lookup Table'
                                        */
  real_T LookupTable_YData_h[3];       /* Expression: [+360 0 -360]
                                        * Referenced by: '<S83>/Lookup Table'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Bias_Value;                   /* Expression: -9027
                                        * Referenced by: '<S5>/Bias'
                                        */
  real_T Constant_Value_j;             /* Expression: const
                                        * Referenced by: '<S75>/Constant'
                                        */
  real_T UnitDelay2_X0_f;              /* Expression: 0
                                        * Referenced by: '<S79>/Unit Delay2'
                                        */
  real_T Gain1_Gain_f[4];              /* Expression: Az
                                        * Referenced by: '<S79>/Gain1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Gain4_Gain_a;                 /* Expression: -1
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real_T Gain6_Gain_i;                 /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain6'
                                        */
  real_T UD_X0;                        /* Expression: ICPrevInput
                                        * Referenced by: '<S18>/UD'
                                        */
  real_T Constant_Value_jk;            /* Expression: const
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant_Value_eje;           /* Expression: const
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T LookupTable_XData_i[3];       /* Expression: [-500 -195 195]
                                        * Referenced by: '<S13>/Lookup Table'
                                        */
  real_T LookupTable_YData_k[3];       /* Expression: [+360 0 -360]
                                        * Referenced by: '<S13>/Lookup Table'
                                        */
  real_T UD_X0_c;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S25>/UD'
                                        */
  real_T Constant_Value_m;             /* Expression: const
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T DiscreteZeroPole_A_h[3];      /* Computed Parameter: DiscreteZeroPole_A_h
                                        * Referenced by: '<S30>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_B_m;         /* Computed Parameter: DiscreteZeroPole_B_m
                                        * Referenced by: '<S30>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_C_e[2];      /* Computed Parameter: DiscreteZeroPole_C_e
                                        * Referenced by: '<S30>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_D_m;         /* Computed Parameter: DiscreteZeroPole_D_m
                                        * Referenced by: '<S30>/Discrete Zero-Pole'
                                        */
  real_T Gain1_Gain_od;                /* Expression: -1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: -1
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Gain3_Gain_a;                 /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T Gain4_Gain_j;                 /* Expression: -1
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T Gain6_Gain_o;                 /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain6'
                                        */
  real_T UD_X0_g;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S39>/UD'
                                        */
  real_T Constant_Value_mj;            /* Expression: const
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: const
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T LookupTable_XData_ej[3];      /* Expression: [-500 -195 195]
                                        * Referenced by: '<S34>/Lookup Table'
                                        */
  real_T LookupTable_YData_e[3];       /* Expression: [+360 0 -360]
                                        * Referenced by: '<S34>/Lookup Table'
                                        */
  real_T UD_X0_n;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S46>/UD'
                                        */
  real_T Constant_Value_pg;            /* Expression: const
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: const
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T UD_X0_d;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S64>/UD'
                                        */
  real_T Constant_Value_o0;            /* Expression: const
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Constant_Value_ba;            /* Expression: const
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T UD_X0_m;                      /* Expression: ICPrevInput
                                        * Referenced by: '<S71>/UD'
                                        */
  real_T Constant_Value_mw;            /* Expression: const
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T Constant_Value_ll;            /* Expression: const
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T UD_X0_d5;                     /* Expression: ICPrevInput
                                        * Referenced by: '<S90>/UD'
                                        */
  real_T Constant_Value_ds;            /* Expression: const
                                        * Referenced by: '<S87>/Constant'
                                        */
  real_T Constant_Value_j0;            /* Expression: const
                                        * Referenced by: '<S88>/Constant'
                                        */
  real_T UD_X0_g0;                     /* Expression: ICPrevInput
                                        * Referenced by: '<S97>/UD'
                                        */
  real_T Constant_Value_jd;            /* Expression: const
                                        * Referenced by: '<S94>/Constant'
                                        */
  real_T Constant_Value_fg;            /* Expression: const
                                        * Referenced by: '<S95>/Constant'
                                        */
  uint8_T UnitDelay_X0;                /* Computed Parameter: UnitDelay_X0
                                        * Referenced by: '<S80>/Unit Delay'
                                        */
  uint8_T UnitDelay_X0_h;              /* Computed Parameter: UnitDelay_X0_h
                                        * Referenced by: '<S79>/Unit Delay'
                                        */
  boolean_T DelayInput1_X0;            /* Computed Parameter: DelayInput1_X0
                                        * Referenced by: '<S85>/Delay Input1'
                                        */
  boolean_T DelayInput1_X0_b;          /* Computed Parameter: DelayInput1_X0_b
                                        * Referenced by: '<S86>/Delay Input1'
                                        */
  rtP_unwrap_IMU_Simulation unwrap1_o; /* '<S84>/unwrap1' */
  rtP_unwrap_IMU_Simulation unwrap_i;  /* '<S84>/unwrap' */
  rtP_unwrap_IMU_Simulation unwrap1_c; /* '<S83>/unwrap1' */
  rtP_unwrap_IMU_Simulation unwrap_eb; /* '<S83>/unwrap' */
  rtP_ComputeArcTan2_IMU_Simulati ComputeArcTan2b_h;/* '<S4>/Compute ArcTan2 b' */
  rtP_ComputeArcTan2_IMU_Simulati ComputeArcTan2_n;/* '<S4>/Compute ArcTan2' */
  rtP_unwrap_IMU_Simulation unwrap1_ha;/* '<S58>/unwrap1' */
  rtP_unwrap_IMU_Simulation unwrap_g;  /* '<S58>/unwrap' */
  rtP_unwrap_IMU_Simulation unwrap1_m; /* '<S57>/unwrap1' */
  rtP_unwrap_IMU_Simulation unwrap_j;  /* '<S57>/unwrap' */
  rtP_ComputeArcTan2_IMU_Simulati ComputeArcTan2b;/* '<S3>/Compute ArcTan2 b' */
  rtP_ComputeArcTan2_IMU_Simulati ComputeArcTan2;/* '<S3>/Compute ArcTan2' */
  rtP_unwrap_IMU_Simulation unwrap1_h; /* '<S35>/unwrap1' */
  rtP_unwrap_IMU_Simulation unwrap_n5; /* '<S35>/unwrap' */
  rtP_unwrap_IMU_Simulation unwrap1_k; /* '<S34>/unwrap1' */
  rtP_unwrap_IMU_Simulation unwrap_n;  /* '<S34>/unwrap' */
  rtP_unwrap_IMU_Simulation unwrap1_a; /* '<S14>/unwrap1' */
  rtP_unwrap_IMU_Simulation unwrap_e;  /* '<S14>/unwrap' */
  rtP_unwrap_IMU_Simulation unwrap1;   /* '<S13>/unwrap1' */
  rtP_unwrap_IMU_Simulation unwrap;    /* '<S13>/unwrap' */
};

/* Real-time Model Data Structure */
struct RT_MODEL_IMU_Simulation {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    struct {
      uint16_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_IMU_Simulation IMU_Simulation_P;

/* Block signals (auto storage) */
extern BlockIO_IMU_Simulation IMU_Simulation_B;

/* Block states (auto storage) */
extern D_Work_IMU_Simulation IMU_Simulation_DWork;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Real-time Model object */
extern struct RT_MODEL_IMU_Simulation *const IMU_Simulation_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'IMU_Simulation'
 * '<S1>'   : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1'
 * '<S2>'   : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2'
 * '<S3>'   : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)'
 * '<S4>'   : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)'
 * '<S5>'   : 'IMU_Simulation/Sensor Calibration (2 axis gyro and 3 axis accelerometer)'
 * '<S6>'   : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/High Pass2'
 * '<S7>'   : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Low Pass'
 * '<S8>'   : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Low Pass1'
 * '<S9>'   : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Pseudo Integrator  with inverted gyro gynamic'
 * '<S10>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Pseudo Integrator *  High pass Filter * inverted gyro dynamic2'
 * '<S11>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Pseudo Integrator * High pass Filter * inverted gyro dynamic'
 * '<S12>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Pseudo Integrator * High pass Filter * inverted gyro dynamic1'
 * '<S13>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap1'
 * '<S14>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap2'
 * '<S15>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap1/Compare To Constant'
 * '<S16>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap1/Compare To Constant1'
 * '<S17>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap1/Compare To Zero'
 * '<S18>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap1/Difference'
 * '<S19>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap1/unwrap'
 * '<S20>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap1/unwrap1'
 * '<S21>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap1/unwrap2'
 * '<S22>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap2/Compare To Constant'
 * '<S23>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap2/Compare To Constant1'
 * '<S24>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap2/Compare To Zero'
 * '<S25>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap2/Difference'
 * '<S26>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap2/unwrap'
 * '<S27>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap2/unwrap1'
 * '<S28>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 1/Unwrap2/unwrap2'
 * '<S29>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Integrator * High pass Filter'
 * '<S30>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Integrator * High pass Filter * inverted gyro dynamic'
 * '<S31>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Integrator * High pass Filter1'
 * '<S32>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Transfer Fcn'
 * '<S33>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Transfer Fcn1'
 * '<S34>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap1'
 * '<S35>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap2'
 * '<S36>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap1/Compare To Constant'
 * '<S37>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap1/Compare To Constant1'
 * '<S38>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap1/Compare To Zero'
 * '<S39>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap1/Difference'
 * '<S40>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap1/unwrap'
 * '<S41>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap1/unwrap1'
 * '<S42>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap1/unwrap2'
 * '<S43>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap2/Compare To Constant'
 * '<S44>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap2/Compare To Constant1'
 * '<S45>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap2/Compare To Zero'
 * '<S46>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap2/Difference'
 * '<S47>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap2/unwrap'
 * '<S48>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap2/unwrap1'
 * '<S49>'  : 'IMU_Simulation/Angle Estimation Complementary Filter Order 2/Unwrap2/unwrap2'
 * '<S50>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Compare To Constant'
 * '<S51>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Compare To Constant1'
 * '<S52>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Compute ArcTan2'
 * '<S53>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Compute ArcTan2 b'
 * '<S54>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Norm L1'
 * '<S55>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Pisano'
 * '<S56>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Pisano1'
 * '<S57>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap1'
 * '<S58>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap2'
 * '<S59>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Pisano/Low Pass1'
 * '<S60>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Pisano1/Low Pass1'
 * '<S61>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap1/Compare To Constant'
 * '<S62>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap1/Compare To Constant1'
 * '<S63>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap1/Compare To Zero'
 * '<S64>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap1/Difference'
 * '<S65>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap1/unwrap'
 * '<S66>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap1/unwrap1'
 * '<S67>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap1/unwrap2'
 * '<S68>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap2/Compare To Constant'
 * '<S69>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap2/Compare To Constant1'
 * '<S70>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap2/Compare To Zero'
 * '<S71>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap2/Difference'
 * '<S72>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap2/unwrap'
 * '<S73>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap2/unwrap1'
 * '<S74>'  : 'IMU_Simulation/Angles Estimation (Ref: Pisano 2005)/Unwrap2/unwrap2'
 * '<S75>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Compare To Constant'
 * '<S76>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Compare To Constant1'
 * '<S77>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Compute ArcTan2'
 * '<S78>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Compute ArcTan2 b'
 * '<S79>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Kalman1'
 * '<S80>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Kalman2'
 * '<S81>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Norm L1'
 * '<S82>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Simplified Kalman for publi'
 * '<S83>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap1'
 * '<S84>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap2'
 * '<S85>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Kalman1/Detect Rising edge'
 * '<S86>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Kalman2/Detect Rising edge'
 * '<S87>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap1/Compare To Constant'
 * '<S88>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap1/Compare To Constant1'
 * '<S89>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap1/Compare To Zero'
 * '<S90>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap1/Difference'
 * '<S91>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap1/unwrap'
 * '<S92>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap1/unwrap1'
 * '<S93>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap1/unwrap2'
 * '<S94>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap2/Compare To Constant'
 * '<S95>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap2/Compare To Constant1'
 * '<S96>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap2/Compare To Zero'
 * '<S97>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap2/Difference'
 * '<S98>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap2/unwrap'
 * '<S99>'  : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap2/unwrap1'
 * '<S100>' : 'IMU_Simulation/Angles Estimation Alpha Beta Filter (Kalman structure)/Unwrap2/unwrap2'
 */
#endif                                 /* RTW_HEADER_IMU_Simulation_h_ */

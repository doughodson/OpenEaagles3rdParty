/* $include$="c.cfg"
@name@
DriverùLINX(tm) Message and Result Codes
@paths@
modules\DriverLINX(R) Message and Result Codes
modules\all
modules\@./MDL@
@1@
@skip start@*/
/****************************************************************************/
/*                                                                          */
/*        D L C O D E S . H - DriverLINX(R) Message and Result Codes        */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*            (C) Copyright 1991 Scientific Software Tools, Inc.            */
/*                           All Rights Reserved.                           */
/*                                                                          */
/*                      Scientific Software Tools, Inc.                     */
/*                          19 East Central Avenue                          */
/*                              Paoli, PA 19301                             */
/*                    (215) 889-1354  FAX (215) 889-1556                    */
/*                DriverLINX is a registered trademark of SST               */
/*                                                                          */
/****************************************************************************/
/*@skip end@*/
/****************************************************************************
 *      D L C O D E S . H    R E V I S I O N   H I S T O R Y
 * @/F1@
 * $Revision: 3 $
 * $Log: /Dlnx5000/DlnxShar/DLCODES.H $
 * 
 * 3     7/22/97 2:15p Royf
 * Remove DLXSOFTWAREKEY
 * 
 * 2     7/22/97 1:14p Royf
 * Added VENDORKEY and DLXSOFTWAREKEY
 * 
 * 1     5/24/95 4:29p Royf
 * 
 * 1     5/24/95 1:57p Royf
   
      Rev 1.13   05 Nov 1993 10:04:44   RFURMAN
   
      Rev 1.12   22 Mar 1993 16:48:22   RFURMAN
   Added Axon Instruments
   
   
      Rev 1.11   06 Sep 1992 20:23:40   Furman
   Added following messages
     erTaskAlloc
     erBufAlloc
     erTimeout              
     erInternalTimer
     erNoFIFO          
     erNoDASRam
     erDACLinearity
     erADCalibration
     erDACalibration
   
   
      Rev 1.10   20 Aug 1992 20:43:10   Furman
   Changed macros to inline functions for C++.
   
   
      Rev 1.9   09 Feb 1992 21:47:46   Furman
   Added IOValueErr and Analogic Corporation
   
      Rev 1.8   17 Sep 1991 10:06:58   Furman
   Added new error messages: HardwareTestErr, ClockingError, SettlingError,
   and DataLost.
   
      Rev 1.7   11 Sep 1991 22:20:32   Furman
   Added vendor ADAC Corporation
   
      Rev 1.6   09 Sep 1991 11:22:34   Furman
   Modified Channel/Gain list overflow to include too few channels.
   Added vendor code for Data Translation.
   
      Rev 1.5   17 Jul 1991 16:06:00
   
      Rev 1.4   13 May 1991 23:39:20
   
      Rev 1.3   05 May 1991 19:16:40
   
      Rev 1.2   10 Mar 1991 21:12:10
   
      Rev 1.1   13 Jan 1991 22:00:30
   
      Rev 1.0   05 Jan 1991 13:41:44
   Initial revision.
 *
 ****************************************************************************/
/*@/F2@*/
/****************************************************************************
 *                                                            +-------------+
 *  Author: Roy Furman                                        | M O D U L E |
 *  Date:   December, 1990                                    +-------------+
 *
 **************@0@
 * SYNOPSIS:    Definition of Symbolic Messages and Result Code Constants
 *
 * DESCRIPTION: Codes for use with all boards.
 *
 *   Most result codes are standardized for all data acquisition boards
 * supported by the DriverùLINX line of Windows DLLs so that an application
 * can respond automatically to various situations.  All DriverùLINX functions
 * return 0 (NoErr) on success or a result code in case of error.  Codes are
 * returned both in the result field of the Service Request and as a function
 * value.
 *
 *   The result encodes the error severity and one of the following codes.
 * The status can be returned to DriverùLINX for display as a message box, or
 * the application can decode the status using the macros defined below.
 *
 * Error severity levels:
 *      Warning  - errors that do not result in failure of function, such
 *                 as data overruns.
 *      Abort    - Requested function was not performed.  No ongoing functions
 *                 were disturbed.  Request may be repeated after correcting
 *                 the error.
 *      Fatal    - Request was terminated with an unrecoverable error and/or
 *                 data loss.
 *      Internal - Unexpected errors resulting from corruption of device driver
 *                 data or device driver programming errors.
 *
 ****************************************************************************/
/*@end@*/


#ifndef DLCODES_H
#define DLCODES_H

  /* Table of result codes */
  /* Following result codes are standardized for all device drivers */

  /* General */

#define NoErr                       0  /* No error */
#define InternalErr                 1  /* Internal driver error */
#define InvalidErrErr               2  /* Invalid error number */

  /* Service Request */

#define InvalidSRHandleErr          5  /* Invalid service request handle */
#define OutOfBoundsErr             10  /* Invalid service request */
#define InvalidWinHandleErr        15  /* Invalid window handle */
#define ServiceNotSupportedErr     20  /* Service not supported by driver */
#define InvalidDeviceNumErr        25  /* Invalid logical device number */
#define InvalidSubsystemErr        30  /* Invalid subsystem requested */
#define InvalidModeErr             35  /* Invalid operation mode requested */
#define InvalidOpErr               40  /* Invalid operation requested */
#define InvalidOpFlagsErr          45  /* Invalid operation flags */
#define InvalidExtErr              50  /* Invalid OEM extension handle */
#define erTaskAlloc                51  /* Cannot allocate task memory */
#define NotTaskErr                 55  /* Service request not found */
#define SystemNotInit              60  /* Subsystem not initialized */
#define WindowCreateErr            65  /* Window creation error */
#define EditCanceled               70  /* Edit cancelled */
#define ConfigureCanceled          75  /* Configure canceled */

  /* Logical Device Descriptors */

#define UnpairedLDDLockErr         80  /* Lock/UnlockLDD calls cannot be nested */

  /* Messages */

#define MsgQOverflow               85  /* Message queue overflowed */

  /* Driver and Device */

#define NOTINIT                    90  /* Driver not initialized */
#define DriverBusyErr              95  /* Driver busy */
#define NoHardwareErr             100  /* No hardware detected */
#define INVADDRESS                105  /* Invalid hardware base address */
#define HardwareMismatch          110  /* Mismatch between hardware and LDD */
#define HardwareTestErr           111  /* Hardware failed testing */
#define DeviceNotInitErr          115  /* Device not initialized */
#define DeviceBusyErr             120  /* Device busy */
#define DeviceInUse               125  /* Device in use by another application */

  /* Channels */

#define IllegalStartChan          130  /* Start Channel is invalid */
#define IllegalEndChan            135  /* End Channel is invalid */
#define StartAboveEnd             140  /* Start > End not supported */
#define GAINCODE                  145  /* Illegal gain requested */
#define NoGainErr                 150  /* Programmable gain not supported */
#define ChanGainNotSup            155  /* Channel/Gain List is not supported */
#define ChanConflict              160  /* Start/Stop and Channel/Gain list specified */
#define ChanGainListOvr           165  /* Channel/Gain list has too few/many entries */
#define BadChanInList             170  /* Invalid channel in Channel/Gain list */
#define BadGainInList             175  /* Invalid gain in Channel/Gain list */
#define CyclicConvIllegal         180  /* Circular conversions not supported */
#define PermErr                   185  /* Requested options not supported */
#define SimulErr                  190  /* Simultaneous I/O not supported */

  /* Buffers */

#define BufNotReqdErr             195  /* I/O buffers not used */
#define IOValueErr                196  /* I/O value not specified */
#define InvalidBLHandleErr        200  /* Invalid buffer list handle */
#define InvalidNBuffer            205  /* Number of buffers 0 or exceeds limit */
#define erBufAlloc                206  /* Cannot allocate memory for buffers */
#define IncompleteScanErr         210  /* Buffer does not hold integral # of scans */
#define InvNConv                  215  /* Invalid # of conversions */
#define BufAllocErr               220  /* Memory buffer allocation failed */
#define BufFreeErr                225  /* Memory buffer deallocation failed */
#define NullHandleErr             230  /* Memory handle is null */
#define NullPointerErr            235  /* Memory pointer is null */
#define NilPointerErr             240  /* Nil memory pointer */
#define NoObjForHandleErr         245  /* Handle does not refer to valid memory object */
#define NumFormatNotSupported     250  /* Requested number format not supported */
#define InvalidNumFormat          255  /* Unrecognized number format */

  /* Critical Section Flags */

#define NoCritSectErr             260  /* Multiple critical sections are not supported */
#define NoCritSectOpt             265  /* Unrecognized critical section option */
#define NoCritSectWarn            270  /* Critical section may cause deadlock */
#define NoCritSectAllowd          275  /* Critical section not allowed */
#define NoCritSectBegin           280  /* Not in critical section */
#define NoCritSectNoOp            285  /* Critical section options will block task */

  /* Interrupts */

#define IntNotSupported           290  /* Interrupts not supported */
#define INVIRQ                    295  /* Invalid interrupt level */
#define IntInUseErr               300  /* Interrupt(s) are in use */
#define IntOvrErr                 305  /* Interrupt overrun */

  /* DMA */

#define DMANotSupported           310  /* DMA not supported */
#define INVDMA                    315  /* Invalid DMA level */
#define DMAInUseErr               320  /* DMA channel(s) are in use */
#define DMAIntActiveErr           325  /* DMA/Interrupt already active */
#define DMABufferErr              330  /* DMA buffer straddles physical page */
#define VDS_NotContig             335  /* DMA region not in contiguous memory */
#define VDS_NotLocked             340  /* Unable to lock memory pages for DMA */
#define VDS_NoBuffer              345  /* No DMA buffer available */
#define VDS_RegionTooLarge        350  /* DMA region too large for buffer */
#define VDS_BufferBusy            355  /* DMA buffer currently in use */
#define VDS_RegionInvalid         360  /* Invalid DMA memory region */
#define VDS_RegionNotLocked       365  /* DMA region was not locked */
#define VDS_TooManyPages          370  /* Number of physical pages was greater than table length */
#define VDS_InvalidBufferId       375  /* Invalid DMA buffer ID */
#define VDS_CopyOutOfRange        380  /* Copy out of DMA buffer range */
#define VDS_InvalidDMAChannel     385  /* Invalid DMA channel number */
#define VDS_CountOverflow         390  /* Disable count overflow */
#define VDS_CountUnderflow        395  /* Disable count underflow */
#define DMANoIntErr               400  /* Interrupt required for multiple DMA buffering */

  /* Events */

#define EventNotSupErr            405  /* Requested event not supported for operation */
#define BadEventErr               410  /* Invalid event type specified */
#define TimingEventNotSupErr      415  /* Requested timing event not supported */
#define StartEventNotSupErr       420  /* Requested start event not supported */
#define StopEventNotSupErr        425  /* Requested stop event not supported */
#define EventComboNotSupErr       430  /* Requested combination of events not supported */

  /* Analog Events */

#define AEvtChnErr                435  /* Invalid analog event channel */
#define AEvtGainErr               440  /* Invalid analog event gain */
#define AEvtLvlErr                445  /* Invalid analog event thresholds */

  /* Digital Events */

#define DEvtChnErr                450  /* Invalid digital event channel */
#define DigMaskErr                455  /* Digital mask bits outside hardware range */
#define DigPatErr                 460  /* Digital pattern bits outside mask range */

  /* Time Events */

#define TEvtChnErr                465  /* Invalid time event channel */

  /* Rate Events */

#define REvtChnErr                470  /* Invalid rate event channel */
#define TimerFuncErr              475  /* Function not supported by requested timer */
#define NoConvDelay               480  /* Conversion delay not specified */
#define BadTimerChan              485  /* Counter/timer channel is invalid */
#define BadTimerDelay             490  /* Counter value is invalid */
#define RolloverErr               495  /* Counter overflow */
#define InversionWarn             500  /* Pulse output is inverted */
#define IntervalNotSupErr         505  /* Time interval on 1 timer is not supported */
#define HardwareLimWarn           510  /* Consult manual for hardware limitations */
#define OnCountInvalid            515  /* Pulse on-count > specified period */
#define BadGateValue              520  /* Gate value is invalid */
#define BadClockValue             525  /* Clock value is invalid */
#define BadCTModeErr              530  /* Counter/timer mode is not supported */
#define GateNotAllowed            535  /* Counter/timer gate mode not allowed */
#define NoPulsesErr               540  /* Requested number of pulses not supported */
#define NoExtClkErr               545  /* External clocking required */
#define NoIntClkErr               550  /* Internal clocking required */

  /* Errors detected during tasks */

#define ClockingErr               555  /* Clock rate too fast to process */
#define SettlingErr               560  /* Multiplexer settling error */
#define DataLost                  565  /* Data lost */

  /* Errors detected with hardware resources */

#define erTimeout                 570  /* Hardware timeout */
#define erInternalTimer           575  /* Internal timer request failed */
#define erNoFIFO                  580  /* FIFO not detected */
#define erNoDASRam                585  /* On-board RAM not detected */
#define erDACLinearity            590  /* DAC linearity test failed */
#define erADCalibration           595  /* A/D calibration error */
#define erDACalibration           600  /* D/A calibration error */

#define DRIVERNAME             0x3fff  /* Name of DriverùLINX */
#define COPYRIGHT              0x3ffe  /* Copyright notice */
#define DRIVERLINXVERSION      0x3ffd  /* Specific version of DriverùLINX */
#define VENDORKEY              0x3ffc  /* SST registry key name */

  /* Following are vendor codes */

#define ADVANTECH_LTD          0x2ff0  /* Advantech */
#define COMPUTER_BOARDS        0x2fe0  /* Computer Boards */
#define INDUSTRIAL_COMPUTER    0x2fd0  /* Industrial Computer Source */
#define KEITHLEY_METRABYTE     0x2fc0  /* Keithley MetraByte */
#define SCIENTIFIC_SOLUTIONS   0x2fb0  /* Scientific Solutions */
#define SOLTEC                 0x2fa0  /* Soltec */
#define DATA_TRANSLATION       0x2f90  /* Data Translation */
#define ADAC_CORPORATION       0x2f80  /* ADAC Corporation */
#define ANALOGIC               0x2f70  /* Analogic Corporation */
#define AXON                   0x2f60  /* Axon Instruments */

  /* Following result codes are OEM specific */


#ifndef DLCODES_RC

typedef enum ErrSeverity { Warning, Abort, Fatal, Internal } ErrSeverities;

#ifdef __cplusplus

  /* Create encoded error */
inline WORD PASCAL Error (const WORD severity, const WORD code)
{ return ((WORD) ((severity & 3) << 14) | (code & 0x3fff)); }

  /* Return error severity */
inline WORD PASCAL getErrSeverity (const WORD error) { return (error >> 14); }

  /* Return error code */
inline WORD PASCAL getErrCode (const WORD error) { return (error & 0x3fff); }

#else

  /* Create encoded error */
#define Error(severity, code) \
    ((WORD) ((severity & 3) << 14) | (code & 0x3fff))

  /* Return error severity */
#define getErrSeverity(error) (error >> 14)

  /* Return error code */
#define getErrCode(error) (error & 0x3fff)

#endif

#endif /* DLCODES_RC */

#endif /* DLCODES_H */



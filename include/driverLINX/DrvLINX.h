/* $include$="c.cfg"
@name@
DriverLINX(R) Interface Header for C/C++
@paths@
modules\DriverLINX(R) Interface Header for C/C++
modules\all
modules\@./MDL@
@1@
@skip start@*/
/****************************************************************************/
/*                                                                          */
/*       D R V L I N X . H - DriverLINX(R) Interface Header for C/C++       */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*            (C) Copyright 1993 Scientific Software Tools, Inc.            */
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
 *      D R V L I N X . H    R E V I S I O N   H I S T O R Y
 * @/F1@
 * $Revision: 25 $
 * $Log: /DlWin32/DRVLINX.H $
 *
 * 25    8/09/01 8:51a Royf
 * Added note that multitasking flags are not used with 32-bit apps.
 * Added NO_INTERACTION flag for internal use.
 *
 * 24    7/18/01 4:41p Royf
 * Added  DL_INTERNAL_FLAGS and DL_WDM_FLAG for DevFlags.
 *
 * 23    9/22/99 5:24p Royf
 * Added An_AnaChan if hardware supports separate analog trigger channel.
 * Added symbolic constant for AnaDefTrgChn, default analog trigger
 * channel.
 * Added CHAN_OEM... gain modifiers for unique hardware-specific features.
 *
 * 22    5/07/99 2:23p Royf
 * Added support for programmable analog coupling.
 *
 * 21    3/23/99 3:01p Royf
 * Add new An_Uses32BitXfer flag to indicate hdw always transfers samples
 * in units of 32-bits.
 *
 * 20    2/18/99 11:05a Royf
 * Added portable definitions for programmable SE/DIFF inputs.
 *
 * 19    12/15/98 3:47p Royf
 * Added new analog I/O flag: An_CustomGains for boards that support
 * modifier bits to basic gain settings.
 *
 * 18    5/26/98 10:57a Royf
 * Version to resynchronize file in version control system.
 *
 * 18    4/01/98 4:48p Royf
 * Added DIO_STROBED_NE
 *
 * 17    1/22/98 2:54p Royf
 *
 * 16    10/28/97 10:47a Royf
 * Changed DL_BASEADDR_MASK to 3 bits
 *
 * 15    7/21/97 1:46p Royf
 * Added bus and device address flags for DevFlags property in LDD.
 *
 * 14    6/30/97 11:23a Royf
 * Added counter/timer flag to support group tasks.
 *
 * 13    12/27/96 1:27p Royf
 * Added CT_BUFFERS flag.
 *
 * 12    11/14/96 11:08a Royf
 * Added Di_ChanList.
 *
 * 11    10/09/96 10:30a Royf
 * Added conditional defines and macros around DigitalChanAddr definitions
 * to support 16/32 bit compilation.
 *
 * 10    9/25/96 10:58a Royf
 * Added definitions for new digital channel addressing scheme.
 *
 * 9     9/16/96 5:04p Royf
 * Changed ULONG to DWORD.
 *
 * 8     9/12/96 12:06p Royf
 * 1. Updated interface version
 * 2. Added new DigitalConfiguration enum.
 * 3. Added new TaskStatus enums.
 * 4. Added new field to Timer_Status.
 * 5. Defined Group Event.
 *
 * 7     8/20/96 4:23p Royf
 * Fixed error in definition of OUTPUT... control values for rate
 * generator.
 *
 * 6     8/12/96 3:28p Royf
 * Added new enumerations for GENERATORS, CLOCKS, and GATESTATUS.
 * Added new modifiers for counter/timer output control.
 * Defined new "event" event for Win32.
 *
 * 2     7/13/95 4:16p Royf
 * Change Lock/UnlockPtr, HNDasPTR macros to expand as null if Win32.
 *
 * 1     5/24/95 4:19p Royf
 * DriverLINX API and main entry points
 *
 * 1     5/24/95 1:32p Royf
 * DriverLINX API and main entry points

      Rev 1.24   22 Nov 1994 15:39:22   ROYF
   Added GBUF_NOCOMPACT and GBUF_NOVXDALLOC flags.
   Added definitions to sub-divide Rate_Event.pulses field to handle special
   feature of some hardware: Global repeat count for each channel sampled.

      Rev 1.23   19 Nov 1993 16:01:46   RFURMAN
   Defined Di_ProcessStart for internal use by DriverLINX.

      Rev 1.22   05 Nov 1993 10:01:00   RFURMAN
   DriverLINX is now source code compatible with Win 3.x, Watcom C/C++ 32-bit,
   Win32s and Win NT.
   Added new functions, OpenDriverLINX, CloseDriverLINX, and SelectDriverLINX.
   Replaced OEMextensions in Service Request with hDLL.

      Rev 1.21   16 Jul 1993 11:30:46   RFURMAN
   Added new rate generator: a split clock, SPLITCLK.


      Rev 1.20   04 May 1993 11:59:32   RFURMAN
   Remove redundant type-specifier, PASCAL, on GetEvent.
   Changed definition of AUDITONLY flag for MSVC compatibility.
   Added structure packing pragmas for popular compilers.


      Rev 1.19   11 Mar 1993 11:38:30   RFURMAN
   Added structures and functions for getting additional DriverLINX event data
   from handles posted by some DriverLINX messages.
   Added "nonstop" delay value to allow continuous reporting of stop events.


      Rev 1.18   15 Dec 1992 12:09:22   Furman
   Added PULSEWD (pulse width) option to GENERATORS.


      Rev 1.17   06 Sep 1992 20:28:44   Furman
   Converted macros to inline functions if compiled as C++.
   Added user break message.


      Rev 1.16   30 Jul 1992 20:50:10   Furman
   Minor changes to reduce warnings when compiling with C++
   Changed lostData field in IO_STATUS to bufCount.
   Added COUNTEVENT as new (stop) EventType (acquires requested # of samples).
   Added notification flags for sending start and stop event messages.
   Added start (DL_STARTEVENT) and stop (DL_STOPEVENT) event messages.
   Added new AnFlag An_ScatterGather for scatter/gather support.


      Rev 1.15   14 Jul 1992 17:12:00   Furman
   Added new support function DLMinPeriod.


      Rev 1.14   28 Jun 1992 18:07:40   Furman
   Defined 2 new analog trigger types for edge-crossings of dual thresholds.


      Rev 1.13   21 Jun 1992 20:49:20   Furman
   Added CONVERT operation and DATA_CONVERT and TIMEBASE types.
   Slightly modified definition of notify field in DL_BUFFERLIST structure.


      Rev 1.12   17 May 1992 16:43:24   Furman
   Added new external CLOCKS:
     EXTERNALPE (positive edge), EXTERNALNE (negative edge).


      Rev 1.11   09 Apr 1992 15:53:48   Furman
   Added NO_SERVICESTART and NO_SERVICEDONE task flags

      Rev 1.10   03 Apr 1992 13:05:32   Furman
   Added DI_EXTCLK channel and ExtClkChn enum to DigitalTypes.


      Rev 1.9   27 Mar 1992 14:29:18   Furman
   Added DIOSETUP event type and defined standardized digital I/O modes.


      Rev 1.8   08 Mar 1992 14:31:08   Furman
   Adopted Microsoft floating point function return convention for Borland C++.
   Added declarations to allow compilation with C++.
   Added DLLAPI definition and changed function prototypes to use it.


      Rev 1.7   01 Mar 1992 22:08:24   Furman
   Added DL_LDDCHANGED message
   Added prototypes for new utility functions
   Added An_DirectIRQ definition for AnFlags


      Rev 1.6   02 Oct 1991 11:34:32   Furman
   Added ExtTrgChn enum to DigitalTypes.

      Rev 1.5   17 Sep 1991 10:26:36   Furman
   Modified typecasting on LockPtr to pass stricter syntax checking.
   Added "#define DI_EXTTRG", a dedicated hdw ext trig pseudo-channel.
   Replaced all byte fields (BYTE & char) with short integer (SINT).
   Added new operation code, TEST.
   Removed operation modifiers from Ops enum and widened to 16-bit flags.
   Defined DL_DEF_NBUF as default # of buffers in DL_BUFFLIST.


      Rev 1.4   17 Jul 1991 16:04:20

      Rev 1.3   05 May 1991 19:04:08

      Rev 1.2   10 Mar 1991 21:11:20

      Rev 1.1   13 Jan 1991 21:58:42

      Rev 1.0   05 Jan 1991 13:33:20
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
 * SYNOPSIS:    DriverLINX Interface Data Structures and Prototypes for C/C++
 *
 * DESCRIPTION: Typical data acquistion drivers perform services by responding
 * to a sequence of function calls that setup the various parts of the hardware
 * necessary to complete a data acquisition service.  DriverLINX, however,
 * takes a declarative approach to data acqusition tasks.  Each data
 * acquisition task is completely specified by the contents of a data
 * structure which is passed to the DriverLINX DLL.  This data-driven
 * approach is in the spirit of the modern programming paradigms, such as
 * object-oriented programming, but only conventional procedural languages are
 * need to use DriverLINX.
 *
 *   All data acquisition tasks are initiated by passing to DriverLINX a
 * structure: a Service Request with an optional buffer list.  All Service
 * Requests must identify the requesting window, the Logical Device to
 * execute the service, the device Subsystem needed, the subsystem operation
 * Mode, and the requested Operation.   Most requests also require
 * specification of Timing, Start, and Stop events as well as the locations
 * of I/O buffers.  The outcome of the Service Request is returned in the
 * Result field and, for some operations, in the Status field.
 *
 *   The OEM data acquisition products installed in a PC are identified as
 * one or more Logical Devices through a configuration procedure.  Each
 * Logical Device is divided into 6 subsystems: the entire device, analog input,
 * analog output, digital input, digital output, and timer/counters.  Each
 * subsystem can be operated in one or more modes.  The analog and digital I/O
 * sections can operate in polled, DMA, or hardware interrupt modes, while the
 * timer/counter sections operate in frequency measurement, event counting,
 * time interval measurement, pulse and one-shot output modes, and periodic
 * message sending.
 *
 *  Each Service Request becomes either a foreground or background task managed
 * by DriverLINX.  If sufficient data acquisition and PC hardware resources
 * are available, DriverLINX can manage multiple, concurrent background
 * and foreground tasks.
 *
 *   Each subsystem responds to a consistent set of commands.  Commands are
 * available to start, stop, schedule, and report the status of a task.
 * Subsystems can also be initialized to a default state, or requested for
 * exclusive access by a window, if they are not servicing a task.  As a
 * convenience, DriverLINX also provides interactive dialog boxes that
 * allow the user to edit a service request or to respond to a message box
 * reporting the result code of a task.  The DEVICE subsystem responds to
 * commands to allow interactive configuration, to force the hardware to
 * a default state, or to return the device capabilities information.
 *
 *   Analog and digital I/O requests require specification of starting and
 * stopping events as well as a timing event.  By selection of the appropriate
 * starting and stopping events, the application can implement a wide variety
 * of data acquistion configurations.  Examples include
 *   1) Start on trigger after delay, stop on command (circular buffering)
 *   2) Start on trigger after delay, stop on terminal count (linear buffering)
 *   3) Start on command, stop on terminal count (linear buffering)
 *   4) Start on command, stop on trigger after delay (circular buffering)
 *   5) Start on command, stop on command (circular buffering)
 * Trigger events include analog thresholds, digital input patterns, time of
 * day or delay, memory flags, and internal or external interrupts.  The
 * availability of triggers is dependent on hardware capabilities and driver
 * software.  If I/O reaches the end of a buffer(s) without encountering a
 * trigger condition, the next sample is wrapped around to the start of the
 * buffer list (circular buffering).
 *
 ****************************************************************************/
/*@end@*/

  /* This header file requires prior inclusion of <windows.h> */

#if !defined(DRVLINX_H) || defined(DL_REDECLARE)
#ifndef DL_REDECLARE
  #define DRVLINX_H
  #define DriverLINX_INTERFACE  0x0200 /* Version of interface specification */
#endif

#ifdef DRVLINX_G
  #define vextern
#else
  #define vextern extern
#endif

  /* Test for 32-bit environment.  If you are compiling for 32-bit Windows
     (NT or Win32s), make sure your compiler or files define one of the
     following values.  If your compiler defines another value, add it to
     the conditional statement below.
  */
#if !defined(ISWIN32) && !defined(DL_REDECLARE)
  #if defined(WIN32) || defined(__WIN32__) || defined(_WIN32) || \
      defined(__NT__)
    #define ISWIN32
  #endif
#endif

  /* Force enums to have consistent size independent of compiler defaults */
#if !defined(ISWIN32) || (defined(__WATCOMC__) && defined(__WINDOWS_386__))
  #define DLMAXENUM 0x7FFF
#else
  #define DLMAXENUM 0x7FFFFFFF
#endif
#define DLWORDSIZE  16
#define DLDWORDSIZE 32

  /* The following macros normally evaluate to just their argument, str.
     The DL_REDECLARE option and "dlintrnl.h" file is reserved for internal
     use by DriverLINX.  Your version of DriverLINX doesn't include this
     header file.
  */
#ifndef DL_REDECLARE
  #define E(str)   str
  #define H(str)   str
  #define S(str)   str
  #define Bool     BOOL
  #ifdef ISWIN32
    #define ISWIN32FIELD
  #endif
#else
  #include "dlintrnl.h"
#endif
#if defined(__WATCOMC__) && defined(__WINDOWS_386__)
  #define P(str) DWORD
#else
  #define P(str) str
#endif

#if !defined(ISWIN32) && (WINVER==0x0300) /* for Win 3.0 compatibility */
  #define HGLOBAL HANDLE
#endif

  /* 16/32-bit compatibility definitions */

#if !defined(SELECTOROF) || defined(ISWIN32)
  #ifndef ISWIN32
    #define SELECTOROF(ptr) FP_SEG(ptr)
  #else
    #undef  SELECTOROF
    #define SELECTOROF(ptr) HIWORD(ptr)
  #endif
#endif

#if !defined(OFFSETOF) || defined(ISWIN32)
  #ifndef ISWIN32
    #define OFFSETOF(ptr) FP_OFF(ptr)
  #else
    #undef  OFFSETOF
    #define OFFSETOF(ptr) LOWORD(ptr)
  #endif
#endif

#ifndef DLLAPI
  #define DLLAPI FAR PASCAL
#endif

  /* Set compiler options for consistency with DriverLINX DLL */

#ifdef _MSC_VER
  #pragma pack(1)                      /* byte align structures */
#endif

#ifdef __BORLANDC__
  #pragma option -a-                   /* byte align structures */
  #pragma option -b                    /* enums are words */
#endif

#ifdef __WATCOMC__
  #pragma pack(1)                      /* byte align structures */
  #if defined(__WINDOWS_386__) && defined(__SW_EI)
    #error Can not compile this header with -ei switch
  #endif
#endif

#ifdef __ZTC__
  #pragma ZTC align 1                  /* byte align structures */
#endif

  /* DriverLINX Data Types */
typedef short int SINT;

#ifndef FAR_16
  #if defined(__WATCOMC__) && defined(__WINDOWS_386__)
    #define FAR_16
  #else
    #define FAR_16 FAR
  #endif
#endif

  /* Device Subsystems, Modes, and Operations */

#ifndef DL_REDECLARE
  typedef enum { DEVICE, AI, AO, DI, DO, CT,
                 INTXXX0 = DLMAXENUM } SubSystems;
  #define nSubSystems (CT+1)
#endif

#ifndef DL_REDECLARE
  typedef enum { OTHER, POLLED, DMA, INTERRUPT,
                 INTXXX1 = DLMAXENUM } Modes;
  #define nModes (INTERRUPT+1)
#endif

#ifndef DL_REDECLARE
  typedef enum { START, STOP, SCHEDULE, STATUS,
                 INITIALIZE, CONFIGURE, CALIBRATE, CAPABILITIES,
                 REQUEST, RELEASE, MESSAGEBOX, TEST, CONVERT,
    /* Operation modifiers.  Logical "or" modifier with operation */
                 EDIT = 0x2000, NOAUDIT = 0x4000,
                 AUDITONLY = -32768, /* 0x8000 */
                 INTXXX1A = DLMAXENUM } Ops;
  #define nOps (CONVERT+1)
#endif

  /* MS VC++ && Borland C++ 3.1 doesn't support this idiom: */
#if defined(__cplusplus) && defined(__WATCOMC__)
  /* These operators extend a common C idiom to C++ */
  inline Ops& operator|=(Ops& lhs, const Ops rhs)
  {
    lhs = (Ops)((int)lhs | (int)rhs);
    return lhs;
  }
  inline Ops operator|(const Ops a, const Ops b)
  {
    return (Ops)((int)a | (int)b);
  }
#endif

#ifndef DL_REDECLARE
  /* Definitions for DeviceCapabilities DevFlags property */

  /* Hardware bus interface definitions */
  #define DL_BUS_SHIFT           0x0
  #define DL_BUS_MASK            (0x7 << DL_BUS_SHIFT)

  #define DL_ISA_BUS             (0x0 << DL_BUS_SHIFT)
  #define DL_EISA_BUS            (0x1 << DL_BUS_SHIFT)
  #define DL_MICROCHANNEL_BUS    (0x2 << DL_BUS_SHIFT)
  #define DL_PCI_BUS             (0x3 << DL_BUS_SHIFT)
  #define DL_PCMCIA_BUS          (0x4 << DL_BUS_SHIFT)
  #define DL_ISA_PNP_BUS         (0x5 << DL_BUS_SHIFT)
  #define DL_SCSI_BUS            (0x6 << DL_BUS_SHIFT)

  /* BaseAddr property type */
  #define DL_BASEADDR_SHIFT      0x3
  #define DL_BASEADDR_MASK       (0x7 << DL_BASEADDR_SHIFT)

  #define DL_BASEADDR_IO         (0x0 << DL_BASEADDR_SHIFT)
  #define DL_BASEADDR_MEMORY     (0x1 << DL_BASEADDR_SHIFT)
  #define DL_BASEADDR_ID         (0x2 << DL_BASEADDR_SHIFT)

  /* Dynamic flags for internal use only */
  #define DL_WDM_FLAG             0x80000000
  #define DL_INTERNAL_FLAGS       DL_WDM_FLAG
#endif



  /*           L O G I C A L  D E V I C E  D E S C R I P T O R              */

  /* The characteristics and capabilities of a data acquisition device are
     described by the Logical Device Descriptor (LDD).  A client of the driver
     may request a copy of this data structure by invoking the CAPABILITIES
     Service Request.  The handle to the LDD is returned in the status field
     of the Service Request.  As the LDD consists of a collection of data
     structures, DriverLINX exports support functions to lock, unlock, and
     free the LDD and its component structures.
  */

typedef struct S(_DeviceCapabilities) {
  WORD          VendorCode;                  /* OEM for device */
  WORD          ModelCode;                   /* model code for device */
  /* Device physical address */
  union {
    struct {
      WORD      addr;
      WORD      zero;                        /* if I/O mapped */
    } IO;
    LPVOID      MemAddr;                     /* if memory mapped */
    LPCSTR      BoardId;                     /* if unique id */
  } BaseAddr;
  WORD          NumAddr;                     /* size of address space */
  SINT          FeatureBitMap;               /* bit map of subsystems */
  SINT          BusWidth;                    /* 8/16 bit transfers */
  DWORD         DevOpMap[nModes];            /* allowed device operations */
  DWORD         DevFlags;                    /* bus/addr info, etc. */
  Bool          OEMextensionUsed;            /* TRUE if OEM extension used */
  Bool          DeviceInit;                  /* device detected & initialized */
} S(DL_DeviceCapabilities);

#ifndef DL_REDECLARE
  typedef enum { TrueBinary, TwosComplement, SignedBinary,
                 INTXXX2 = DLMAXENUM } DataCoding;
  typedef enum { tNATIVE, tBYTE, tINTEGER, tLONG, tSINGLE, tDOUBLE,
                 INTXXX3 = DLMAXENUM } NumberTypes;
  #define nNumberTypes (tDOUBLE+1)
#endif


  /* Analog Gain/Multiplier Conversion Table (pointed to by LDD) */

typedef struct S(GainMultPairs) {
  SINT        GainCode;                      /* code number */
  float       Multiplier;                    /* gain factor */
  float       min, max;                      /* lo/hi analog voltages */
} S(GainMultPairs);

typedef struct S(AnGainMultiplierTable) {
  WORD           Nentries;
  GainMultPairs  ArrayList[4];               /* Actual # of elements may vary */
} S(AnGainMultiplierTable);

typedef S(AnGainMultiplierTable) FAR_16 *S(lpAnGainMultiplierTable);


  /* Analog Min/Max Range Table (pointed to by LDD) */

typedef struct S(AnMinMaxPairs) {
  float min, max;                            /* lo/hi analog voltages */
  LONG  minCode, maxCode;                    /* lo/hi analog values */
} S(AnMinMaxPairs);

typedef S(AnMinMaxPairs) FAR_16 *S(lpAnMinMaxTable);

typedef struct S(EventMaps) {                /* Bitmaps of allowed events */
  WORD          TimingEvents[nModes];
  WORD          StartEvents[nModes];
  WORD          StopEvents[nModes];
} S(EventMaps);

#ifndef DL_REDECLARE
  /* Definitions for AnFlags */
  #define An_AllowPCClk     1                /* Allow PC system clocking */
  #define An_AllowRTC       2                /* Allow AT RTC clocking */
  #define An_SimultaneousIO 4                /* Simultaneous I/O ability */
  #define An_Buffered       8                /* Device buffers data */
  #define An_ChanGainSame   16               /* TRUE = gains must be equal */
  #define An_RangesVary     32               /* TRUE = each chan range may
                                                                       vary */
  #define An_ScatterGather  64               /* TRUE = scatter/gather support */
  #define An_CustomGains    128              /* TRUE = gain table has only
                                                       basic gains */
  #define An_Uses32BitXfer  256              /* TRUE = hdw transfers data
                                                       using 32-bit DWORDs */
  #define An_ProgSeDiff     512              /* TRUE = supports programmable
                                                       inputs */
  #define An_ProgCoupling  1024              /* TRUE = supports programmable
                                                       input coupling */
  #define An_AnaChan       2048              /* TRUE = supports separate
                                                       analog trigger chan */
  #define An_DirectIRQ      0x80000000       /* TRUE = clk directly tied to
                                                                          IRQ */
#endif

typedef struct S(AnalogChannels) {
  /* Capabilities of analog subsystem */
  E(DataCoding)            AnCode;           /* value encoding technique */
  WORD                     NAnChan;          /* # of analog channels */
  WORD                     NAnConverters;    /* # of converters on device */
  SINT                     AnBits;           /* analog resolution in bits */
  SINT                     AnBytes;          /* size of value in bytes */
  DWORD                    Anmask;           /* mask to extract value */
  WORD                     AnChanGainMaxEntries; /* 0 = no chan/gain list */
  S(lpAnGainMultiplierTable) lpAnGainMult;   /* CAPABILITIES returns handle */
  S(lpAnMinMaxTable)       lpAnMinMaxRange;  /* CAPABILITIES returns handle */
  S(EventMaps)             AnEvents;         /* Bitmaps of allowed events */
  DWORD                    AnOpMap[nModes];  /* Bitmaps of allowed operations */
  DWORD                    AnEventCombo[nModes];/* Bitmap of allowed combos */
  DWORD                    AnSoftZero;       /* Bitmap of software auto 0 */
  DWORD                    AnHardZero;       /* Bitmap of hardware auto 0 */
  E(NumberTypes)           AnNumTypeBitMap[nModes]; /* Bitmap of number types */
  DWORD                    AnFlags;          /* Boolean flags */
  SINT                     AnMaxBuffers;     /* Max # of buffers (1..255) */
  SINT                     AnDefaultTimingChan; /* default timing channel;
                                                   -1   = PC system timer,
                                                   -2   = AT RTC,
                                                   -127 = any device timer,
                                                   -128 = any timer */
  Bool                     Aninit;           /* hardware init flag */

  /* A/D DMA and interrupt resources */
  SINT                     An_DMAChanBuf[2]; /* DMA channels to use */
  SINT                     An_IntChan;       /* Interrupt channel to use */
} S(AnalogChannels);

  /* Event combination maps define allowed buffering techniques and
     timing, start, stop events.  Buffering may be single or multiple and
     non-circular versus circular.  Events are classified as either
     internal or external (see EventTypes enumeration).  It is possible
     that individual drivers may further restrict combinations even though
     the event combination is allowed.
     The bit for a particular combination is found by treating the above
     properties as specifing a binary number with the following place values:

     Property     0             1         scale factor
     Buffering    single        multiple  16
                  non-circular  circular   8
     Timing       internal      external   4
     Starting     internal      external   2
     Stoping      internal      external   1
  */

#ifndef DL_REDECLARE
  /* Types for digital channels
       custom    = OEM-specific implementation
       Intel8255 = Intel 8255 Programmable Peripheral Interface
       ExtTrgChn = OEM-defined external trigger channel
       ExtClkChn = OEM-defined external clock channel
  */
  typedef enum { custom, Intel8255, ExtTrgChn, ExtClkChn,
                 INTXXX4 = DLMAXENUM } DigitalTypes;

    /* Configuration capabilites for digital channel */
  typedef enum { dcFixed=0, dcBit=1, dcNibble=2, dcByte=4, dcWord=8, dcDWord=16,
                 dcSwitch=64,
                 INTXXX5 = DLMAXENUM } DigitalConfig;
#endif

  /* Digital Channel Capabilities Table */

typedef struct S(DigitalCapabilities) {
  SINT                     DiBytes;          /* size of value in bytes */
  DWORD                    DiMask;           /* mask to extract value */
  E(DigitalTypes)          DiType;           /* type of channel */
  E(DigitalConfig)         DiConfig;         /* configuration capabilities */
} S(DIOCapabilities);

typedef S(DIOCapabilities) FAR_16 *S(lpDIOCapabilities);

#ifndef DL_REDECLARE
  /* Definitions for DiFlags */
  #define Di_AllowPCClk     1                /* Allow PC system clocking */
  #define Di_AllowRTC       2                /* Allow AT RTC clocking */
  #define Di_SimultaneousIO 4                /* Simultaneous I/O ability */
  #define Di_Buffered       8                /* Device buffers data */
  #define Di_ChanList      16                /* Device allows channel list */
  #define Di_ProcessStart 0x80000000         /* Reserved for internal use */
#endif

typedef struct S(DigitalChannels) {
  /* Capabilities of digital subsystem */
  SINT                     NDiChan;          /* # of digital channels */
  S(lpDIOCapabilities)     lpDiCapabilities; /* capabilities for each channel */
  S(EventMaps)             DiEvents;         /* Bitmaps of allowed events */
  DWORD                    DiOpMap[nModes];  /* Bitmaps of allowed operations */
  DWORD                    DiEventCombo[nModes];/* Bitmap of allowed combos */
  DWORD                    DiFlags;          /* Boolean flags */
  SINT                     DiMaxBuffers;     /* Max # of buffers (1..255) */
  SINT                     DiDefaultTimingChan; /* default timing channel */
  Bool                     Diinit;           /* hardware init flag */

  /* Digital DMA and interrupt resources */
  SINT                     Di_DMAChanBuf[2]; /* DMA channels to use */
  SINT                     Di_IntChan;       /* Interrupt channel to use */
} S(DigitalChannels);


#ifndef DL_REDECLARE
    /* Definitions for TimerType in struct CTCapabilities */
  typedef enum { Other, Intel8254, Am9513, MC146818,
                 INTXXX6 = DLMAXENUM } TimerTypes;
#endif

  /* Counter/Timer capabilities table (pointed to by LDD) */

typedef struct S(CTCapabilities) {
  DWORD minTics;                       /* minimum # of tics */
  DWORD modes;                         /* bitmap of supported generator modes */
  DWORD clocks;                        /* bitmap of supported clocks */
  DWORD gates;                         /* bitmap of supported gates */
  E(TimerTypes) CTTimerType;           /* see above definitions */
  float microseconds;                  /* tic period */
} S(CTCapabilities);

typedef S(CTCapabilities) FAR_16 *S(lpCapabilitiesTable);

#ifndef DL_REDECLARE
  /* Definitions for CTFlags */
  #define CT_PULSETRAINS  1                  /* Allow finite pulse trains */
  #define CT_BUFFERS      2                  /* Allow buffered input */
  #define CT_GROUP        4                  /* Supports group operations */
#endif

typedef struct S(CounterTimerChannels) {
  /* Capabilities of counter/timer subsystem */
  SINT                     NCTChan;          /* # of counter/timer channels */
  S(lpCapabilitiesTable)   lpCTCapabilities; /* CAPABILITIES returns handle */
  S(EventMaps)             CTEvents;         /* Bitmaps of allowed events */
  DWORD                    CTOpMap[nModes];  /* Bitmaps of allowed operations */
  DWORD                    CTFlags;          /* Boolean flags */
  SINT                     CTDefaultTimingChan; /* default timing channel */
  SINT                     CT_IntChan;       /* Interrupt channel to use */
  Bool                     CTinit;           /* hardware init flag */
} S(CounterTimerChannels);


  /* Logical Device Descriptor Data Structure -- Read-only */

typedef struct S(LDD) {
  /* Device number and driver/interface version numbers */
  WORD                     DeviceNumber;     /* # of this device (0-based) */
  WORD                     MaxDevices;       /* max # of devices in driver */
  WORD                     DriverVersion;    /* driver version/revision */
  WORD                     InterfaceVersion; /* interface version/revision */

  /* Capabilities of device */
  S(DL_DeviceCapabilities) DevCap;

  /* Capabilities of analog I/O subsystem */
  S(AnalogChannels)        AnaChan[2];       /* 0 = output, 1 = input */

  /* Capabilities of digital I/O subsystem */
  S(DigitalChannels)       DigChan[2];       /* 0 = output, 1 = input */

  /* Capabilities of counter/timer subsystem */
  S(CounterTimerChannels)  CTChan;

  /* Optional private data for use by DriverLINX */
  H(HANDLE)                hData;
} S(LDD);

typedef S(LDD) FAR_16 *S(LPLDD);


  /*             M U L T I T A S K I N G  S U P P O R T                     */

  /* Critical sections can be declared for tasks that must be protected
     from interference by the occurence of other events in the system.
     The taskFlags field of the Service Request allows masking of some or
     all classes of interfering events.  This service should be used carefully
     as it can lead to system failure or a deadlock condition requiring
     a reboot of the operating system.  Only one critical section may be
     entered at a time.
  */

  /* Note: DriverLINX does NOT use or need multitasking flags for
     32-bit applications.
  */

#ifndef DL_REDECLARE
  #define CS_NONE               0x0000 /* no critical section */
  #define CS_BLOCK_TIMER        0x0001 /* block timer tics */
  #define CS_BLOCK_KEYBOARD     0x0002 /* block keyboard input */
  #define CS_BLOCK_MOUSE        0x0004 /* block mouse input */
  #define CS_BLOCK_INPUT        0x0006 /* block keyboard and mouse input */
  #define CS_BLOCK_NEWFOCUS     0x0010 /* block change of Window focus */
  #define CS_BLOCK_TIMESLICING  0x0020 /* block pre-emptive multitasking */
  #define CS_BLOCK_ALL          0x3fff /* block all asynchronous events */

  /* These task flags block sending start/done messages to the application.
     Normally there is no advantage to disabling these messages.  However,
     applications that are frequently polling for one or a few samples
     will find substantial speed improvements by blocking these messages.
     N.B. Service Done messages can only be blocked for polled tasks.
   */

  #define NO_SERVICESTART       0x8000 /* no service start messages */
  #define NO_SERVICEDONE        0x4000 /* no service done messages */
  #define NO_INTERACTION        0x2000 /* reserved */
#endif


  /*            S T A T U S / R E A D  S T R U C T U R E S                  */

  /* Status/read operations return results in the status field of the
     DriverLINX Service Request.
  */

#ifndef DL_REDECLARE
  typedef enum { scheduled, armed, active, inactive, done,
                 noPulses = 0,
                 chn1Pulse = 1,
                 chn2Pulse = 2,
                 chn1chn2Pulses = 3,
                 chn2chn1Pulses = 4,
                 INTXXX7 = DLMAXENUM } TaskStatus;
#endif

  /* Timer/Counter status/read is returned by DriverLINX in status field */

typedef struct S(Timer_Status) {
  E(TaskStatus) status;                /* task status */
  DWORD       count;                   /* count value */
  DWORD       countHi;                 /* high-order count value, if used */
} S(TIMER_STATUS);


  /* I/O status/read is returned by DriverLINX in status field */

typedef struct S(IO_Status) {
  E(TaskStatus) status;                /* task status */
  WORD          currentBuffer;         /* active/last buffer */
  DWORD         nextElement;           /* next/last element for I/O */
  LONG          triggerElement;        /* element where stop trigger occurred */
                                       /* < 0 = no trigger occurred */
  WORD          triggerBuffer;         /* buffer where trigger occurred */
  WORD          bufCount;              /* # of buffers processed */
} S(IO_STATUS);

    /* Calibration constants are returned by DriverLINX in this
       structure as a handle to a global data block.  The internal
       structure of this block is implementation-dependent.  An
       application can override the current calibrations by passing
       a new calibration in this structure when performing the
       data CONVERT operation. */

typedef struct S(cal_const) {
  H(HANDLE)   hCalMem;                 /* Handle to a calibration block */
  DWORD       CalSize;                 /* size of block in bytes */
} S(CAL_CONST);

#ifndef DL_REDECLARE
    /* Type of data error for lostData field of IO_STATUS */
  typedef enum { dataLost = 1,            /* I/O data lost */
                 queueOverflow = 2,       /* app message queue overflow */
                 isrOverrun = 4,          /* re-entered busy ISR */
                 INTXXX8 = DLMAXENUM
               } lostDataCodes;
#endif

  /* The status field returns results from i/o status requests, counter/timer
     read requests, capabilities handles, and I/O values.  I/O values are used
     for transfering single values of analog and digital I/O to or from
     DriverLINX when lpBuffers is 0 and typeStatus is IOVALUE.  The contents
     of the status field are not audited by DriverLINX, but the contents of
     the fields may be used by DriverLINX for internal purposes when not being
     returned as an output field.
  */

#ifndef DL_REDECLARE
  typedef enum { IOVALUE, TIMERSTATUS, IOSTATUS, CAPSTATUS, CALCONST,
                 INTXXX9 = DLMAXENUM } StatusType;
  #define nStatusTypes (CALCONST+1)
#endif

typedef struct S(DLStatus) {
  E(StatusType)     typeStatus;        /* status type code */
  union {
    DWORD           ioValue;           /* transfer a single I/O value */
    S(TIMER_STATUS) timerStatus;
    S(IO_STATUS)    ioStatus;
    H(HANDLE)       hCapabilities;     /* global handle of CAPABILITIES */
    S(CAL_CONST)    calibrations;
  } u;
} S(DLSTATUS);


  /*             E V E N T  D A T A  S T R U C T U R E S                    */

  /* An analog input channel can be monitored as a start or stop event.
     Eight types of analog triggers are defined:
       1) signal is above threshold     (signal > threshold)
       2) signal is below threshold     (signal < threshold)
       3) signal is between thresholds  (lo <= signal <= hi)
       4) signal is outside thresholds  (signal < lo or signal > hi)
       5) signal is crossing threshold with positive slope
                                        (last <= hi and signal > hi)
       6) signal is crossing threshold with negative slope
                                        (last >= hi and signal < hi)
       7) signal is crossing both thresholds with positive slope
                                        (last <= lo and signal > lo then
                                         last <= hi and signal > hi)
       8) signal is crossing both thresholds with negative slope
                                        (last >= hi and signal < hi then
                                         last >= lo and signal < lo)

     Setup required:
     Type  Upper      Lower       flags
     ----  ---------  ---------   -------------------------------------
      1    threshold  min         AnaTrgPosOutside
      2    max        threshold   AnaTrgPosOutside
      3    high       low         AnaTrgNegInside
      4    high       low         AnaTrgPosOutside
      5    threshold  threshold   AnaTrgPosOutside
      6    threshold  threshold   AnaTrgNegInside
      7    high       low         AnaTrgPosOutside | AnaTrgDUALCROSSING
      8    high       low         AnaTrgNegInside  | AnaTrgDUALCROSSING
  */

#ifndef DL_REDECLARE
  #define AnaTrgNegInside    0         /* negative slope or inside limits */
  #define AnaTrgPosOutside   1         /* positive slope or outside limits */
  #define AnaTrgDUALCROSSING 2         /* dual threshold crossing flag */
  #define AnaTrgACCOUPLING   4         /* AC trigger coupling */

  #define OutsideOrPosSlope flags      /* for compatibility with old name */
  #define AnaDefTrgChn      ((SINT)-1) /* default analog trigger channel */
#endif

typedef struct S(AI_Event) {
  SINT        channel;                 /* analog trigger channel */
  SINT        gain;                    /* gain for channel */
  SINT        upperThreshold;          /* high threshold */
  SINT        lowerThreshold;          /* low threshold */
  WORD        flags;                   /* trigger-type flags */
} S(AI_EVENT);


  /* A digital input channel can be monitored as a start, stop, or timing event.
     The digital event is computed as
       (channel & mask) <op> pattern,
     where <op> is "==" (match = TRUE) or "!=" (match = FALSE).
     A digital event can only be used as a timing event in polled mode unless
     the event specifies a match on a hardware supported external clock
     input via a digital channel or the hardware supports an interrupt on
     digital input.  In all modes, a digital start event is monitored by
     polling if the hardware does not support an interrupt on digital input.
     Digital stop events are not supported for DMA unless the hardware
     interrupts on digital input.  Delay after a digital stop event in DMA
     modes is not supported if the data acquisition board does not implement
     a sample counter.
  */

  /* Special digital event channel ids */
#ifndef DL_REDECLARE
  #define DI_EXTTRG  -1                /* Specifies a dedicated hdw ext trig
                                          line if any.  Match, mask, &
                                          pattern may be ignored. */
  #define DI_EXTCLK  -2                /* Specifies a dedicated hdw ext clock
                                          line if any.  Match, mask, &
                                          pattern may be ignored. */
#endif

typedef struct S(DI_Event) {
  SINT        channel;                 /* digital trigger channel */
  SINT        match;                   /* TRUE = "==", FALSE = "!=" */
  WORD        mask;                    /* bit mask for channel */
  WORD        pattern;                 /* match pattern */
} S(DI_EVENT);


/* Digital channel addressing layout:
   If hardware/driver supported, allows addressing at following levels:
   bit, half-nibble, nibble, word, dword, qword */
typedef struct S(tagDigitalChanAddr16) {
  unsigned int channel : 12;           /* channel address */
  unsigned int size    :  3;           /* IOSIZECODES */
  unsigned int unused  :  1;           /* not used */
} S(DigitalChanAddr16);

#ifndef DL_REDECLARE
/* Constants useful for (un)packing DigitalChanAddr16 fields */
#define IOCHANMASK  0xFFF
#define IOSIZESHIFT 12
#define IOSIZEMASK  (7 << IOSIZESHIFT)

typedef enum { IOSIZENATURAL,
               IOSIZE1,  IOSIZE2,  IOSIZE4, IOSIZE8,
               IOSIZE16, IOSIZE32, IOSIZE64,
               IOSIZEXXX0 = DLMAXENUM
             } IOSIZECODES;
#endif // DL_REDECLARE

  /* A time channel can be monitored as a start, stop, or timing event.
     Tics specifies the time as either a time interval to wait or as the
     scheduled time of day for the event.  The reference point for time of day
     is implementation dependent.
  */

#ifndef DL_REDECLARE
  /* Special timer channel ids */
  #define PCSYSTEMTIMER 0xff           /* PC 8254 system timer */
  #define ATRTC         0xfe           /* AT CMOS MC146818 real time clock */
  #define DEFAULTTIMER  0xfd           /* default timer channel for subsystem */
#endif

typedef struct S(Time_Event) {
  SINT        channel;                 /* time channel */
  DWORD       tics;                    /* time in clock tics */
  Bool        timeOfDay;               /* TRUE = time of day, FALSE = delay */
} S(TIME_EVENT);


  /* A rate (counter/timer) channel can be monitored as a timing event or used
     to setup a counter/timer measurement or pulse output service request.
     A rate event may implement one of several types of rate generators: square
     wave, burst, variable duty cycle.  It may also implement a frequency
     divider or a frequency or time interval measurement and event counter.
     A split clock generates "n" tics at rate "t1" and then switches to
     rate "t2" for the remainder of the Service Request.

     Generator            Period  onCount  pulses
     rate & square wave   value   -------  cycles
     variable duty cycle  value   value    cycles
     burst                major   minor    /burst

     Divider              divisor -------  ------
     Frequency            -----   gate     ------
     Interval             chan 2
     Count                -----   -------  ------
     Pulse width          -----   -------  ------
     Split clock          t1      t2       n
     freq shift keying    value   value    ------
     one-shot             delay   -------  0 or 1
     pulse                delay   width    ------
  */

#ifndef DL_REDECLARE
  typedef enum { RATEGEN, SQWAVE, VDCGEN, BURSTGEN,
                 DIVIDER, FREQ, INTERVAL, COUNT, PULSEWD, SPLITCLK,
                 FSKGEN,
                 ONESHOT,
                 RETRIGONESHOT,
                 PULSEGEN,
                 RETRIGPULSEGEN,
                 FREQRATIO,
                 FREQ32,
                 COUNT32,
                 COUNT64,
                 RETRIGCOUNT,
                 RETRIGRATEGEN,
                 RETRIGSQWAVE,
                 INTXXX10 = DLMAXENUM } GENERATORS;

  /* Modifiers for CLOCKS */
  typedef enum { INTERNAL1,              /* master clock */
                 /* Hardware dependent prescaled clocks */
                 INTERNAL2, INTERNAL3, INTERNAL4, INTERNAL5,
                 /* Hardware dependent, software selectable clock inputs */
                 GATE1, GATE2, GATE3, GATE4, GATE5,
                 SOURCE1, SOURCE2, SOURCE3, SOURCE4, SOURCE5,
                 /* Default external clock input */
                 EXTERNAL, EXTERNALPE, EXTERNALNE,
                 /* Terminal count on previous counter */
                 TCNm1,
                 /* Falling edge clocks */
                 mINTERNAL1,
                 mINTERNAL2, mINTERNAL3, mINTERNAL4, mINTERNAL5,
                 mGATE1, mGATE2, mGATE3, mGATE4, mGATE5,
                 mSOURCE1, mSOURCE2, mSOURCE3, mSOURCE4, mSOURCE5,
                 mTCNm1,
                 INTXXX11 = DLMAXENUM } CLOCKS;

  /* Modifiers for GATESTATUS */
  typedef enum { ENABLED, DISABLED, NOCONNECT,
                 LOLEVELGATEN,
                 LOEDGEGATEN,
                 HILEVELGATEN,
                 HILEVELGATENp1,
                 HILEVELGATENm1,
                 HITCNm1,
                 HIEDGEGATEN,
                 INTXXX12 = DLMAXENUM } GATESTATUS;

  /* Output control modifiers for pulses field in RATE_EVENT structure */
  #define OUTPUTMODIFIERSHIFT (DLDWORDSIZE - 4)
  #define OUTPUTDEFAULT    (0 << OUTPUTMODIFIERSHIFT)
  #define OUTPUTLOTOGGLED  (1 << OUTPUTMODIFIERSHIFT)
  #define OUTPUTLOACTIVE   (2 << OUTPUTMODIFIERSHIFT)
  #define OUTPUTLOZ        (3 << OUTPUTMODIFIERSHIFT)
  #define OUTPUTTOGGLED    (4 << OUTPUTMODIFIERSHIFT)
  #define OUTPUTHITOGGLED  (5 << OUTPUTMODIFIERSHIFT)
  #define OUTPUTHIACTIVE   (6 << OUTPUTMODIFIERSHIFT)
  #define OUTPUTHIZ        (7 << OUTPUTMODIFIERSHIFT)
  #define OUTPUTMODIFIERS  (7 << OUTPUTMODIFIERSHIFT)

  /* Rate_Event.pulses fields to support repeated sampling of
     each channel before advancing to next channel.  N.B. Most
     hardware doesn't support this feature.
  */
  #define PULSE_REPEAT_COUNT_FLAG 0x80000000
  #define PULSE_REPEAT_COUNT_MASK 0x7FFF0000
  #define PULSE_COUNT_MASK        0x0000FFFF
  /* if ((pulses & PULSE_REPEAT_COUNT_FLAG) != 0)
       pulses & PULSE_COUNT_MASK = pulses per burst or cycles
       pulses & PULSE_REPEAT_COUNT_MASK = repeat count.
  */
#endif

typedef struct S(Rate_Event) {
  SINT          channel;               /* timer channel */
  E(GENERATORS) mode;                  /* type of rate generator */
  E(CLOCKS)     clock;                 /* clock input for timer/counter */
  E(GATESTATUS) gate;                  /* gate status for timer/counter */
  DWORD         period;                /* rate period in tics */
  DWORD         onCount;               /* on time in tics */
  DWORD         pulses;                /* pulses per burst or cycles */
} S(RATE_EVENT);


  /* A Counter/Timer setup can be used to custom configure a Logical Channel.
  */

  /* SPECIFICATION OF CT_SETUP MAY CHANGE IN FUTURE VERSIONS */

#ifndef DL_REDECLARE
  typedef enum { HILEVEL, LOLEVEL, UPEDGE, DOWNEDGE,
                 INTXXX13 = DLMAXENUM } GATEMODE;
  typedef enum { ACTIVEHI, ACTIVELO, HIZ,
                 INTXXX14 = DLMAXENUM } OUTPUTS;
#endif

typedef struct S(CT_Setup) {
  SINT        channel;                 /* counter/timer channel */
  SINT        mode;                    /* OEM specific */
  E(CLOCKS)   source;                  /* source (clock) input */
  E(GATEMODE) gate;                    /* gate input */
  E(OUTPUTS)  output;                  /* counter output */
  DWORD       count;                   /* counter load value */
} S(CT_SETUP);


  /* SPECIFICATION OF DIO_SETUP MAY BE EXTENDED IN FUTURE VERSIONS */

  /* A Digital I/O setup can be used to custom configure a logical channel.
  */

typedef struct S(DIO_Setup) {
  WORD        channel;                 /* digital channel */
  DWORD       mode;                    /* OEM specific */
} S(DIO_SETUP);

#ifndef DL_REDECLARE
  #define DIO_BASIC          0x00000000  /* simple I/O */
  #define DIO_STROBED        0x10000000  /* I/O with handshaking */
  #define DIO_STROBED_NE     0x10000001  /* I/O with handshaking */
  #define DIO_BIDIRECTIONAL  0x20000000  /* bidirectional I/O */
#endif


  /* A Group event allows certain counter/timer tasks to be started or stopped
     at the same time.
  */

typedef struct S(Group_Event) {
  DWORD       group;                   /* group number */
} S(GROUP_EVENT);



  /* A hardware or software interrupt can be monitored as a start, stop or
     timing event.
     Careless monitoring of hardware events may lead to system failure.
  */

typedef struct S(Interrupt_Event) {
  SINT        IntNum;                  /* interrupt number */
} S(INT_EVENT);


  /* A memory location can be monitored as a start, stop, or timing event.
     Any non-zero value initiates the event.
  */

typedef struct S(Flag_Event) {
  LPDWORD     addr;                    /* memory address of flag */
  WORD        pattern;                 /* bits to match */
  Bool        matchAll;                /* TRUE = all, FALSE = any bits */
} S(FLAG_EVENT);

  /* A data conversion event specifies a transformation between a user
     buffer and a DriverLINX data buffer.  This event may be used to
     convert proprietary AI formats to engineering units or to convert
     engineering units to proprietary AO data formats.
     Conversions of AI data to floating-point data types will automatically
     apply any hardware-specific gains and calibration factors to the data.
     Scaling and offset fields may be used to convert from volts to other
     engineering units.
   */

typedef struct S(data_convert) {
  WORD           wBuffer;              /* buffer # to convert */
  WORD           startIndex;           /* 0-based starting index */
  WORD           nSamples;             /* # of samples to convert */
  LPVOID         lpBuffer;             /* source/destination buffer */
  E(NumberTypes) numberFormat;         /* source/destination format */
  float          scaling;              /* y = scaling * x + offset */
  float          offset;               /* fields valid for floating only */
} S(DATA_CONVERT);

  /* A timebase event returns the relative time when channels in the buffer
     list were sampled.  While most devices have a simple mathematical
     relationship between sample buffer index and time, some devices have
     more complex timing relationships that may subtly depend on internal
     hardware modes.  This event provides a hardware-independent technique
     to calculate the sample timebase for all devices.

     The timebase is returned as a TimebaseRecord with the following fields:
       period  - # of clock tics per cycle
       nCycles - # of cycles returned (usually 1)
       nChan   - # of channels in a cycle
       relTime - relative time in clock tics for each channel in a cycle.
    A cycle is defined as a scan of all channels specified by the Service
    Request's channel/gain list.

    The time in tics of each sample, i, is computed
      t = 0;                           // starting time
      dt = period * nCycles;           // time increment after cycle set
      nChanCycles = nCycles * nChan;   // # of relative times in table
      for (i = 0, j = 0; i < nSamples; ++i) {
        tics[i] = t + relTime[j++];
        if (j >= nChanCycles) {
          j = 0;
          t += dt;
        }
      }
  */

typedef struct S(timebaseRecord) {
  DWORD       period;                  /* # of tics/cycle */
  WORD        nCycles;                 /* # of cycles returned */
  WORD        nChan;                   /* # of channels/cycle */
  DWORD       relTime[1];              /* relative sample time in tics */
} S(TimebaseRecord);

  /* Macro to compute size for a TimebaseRecord of nSamples in bytes */
#ifndef DL_REDECLARE
  #define SizeOfTimebaseRecord(nSamples) (sizeof(TimebaseRecord) + \
                                 ((nSamples) > 1 ? (nSamples) - 1 : 0) * \
                                 sizeof(DWORD))
#endif

typedef S(TimebaseRecord) FAR_16 *S(LPTimebase);

typedef struct S(time_base) {
  WORD        nSamples;                /* max # of relTime entries avail */
  S(LPTimebase)  lpTimebase;           /* timebase results buffer */
} S(TIME_BASE);

  /* Events determine the starting, stopping, and timing mechanisms for data
     acquisition service requests.  A start or stop event may be delayed by
     an integral number of occurences of the timing event.
  */

#ifndef DL_REDECLARE
  typedef enum { /* Internal events */
                 NULLEVENT, COMMAND, INTEVENT, FLAGEVENT, TIMEEVENT, TCEVENT,
                 /* External events */
                 AIEVENT, DIEVENT,
                 /* Timing events (also includes DIEVENT) */
                 RATEEVENT,
                 /* Counter/timer setup */
                 CTSETUP,
                 /* Digital I/O setup */
                 DIOSETUP,
                 /* Data Conversion */
                 DATACONVERT,
                 /* Timebase Vector */
                 TIMEBASE,
                 /* Sample Counting Event */
                 COUNTEVENT,
                 /* Task Group Event */
                 GROUPEVENT,
                 INTXXX15 = DLMAXENUM } EventTypes;

  #define nEventTypes (GROUPEVENT+1)

  #define REPORTSTOPONLY 0xFFFFFFFF      /* special delay code to signal
                                            stop events without stopping */
#endif

typedef struct S(DLEVENT) {
  DWORD             delay;             /* # of timing events to delay */
  E(EventTypes)     typeEvent;         /* event type code */
  union {
    S(AI_EVENT)     aiEvent;
    S(DI_EVENT)     diEvent;
    S(TIME_EVENT)   timeEvent;
    S(RATE_EVENT)   rateEvent;
    S(INT_EVENT)    intEvent;
    S(FLAG_EVENT)   flagEvent;
    S(CT_SETUP)     tcSetup;
    S(DIO_SETUP)    diSetup;
    S(DATA_CONVERT) dataConvert;
    S(TIME_BASE)    timeBase;
    S(GROUP_EVENT)  groupEvent;
  } u;
} S(DLEVENT);


  /*                      O E M  E X T E N S I O N S                        */

  /* OEM extensions provide the mechanism to add additional capabilities
     to a Service Request.  Using this field limits portability of the
     software interface to the data acquisition hardware, but it allows
     future accommodation of OEM specific features that cannot be expressed
     with a standard Service Request.
  */

typedef VOID FAR_16 *S(LPOEM);


  /*           B U F F E R  L I S T  D A T A  S T R U C T U R E             */

  /* The buffer list specifies the memory buffers needed by a data acqusition
     Service Request.  Single or multiple buffering is supported.  Buffering
     may be linear or circular depending on stop event specified in Service
     Request.
  */

#ifndef DL_REDECLARE
  #define DL_DEF_NBUF 2                /* default # buffers in DL_BUFFERLIST */

  #define NOTIFY       0x0001          /* send buffer filled messages */
  #define HANDSHAKE    0x0002          /* require buffer acknowlegement */
  #define NOTIFY_START 0x0004          /* send start event messages */
  #define NOTIFY_STOP  0x0008          /* send stop event messages */
#endif

typedef struct S(DL_BufferList) {
  SINT        nBuffers;                /* number of buffers in list */
  SINT        fileHandle;              /* 0 or disk file handle for buffering */
  WORD        notify;                  /* see above definitions */
  DWORD       bufferSize;              /* buffer size in bytes */
  P(LPVOID)   BufferAddr[DL_DEF_NBUF]; /* addrs of buffers; actual # varies */
} S(DL_BUFFERLIST);

typedef S(DL_BUFFERLIST) FAR_16 *S(LPBUFFLIST);

#ifndef DL_REDECLARE
#ifdef __cplusplus

  /* Function to compute size of Buffer List for nBuf in bytes */
inline DWORD PASCAL DL_BufferListBytes (SINT nBuf)
{
  return (sizeof(DL_BUFFERLIST) + ((nBuf) > 2 ? (nBuf) - 2 : 0) *
                                 sizeof(LPVOID));
}

#else

  /* Macro to compute size of Buffer List for nBuf in bytes */
#define DL_BufferListBytes(nBuf) (sizeof(DL_BUFFERLIST) + \
                                 ((nBuf) > 2 ? (nBuf) - 2 : 0) * \
                                 sizeof(LPVOID))
#endif
#endif /* DL_REDECLARE */


  /*      C H A N N E L / G A I N  L I S T  D A T A  S T R U C T U R E      */

  /* Channel number and analog gain-or-range code.  Analog output and digital
     channels ignore the gain-or-range code. */

typedef struct S(ChanGain) {
  SINT        channel;                 /* analog channel */
  SINT        gainOrRange;             /* gain or range code for channel */
} S(CHANGAIN);

typedef S(CHANGAIN) FAR_16 *S(LPCHANGAIN);

#ifndef DL_REDECLARE
/* Portable constants for specifying additional channel attributes */

/* For boards having unique, product-specific attributes */
#define CHAN_OEM_SHIFT       15
#define CHAN_OEM_MASK       (1 << CHAN_OEM_SHIFT)
#define CHAN_OEM_DEFAULT    (0 << CHAN_OEM_SHIFT) /* use std attribs */
#define CHAN_OEM_FLAG       (1 << CHAN_OEM_SHIFT) /* use OEM attribs */

/* For boards supporting programmable single-ended vs. differential inputs */
#define CHAN_SEDIFF_SHIFT    13
#define CHAN_SEDIFF_MASK    (3 << CHAN_SEDIFF_SHIFT)
#define CHAN_SEDIFF_DEFAULT (0 << CHAN_SEDIFF_SHIFT) /* use static config */
#define CHAN_SEDIFF_DIG     (1 << CHAN_SEDIFF_SHIFT) /* digital input chan */
#define CHAN_SEDIFF_SE      (2 << CHAN_SEDIFF_SHIFT) /* single-ended input */
#define CHAN_SEDIFF_DIFF    (3 << CHAN_SEDIFF_SHIFT) /* differential input */

/* For boards supporting programmable input coupling */
#define CHAN_COUPLING_SHIFT    11
#define CHAN_COUPLING_MASK    (3 << CHAN_COUPLING_SHIFT)
#define CHAN_COUPLING_DEFAULT (0 << CHAN_COUPLING_SHIFT) /* use static config */
#define CHAN_COUPLING_AC      (1 << CHAN_COUPLING_SHIFT) /* AC */
#define CHAN_COUPLING_DC      (2 << CHAN_COUPLING_SHIFT) /* DC */
#define CHAN_COUPLING_GND     (3 << CHAN_COUPLING_SHIFT) /* ground */

#endif // DL_REDECLARE

  /* List of channels to read/write.  Autozeroing feature is hardware and/or
     software-mode dependent.
  */

#ifndef DL_REDECLARE
  #define DISABLE_ZEROREF  ((WORD)(-1))
  #define HARDWARE_ZEROREF ((WORD)(-2))
#endif

typedef struct S(CHANLIST) {
  WORD           nChannels;            /* number of channels in list */
  WORD           zeroRef;              /* auto zero reference channel */
  E(NumberTypes) numberFormat;         /* number format */
  Bool           simultaneousScan;     /* TRUE = simultaneous or scan op */
  S(CHANGAIN)    chanGain[2];          /* start/stop channels */
  S(LPCHANGAIN)  chanGainList;         /* channel/gain list (0 if not used) */
} S(CHANLIST);


  /*       S E R V I C E  R E Q U E S T  D A T A  S T R U C T U R E         */

  /* All data acquisition tasks are initiated by passing to DriverùLINX two
     structures: a Service Request and an optional buffer list.  All Service
     Requests must identify the requesting window, the logical device to
     execute the service, the device subsystem needed, the subsystem operation
     mode, the requested operation, and the critical section flags.   Most
     requests also require specification of timing, start, and stop events.
     The outcome of the Service Request is returned in the result field and,
     for some operations, the status field.  Start operations also return a
     task id field to assist identifing messages sent to the calling
     application.
  */

  /* Masks to isolate flags or op from an operation field */
#ifndef DL_REDECLARE
  #define FLAGS     (AUDITONLY | NOAUDIT | EDIT)
  #define OPS       ~FLAGS
#endif


typedef struct S(DL_ServiceRequest) {
  #ifdef ISWIN32FIELD
  /* Control info for 32-bit DriverLINX */
  DWORD         dwSize;                /* size of Service Request structure */
  #endif
  /* Request Group */
  H(HWND)       hWnd;                  /* window handle requesting service */
  WORD          device;                /* logical device to use */
  E(SubSystems) subsystem;             /* requested subsystem */
  E(Modes)      mode;                  /* subsystem operation mode */
  E(Ops)        operation;             /* requested operation */
  /* Results Group */
  WORD          result;                /* output: result code for operation */
  WORD          taskId;                /* output: task id for operation */
  S(DLSTATUS)   status;                /* status/read output for request */
  /* Events Group */
  S(DLEVENT)    timing;                /* timing event */
  S(DLEVENT)    start;                 /* starting event for request */
  S(DLEVENT)    stop;                  /* stopping event for request */
  /* Select Group */
  WORD          taskFlags;             /* critical section flags */
  #ifndef ISWIN32FIELD                 /* Replaces old OEMextension field */
  WORD          reserved;              /* reserved for DriverLINX */
  #endif
  H(HINSTANCE)  hDLL;                  /* DriverLINX DLL handle, 0 if not used*/
  S(LPBUFFLIST) lpBuffers;             /* I/O buffers for request */
  S(CHANLIST)   channels;              /* channels to read or write */
} S(DL_SERVICEREQUEST);

typedef S(DL_SERVICEREQUEST) FAR_16 *S(LPServiceRequest);

#ifdef ISWIN32
  #define DL_SetServiceRequestSize(sr) \
                                     (sr).dwSize = sizeof(DL_SERVICEREQUEST)
#else
  #define DL_SetServiceRequestSize(sr)
#endif

/* Following "handle-as-pointer" functions not supported for 32-bit */
#if !defined(DL_REDECLARE) && \
    !(defined(__WATCOMC__) && defined(__WINDOWS_386__))
#ifdef __cplusplus

#ifndef ISWIN32
  /* Function to pass global memory handle to structure instead of pointer */
inline LPVOID PASCAL HNDasPTR (HGLOBAL hGlobal)
{
  return ((LPVOID)MAKELONG(hGlobal, 0));
}
#endif // !ISWIN32

  /* Function to lock (dereference) global handle or pointer */
inline LPVOID PASCAL LockPtr (LPVOID ptr)
{
  #ifndef ISWIN32
    return ((SELECTOROF(ptr) == 0) ? GlobalLock((HGLOBAL)OFFSETOF(ptr)) : ptr);
  #else
    return ptr;
  #endif // ISWIN32
}

  /* Function to unlock global handle or pointer */
inline VOID PASCAL UnlockPtr (LPVOID)
{
  #ifndef ISWIN32
    if (SELECTOROF(ptr) == 0) GlobalUnlock((HGLOBAL)OFFSETOF(ptr));
  #endif // !ISWIN32
}

  /* Function to distinguish pointer from global handle */
inline BOOL PASCAL IsPtr (LPVOID)
{
  #ifndef ISWIN32
    return ((SELECTOROF(ptr) != 0) ? TRUE : FALSE);
  #else
    return TRUE;
  #endif // ISWIN32
}

#else

#ifndef ISWIN32
  /* Macro to pass global memory handle to structure instead of pointer */
#define HNDasPTR(hGlobal) ((LPVOID)MAKELONG(hGlobal, 0))
#endif // !ISWIN32

  /* Macro to lock (dereference) global handle or pointer */
#ifndef ISWIN32
  #define LockPtr(ptr) ((SELECTOROF(ptr) == 0) ? \
                                        GlobalLock((HGLOBAL)OFFSETOF(ptr)) : \
                                                  (LPVOID)(ptr))
#else
  #define LockPtr(ptr) (ptr)
#endif // !ISWIN32

  /* Macro to unlock global handle or pointer */
#ifndef ISWIN32
  #define UnlockPtr(ptr) if (SELECTOROF(ptr) == 0) \
                      GlobalUnlock((HGLOBAL)OFFSETOF(ptr))
#else
  #define UnlockPtr(ptr) ((void)0)
#endif // !ISWIN32

  /* Macro to distinguish pointer from global handle */
#ifndef ISWIN32
  #define IsPtr(ptr) ((SELECTOROF(ptr) != 0) ? TRUE : FALSE)
#else
  #define IsPtr(ptr) TRUE
#endif // !ISWIN32

#endif /* __cplusplus */
#endif /* !DL_REDECLARE */

  /*     M E S S A G E S  P O S T E D  B Y  D r i v e r L I N X       */

  /* Message are posted to the calling application reporting the progress
     of the service request.  DriverLINX posts all its messages using the
     unique code returned by the RegisterWindowMessage function and wParam
     passes the specific message.  All messages return information identifying
     the original service request in lParam as well as optional additional
     information for some messages.
  */

#ifndef DL_REDECLARE
  #define DL_MESSAGE          "DriverLINX"  /* registered Window message name */

  #define DL_SERVICESTART     0             /* service has started */
  #define DL_SERVICEDONE      1             /* service has completed */
  #define DL_TIMERTIC         2             /* timer tic */
  #define DL_CRITICALERROR    3             /* critical error occurred */
  #define DL_BUFFERFILLED     4             /* data buffer filled */
  #define DL_DATALOST         5             /* data was lost */
  #define DL_LDDCHANGED       6             /* LDD updated */
  #define DL_STARTEVENT       7             /* start event occurred */
  #define DL_STOPEVENT        8             /* stop event occurred */
  #define DL_USERBREAK        9             /* user break detected */
#endif /* DL_REDECLARE */

  /* All messages return the following fields packed in the low word of lParam:
      task      - task id of service request
      device    - that initiated original service request
      subsystem - that initiated original service request
      mode      - that initiated original service request

    Additional information is returned by the high word of lParam
    in the following messages:
      DL_CRITICALERROR      DriverLINX result code

    Additional information is returned by the high word, low byte of lParam
    in the following messages:
      DL_BUFFERFILLED       BufferAddr index (0..254)

    The high word, high byte of lParam is currently unused, but reserved.

    The following messages return a "handle" to additional information
    that can be accessed by calling the GetEvent function with the handle.
    The handle is stored in the high word of lParam.
      DL_STOPEVENT - returns buffer # in param 1, sample index in param 2
      DL_DATALOST  - returns buffer # in param 1, sample index in param 2

    The following messages are conditionally reported:
      DL_STARTEVENT   - depends on notify field of DL_BUFFERLIST
      DL_STOPEVENT    - depends on notify field of DL_BUFFERLIST
      DL_BUFFERFILLED - depends on notify field of DL_BUFFERLIST
      DL_DATALOST     - reported if supported by hardware or if a message
                        could not be posted to an application.
  */

  /* DriverLINX events contain additional information that could not be
     passed to an application using message parameters.  The DriverLINX
     message returns an event handle which the application uses to retrieve
     the additional information using the GetEvent function.

     The meaning of the event information depends on the associated message.
     The application must initialize the size field in the event message
     before calling GetEvent.
  */

#ifndef DL_REDECLARE
  DECLARE_HANDLE(HDLEVENT);

  typedef struct tagDLEVENTMSG {
    DWORD       size;                  /* size of structure */
    LPARAM      prm1;                  /* parameter */
    LPARAM      prm2;                  /* parameter */
  } DLEVENTMSG;

  typedef DLEVENTMSG FAR_16 * LPDLEVENTMSG;

  #define DLEVENTMSGSIZE sizeof(DLEVENTMSG)
#endif /* DL_REDECLARE */

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__WATCOMC__) || !defined(__WINDOWS_386__)

extern BOOL DLLAPI GetEvent (LPDLEVENTMSG lpEvt, HWND hWnd, HDLEVENT hEvent);
  /* Return DriverLINX event data */

#endif /* !defined(__WATCOMC__) || !defined(__WINDOWS_386__) */

#ifdef __cplusplus
}
#endif

#ifndef DL_REDECLARE
#ifdef __cplusplus

  /* Return event handle from lParam */
inline HDLEVENT PASCAL getEventHandle (LPARAM lParam)
{
  return (HDLEVENT)HIWORD(lParam);
}

  /* Return task id from lParam */
inline BYTE PASCAL getTaskId (LPARAM lParam)
{
  return ((BYTE)(LOWORD(lParam) >> 8));
}

  /* Return device from lParam */
inline UINT PASCAL getDevice (LPARAM lParam)
{
  return ((WORD)((LOWORD(lParam) >> 5) & 7));
}

  /* Return subsystem from lParam */
inline SubSystems PASCAL getSubSystem (LPARAM lParam)
{
  return ((SubSystems)((LOWORD(lParam) >> 2) & 7));
}

  /* Return mode for subsystem from lParam */
inline Modes PASCAL getMode (LPARAM lParam)
{
  return ((Modes)(LOWORD(lParam) & 3));
}

  /* Return buffer address index from high word of lParam */
inline UINT PASCAL getBufIndex (LPARAM lParam)
{
  return (HIWORD(lParam) & 255);
}

  /* Return result code from high word of lParam */
inline UINT PASCAL getResult (LPARAM lParam)
{
  return (HIWORD(lParam));
}

  /* Build message data for low word of lParam */
inline UINT PASCAL makeMsgData (UINT task, UINT device, SubSystems subsystem,
                                Modes mode)
{
  return ((WORD)(
    (((task) & 255) << 8) |
    (((device) & 7) << 5) |
    (((subsystem) & 7) << 2) |
    ((mode) & 3)
  ));
}

#else

  /* Return event handle from lParam */
#define getEventHandle(lParam) (HDLEVENT)(HIWORD(lParam))

  /* Return task id from lParam */
#define getTaskId(lParam) ((BYTE)(LOWORD(lParam) >> 8))

  /* Return device from lParam */
#define getDevice(lParam) ((WORD)((LOWORD(lParam) >> 5) & 7))

  /* Return subsystem from lParam */
#define getSubSystem(lParam) ((SubSystems)((LOWORD(lParam) >> 2) & 7))

  /* Return mode for subsystem from lParam */
#define getMode(lParam) ((Modes)(LOWORD(lParam) & 3))

  /* Return buffer address index from high word of lParam */
#define getBufIndex(lParam) (HIWORD(lParam) & 255)

  /* Return result code from high word of lParam */
#define getResult(lParam) (HIWORD(lParam))

  /* Build message data for low word of lParam */
#define makeMsgData(task, device, subsystem, mode) \
  ((WORD)( \
    (((task) & 255) << 8) | \
    (((device) & 7) << 5) | \
    (((subsystem) & 7) << 2) | \
    ((mode) & 3) \
  ))

#endif
#endif /* DL_REDECLARE */


#ifndef DL_REDECLARE
#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__WATCOMC__) || !defined(__WINDOWS_386__)

  /* The following three functions are not exported by
     older versions of DriverLINX */

extern HINSTANCE DLLAPI OpenDriverLINX (const HWND hWnd, LPCSTR name);
  /* Load a DriverLINX driver for "name" device */

extern VOID DLLAPI CloseDriverLINX (const HINSTANCE hDLL);
  /* Close a DriverLINX driver */

extern HINSTANCE DLLAPI SelectDriverLINX (const HINSTANCE hDLL);
  /* Select hDLL as current DriverLINX device */

  /*           D r i v e r ù L I N X  E N T R Y  P O I N T                  */

extern UINT DLLAPI DriverLINX (LPServiceRequest hpServiceRequest);


  /*               S U P P O R T   F U N C T I O N S                        */

extern DWORD DLLAPI GetDriverLINXVersion (VOID);
  /* Return version of DriverùLINX interface specification and driver.
     High word contains DriverùLINX interface specification version and
     low word contains driver version.  Major version in high byte and
     minor version in low byte. */

extern UINT DLLAPI ReturnMessageString (HWND hWnd, UINT StringCode,
                                        LPSTR Msg, UINT len);
  /* Return message string for code number */

#endif /* !defined(__WATCOMC__) || !defined(__WINDOWS_386__) */

  /* Special pointer to automatically allocate global memory for buffers */
#define AUTO_ALLOC_BUFFER ((LPVOID)(0xFFFFL))

  /* Buffer memory allocation flags */
#define GBUF_SHARE         1           /* DDE sharing */
#define GBUF_ZEROINIT      2           /* zero buffer */
#define GBUF_LOWMEM        4           /* allocate below 1 MB address */
#define GBUF_NOSWAP        8           /* inhibit bank or page swap */
#define GBUF_ALIGN64K     16           /* for byte DMA transfers */
#define GBUF_ALIGN128K    32           /* for word DMA transfers */
#define GBUF_CONTIG       64           /* DMA memory is physically contiguous */
#define GBUF_NOCOMPACT   128           /* don't compact to satisfy alloc */
#define GBUF_NOVXDALLOC  256           /* don't use VxD allocator */

#define GBUF_POLLED   0
#define GBUF_INT     (GBUF_LOWMEM | GBUF_NOSWAP)
#define GBUF_DMA8    (GBUF_NOSWAP | GBUF_ALIGN64K | GBUF_CONTIG)
#define GBUF_DMA16   (GBUF_NOSWAP | GBUF_ALIGN128K | GBUF_CONTIG)

#if !defined(__WATCOMC__) || !defined(__WINDOWS_386__)

#define Deref32(lpPtr) (lpPtr)
  /* Maps pointer into app's address space */

  /* Memory buffer allocation functions */

extern LPVOID DLLAPI BufAlloc (UINT wFlags, DWORD dwBytes);
  /* Allocate memory buffer */

extern UINT DLLAPI BufFree (LPVOID buffer);
  /* Free an allocated memory buffer */


  /* Functions to lock/unlock/free Logical Device Descriptors */

extern HANDLE DLLAPI GetLDD (HWND hWnd, UINT device);
  /* Return handle to copy of LDD */

extern LPLDD DLLAPI LockLDD (HANDLE hLDD);
  /* Lock LDD copy and return memory pointer to data structure */

extern UINT DLLAPI UnlockLDD (LPLDD lpLDD);
  /* Unlock LDD copy */
  /* N.B. Not re-entrant.  Calls to Lock/UnlockLDD cannot be nested */

extern UINT DLLAPI FreeLDD (HANDLE hLDD);
  /* Release memory for LDD copy */


  /* Useful utility functions */

extern BOOL DLLAPI Tics2Sec (UINT device, SubSystems subsystem, UINT chan,
                             DWORD tics, float FAR_16 *lpFloat);
  /* Convert tics to seconds */

extern DWORD DLLAPI Sec2Tics (UINT device, SubSystems subsystem, UINT chan,
                              float secs);
  /* Convert seconds to tics */

extern DWORD DLLAPI Samples2Bytes (UINT device, SubSystems subsystem, UINT chan,
                                   DWORD samples);
  /* Convert samples to bytes */

extern DWORD DLLAPI Bytes2Samples (UINT device, SubSystems subsystem, UINT chan,
                                   DWORD bytes);
  /* Convert bytes to samples */

extern SINT DLLAPI Gain2Code (UINT device, SubSystems subsystem, float gain);
  /* Convert gain to gain code */
  /* Returns 0 if gain not found */

extern BOOL DLLAPI Code2Gain (UINT device, SubSystems subsystem, SINT code,
                              float FAR_16 *lpFloat);
  /* Convert gain code to gain */
  /* Returns 0 if code not found */

extern DWORD DLLAPI Volts2Code (UINT device, SubSystems subsystem, float volts);
  /* Convert volts to digital code */
  /* Assumes unity gain */

extern DWORD DLLAPI Volts2CalibratedCode (UINT device, SubSystems subsystem,
				                                  float volts, float gain);
  /* Convert volts to digital code using calibration tables, if any */

extern BOOL DLLAPI Volts2CodeXform (UINT device, SubSystems subsystem,
                                    float FAR_16 * lpUnitsVolt,
                                    float FAR_16 * lpVoltsOffset);
  /* Returns transform for volts-to-code conversion: */
  /* code = (volts + VoltsOffset) * UnitsVolt */
  /* Assumes unity gain */

extern BOOL DLLAPI Code2Volts (UINT device, SubSystems subsystem, DWORD code,
                               float FAR_16 * lpFloat);
  /* Convert digital code to volts */
  /* Expects code has been correctly sign extended if < 0 */
  /* Assumes unity gain */

extern BOOL DLLAPI Code2VoltsXform (UINT device, SubSystems subsystem,
                                    float FAR_16 * lpVoltsUnit,
                                    float FAR_16 * lpVoltsOffset);
  /* Returns transform for code-to-volts conversion: */
  /* volts = code * VoltsUnit + VoltsOffset */
  /* Assumes unity gain */

extern DWORD DLLAPI UnmaskCode (UINT device, SubSystems subsystem, DWORD code);
  /* Unmask and shift native A/D or D/A code */

extern UINT DLLAPI DLMinPeriod (LPServiceRequest lpServiceRequest);
  /* Returns minimum sampling period supported by hardware for
     a given Service Request.  Value is returned in the timing rate
     event period field. A zero is returned if hardware does not
     support timed sampling for the Service Request.  A standard DriverLINX
     error code is returned as a function result and in the Service Request
     result field.  A ServiceNotSupportedErr is returned if no information
     is available. */

extern UINT DLLAPI AboutDriverLINX (const HWND hWnd);
  /* Display DriverLINX About dialog */

extern DWORD DLLAPI Volts2CalibratedCode (UINT device, SubSystems subsystem,
				                                  float volts, float gain);

#endif /* !defined(__WATCOMC__) || !defined(__WINDOWS_386__) */

#ifdef __cplusplus
}
#endif
#endif /* DL_REDECLARE */


#ifdef _MSC_VER
  #pragma pack()                       /* revert to previous value */
#endif

#ifdef __BORLANDC__
  #pragma option -a.                   /* revert to previous value */
  #pragma option -b.                   /* revert to previous value */
#endif

#ifdef __WATCOMC__
  #pragma pack()                       /* revert to previous value */
#endif

#ifdef __ZTC__
  #pragma ZTC align                    /* revert to previous value */
#endif

/* Undefine internal macros */
#undef vextern
#undef DLMAXENUM
#ifndef DL_REDECLARE
  #undef E
  #undef H
  #undef P
  #undef S
#endif

#if defined(__WATCOMC__) && defined(__WINDOWS_386__)
  #include "drvlnxwc.h"
#endif

#endif /* DRVLINX_H */


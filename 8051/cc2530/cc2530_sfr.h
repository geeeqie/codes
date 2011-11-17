

#ifndef IOCC2530_H
#define IOCC2530_H

#define BV(x) (1<<(x))

/* ------------------------------------------------------------------------------------------------
 *                                      Compiler Abstraction
 * ------------------------------------------------------------------------------------------------*/

#ifdef SDCC
#define SFR(name, addr)        __sfr   __at(addr)                      name;
#define SBIT(name, addr, bit)  __sbit  __at(addr+bit)                  name;
#define SFRBIT(name, addr, bit7, bit6, bit5, bit4, bit3, bit2, bit1, bit0) \
__sfr __at(addr) name; \
__sbit __at(addr+7) bit7; \
__sbit __at(addr+6) bit6; \
__sbit __at(addr+5) bit5; \
__sbit __at(addr+4) bit4; \
__sbit __at(addr+3) bit3; \
__sbit __at(addr+2) bit2; \
__sbit __at(addr+1) bit1; \
__sbit __at(addr+0) bit0;
#define XREG(addr)       ((__xdata volatile volatile unsigned char *) 0)[addr]
#define PXREG(addr)      ((__xdata volatile volatile unsigned char *) addr)
#define VECT(num,addr)   num

#else
#error "Unrecognized compiler."
#endif


/* ------------------------------------------------------------------------------------------------
 *                                        Interrupt Vectors
 * ------------------------------------------------------------------------------------------------
 */
#define  RFERR_VECTOR    0   /*  RF TX FIFO Underflow and RX FIFO Overflow   */
#define  ADC_VECTOR      1   /*  ADC End of Conversion                       */
#define  URX0_VECTOR     2   /*  USART0 RX Complete                          */
#define  URX1_VECTOR     3   /*  USART1 RX Complete                          */
#define  ENC_VECTOR      4   /*  AES Encryption/Decryption Complete          */
#define  ST_VECTOR       5   /*  Sleep Timer Compare                         */
#define  P2INT_VECTOR    6   /*  Port 2 Inputs                               */
#define  UTX0_VECTOR     7   /*  USART0 TX Complete                          */
#define  DMA_VECTOR      8   /*  DMA Transfer Complete                       */
#define  T1_VECTOR       9   /*  Timer 1 (16-bit) Capture/Compare/Overflow   */
#define  T2_VECTOR       10   /*  Timer 2 (MAC Timer)                         */
#define  T3_VECTOR       11   /*  Timer 3 (8-bit) Capture/Compare/Overflow    */
#define  T4_VECTOR       12   /*  Timer 4 (8-bit) Capture/Compare/Overflow    */
#define  P0INT_VECTOR    13   /*  Port 0 Inputs                               */
#define  UTX1_VECTOR     14   /*  USART1 TX Complete                          */
#define  P1INT_VECTOR    15   /*  Port 1 Inputs                               */
#define  RF_VECTOR       16   /*  RF General Interrupts                       */
#define  WDT_VECTOR      17   /*  Watchdog Overflow in Timer Mode             */


/* ------------------------------------------------------------------------------------------------
 *                                            SFRs
 * ------------------------------------------------------------------------------------------------
 */

/*
 *   SFRs with an address ending with 0 or 8 are bit accessible.
 *   They are defined with the SFRBIT() macro that sets the name of each bit.
 */

/* Port 0                                                                           */
__sfr __at(0x80) P0;
__sbit __at(0x87) P0_7;
__sbit __at(0x86) P0_6;
__sbit __at(0x85) P0_5;
__sbit __at(0x84) P0_4;
__sbit __at(0x83) P0_3;
__sbit __at(0x82) P0_2;
__sbit __at(0x81) P0_1;
__sbit __at(0x80) P0_0;

__sfr __at(0x81) SP;/*  Stack Pointer     */
__sfr __at(0x82) DPL0;   /*  Data Pointer 0 Low	 */
__sfr __at(0x83) DPH0;   /*  Data Pointer 0 High Byte    */
__sfr __at(0x84) DPL1;   /*  Data Pointer 1 Low Byte    */
__sfr __at(0x85) DPH1;   /*  Data Pointer 1 High Byte    */
__sfr __at(0x86) U0CSR;   /*  USART 0 Control and Status   */
__sfr __at(0x87) PCON;   /*  Power Mode Control      */

/* Interrupt Flags                                                                  */
__sfr __at(0x88) TCON;
__sbit __at(0x8F) URX1IF;
__sbit __at(0x8E) _TCON6;
__sbit __at(0x8D) ADCIF;
__sbit __at(0x8C) _TCON4;
__sbit __at(0x8B) URX0IF;
__sbit __at(0x8A) IT1;
__sbit __at(0x89) RFERRIF;
__sbit __at(0x88) IT0;

__sfr __at(0x89) P0IFG;   /*  Port 0 Interrupt Status Flag     */
__sfr __at(0x8A) P1IFG;   /*  Port 1 Interrupt Status Flag    */
__sfr __at(0x8B) P2IFG;   /*  Port 2 Interrupt Status Flag     */
__sfr __at(0x8C) PICTL;   /*  Port Interrupt Control        */
__sfr __at(0x8D) P1IEN;   /*  Port 1 Interrupt Mask          */
__sfr __at(0x8E) _SFR8E;   /*  not used               */
__sfr __at(0x8F) P0INP;   /*  Port 0 Input Mode        */

/* Port 1                                                                           */
__sfr __at(0x90) P1;
__sbit __at(0x97) P1_7;
__sbit __at(0x96) P1_6;
__sbit __at(0x95) P1_5;
__sbit __at(0x94) P1_4;
__sbit __at(0x93) P1_3;
__sbit __at(0x92) P1_2;
__sbit __at(0x91) P1_1;
__sbit __at(0x90) P1_0;

__sfr __at(0x91) RFIRQF1;   /*  RF Interrupt Flags MSB      */
__sfr __at(0x92) DPS;   /*  Data Pointer Select        */
__sfr __at(0x93) MPAGE;   /*  Memory Page Select      */
__sfr __at(0x93) _XPAGE;   /*  Memory Page Select  -- name declare for SDCC compiler    */
__sfr __at(0x94) T2CTRL;  /*  Timer2 Control Register     */
__sfr __at(0x95) ST0;   /*  Sleep Timer 0      */
__sfr __at(0x96) ST1;   /*  Sleep Timer 1       */
__sfr __at(0x97) ST2;   /*  Sleep Timer 2     */

/*  Interrupt Flags 2                                                               */
__sfr __at(0x98) S0CON;
__sbit __at(0x9F) _S0CON7;
__sbit __at(0x9E) _S0CON6;
__sbit __at(0x9D) _S0CON5;
__sbit __at(0x9C) _S0CON4;
__sbit __at(0x9B) _S0CON3;
__sbit __at(0x9A) _S0CON2;
__sbit __at(0x99) ENCIF_1;
__sbit __at(0x98) ENCIF_0;

__sfr __at(0x99) _SFR99;   /*  reserved           */
__sfr __at(0x9A) IEN2;  /*  Interrupt Enable 2       */
__sfr __at(0x9B) S1CON;   /*  Interrupt Flags 3         */
__sfr __at(0x9C) T2CSPCFG;   /*  Timer2 CSP Interface Configuration (legacy name)   */
__sfr __at(0x9C) T2EVTCFG;  /*  Timer2 Event Output Configuration      */
__sfr __at(0x9D) SLEEPSTA;   /*  Sleep Status       */
__sfr __at(0x9E) CLKCONSTA;   /*  Clock Control Status     */
__sfr __at(0x9F) FMAP;   /*  Flash Bank Map      */

/* Port 2                                                                           */
__sfr __at(0xA0) P2;
__sbit __at(0xA7) _P2_7;
__sbit __at(0xA6) _P2_6;
__sbit __at(0xA5) _P2_5;
__sbit __at(0xA4) P2_4;
__sbit __at(0xA3) P2_3;
__sbit __at(0xA2) P2_2; 
__sbit __at(0xA1) P2_1;
__sbit __at(0xA0) P2_0;

__sfr __at(0xA1) T2IRQF;   /* Timer2 Interrupt Flags                              */
__sfr __at(0xA2) T2M0;   /* Timer2 Multiplexed Register 0                       */
__sfr __at(0xA3) T2M1;   /* Timer2 Multiplexed Register 1                       */
__sfr __at(0xA4) T2MOVF0;   /* Timer2 Multiplexed Overflow Register 0              */
__sfr __at(0xA5) T2MOVF1;   /* Timer2 Multiplexed Overflow Register 1              */
__sfr __at(0xA6) T2MOVF2;   /* Timer2 Multiplexed Overflow Register 2              */
__sfr __at(0xA7) T2IRQM;   /* Timer2 Interrupt Mask                               */

/* Interrupt Enable 0                                                               */
__sfr __at(0xA8) IEN0;
__sbit __at(0xAF) EA;
__sbit __at(0xAE) _IEN06;
__sbit __at(0xAD) STIE;
__sbit __at(0xAC) ENCIE;
__sbit __at(0xAB) URX1IE;
__sbit __at(0xAA) URX0IE;
__sbit __at(0xA9) ADCIE;
__sbit __at(0xA8) RFERRIE;

__sfr __at(0xA9) IP0;   /*  Interrupt Priority 0                               */
__sfr __at(0xAA) _SFRAA;   /*  not used                                           */
__sfr __at(0xAB) P0IEN ;   /*  Port 0 Interrupt Mask                              */
__sfr __at(0xAC) P2IEN ;  /*  Port 2 Interrupt Mask                              */
__sfr __at(0xAD) STLOAD;  /*  Sleep Timer Load Status                            */
__sfr __at(0xAE) PMUX;   /*  Power Down Signal MUX                              */
__sfr __at(0xAF) T1STAT;   /*  Timer 1 Status                                     */

__sfr __at(0xB0) _SFRB0;   /*  not used                                           */
__sfr __at(0xB1) ENCDI;   /*  Encryption/Decryption Input Data                   */
__sfr __at(0xB2) ENCDO;   /*  Encryption/Decryption Output Data                  */
__sfr __at(0xB3) ENCCS ;   /*  Encryption/Decryption Control and Status           */
__sfr __at(0xB4) ADCCON1;  /*  ADC Control 1                                      */
__sfr __at(0xB5) ADCCON2;   /*  ADC Control 2                                      */
__sfr __at(0xB6) ADCCON3;   /*  ADC Control 3                                      */
__sfr __at(0xB7) _SFRB7;   /*  reserved                                           */

/*  Interrupt Enable 1                                                              */
__sfr __at(0xB8) IEN1;
__sbit __at(0xBF) _IEN17;
__sbit __at(0xBE) _IEN16;
__sbit __at(0xBD) P0IE;
__sbit __at(0xBC) T4IE;
__sbit __at(0xBB) T3IE;
__sbit __at(0xBA) T2IE;
__sbit __at(0xB9) T1IE;
__sbit __at(0xB8) DMAIE;


__sfr __at(0xB9) IP1;   /*  Interrupt Priority 1                               */
__sfr __at(0xBA) ADCL;   /*  ADC Data Low                                       */
__sfr __at(0xBB) ADCH;   /*  ADC Data High                                      */
__sfr __at(0xBC) RNDL;   /*  Random Number Generator Low Byte                   */
__sfr __at(0xBD) RNDH;   /*  Random Number Generator High Byte                  */
__sfr __at(0xBE) SLEEPCMD;   /*  Sleep Mode Control Command                         */
__sfr __at(0xBF) RFERRF;  /*  RF Error Interrupt Flags                           */

/*  Interrupt Flags 4                                                               */
SFRBIT( IRCON   ,  0xC0, STIF, _IRCON6, P0IF, T4IF, T3IF, T2IF, T1IF, DMAIF )
__sfr __at(0xC0) IRCON;
__sbit __at(0xC7) STIF;
__sbit __at(0xC6) _IRCON6;
__sbit __at(0xC5) P0IF;
__sbit __at(0xC4) T4IF;
__sbit __at(0xC3) T3IF;
__sbit __at(0xC2) T2IF;
__sbit __at(0xC1) T1IF;
__sbit __at(0xC0) DMAIF;


__sfr __at(0xC1) U0DBUF;   /*  USART 0 Receive/Transmit Data Buffer               */
__sfr __at(0xC2) U0BAUD;   /*  USART 0 Baud Rate Control                          */
__sfr __at(0xC3) T2MSEL;   /*  Timer2 Multiplex Select                            */
__sfr __at(0xC4) U0UCR;   /*  USART 0 UART Control                               */
__sfr __at(0xC5) U0GCR;  /*  USART 0 Generic Control                            */
__sfr __at(0xC6) CLKCONCMD ;  /*  Clock Control Command                              */
__sfr __at(0xC7) MEMCTR ;   /*  Memory System Control                              */

__sfr __at(0xC8) _SFRC8;   /*  not used                                           */
__sfr __at(0xC9) WDCTL;   /*  Watchdog Timer Control                             */
__sfr __at(0xCA) T3CNT;   /*  Timer 3 Counter                                    */
__sfr __at(0xCB) T3CTL ;   /*  Timer 3 Control                                    */
__sfr __at(0xCC) T3CCTL0 ;  /*  Timer 3 Channel 0 Capture/Compare Control          */
__sfr __at(0xCD) T3CC0 ;   /*  Timer 3 Channel 0 Capture/Compare Value            */
__sfr __at(0xCE) T3CCTL1;  /*  Timer 3 Channel 1 Capture/Compare Control          */
__sfr __at(0xCF) T3CC1 ;   /*  Timer 3 Channel 1 Capture/Compare Value            */

 /*  Program Status Word                                                            */
__sfr __at(0xD0) PSW;
__sbit __at(0xD7) CY ;
__sbit __at(0xD6) AC ;
__sbit __at(0xD5) F0 ;
__sbit __at(0xD4) RS1 ;
__sbit __at(0xD3) RS0 ;
__sbit __at(0xD2) OV ;
__sbit __at(0XD1) F1 ;
__sbit __at(0xD0) P ;

__sfr __at(0xD1)  DMAIRQ;   /*  DMA Interrupt Flag                                 */
__sfr __at(0xD2) DMA1CFGL ;  /*  DMA Channel 1-4 Configuration Address Low Byte     */
__sfr __at(0xD3) DMA1CFGH;   /*  DMA Channel 1-4 Configuration Address High Byte    */
__sfr __at(0xD4) DMA0CFGL;   /*  DMA Channel 0 Configuration Address Low Byte       */
__sfr __at(0xD5) DMA0CFGH ;   /*  DMA Channel 0 Configuration Address High Byte      */
__sfr __at(0xD6) DMAARM  ;  /*  DMA Channel Arm                                    */
__sfr __at(0xD7) DMAREQ ;   /*  DMA Channel Start Request and Status               */

/*  Timers 1/3/4 Interrupt Mask/Flag                                                */
__sfr __at(0xD8) TIMIF;
__sbit __at(0xDF) _TIMIF7;
__sbit __at(0xDE) T1OVFIM;
__sbit __at(0xDD) T4CH1IF;
__sbit __at(0xDC) T4CH0IF;
__sbit __at(0xDB) T4OVFIF;
__sbit __at(0xDA) T3CH1IF;
__sbit __at(0xD9) T3CH0IF;
__sbit __at(0xD8) T3OVFIF;

__sfr __at(0xD9) RFD;   /*  RF Data                                            */
__sfr __at(0xDA) T1CC0L;   /*  Timer 1 Channel 0 Capture/Compare Value Low Byte   */
__sfr __at(0xDB) T1CC0H ;   /*  Timer 1 Channel 0 Capture/Compare Value High Byte  */
__sfr __at(0xDC) T1CC1L ;   /*  Timer 1 Channel 1 Capture/Compare Value Low Byte   */
__sfr __at(0xDD) T1CC1H ;   /*  Timer 1 Channel 1 Capture/Compare Value High Byte  */
__sfr __at(0xDE) T1CC2L;   /*  Timer 1 Channel 2 Capture/Compare Value Low Byte   */
__sfr __at(0xDF) T1CC2H ;   /*  Timer 1 Channel 2 Capture/Compare Value High Byte  */

__sfr __at(0xE0) ACC ;   /*  Accumulator                                        */
__sfr __at(0xE1) RFST ;   /*  RF Command Strobe                                  */
__sfr __at(0xE2) T1CNTL;  /*  Timer 1 Counter Low                                */
__sfr __at(0xE3) T1CNTH ; /*  Timer 1 Counter High                               */
__sfr __at(0xE4) T1CTL ;   /*  Timer 1 Control And Status                         */
__sfr __at(0xE5) T1CCTL0 ;  /*  Timer 1 Channel 0 Capture/Compare Control          */
__sfr __at(0xE6) T1CCTL1 ;  /*  Timer 1 Channel 1 Capture/Compare Control          */
__sfr __at(0xE7) T1CCTL2 ;   /*  Timer 1 Channel 2 Capture/Compare Control          */

/*  Interrupt Flags 5                                                               */
__sfr __at(0xE8) IRCON2;
__sbit __at(0xEF) _IRCON27;
__sbit __at(0xEE) _IRCON26;
__sbit __at(0xED) _IRCON25;
__sbit __at(0xEC) WDTIF;
__sbit __at(0xEB) P1IF;
__sbit __at(0xEA) UTX1IF;
__sbit __at(0xE9) UTX0IF;
__sbit __at(0xE8) P2IF;

__sfr __at(0xE9) RFIRQF0;  /*  RF Interrupt Flags LSB                             */
__sfr __at(0xEA) T4CNT;  /*  Timer 4 Counter                                    */
__sfr __at(0xEB) T4CTL ;  /*  Timer 4 Control                                    */
__sfr __at(0xEC) T4CCTL0 ;  /*  Timer 4 Channel 0 Capture/Compare Control          */
__sfr __at(0xED) T4CC0 ;  /*  Timer 4 Channel 0 Capture/Compare Value            */
__sfr __at(0xEE) T4CCTL1 ;  /*  Timer 4 Channel 1 Capture/Compare Control          */
__sfr __at(0xEF) T4CC1  ;  /*  Timer 4 Channel 1 Capture/Compare Value            */

__sfr __at(0xF0) B  ;  /*  B Register                                         */
__sfr __at(0xF1) PERCFG  ;   /*  Peripheral I/O Control                             */
__sfr __at(0xF2) ADCCFG ;   /*  ADC Input Configuration (legacy name)              */
__sfr __at(0xF2) APCFG ;   /*  Analog Periferal I/O Configuration                 */
__sfr __at(0xF3) P0SEL ;   /*  Port 0 Function Select                             */
__sfr __at(0xF4) P1SEL ;   /*  Port 1 Function Select                             */
__sfr __at(0xF5) P2SEL  ;   /*  Port 2 Function Select                             */
__sfr __at(0xF6) P1INP  ;  /*  Port 1 Input Mode                                  */
__sfr __at(0xF7) P2INP ;   /*  Port 2 Input Mode                                  */

/*  USART 1 Control and Status                                                      */
__sfr __at(0xF8) U1CSR ;
__sbit __at(0xFF) U1MODE;
__sbit __at(0xFE) U1RE;
__sbit __at(0xFD) U1SLAVE;
__sbit __at(0xFC) U1FE;
__sbit __at(0xFB) U1ERR;
__sbit __at(0xFA) U1RX_BYTE;
__sbit __at(0xF9) U1TX_BYTE;
__sbit __at(0xF8) U1ACTIVE;

__sfr __at(0xF9) U1DBUF;   /*  USART 1 Receive/Transmit Data Buffer               */
__sfr __at(0xFA) U1BAUD ;   /*  USART 1 Baud Rate Control                          */
__sfr __at(0xFB) U1UCR ;   /*  USART 1 UART Control                               */
__sfr __at(0xFC) U1GCR ;   /*  USART 1 Generic Control                            */
__sfr __at(0xFD) P0DIR  ;  /*  Port 0 Direction                                   */
__sfr __at(0xFE) P1DIR ;   /*  Port 1 Direction                                   */
__sfr __at(0xFF) P2DIR ;   /*  Port 2 Direction                                   */


/* ------------------------------------------------------------------------------------------------
 *                                       Xdata Radio Registers
 * ------------------------------------------------------------------------------------------------
 */
/* RF Core RAM */
//#define RFCORE_RAM      PXREG( 0x6000 )
__xdata __at (0x6000) volatile unsigned char RFCORE_RAM;
#define RFCORE_RAM_SZ   384

/* FIFO Direct Access */
//#define RXFIFO          PXREG( 0x6000 )
__xdata __at (0x6000) volatile unsigned char RXFIFO;
#define RXFIFO_SZ       128
//#define TXFIFO          PXREG( 0x6080 )
__xdata __at (0x6080) volatile unsigned char TXFIFO;
#define TXFIFO_SZ       128

/* Frame Filtering and Source Matching Memory */
//#define FRMF_SRCM_RAM   PXREG( 0x6100 )
__xdata __at (0x6100) volatile unsigned char FRMF_SRCM_RAM;
#define FRMF_SRCM_RAM_SZ 128

/* Source Address Table */
//#define SRC_ADDR_TABLE  PXREG( 0x6100 )
__xdata __at (0x6100) volatile unsigned char SRC_ADDR_TABLE;
#define SRC_ADDR_TABLE_SZ 96

/* Source Address Matching Control */
//#define SRCRESMASK0     XREG( 0x6160 )
__xdata __at (0x6160) volatile unsigned char SRCRESMASK0;
//#define SRCRESMASK1     XREG( 0x6161 )
__xdata __at (0x6161) volatile unsigned char SRCRESMASK1;
//#define SRCRESMASK2     XREG( 0x6162 )
__xdata __at (0x6162) volatile unsigned char SRCRESMASK2;
//#define SRCRESINDEX     XREG( 0x6163 )
__xdata __at (0x6163) volatile unsigned char SRCRESINDEX;
//#define SRCEXTPENDEN0   XREG( 0x6164 )
__xdata __at (0x6164) volatile unsigned char SRCEXTPENDEN0;
//#define SRCEXTPENDEN1   XREG( 0x6165 )
__xdata __at (0x6165) volatile unsigned char SRCEXTPENDEN1;
//#define SRCEXTPENDEN2   XREG( 0x6166 )
__xdata __at (0x6166) volatile unsigned char SRCEXTPENDEN2;
//#define SRCSHORTPENDEN0 XREG( 0x6167 )
__xdata __at (0x6167) volatile unsigned char SRCSHORTPENDEN0;
//#define SRCSHORTPENDEN1 XREG( 0x6168 )
__xdata __at (0x6168) volatile unsigned char SRCSHORTPENDEN1;
//#define SRCSHORTPENDEN2 XREG( 0x6169 )
__xdata __at (0x6169) volatile unsigned char SRCSHORTPENDEN2;

/* Local Address Information */
//#define EXT_ADDR0       XREG( 0x616A )
__xdata __at (0x616A) volatile unsigned char EXT_ADDR0;
//#define EXT_ADDR1       XREG( 0x616B )
__xdata __at (0x616B) volatile unsigned char EXT_ADDR1;
//#define EXT_ADDR2       XREG( 0x616C )
__xdata __at (0x616C) volatile unsigned char EXT_ADDR2;
//#define EXT_ADDR3       XREG( 0x616D )
__xdata __at (0x616D) volatile unsigned char EXT_ADDR3;
//#define EXT_ADDR4       XREG( 0x616E )
__xdata __at (0x616E) volatile unsigned char EXT_ADDR4;
//#define EXT_ADDR5       XREG( 0x616F )
__xdata __at (0x616F) volatile unsigned char EXT_ADDR5;
//#define EXT_ADDR6       XREG( 0x6170 )
__xdata __at (0x6170) volatile unsigned char EXT_ADDR6;
//#define EXT_ADDR7       XREG( 0x6171 )
__xdata __at (0x6171) volatile unsigned char EXT_ADDR7;
//#define PAN_ID0         XREG( 0x6172 )
__xdata __at (0x6172) volatile unsigned char PAN_ID0;
//#define PAN_ID1         XREG( 0x6173 )
__xdata __at (0x6173) volatile unsigned char PAN_ID1;
//#define SHORT_ADDR0     XREG( 0x6174 )
__xdata __at (0x6174) volatile unsigned char SHORT_ADDR0;
//#define SHORT_ADDR1     XREG( 0x6175 )
__xdata __at (0x6175) volatile unsigned char SHORT_ADDR1;

/* Address information for RX Control */
//#define FRMFILT0        XREG( 0x6180 )
__xdata __at (0x6180) volatile unsigned char FRMFILT0;
//#define FRMFILT1        XREG( 0x6181 )
__xdata __at (0x6181) volatile unsigned char FRMFILT1;
//#define SRCMATCH        XREG( 0x6182 )
__xdata __at (0x6182) volatile unsigned char SRCMATCH;
//#define SRCSHORTEN0     XREG( 0x6183 )
__xdata __at (0x6183) volatile unsigned char SRCSHORTEN0;
//#define SRCSHORTEN1     XREG( 0x6184 )
__xdata __at (0x6184) volatile unsigned char SRCSHORTEN1;
//#define SRCSHORTEN2     XREG( 0x6185 )
__xdata __at (0x6185) volatile unsigned char SRCSHORTEN2 ;
//#define SRCEXTEN0       XREG( 0x6186 )
__xdata __at (0x6186) volatile unsigned char SRCEXTEN0;
//#define SRCEXTEN1       XREG( 0x6187 )
__xdata __at (0x6187) volatile unsigned char SRCEXTEN1;
//#define SRCEXTEN2       XREG( 0x6188 )
__xdata __at (0x6188) volatile unsigned char SRCEXTEN2;

/* Radio Control */
//#define FRMCTRL0        XREG( 0x6189 )
__xdata __at (0x6189) volatile unsigned char FRMCTRL0;
//#define FRMCTRL1        XREG( 0x618A )
__xdata __at (0x618A) volatile unsigned char FRMCTRL1;
//#define RXENABLE        XREG( 0x618B )
__xdata __at (0x618B) volatile unsigned char RXENABLE;
//#define RXMASKSET       XREG( 0x618C )
__xdata __at (0x618C) volatile unsigned char  RXMASKSET;
//#define RXMASKCLR       XREG( 0x618D )
__xdata __at (0x618D) volatile unsigned char RXMASKCLR;
//#define FREQTUNE        XREG( 0x618E )
__xdata __at (0x618E) volatile unsigned char FREQTUNE;
//#define FREQCTRL        XREG( 0x618F )
__xdata __at (0x618F) volatile unsigned char FREQCTRL;
//#define TXPOWER         XREG( 0x6190 )
__xdata __at (0x6190) volatile unsigned char TXPOWER;
//#define TXCTRL          XREG( 0x6191 )
__xdata __at (0x6191) volatile unsigned char TXCTRL;
//#define FSMSTAT0        XREG( 0x6192 )
__xdata __at (0x6192) volatile unsigned char FSMSTAT0;
//#define FSMSTAT1        XREG( 0x6193 )
__xdata __at (0x6193) volatile unsigned char FSMSTAT1;
//#define FIFOPCTRL       XREG( 0x6194 )
__xdata __at (0x6194) volatile unsigned char FIFOPCTRL;
//#define FSMCTRL         XREG( 0x6195 )
__xdata __at (0x6195) volatile unsigned char FSMCTRL;
//#define CCACTRL0        XREG( 0x6196 )
__xdata __at (0x6196) volatile unsigned char CCACTRL0 ;
//#define CCACTRL1        XREG( 0x6197 )
__xdata __at (0x6197) volatile unsigned char CCACTRL1;
//#define RSSI            XREG( 0x6198 )
__xdata __at (0x6198) volatile unsigned char RSSI;
//#define RSSISTAT        XREG( 0x6199 )
__xdata __at (0x6199) volatile unsigned char RSSISTAT;
//#define RXFIRST         XREG( 0x619A )
__xdata __at (0x619A) volatile unsigned char RXFIRST;
//#define RXFIFOCNT       XREG( 0x619B )
__xdata __at (0x619B) volatile unsigned char RXFIFOCNT;
//#define TXFIFOCNT       XREG( 0x619C )
__xdata __at (0x619C) volatile unsigned char TXFIFOCNT;
//#define RXFIRST_PTR     XREG( 0x619D )
__xdata __at (0x619D) volatile unsigned char RXFIRST_PTR;
//#define RXLAST_PTR      XREG( 0x619E )
__xdata __at (0x619E) volatile unsigned char RXLAST_PTR;
//#define RXP1_PTR        XREG( 0x619F )
__xdata __at (0x619F) volatile unsigned char RXP1_PTR;
//#define _XREG61A0       XREG( 0x61A0 )
__xdata __at (0x61A0) volatile unsigned char _XREG61A0;
//#define TXFIRST_PTR     XREG( 0x61A1 )
__xdata __at (0x61A1) volatile unsigned char TXFIRST_PTR;
//#define TXLAST_PTR      XREG( 0x61A2 )
__xdata __at (0x61A2) volatile unsigned char TXLAST_PTR;

/* Interrupt Controller Registers */
//#define RFIRQM0         XREG( 0x61A3 )
__xdata __at (0x61A3) volatile unsigned char RFIRQM0;
//#define RFIRQM1         XREG( 0x61A4 )
__xdata __at (0x61A4) volatile unsigned char RFIRQM1;
//#define RFERRM          XREG( 0x61A5 )
__xdata __at (0x61A5) volatile unsigned char RFERRM;

/* Random Number Generator */
//#define RFRND           XREG( 0x61A7 )
__xdata __at (0x61A7) volatile unsigned char RFRND;

/* Analog and Digital Radio Test And Tuning */
//#define MDMCTRL0        XREG( 0x61A8 )
__xdata __at (0x61A8) volatile unsigned char MDMCTRL0;
//#define MDMCTRL1        XREG( 0x61A9 )
__xdata __at (0x61A9) volatile unsigned char MDMCTRL1;
//#define FREQEST         XREG( 0x61AA )
__xdata __at (0x61AA) volatile unsigned char FREQEST;
//#define RXCTRL          XREG( 0x61AB )
__xdata __at (0x61AB) volatile unsigned char RXCTRL;
//#define FSCTRL          XREG( 0x61AC )
__xdata __at (0x61AC) volatile unsigned char FSCTRL;
//#define FSCAL0          XREG( 0x61AD )
__xdata __at (0x61AD) volatile unsigned char FSCAL0;
//#define FSCAL1          XREG( 0x61AE )
__xdata __at (0x61AE) volatile unsigned char FSCAL1;
//#define FSCAL2          XREG( 0x61AF )
__xdata __at (0x61AF) volatile unsigned char FSCAL2;
//#define FSCAL3          XREG( 0x61B0 )
__xdata __at (0x61B0) volatile unsigned char FSCAL3;
//#define AGCCTRL0        XREG( 0x61B1 )
__xdata __at (0x61B1) volatile unsigned char AGCCTRL0;
//#define AGCCTRL1        XREG( 0x61B2 )
__xdata __at (0x61B2) volatile unsigned char AGCCTRL1;
//#define AGCCTRL2        XREG( 0x61B3 )
__xdata __at (0x61B3) volatile unsigned char AGCCTRL2;
//#define AGCCTRL3        XREG( 0x61B4 )
__xdata __at (0x61B4) volatile unsigned char AGCCTRL3;
//#define ADCTEST0        XREG( 0x61B5 )
__xdata __at (0x61B5) volatile unsigned char ADCTEST0;
//#define ADCTEST1        XREG( 0x61B6 )
__xdata __at (0x61B6) volatile unsigned char ADCTEST1;
//#define ADCTEST2        XREG( 0x61B7 )
__xdata __at (0x61B7) volatile unsigned char ADCTEST2;
//#define MDMTEST0        XREG( 0x61B8 )
__xdata __at (0x61B8) volatile unsigned char MDMTEST0;
//#define MDMTEST1        XREG( 0x61B9 )
__xdata __at (0x61B9) volatile unsigned char MDMTEST1;
//#define DACTEST0        XREG( 0x61BA )
__xdata __at (0x61BA) volatile unsigned char DACTEST0;
//#define DACTEST1        XREG( 0x61BB )
__xdata __at (0x61BB) volatile unsigned char DACTEST1;
//#define DACTEST2        XREG( 0x61BC )
__xdata __at (0x61BC) volatile unsigned char DACTEST2;
//#define ATEST           XREG( 0x61BD )
__xdata __at (0x61BD) volatile unsigned char ATEST;
//#define PTEST0          XREG( 0x61BE )
__xdata __at (0x61BE) volatile unsigned char PTEST0;
//#define PTEST1          XREG( 0x61BF )
__xdata __at (0x61BF) volatile unsigned char PTEST1;
//#define TXFILTCFG       XREG( 0x61FA )
__xdata __at (0x61FA) volatile unsigned char TXFILTCFG;

/* CSP Control and Observation Registers */
//efine CSPPROG0        XREG( 0x61C0 )
__xdata __at (0x61C0) volatile unsigned char CSPPROG0;
//efine CSPPROG1        XREG( 0x61C1 )
__xdata __at (0x61C1) volatile unsigned char CSPPROG1;
//efine CSPPROG2        XREG( 0x61C2 )
__xdata __at (0x61C2) volatile unsigned char CSPPROG2;
//efine CSPPROG3        XREG( 0x61C3 )
__xdata __at (0x61C3) volatile unsigned char CSPPROG3;
//efine CSPPROG4        XREG( 0x61C4 )
__xdata __at (0x61C4) volatile unsigned char CSPPROG4;
//efine CSPPROG5        XREG( 0x61C5 )
__xdata __at (0x61C5) volatile unsigned char CSPPROG5;
//efine CSPPROG6        XREG( 0x61C6 )
__xdata __at (0x61C6) volatile unsigned char CSPPROG6;
//#define CSPPROG7        XREG( 0x61C7 )
__xdata __at (0x61C7) volatile unsigned char CSPPROG7;
//#define CSPPROG8        XREG( 0x61C8 )
__xdata __at (0x61C8) volatile unsigned char CSPPROG8;
//#define CSPPROG9        XREG( 0x61C9 )
__xdata __at (0x61C9) volatile unsigned char CSPPROG9;
//#define CSPPROG10       XREG( 0x61CA )
__xdata __at (0x61CA) volatile unsigned char CSPPROG10;
//#define CSPPROG11       XREG( 0x61CB )
__xdata __at (0x61CB) volatile unsigned char CSPPROG11;
//#define CSPPROG12       XREG( 0x61CC )
__xdata __at (0x61CC) volatile unsigned char CSPPROG12;
//#define CSPPROG13       XREG( 0x61CD )
__xdata __at (0x61CD) volatile unsigned char CSPPROG13 ;
//#define CSPPROG14       XREG( 0x61CE )
__xdata __at (0x61CE) volatile unsigned char CSPPROG14;
//#define CSPPROG15       XREG( 0x61CF )
__xdata __at (0x61CF) volatile unsigned char CSPPROG15;
//#define CSPPROG16       XREG( 0x61D0 )
__xdata __at (0x61D0) volatile unsigned char CSPPROG16 ;
//#define CSPPROG17       XREG( 0x61D1 )
__xdata __at (0x61D1) volatile unsigned char CSPPROG17;
//#define CSPPROG18       XREG( 0x61D2 )
__xdata __at (0x61D2) volatile unsigned char CSPPROG18;
//#define CSPPROG19       XREG( 0x61D3 )
__xdata __at (0x61D3) volatile unsigned char CSPPROG19;
//#define CSPPROG20       XREG( 0x61D4 )
__xdata __at (0x61D4) volatile unsigned char CSPPROG20;
//#define CSPPROG21       XREG( 0x61D5 )
__xdata __at (0x61D5) volatile unsigned char CSPPROG21;
//#define CSPPROG22       XREG( 0x61D6 )
__xdata __at (0x61D6) volatile unsigned char CSPPROG22;
//#define CSPPROG23       XREG( 0x61D7 )
__xdata __at (0x61D7) volatile unsigned char CSPPROG23;
//#define _XREG61D8       XREG( 0x61D8 )
__xdata __at (0x61D8) volatile unsigned char _XREG61D8;
//#define _XREG61D9       XREG( 0x61D9 )
__xdata __at (0x61D9) volatile unsigned char _XREG61D9;
//#define _XREG61DA       XREG( 0x61DA )
__xdata __at (0x61DA) volatile unsigned char _XREG61DA;
//#define _XREG61DB       XREG( 0x61DB )
__xdata __at (0x61DB) volatile unsigned char _XREG61DB;
//#define _XREG61DC       XREG( 0x61DC )
__xdata __at (0x61DC) volatile unsigned char _XREG61DC;
//#define _XREG61DD       XREG( 0x61DD )
__xdata __at (0x61DD) volatile unsigned char _XREG61DD;
//#define _XREG61DE       XREG( 0x61DE )
__xdata __at (0x61DE) volatile unsigned char _XREG61DE ;
//#define _XREG61DF       XREG( 0x61DF )
__xdata __at (0x61DF) volatile unsigned char _XREG61DF ;
//#define CSPCTRL         XREG( 0x61E0 )
__xdata __at (0x61E0) volatile unsigned char CSPCTRL;
//#define CSPSTAT         XREG( 0x61E1 )
__xdata __at (0x61E1) volatile unsigned char CSPSTAT;
//#define CSPX            XREG( 0x61E2 )
__xdata __at (0x61E2) volatile unsigned char CSPX;
//#define CSPY            XREG( 0x61E3 )
__xdata __at (0x61E3) volatile unsigned char CSPY;
//#define CSPZ            XREG( 0x61E4 )
__xdata __at (0x61E4) volatile unsigned char CSPZ;
//#define CSPT            XREG( 0x61E5 )
__xdata __at (0x61E5) volatile unsigned char CSPT;
//#define _XREG61E6       XREG( 0x61E6 )
__xdata __at (0x61E6) volatile unsigned char _XREG61E6;
//#define _XREG61E7       XREG( 0x61E7 )
__xdata __at (0x61E7) volatile unsigned char _XREG61E7;
//#define _XREG61E8       XREG( 0x61E8 )
__xdata __at (0x61E8) volatile unsigned char _XREG61E8;
//#define _XREG61E9       XREG( 0x61E9 )
__xdata __at (0x61E9) volatile unsigned char _XREG61E9;
//#define _XREG61EA       XREG( 0x61EA )
__xdata __at (0x61EA) volatile unsigned char _XREG61EA;


/* Observability Control */
//#define RFC_OBS_CTRL0   XREG( 0x61EB )
__xdata __at (0x61EB) volatile unsigned char RFC_OBS_CTRL0;
//#define RFC_OBS_CTRL1   XREG( 0x61EC )
__xdata __at (0x61EC) volatile unsigned char RFC_OBS_CTRL1;
//#define RFC_OBS_CTRL2   XREG( 0x61ED )
__xdata __at (0x61ED) volatile unsigned char RFC_OBS_CTRL2 ;
//#define OBSSEL0         XREG( 0x6243 )
__xdata __at (0x6243) volatile unsigned char OBSSEL0;
//#define OBSSEL1         XREG( 0x6244 )
__xdata __at (0x6244) volatile unsigned char OBSSEL1;
//#define OBSSEL2         XREG( 0x6245 )
__xdata __at (0x6245) volatile unsigned char OBSSEL2;
//#define OBSSEL3         XREG( 0x6246 )
__xdata __at (0x6246) volatile unsigned char OBSSEL3;
//#define OBSSEL4         XREG( 0x6247 )
__xdata __at (0x6247) volatile unsigned char OBSSEL4;
//#define OBSSEL5         XREG( 0x6248 )
__xdata __at (0x6248) volatile unsigned char OBSSEL5;
//#define TR0             XREG( 0x624B )
__xdata __at (0x624B) volatile unsigned char TR0;

/* Chip Identification */
//#define CHVER           XREG( 0x6249 )
__xdata __at (0x6249) volatile unsigned char CHVER;
//#define CHIPID          XREG( 0x624A )
__xdata __at (0x624A) volatile unsigned char CHIPID;

/* Debug Interface DMA Write to Flash */
#define DBGDATA         XREG( 0x6260 )
__xdata __at (0x624A) volatile unsigned char CHIPID;

/* Flash Controller */
//#define FCTL            XREG( 0x6270 )
__xdata __at (0x6270) volatile unsigned char FCTL;
//#define FADDRL          XREG( 0x6271 )
__xdata __at (0x6271) volatile unsigned char FADDRL;
//#define FADDRH          XREG( 0x6272 )
__xdata __at (0x6272) volatile unsigned char FADDRH;
//#define FWDATA          XREG( 0x6273 )
__xdata __at (0x6273) volatile unsigned char FWDATA;
//#define _XREG6274       XREG( 0x6274 )
__xdata __at (0x6274) volatile unsigned char _XREG6274;
//#define _XREG6275       XREG( 0x6275 )
__xdata __at (0x6275) volatile unsigned char _XREG6275;

/* Chip Information */
//#define CHIPINFO0       XREG( 0x6276 )
__xdata __at (0x6276) volatile unsigned char CHIPINFO0;
//#define CHIPINFO1       XREG( 0x6277 )
__xdata __at (0x6277) volatile unsigned char CHIPINFO1;

/* Clock Loss Detector */
//#define CLD             XREG( 0x6290 )
__xdata __at (0x6290) volatile unsigned char CLD;

/* Timer 1 Channels (only mapped as XREG) */
//#define T1CCTL3         XREG( 0x62A3 )
__xdata __at (0x62A3) volatile unsigned char T1CCTL3;
//#define T1CCTL4         XREG( 0x62A4 )
__xdata __at (0x62A4) volatile unsigned char T1CCTL4;
//#define T1CC3L          XREG( 0x62AC )
__xdata __at (0x62AC) volatile unsigned char T1CC3L;
//#define T1CC3H          XREG( 0x62AD )
__xdata __at (0x62AD) volatile unsigned char T1CC3H ;
//#define T1CC4L          XREG( 0x62AE )
__xdata __at (0x62AE) volatile unsigned char T1CC4L;
//#define T1CC4H          XREG( 0x62AF )
__xdata __at (0x62AF) volatile unsigned char T1CC4H;
/* Definition which includes channels represented in SFR (additional XREG mapping of SFR) */
//#define XX_T1CCTL0      XREG( 0x62A0 )
__xdata __at (0x62A0) volatile unsigned char XX_T1CCTL0;
//#define XX_T1CCTL1      XREG( 0x62A1 )
__xdata __at (0x62A1) volatile unsigned char XX_T1CCTL1;
//#define XX_T1CCTL2      XREG( 0x62A2 )
__xdata __at (0x62A2) volatile unsigned char XX_T1CCTL2;
//#define XX_T1CCTL3      XREG( 0x62A3 )
__xdata __at (0x62A3) volatile unsigned char XX_T1CCTL3;
//#define XX_T1CCTL4      XREG( 0x62A4 )
__xdata __at (0x62A4) volatile unsigned char XX_T1CCTL4;
//#define XX_T1CC0L       XREG( 0x62A6 )
__xdata __at (0x62A6) volatile unsigned char XX_T1CC0L;
//#define XX_T1CC0H       XREG( 0x62A7 )
__xdata __at (0x62A7) volatile unsigned char XX_T1CC0H;
//#define XX_T1CC1L       XREG( 0x62A8 )
__xdata __at (0x62A8) volatile unsigned char XX_T1CC1L;
//#define XX_T1CC1H       XREG( 0x62A9 )
__xdata __at (0x62A9) volatile unsigned char XX_T1CC1H;
//#define XX_T1CC2L       XREG( 0x62AA )
__xdata __at (0x62AA) volatile unsigned char XX_T1CC2L;
//#define XX_T1CC2H       XREG( 0x62AB )
__xdata __at (0x62AB) volatile unsigned char XX_T1CC2H;
//#define XX_T1CC3L       XREG( 0x62AC )
__xdata __at (0x62AC) volatile unsigned char XX_T1CC3L;
//#define XX_T1CC3H       XREG( 0x62AD )
__xdata __at (0x62AD) volatile unsigned char XX_T1CC3H;
//#define XX_T1CC4L       XREG( 0x62AE )
__xdata __at (0x62AE) volatile unsigned char XX_T1CC4L ;
//#define XX_T1CC4H       XREG( 0x62AF )
__xdata __at (0x62AF) volatile unsigned char XX_T1CC4H;

/* Pointers for array access */
//#define P_T1CCTL        PXREG( 0x62A0 )
__xdata __at (0x62A0) volatile unsigned char P_T1CCTL;
//#define P_T1CC          PXREG( 0x62A6 )
__xdata __at (0x62A6) volatile unsigned char P_T1CC;

/* Sleep Timer Capture Control */
//#define STCC            XREG( 0x62B0 )
__xdata __at (0x62B0) volatile unsigned char STCC;
//#define STCS            XREG( 0x62B1 )
__xdata __at (0x62B1) volatile unsigned char STCS;
//#define STCV0           XREG( 0x62B2 )
__xdata __at (0x62B2) volatile unsigned char STCV0;
//#define STCV1           XREG( 0x62B3 )
__xdata __at (0x62B3) volatile unsigned char STCV1;
//#define STCV2           XREG( 0x62B4 )
__xdata __at (0x62B4) volatile unsigned char STCV2 ;

/* Op.Amp. Control */
//#define OPAMPC          XREG( 0x62C0 )
__xdata __at (0x62C0) volatile unsigned char OPAMPC;
//#define OPAMPS          XREG( 0x62C1 )
__xdata __at (0x62C1) volatile unsigned char OPAMPS;

/* Comparator Control */
//#define CMPCTL          XREG( 0x62D0 )
__xdata __at (0x62D0) volatile unsigned char CMPCTL;

/* ------------------------------------------------------------------------------------------------
 *                                      Xdata Mapped SFRs
 * ------------------------------------------------------------------------------------------------
 */

/*
 *   Most SFRs are also accessible through XDATA address space.  The register definitions for
 *   this type of access are listed below.  The register names are identical to the SFR names
 *   but with the prefix X_ to denote an XDATA register.
 *
 *   Some SFRs are not accessible through XDATA space.  For clarity, entries are included for these
 *   registers.  They have a prefix of _NA to denote "not available."
 *
 *   For register descriptions, refer to the actual SFR declartions elsewhere in this file.
 */

//#define X_P0        XREG( 0x7080 )   /*  Port 0. NOTE! Read-only access from XREG.          */
__xdata __at (0x7080) volatile unsigned char X_P0;
//#define _NA_SP      XREG( 0x7081 )
__xdata __at (0x7081) volatile unsigned char _NA_SP;
//#define _NA_DPL0    XREG( 0x7082 )
__xdata __at (0x7082) volatile unsigned char _NA_DPL0;
//#define _NA_DPH0    XREG( 0x7083 )
__xdata __at (0x7083) volatile unsigned char _NA_DPH0;
//#define _NA_DPL1    XREG( 0x7084 )
__xdata __at (0x7084) volatile unsigned char _NA_DPL1;
//#define _NA_DPH1    XREG( 0x7085 )
__xdata __at (0x7085) volatile unsigned char _NA_DPH1;
//#define X_U0CSR     XREG( 0x7086 )   /*  USART 0 Control and Status                         */
__xdata __at (0x7086) volatile unsigned char X_U0CSR;
//#define _NA_PCON    XREG( 0x7087 )
__xdata __at (0x7087) volatile unsigned char _NA_PCON;

//#define _NA_TCON    XREG( 0x7088 )
__xdata __at (0x7088) volatile unsigned char _NA_TCON;
//#define X_P0IFG     XREG( 0x7089 )   /*  Port 0 Interrupt Status Flag                       */
__xdata __at (0x7089) volatile unsigned char X_P0IFG;
//#define X_P1IFG     XREG( 0x708A )   /*  Port 1 Interrupt Status Flag                       */
__xdata __at (0x708A) volatile unsigned char X_P1IFG;
//#define X_P2IFG     XREG( 0x708B )   /*  Port 2 Interrupt Status Flag                       */
__xdata __at (0x708B) volatile unsigned char X_P2IFG;
//#define X_PICTL     XREG( 0x708C )   /*  Port Interrupt Control                             */
__xdata __at (0x708C) volatile unsigned char X_PICTL;
//#define X_P1IEN     XREG( 0x708D )   /*  Port 1 Interrupt Mask                              */
__xdata __at (0x708D) volatile unsigned char X_P1IEN;
//#define _NA_SFR8E   XREG( 0x708E )
__xdata __at (0x708E) volatile unsigned char _NA_SFR8E; 
//#define X_P0INP     XREG( 0x708F )   /*  Port 0 Input Mode                                  */
__xdata __at (0x708F) volatile unsigned char X_P0INP;

//#define X_P1        XREG( 0x7090 )   /*  Port 1. NOTE! Read-only access from XREG.          */
__xdata __at (0x7090) volatile unsigned char X_P1;
//#define X_RFIRQF1   XREG( 0x7091 )   /*  RF Interrupt Flags MSB                             */
__xdata __at (0x7091) volatile unsigned char X_RFIRQF1;
//#define _NA_DPS     XREG( 0x7092 )
__xdata __at (0x7092) volatile unsigned char _NA_DPS;
//#define X_MPAGE     XREG( 0x7093 )   /*  Memory Page Select                                 */
__xdata __at (0x7093) volatile unsigned char X_MPAGE;
//#define X_T2CTRL    XREG( 0x7094 )   /*  Timer2 Control Register                            */
__xdata __at (0x7094) volatile unsigned char X_T2CTRL;
//#define X_ST0       XREG( 0x7095 )   /*  Sleep Timer 0                                      */
__xdata __at (0x7095) volatile unsigned char X_ST0;
//#define X_ST1       XREG( 0x7096 )   /*  Sleep Timer 1                                      */
__xdata __at (0x7096) volatile unsigned char X_ST1;
//#define X_ST2       XREG( 0x7097 )   /*  Sleep Timer 2                                      */
__xdata __at (0x7097) volatile unsigned char X_ST2;

//#define _NA_S0CON   XREG( 0x7098 )
__xdata __at (0x7098) volatile unsigned char _NA_S0CON;
//#define _NA_SFR99   XREG( 0x7099 )
__xdata __at (0x7099) volatile unsigned char _NA_SFR99;
//#define _NA_IEN2    XREG( 0x709A )
__xdata __at (0x709A) volatile unsigned char _NA_IEN2;
//#define _NA_S1CON   XREG( 0x709B )
__xdata __at (0x709B) volatile unsigned char _NA_S1CON;
//#define X_T2CSPCFG  XREG( 0x709C )   /*  Timer2 CSP Interface Configuration (legacy name)   */
__xdata __at (0x709C) volatile unsigned char X_T2CSPCFG;
//#define X_T2EVTCFG  XREG( 0x709C )   /*  Timer2 Event Output Configuration                  */
__xdata __at (0x709C) volatile unsigned char X_T2EVTCFG;
//#define X_SLEEPSTA  XREG( 0x709D )   /*  Sleep Status                                       */
__xdata __at (0x709D) volatile unsigned char X_SLEEPSTA;
//#define X_CLKCONSTA XREG( 0x709E )   /*  Clock Control Status                               */
__xdata __at (0x709E) volatile unsigned char X_CLKCONSTA;
//#define X_FMAP      XREG( 0x709F )   /*  Flash Bank Map                                     */
__xdata __at (0x709F) volatile unsigned char X_FMAP;

//#define X_P2        XREG( 0x70A0 )   /*  Port 2. NOTE! Read-only access from XREG.          */
__xdata __at (0x70A0) volatile unsigned char X_P2;
//#define X_T2IRQF    XREG( 0x70A1 )   /*  Timer2 Interrupt Flags                             */
__xdata __at (0x70A1) volatile unsigned char X_T2IRQF;
//#define X_T2M0      XREG( 0x70A2 )   /*  Timer2 Multiplexed Register 0                      */
__xdata __at (0x70A2) volatile unsigned char X_T2M0;
//#define X_T2M1      XREG( 0x70A3 )   /*  Timer2 Multiplexed Register 1                      */
__xdata __at (0x70A3) volatile unsigned char X_T2M1;
//#define X_T2MOVF0   XREG( 0x70A4 )   /*  Timer2 Multiplexed Overflow Register 0             */
__xdata __at (0x70A4) volatile unsigned char X_T2MOVF0;
//#define X_T2MOVF1   XREG( 0x70A5 )   /*  Timer2 Multiplexed Overflow Register 1             */
__xdata __at (0x70A5) volatile unsigned char X_T2MOVF1;
//#define X_T2MOVF2   XREG( 0x70A6 )   /*  Timer2 Multiplexed Overflow Register 2             */
__xdata __at (0x70A6) volatile unsigned char X_T2MOVF2;
//#define X_T2IRQM    XREG( 0x70A7 )   /*  Timer2 Interrupt Mask                              */
__xdata __at (0x70A7) volatile unsigned char X_T2IRQM;

//#define _NA_IEN0    XREG( 0x70A8 )
__xdata __at (0x70A8) volatile unsigned char _NA_IEN0;
//#define _NA_IP0     XREG( 0x70A9 )
__xdata __at (0x70A9) volatile unsigned char _NA_IP0;
//#define _NA_SFRAA   XREG( 0x70AA )
__xdata __at (0x70AA) volatile unsigned char _NA_SFRAA;
//#define X_P0IEN     XREG( 0x70AB )   /*                                                     */
__xdata __at (0x70AB) volatile unsigned char X_P0IEN;
//#define X_P2IEN     XREG( 0x70AC )   /*                                                     */
__xdata __at (0x70AC) volatile unsigned char X_P2IEN;
//#define X_STLOAD    XREG( 0x70AD )   /*  Sleep Timer Load Status                            */
__xdata __at (0x70AD) volatile unsigned char X_STLOAD;
//#define X_PMUX      XREG( 0x70AE )   /*                                                     */
__xdata __at (0x70AE) volatile unsigned char X_PMUX;
//#define X_T1STAT    XREG( 0x70AF )   /*                                                     */
__xdata __at (0x70AF) volatile unsigned char X_T1STAT;

//#define _NA_SFRB0   XREG( 0x70A8 )
__xdata __at (0x70A8) volatile unsigned char _NA_SFRB0;
//#define X_ENCDI     XREG( 0x70B1 )   /*  Encryption Input Data                              */
__xdata __at (0x70B1) volatile unsigned char X_ENCDI;
//#define X_ENCDO     XREG( 0x70B2 )   /*  Encryption Output Data                             */
__xdata __at (0x70B2) volatile unsigned char X_ENCDO;
//#define X_ENCCS     XREG( 0x70B3 )   /*  Encryption Control and Status                      */
__xdata __at (0x70B3) volatile unsigned char X_ENCCS;
//#define X_ADCCON1   XREG( 0x70B4 )   /*  ADC Control 1                                      */
__xdata __at (0x70B4) volatile unsigned char X_ADCCON1;
//#define X_ADCCON2   XREG( 0x70B5 )   /*  ADC Control 2                                      */
__xdata __at (0x70B5) volatile unsigned char X_ADCCON2;
//#define X_ADCCON3   XREG( 0x70B6 )   /*  ADC Control 3                                      */
__xdata __at (0x70B6) volatile unsigned char X_ADCCON3;
//#define _NA_SFRB7   XREG( 0x70B7 )
__xdata __at (0x70B7) volatile unsigned char _NA_SFRB7;

//#define _NA_IEN1    XREG( 0x70B8 )
__xdata __at (0x70B8) volatile unsigned char _NA_IEN1;
//#define _NA_IP1     XREG( 0x70B9 )
__xdata __at (0x70B9) volatile unsigned char _NA_IP1;
//#define X_ADCL      XREG( 0x70BA )   /*  ADC Data Low                                       */
__xdata __at (0x70BA) volatile unsigned char X_ADCL;
//#define X_ADCH      XREG( 0x70BB )   /*  ADC Data High                                      */
__xdata __at (0x70BB) volatile unsigned char X_ADCH;
//#define X_RNDL      XREG( 0x70BC )   /*  Random Register Low Byte                           */
__xdata __at (0x70BC) volatile unsigned char X_RNDL;
//#define X_RNDH      XREG( 0x70BD )   /*  Random Register High Byte                          */
__xdata __at (0x70BD) volatile unsigned char X_RNDH;
//#define X_SLEEPCMD  XREG( 0x70BE )   /*  Sleep Mode Command                                 */
__xdata __at (0x70BE) volatile unsigned char X_SLEEPCMD;
//#define X_RFERRF    XREG( 0x70BF )   /*  RF Error Interrupt Flags                           */
__xdata __at (0x70BF) volatile unsigned char X_RFERRF;

//#define _NA_IRCON   XREG( 0x70C0 )
__xdata __at (0x70C0) volatile unsigned char _NA_IRCON;
//#define X_U0DBUF    XREG( 0x70C1 )   /*  USART 0 Receive/Transmit Data Buffer               */
__xdata __at (0x70C1) volatile unsigned char X_U0DBUF;
//#define X_U0BAUD    XREG( 0x70C2 )   /*  USART 0 Baud Rate Control                          */
__xdata __at (0x70C2) volatile unsigned char X_U0BAUD;
//#define X_T2MSEL    XREG( 0x70C3 )   /*  Timer2 Multiplex Select                            */
__xdata __at (0x70C3) volatile unsigned char X_T2MSEL;
//#define X_U0UCR     XREG( 0x70C4 )   /*  USART 0 UART Control                               */
__xdata __at (0x70C4) volatile unsigned char X_U0UCR;
//#define X_U0GCR     XREG( 0x70C5 )   /*  USART 0 Generic Control                            */
__xdata __at (0x70C5) volatile unsigned char X_U0GCR;
//#define X_CLKCONCMD XREG( 0x70C6 )   /*  Clock Control Command                              */
__xdata __at (0x70C6) volatile unsigned char X_CLKCONCMD;
//#define X_MEMCTR    XREG( 0x70C7 )   /*  Memory Arbiter Control                             */
__xdata __at (0x70C7) volatile unsigned char X_MEMCTR;

//#define _NA_SFRC8   XREG( 0x70C8 )
__xdata __at (0x70C8) volatile unsigned char _NA_SFRC8;
//#define X_WDCTL     XREG( 0x70C9 )   /*  Watchdog Timer Control                             */
__xdata __at (0x70C9) volatile unsigned char X_WDCTL;
//#define X_T3CNT     XREG( 0x70CA )   /*  Timer 3 Counter                                    */
__xdata __at (0x70CA) volatile unsigned char X_T3CNT;
//#define X_T3CTL     XREG( 0x70CB )   /*  Timer 3 Control                                    */
__xdata __at (0x70CB) volatile unsigned char X_T3CTL;
//#define X_T3CCTL0   XREG( 0x70CC )   /*  Timer 3 Channel 0 Capture/Compare Control          */
__xdata __at (0x70CC) volatile unsigned char X_T3CCTL0;
//#define X_T3CC0     XREG( 0x70CD )   /*  Timer 3 Channel 0 Capture/Compare Value            */
__xdata __at (0x70CD) volatile unsigned char X_T3CC0;
//#define X_T3CCTL1   XREG( 0x70CE )   /*  Timer 3 Channel 1 Capture/Compare Control          */
__xdata __at (0x70CE) volatile unsigned char X_T3CCTL1;
//#define X_T3CC1     XREG( 0x70CF )   /*  Timer 3 Channel 1 Capture/Compare Value            */
__xdata __at (0x70CF) volatile unsigned char X_T3CC1;

//#define _NA_PSW     XREG( 0x70D0 )
__xdata __at (0x70D0) volatile unsigned char _NA_PSW;
//#define X_DMAIRQ    XREG( 0x70D1 )   /*  DMA Interrupt Flag                                 */
__xdata __at (0x70D1) volatile unsigned char X_DMAIRQ;
//#define X_DMA1CFGL  XREG( 0x70D2 )   /*  DMA Channel 1-4 Configuration Address Low Byte     */
__xdata __at (0x70D2) volatile unsigned char X_DMA1CFGL;
//#define X_DMA1CFGH  XREG( 0x70D3 )   /*  DMA Channel 1-4 Configuration Address High Byte    */
__xdata __at (0x70D3) volatile unsigned char X_DMA1CFGH;
//#define X_DMA0CFGL  XREG( 0x70D4 )   /*  DMA Channel 0 Configuration Address Low Byte       */
__xdata __at (0x70D4) volatile unsigned char X_DMA0CFGL;
//#define X_DMA0CFGH  XREG( 0x70D5 )   /*  DMA Channel 0 Configuration Address High Byte      */
__xdata __at (0x70D5) volatile unsigned char X_DMA0CFGH;
//#define X_DMAARM    XREG( 0x70D6 )   /*  DMA Channel Arm                                    */
__xdata __at (0x70D6) volatile unsigned char X_DMAARM;
//#define X_DMAREQ    XREG( 0x70D7 )   /*  DMA Channel Start Request and Status               */
__xdata __at (0x70D7) volatile unsigned char X_DMAREQ;

//#define X_TIMIF     XREG( 0x70D8 )   /*  Timers 1/3/4 Interrupt Mask/Flag                   */
__xdata __at (0x70D8) volatile unsigned char X_TIMIF;
//#define X_RFD       XREG( 0x70D9 )   /*  RF Data                                            */
__xdata __at (0x70D9) volatile unsigned char X_RFD;
//#define X_T1CC0L    XREG( 0x70DA )   /*  Timer 1 Channel 0 Capture/Compare Value Low Byte   */
__xdata __at (0x70DA) volatile unsigned char X_T1CC0L;
//#define X_T1CC0H    XREG( 0x70DB )   /*  Timer 1 Channel 0 Capture/Compare Value High Byte  */
__xdata __at (0x70DB) volatile unsigned char X_T1CC0H;
//#define X_T1CC1L    XREG( 0x70DC )   /*  Timer 1 Channel 1 Capture/Compare Value Low Byte   */
__xdata __at (0x70DC) volatile unsigned char X_T1CC1L;
//#define X_T1CC1H    XREG( 0x70DD )   /*  Timer 1 Channel 1 Capture/Compare Value High Byte  */
__xdata __at (0x70DD) volatile unsigned char X_T1CC1H;
//#define X_T1CC2L    XREG( 0x70DE )   /*  Timer 1 Channel 2 Capture/Compare Value Low Byte   */
__xdata __at (0x70DE) volatile unsigned char X_T1CC2L ;
//#define X_T1CC2H    XREG( 0x70DF )   /*  Timer 1 Channel 2 Capture/Compare Value High Byte  */
__xdata __at (0x70DF) volatile unsigned char X_T1CC2H;

//#define _NA_ACC     XREG( 0x70E0 )
__xdata __at (0x70E0) volatile unsigned char _NA_ACC;
//#define X_RFST      XREG( 0x70E1 )   /*  RF Strobe                                          */
__xdata __at (0x70E1) volatile unsigned char X_RFST;
//#define X_T1CNTL    XREG( 0x70E2 )   /*  Timer 1 Counter Low                                */
__xdata __at (0x70E2) volatile unsigned char X_T1CNTL;
//#define X_T1CNTH    XREG( 0x70E3 )   /*  Timer 1 Counter High                               */
__xdata __at (0x70E3) volatile unsigned char X_T1CNTH;
//#define X_T1CTL     XREG( 0x70E4 )   /*  Timer 1 Control and Status                         */
__xdata __at (0x70E4) volatile unsigned char X_T1CTL;
//#define X_T1CCTL0   XREG( 0x70E5 )   /*  Timer 1 Channel 0 Capture/Compare Control          */
__xdata __at (0x70E5) volatile unsigned char X_T1CCTL0;
//#define X_T1CCTL1   XREG( 0x70E6 )   /*  Timer 1 Channel 1 Capture/Compare Control          */
__xdata __at (0x70E6) volatile unsigned char X_T1CCTL1;
//#define X_T1CCTL2   XREG( 0x70E7 )   /*  Timer 1 Channel 2 Capture/Compare Control          */
__xdata __at (0x70E7) volatile unsigned char X_T1CCTL2;

//#define _NA_IRCON2  XREG( 0x70E8 )
__xdata __at (0x70E8) volatile unsigned char _NA_IRCON2;
//#define X_RFIRQF0   XREG( 0x70E9 )   /*  RF Interrupt Flags MSB                             */
__xdata __at (0x70E9) volatile unsigned char X_RFIRQF0;
//#define X_T4CNT     XREG( 0x70EA )   /*  Timer 4 Counter                                    */
__xdata __at (0x70EA) volatile unsigned char X_T4CNT;
//#define X_T4CTL     XREG( 0x70EB )   /*  Timer 4 Control                                    */
__xdata __at (0x70EB) volatile unsigned char X_T4CTL;
//#define X_T4CCTL0   XREG( 0x70EC )   /*  Timer 4 Channel 0 Capture/Compare Control          */
__xdata __at (0x70EC) volatile unsigned char X_T4CCTL0;
//#define X_T4CC0     XREG( 0x70ED )   /*  Timer 4 Channel 0 Capture/Compare Value            */
__xdata __at (0x70ED) volatile unsigned char X_T4CC0;
//#define X_T4CCTL1   XREG( 0x70EE )   /*  Timer 4 Channel 1 Capture/Compare Control          */
__xdata __at (0x70EE) volatile unsigned char X_T4CCTL1;
//#define X_T4CC1     XREG( 0x70EF )   /*  Timer 4 Channel 1 Capture/Compare Value            */
__xdata __at (0x70EF) volatile unsigned char X_T4CC1;

//#define _NA_B       XREG( 0x70F0 )
__xdata __at (0x70F0) volatile unsigned char _NA_B;
//#define X_PERCFG    XREG( 0x70F1 )   /*  Peripheral Control                                 */
__xdata __at (0x70F1) volatile unsigned char X_PERCFG;
//#define X_ADCCFG    XREG( 0x70F2 )   /*  ADC Input Configuration (legacy name)              */
__xdata __at (0x70F2) volatile unsigned char X_ADCCFG;
//#define X_APCFG     XREG( 0x70F2 )   /*  Analog Periferal I/O Configuration                 */
__xdata __at (0x70F2) volatile unsigned char X_APCFG ;
//#define X_P0SEL     XREG( 0x70F3 )   /*  Port 0 Function Select                             */
__xdata __at (0x70F3) volatile unsigned char X_P0SEL;
//#define X_P1SEL     XREG( 0x70F4 )   /*  Port 1 Function Select                             */
__xdata __at (0x70F4) volatile unsigned char X_P1SEL;
//#define X_P2SEL     XREG( 0x70F5 )   /*  Port 2 Function Select                             */
__xdata __at (0x70F5) volatile unsigned char X_P2SEL;
//#define X_P1INP     XREG( 0x70F6 )   /*  Port 1 Input Mode                                  */
__xdata __at (0x70F6) volatile unsigned char X_P1INP;
//#define X_P2INP     XREG( 0x70F7 )   /*  Port 2 Input Mode                                  */
__xdata __at (0x70F7) volatile unsigned char X_P2INP;

//#define X_U1CSR     XREG( 0x70F8 )   /*  USART 1 Control and Status                         */
__xdata __at (0x70F8) volatile unsigned char X_U1CSR;
//#define X_U1DBUF    XREG( 0x70F9 )   /*  USART 1 Receive/Transmit Data Buffer               */
__xdata __at (0x70F9) volatile unsigned char X_U1DBUF;
//#define X_U1BAUD    XREG( 0x70FA )   /*  USART 1 Baud Rate Control                          */
__xdata __at (0x70FA) volatile unsigned char X_U1BAUD;
//#define X_U1UCR     XREG( 0x70FB )   /*  USART 1 UART Control                               */
__xdata __at (0x70FB) volatile unsigned char X_U1UCR;
//#define X_U1GCR     XREG( 0x70FC )   /*  USART 1 Generic Control                            */
__xdata __at (0x70FC) volatile unsigned char X_U1GCR;
//#define X_P0DIR     XREG( 0x70FD )   /*  Port 0 Direction                                   */
__xdata __at (0x70FD) volatile unsigned char X_P0DIR;
//#define X_P1DIR     XREG( 0x70FE )   /*  Port 1 Direction                                   */
__xdata __at (0x70FE) volatile unsigned char X_P1DIR;
//#define X_P2DIR     XREG( 0x70FF )   /*  Port 2 Direction                                   */
__xdata __at (0x70FF) volatile unsigned char X_P2DIR ;


__xdata __at (0x61FA) volatile unsigned char TXFILTCFG;
#define TXFILTCFG_RESET_VALUE         0x09





__sfr __at (0xC7) PSBANK;
//__sfr __at (0x9F) PSBANK;	//FMAP


/* ------------------------------------------------------------------------------------------------
 *                                       Flash
 * ------------------------------------------------------------------------------------------------
 */

//#define P_INFOPAGE  PXREG( 0x7800 )  /* Pointer to Start of Flash Information Page          */
__xdata __at (0x7800) volatile unsigned char P_INFOPAGE ;
//#define P_XBANK     PXREG( 0x8000 )  /* Pointer to Start of Selectable Flash Bank (XBANK)   */
__xdata __at (0x8000) volatile unsigned char P_XBANK ;

/**************************************************************************************************
 */
#endif

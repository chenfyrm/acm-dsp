/*****************************************************************************
* COPYRIGHT : (c) 2004 Bombardier Transportation
******************************************************************************
* PROJECT : DCU2 - MCU/LIB
**
MODULE : hw.h
**
ABSTRACT : This module makes definitions related to the hardware.
**
REMARKS :
*
******************************************************************************
HISTORY :
0.0.0.2 04-10-29 10:00 Bertil Soderberg
First version.
0.0.0.4 05-01-10 17:34 Bertil Soderberg
FPGA_BASE not dependent on MBAR.
0.0.0.8 05-02-03 14:56 Bertil Soderberg
FPGA-registers redefined according to FPGA1 Specification_050201.doc,
separate bitmasks for each register containing bit values.
0.0.1.1 05-03-16 16:18 Bertil Soderberg
FPGA-registers added to handle ADCs.
0.0.3.5 05-06-23 14:55 Bertil Soderberg
control bit MCU_OPTO2_ENABLE added in FPGA_OECR
0.0.3.9 05-09-15 16:24 Bertil Soderberg
START_OPTOBUFF_TEST changed to START_OPTOBUFF_TEST_N
0.0.4.1 05-09-29 11:24 Bertil Soderberg
Added definitions related to PSC communication to/from DSP.
0.0.4.3 05-11-18 10:36 Bertil Soderberg
New FPGA-register definitions added:
FPGA_DIEDR
FPGA_MPPDICR
FPGA_MPPDOSCR
FPGA_MPPDIEDR
FPGA_EBCR
0.0.4.4 05-11-23 15:45 Bertil Soderberg
ICTL_PSC6_MASK definition added
Following registers removed (I/O moved to i2c instead of FPGA1)
FPGA_MPPDICR
FPGA_MPPDOSCR
FPGA_MPPDIEDR
0.0.4.7 06-04-04 Anders Persson
FPGA register for Free Running Counter added
0.0.7.6 07-09-04 Anders Persson
New bits in Opto Enable Control Register
0.0.7.8 07-11-06 Anders Persson
New entry: Define size of area to copy dsp data
0.0.7.9 07-11-28 Anders Persson
New setup parameter: CDM_FDCR
3.0.0.0 09-02-20 Anders Persson
Legal owner: PPC Responsible unit: PPC/NE1SC Project: MCU2A
b
Responsible: Markus Pettersson
Changed: 2017-01-19
Projectdate: 2017-01-19 Language: en
Document type: Software diagram Doc. no.: 3EST000888-5401 MCXg3 DCUA ve 0.0.1.7.pdf Page: 934
End of line added at last row of the file
******************************************************************************/
/*****************************************************************************
* DEFINES
*/
#ifndef HW_H
#define HW_H
/*#define Intel*/
/* bit positions for MSB to LSB order of bits */
#define BIT0 (1 << 0)
#define BIT1 (1 << 1)
#define BIT2 (1 << 2)
#define BIT3 (1 << 3)
#define BIT4 (1 << 4)
#define BIT5 (1 << 5)
#define BIT6 (1 << 6)
#define BIT7 (1 << 7)
#define BIT8 (1 << 8)
#define BIT9 (1 << 9)
#define BIT10 (1 << 10)
#define BIT11 (1 << 11)
#define BIT12 (1 << 12)
#define BIT13 (1 << 13)
#define BIT14 (1 << 14)
#define BIT15 (1 << 15)
/* --------------------------------------------------------
definitions pertaining to the MCU
-------------------------------------------------------- */
/* base address for the main board */
#define MBAR 0x80000000
/* GPS Simple GPIO Data Output Values Register (see MPC5200 manual, 7.3.2.1.5) */
#define GPIO_CONF ((UINT32 *) (MBAR + 0x0B00))
#define GPIO_OUT ((UINT32 *) (MBAR + 0x0B10))
#define GPIO_IN ((UINT32 *) (MBAR + 0x0B14))
/* ICTL registers (see MPC5200 manual, 7.2.4) */
#define ICTL_PIMR ((UINT32 *) (MBAR + 0x0500))
#define ICTL_PISAR ((UINT32 *) (MBAR + 0x0530))
#define ICTL_PSC3_MASK 0x10000000
#define ICTL_PSC6_MASK 0x08000000
#define ICTL_CAN1_MASK 0x00004000
/* GPT x Enable and Mode Select Register (see MPC5200 manual, 7.4.4.1) */
#define GPT_BASE (MBAR + 0x0600) /* base address of the register */
#define GPT_IO(x) ((UINT32 *) (GPT_BASE + (x * 0x10)))
#define GPT_BASE_IN (MBAR + 0x060C) /* base address of the status register */
#define GPT_IN(x) ((UINT32 *) (GPT_BASE_IN + (x * 0x10)))
/* bit positions for setting and resetting bits in the GPT Enable and Mode Select Register */
#define GPT_BIT_SET 0x00000034
#define GPT_BIT_RESET 0x00000024
#define GPT_BIT_INPUT 0x00000004
/* bit position for input status in GPT_IN */
#define GPT_INPUT_MASK 0x00000100
/* register addresses for SPI handling (see MPC5200 manual, 17.3) */
#define SPI_CTRL1 ((UINT8 *) (MBAR + 0x0F00))
#define SPI_CTRL2 ((UINT8 *) (MBAR + 0x0F01))
#define SPI_BAUD ((UINT8 *) (MBAR + 0x0F04))
#define SPI_STATUS ((UINT8 *) (MBAR + 0x0F05))
#define SPI_DATA ((BYTE *) (MBAR + 0x0F09))
#define SPI_PDR ((UINT8 *) (MBAR + 0x0F0D))
#define SPI_DDR ((UINT8 *) (MBAR + 0x0F10))
/* register addresses for GPW Wakeup GPIO, used in SPI handling (see MPC5200 manual, 7.3.2.2) */
/* this solution is required with CPU-board rev p1 only */
#define GPW_EN ((UINT32 *) (MBAR + 0x0C00))
#define GPW_DDR ((UINT32 *) (MBAR + 0x0C08))
#define GPW_DATA ((UINT32 *) (MBAR + 0x0C0C))
/* --------------------------------------------------------
definitions pertaining to the PSC
(see chapter 15.2 in MPC5200 user manual)
-------------------------------------------------------- */
#define PSC3 (MBAR + 0x2400) /* base address of PSC3 */
#define PSC6 (MBAR + 0x2C00) /* base address of PSC6 */
/* registers to use in the PSCs */
#define PSC_MR1(x) ((UINT8 *) (PSC##x + 0x00)) /* mode register 1 */
#define PSC_MR2(x) ((UINT8 *) (PSC##x + 0x00)) /* mode register 2 */
#define PSC_SR(x) ((UINT16 *) (PSC##x + 0x04)) /* status register */
#define PSC_CR(x) ((UINT8 *) (PSC##x + 0x08)) /* command register */
#define PSC_RTB(x) ((UINT32 *) (PSC##x + 0x0C)) /* rx/tx buffer register */
#define PSC_IMR(x) ((UINT16 *) (PSC##x + 0x14)) /* interrupt mask register */
#define PSC_ISR(x) ((UINT16 *) (PSC##x + 0x14)) /* interrupt status register */
#define PSC_CTUR(x) ((UINT8 *) (PSC##x + 0x18)) /* counter timer upper register */
#define PSC_CCR(x) ((UINT16 *) (PSC##x + 0x20)) /* codec clock register */
#define PSC_SICR(x) ((UINT32 *) (PSC##x + 0x40)) /* serial interface control register */
#define PSC_RFNUM(x) ((UINT16 *) (PSC##x + 0x58)) /* rx fifo number of data */
#define PSC_TFNUM(x) ((UINT16 *) (PSC##x + 0x5C)) /* tx fifo number of data */
#define PSC_RFDATA(x) ((UINT32 *) (PSC##x + 0x60)) /* rx fifo data */
#define PSC_RFSTAT(x) ((UINT16 *) (PSC##x + 0x64)) /* rx fifo status */
#define PSC_RFCNTL(x) ((UINT8 *) (PSC##x + 0x68)) /* rx fifo control */
#define PSC_RFALARM(x) ((UINT16 *) (PSC##x + 0x6E)) /* rx fifo alarm */
#define PSC_TFDATA(x) ((UINT32 *) (PSC##x + 0x80)) /* tx fifo data */
#define PSC_TFSTAT(x) ((UINT16 *) (PSC##x + 0x84)) /* tx fifo status */
#define PSC_TFCNTL(x) ((UINT8 *) (PSC##x + 0x88)) /* tx fifo control */
#define PSC_TFALARM(x) ((UINT16 *) (PSC##x + 0x8E)) /* tx fifo alarm */
#define PSC3_MCR ((UINT32 *) (MBAR + 0x0230)) /* PSC3 Mclock Config Register */
#define PSC6_MCR ((UINT32 *) (MBAR + 0x0234)) /* PSC6 Mclock Config Register */
#define CDM_CER ((UINT32 *) (MBAR + 0x0214)) /* CDM Clock Enable Register */
#define CDM_FDCR ((UINT32 *) (MBAR + 0x0210)) /* CDM Fractional Divider Configuration Register */
#define PSC3_CLK 0x00000080 /* enable bit for PSC3-clock in CDM_CER */
#define PSC6_CLK 0x00000010 /* enable bit for PSC6-clock in CDM_CER */
/* --------------------------------------------------------
definitions pertaining to the MSCAN
(see chapter 19 in MPC5200 user manual)
-------------------------------------------------------- */
#define CAN1 (MBAR + 0x0900) /* base address of CAN1 */
/* registers to use */
#define CANCTL0 ((UINT8 *) (CAN1 + 0x00)) /* control register 0 */
#define RXFRM 0x80
#define SYNCH 0x10
#define INITRQ 0x01
#define CANCTL1 ((UINT8 *) (CAN1 + 0x01)) /* control register 1 */
#define CANE 0x80
#define CLKSRC 0x40
#define LOOPB 0x20
#define LISTEN 0x10
#define INITAK 0x01
#define CANBTR0 ((UINT8 *) (CAN1 + 0x04)) /* bus timing register 0 */
#define SJW 0xC0
#define BRP 0x3F
#define CANBTR1 ((UINT8 *) (CAN1 + 0x05)) /* bus timing register 1 */
#define TSEG2 0x70
#define TSEG1 0x0F
#define CANRFLG ((UINT8 *) (CAN1 + 0x08)) /* receiver flag register */
#define CSCIF 0x40
#define RSTAT 0x30
#define TSTAT 0x0C
#define RXF 0x01
#define CANRIER ((UINT8 *) (CAN1 + 0x09)) /* receiver interrupt enable register */
#define RXFIE 0x01
#define CANTFLG ((UINT8 *) (CAN1 + 0x0C)) /* transmitter flag register */
#define TXE 0x07
#define CANTBSEL ((UINT8 *) (CAN1 + 0x14)) /* transmit buffer selection register */
#define TX 0x07
#define CANIDAC ((UINT8 *) (CAN1 + 0x15)) /* ID acceptance control register */
#define CANIDAR0 ((UINT8 *) (CAN1 + 0x20)) /* ID acceptance register */
#define CANIDAR1 ((UINT8 *) (CAN1 + 0x21)) /* ID acceptance register */
#define CANIDMR0 ((UINT8 *) (CAN1 + 0x28)) /* ID mask register */
#define CANIDMR1 ((UINT8 *) (CAN1 + 0x29)) /* ID mask register */
#define CANRIDR0 ((UINT8 *) (CAN1 + 0x40)) /* receive buffer: identifier register 0 */
#define CANRIDR1 ((UINT8 *) (CAN1 + 0x41)) /* receive buffer: identifier register 1 */
#define SRR 0x10
#define IDE 0x80
#define CANRDSR0 ((UINT8 *) (CAN1 + 0x48)) /* receive buffer: data segment register 0 */
#define CANRDSR1 ((UINT8 *) (CAN1 + 0x49)) /* receive buffer: data segment register 1 */
#define CANRDSR2 ((UINT8 *) (CAN1 + 0x4C)) /* receive buffer: data segment register 2 */
#define CANRDSR3 ((UINT8 *) (CAN1 + 0x4D)) /* receive buffer: data segment register 3 */
#define CANRDSR4 ((UINT8 *) (CAN1 + 0x50)) /* receive buffer: data segment register 4 */
#define CANRDSR5 ((UINT8 *) (CAN1 + 0x51)) /* receive buffer: data segment register 5 */
#define CANRDSR6 ((UINT8 *) (CAN1 + 0x54)) /* receive buffer: data segment register 6 */
#define CANRDSR7 ((UINT8 *) (CAN1 + 0x55)) /* receive buffer: data segment register 7 */
#define CANRDLR ((UINT8 *) (CAN1 + 0x58)) /* receive buffer: data length register */
#define CANRTBPR ((UINT8 *) (CAN1 + 0x59)) /* receive buffer: receive buffer priority register */
#define CANTIDR0 ((UINT8 *) (CAN1 + 0x60)) /* transmit buffer: identifier register 0 */
#define CANTIDR1 ((UINT8 *) (CAN1 + 0x61)) /* transmit buffer: identifier register 1 */
#define CANTDSR0 ((UINT8 *) (CAN1 + 0x68)) /* transmit buffer: data segment register 0 */
#define CANTDSR1 ((UINT8 *) (CAN1 + 0x69)) /* transmit buffer: data segment register 1 */
#define CANTDSR2 ((UINT8 *) (CAN1 + 0x6C)) /* transmit buffer: data segment register 2 */
#define CANTDSR3 ((UINT8 *) (CAN1 + 0x6D)) /* transmit buffer: data segment register 3 */
#define CANTDSR4 ((UINT8 *) (CAN1 + 0x70)) /* transmit buffer: data segment register 4 */
#define CANTDSR5 ((UINT8 *) (CAN1 + 0x71)) /* transmit buffer: data segment register 5 */
#define CANTDSR6 ((UINT8 *) (CAN1 + 0x74)) /* transmit buffer: data segment register 6 */
#define CANTDSR7 ((UINT8 *) (CAN1 + 0x75)) /* transmit buffer: data segment register 7 */
#define CANTDLR ((UINT8 *) (CAN1 + 0x78)) /* transmit buffer: data length register */
#define CANTTBPR ((UINT8 *) (CAN1 + 0x79)) /* transmit buffer: transmit buffer priority register */
/* --------------------------------------------------------
definitions pertaining to the I2C
-------------------------------------------------------- */
#define I2C_BUS1 0
#define I2C_BUS2 1
#define I2C_PORT0 0
#define I2C_PORT1 1
/* addresses of available I2C units on bus 1
*/
#define I2C_CPU_VERSION 0x20 /* CPU - PCA9500 I/O: board version */
#define I2C_CPU_ICM1 0x50 /* CPU - PCA9500 ICM: memory */
#define I2C_CPU_MVB 0x22 /* CPU - PCA9500 I/O: MVBC */
#define I2C_CPU_ICM2 0x52 /* CPU - PCA9500 ICM: memory */
#define I2C_TEMP 0x48 /* CPU - LM75: onboard temp sensor */
#define I2C_FOB_VERSION 0x23 /* FOB - PCA9500 I/O: board version + I/O */
#define I2C_FOB1 0x2C /* FOB - AD5253: current references */
#define I2C_FOB2 0x2D /* FOB - AD5253: current references */
#define I2C_FOB3 0x2E /* FOB - AD5253: current references */
/* addresses of available I2C units on bus 2
*/
#define I2C_BIOB_IO1 0x22 /* BIOB - PCA9555: general I/O */
#define I2C_BIOB_VERSION 0x25 /* BIOB - PCA9500: board version + start mode */
#define I2C_BIOB_ICM1 0x55 /* BIOB - PCA9500: memory */
#define I2C_BIOB_IO2 0x26 /* BIOB - PCA9500: I/O */
#define I2C_BIOB_ICM2 0x56 /* BIOB - PCA9500: memory */
#define I2C_CLOCK 0x51 /* BIOB - RTC-8564: realtime clock */
#define I2C_HPPFOB_VERSION 0x23 /* HPPFOB - PCA9500 I/O: board version + I/O */
#define I2C_HPPFOB_ICM 0x53 /* HPPFOB - PCA9500 ICM: memory */
#define I2C_HPPFOB_CREF1 0x2C /* HPPFOB - AD5253: current references */
#define I2C_HPPFOB_CREF2 0x2D /* HPPFOB - AD5253: current references */
#define I2C_HPPFOB_CREF3 0x2E /* HPPFOB - AD5253: current references */
#define I2C_HPPEXB_VERSION 0x24 /* HPPEXB - PCA9500 I/O: board version + I/O */
#define I2C_HPPEXB_ICM 0x54 /* HPPEXB - PCA9500 ICM: memory */
#define I2C_MPPEXB_IO 0x74 /* MPPEXB - PCA9539: I/O */
/* definitions for unit PCA9555
*/
/* bitmasks for port 0
#define LAMPTEST_N BIT0
#define SW_OK BIT1
#define ERROR_N BIT2
#define WARNING BIT3
*/
/* definitions for PCA9500, I2C_HPPFOB_VERSION
*/
#define PAIR8_BCR_N BIT7
/* definitions for PCA9500, I2C_BIOB_IO2
*/
#define OPTOBUFF_TEST BIT0
#define SP_01_15V_RES BIT1
#define SP_02_15V_RES BIT2
#define START_OPTOBUFF_TEST_N BIT3
#define AIN_TEST_N BIT4
/* definitions for PCA9500, I2C_HPPEXB_VERSION
*/
#define SP43_15V_RES_N BIT5
#define SP44_15V_RES_N BIT6
#define HPP_AIN_TEST_N BIT7
/* definitions for PCA9539, I2C_MPPEXB_IO
*/
#define PCA9539_IN 0
#define PCA9539_OUT 2
#define PCA9539_CFG 6

/* --------------------------------------------------------
definitions pertaining to the DSP
-------------------------------------------------------- */
#ifdef WIN32
#define DSP_BASE 0x00373000 /* NB! TEMP VALUES for test purposes! */
#else
#define DSP_BASE 0x98000000
#endif
/* define DSP host port interface registers */
#define DSP_HPI_CONTROL ((volatile UINT32 *) (DSP_BASE + 0x00))
#define DSP_HPI_ADDRESS ((volatile UINT32 *) (DSP_BASE + 0x04))
#define DSP_HPI_DATA_AUTOINC ((volatile UINT32 *) (DSP_BASE + 0x08))
#define DSP_HPI_DATA_FIXED ((volatile UINT32 *) (DSP_BASE + 0x0C))
/* define sizes of the signal buffers */
#define DSP_HSTOMC_ENTRIES 128
#define DSP_HSTIMC_ENTRIES 128
#define DSP_HSTPMC_ENTRIES 512
/* define size of area to copy dsp data */
#define DSP_COPY_SIZE 28
/* --------------------------------------------------------
definitions pertaining to the FPGA
-------------------------------------------------------- */
#ifdef WIN32
#define FPGA_BASE 0x00372000 /* NB! TEMP VALUES for test purposes! */
#else
#define FPGA_BASE 0x90000000
#endif
/* bit positions for the different output pins in GPIO_OUT, related to
FPGA2-programming & linetrip control
*/
#define LTRIP_EN_N 0x00000001
#define FPGA2CFG_DONE 0x00000002
#define FPGA2CFG_PROG_N 0x00000004
#define FPGA2CFG_INIT_N 0x00000008
/* define FPGA registers
*/
/* Reset Cause Register
This register shows the latest reset cause. The register is only cleared
during FPGA conguration. A power-on reset is indicated as all reset causes
except RC_HRESET cleared. RC_HRESET can be either high or low after a
power-on reset.
*/
#define FPGA_RCR ((UINT16 *) (FPGA_BASE + 0x00))
#define RC_DSP_HWS BIT7
#define RC_MCU_HWIN BIT6
#define RC_MCU_HWS BIT5
#define RC_MAN_RESIN BIT4
#define RC_MCU_WD_ALARM BIT3
#define RC_CLK33M_ERROR BIT2
#define RC_CLK100M_ERROR BIT1
#define RC_HRESET BIT0
/* Reset Enable Register
Reset due to CLK100M_ERROR will be disabled after a reset. CLK100M isn't
valid before the DSP and FPGA2 have been configured. The MCU should set
the RE_CLK100M_ERROR bit high after the DSP and FPGA2 have been configured
to enable reset due to CLK100M_ERROR.
*/
#define FPGA_RER ((UINT16 *) (FPGA_BASE + 0x02))
#define RE_CLK100M_ERROR BIT0
/* Power Supply Shutdown
A write (any data is valid) to this register will turn off +24V supply on
the Base I/O board.
*/
#define FPGA_PSS ((UINT16 *) (FPGA_BASE + 0x10))
/* MCU HWIN
A write (any data is valid) to this register will result in a HW
reinitialisation.
*/
#define FPGA_MHWIN ((UINT16 *) (FPGA_BASE + 0x12))
/* MCU HWS
A write (any data is valid) to this register will result in a HW
shutdown.
*/
#define FPGA_MHWS ((UINT16 *) (FPGA_BASE + 0x14))
/* MCU Watchdog Trigger
A write (any data is valid) to this register will reset the MCU watchdog
timer.
*/
#define FPGA_MWT ((UINT16 *) (FPGA_BASE + 0x16))
/* MCU FS
A write (any data is valid) to this register will result in a FS.
*/
#define FPGA_FS ((UINT16 *) (FPGA_BASE + 0x18))
/* Peripheral Reset Control Register
After reset, all peripherals remain reset until the MCU releases reset by
writing to this register. Write low to a bit to release reset of
corresponding peripheral.
*/
#define FPGA_PRCR ((UINT16 *) (FPGA_BASE + 0x20))
#define IP_RESET BIT3
#define MVBC_RESET BIT2
#define FPGA2_RESET BIT1
#define DSP_RESET BIT0
/* Line Trip Relay Control Register
*/
#define FPGA_LTRCR ((UINT16 *) (FPGA_BASE + 0x22))
#define LT_RELAY_FB BIT2
#define FPGA2_LT_ON BIT1
#define MCU_LT_ON BIT0
/* Opto Enable Control Register
*/
#define FPGA_OECR ((UINT16 *) (FPGA_BASE + 0x24))
#define MCU_FB_ERR_RESET BIT8
#define FB_5V_PAIR_1_6_ERR BIT7
#define OPTO_ENABLE_FB_ERR BIT6
#define FB_5V_PAIR_1_6 BIT5
#define FB_5V_PAIR BIT4
#define OPTO2_MOUNT BIT3
#define OPTO_ENABLE_FB2 BIT2
#define OPTO_ENABLE_FB BIT1
#define MCU_OPTO_ENABLE BIT0
/* TRAC_SAFE_EN Status Register
*/
#define FPGA_TSESR ((UINT16 *) (FPGA_BASE + 0x26))
#define TRAC_SAFE_EN2 BIT1
#define TRAC_SAFE_EN1 BIT0
/* Jumper Status Register
*/
#define FPGA_JSR ((UINT16 *) (FPGA_BASE + 0x28))
#define JUMPER5 BIT2
#define MVB_EMD_ON BIT1
#define MCU_WD_DISABLED BIT0
/* IP Module Status Register
*/
#define FPGA_IMSR ((UINT16 *) (FPGA_BASE + 0x2A))
#define IP_ERROR BIT0
/* Turn on power supply for the GDU units on HPP
*/
#define FPGA_PSUON ((UINT16 *) (FPGA_BASE + 0x2C))
#define PSU_ON BIT0
/* Turn on power supply for the GDU units on HPP
*/
#define FPGA_COOLLEVEL ((UINT16 *) (FPGA_BASE + 0x2E))
#define COOL_LEVEL BIT0
/* Interrupt Enable Register 0
Set IE_xx high to enable interrupt generation on MCU IRQ0 pin.
*/
#define FPGA_IER0 ((UINT16 *) (FPGA_BASE + 0x30))
#define IE_BUS_WD_ALARM BIT2
#define IE_DIPF_GDU BIT1
#define IE_PFAIL BIT0
/* Interrupt Enable Register 2
Set IE_xx high to enable interrupt generation on MCU IRQ2 pin.
*/
#define FPGA_IER2 ((UINT16 *) (FPGA_BASE + 0x34))
#define IE_MVB_INT1 BIT1
#define IE_MVB_INT0 BIT0
/* Interrupt Enable Register 3
Set IE_xx high to enable interrupt generation on MCU IRQ3 pin.
*/
#define FPGA_IER3 ((UINT16 *) (FPGA_BASE + 0x36))
#define IE_IP_INT1 BIT1
#define IE_IP_INT0 BIT0
/* Interrupt Status Register 0
After an interrupt request on MCU IRQ0 this register indicates the
interrupt cause. The register is cleared when read.
*/
#define FPGA_ISR0 ((UINT16 *) (FPGA_BASE + 0x38))
#define IS_BUS_WD_ALARM BIT2
#define IS_DIPF_GDU BIT1
#define IS_PFAIL BIT0
/* Interrupt Status Register 2
After an interrupt request on MCU IRQ2 this register indicates the
interrupt cause. The register is cleared when read.
*/
#define FPGA_ISR2 ((UINT16 *) (FPGA_BASE + 0x3C))
#define IS_MVB_INT1 BIT1
#define IS_MVB_INT0 BIT0
/* Interrupt Status Register 3
After an interrupt request on MCU IRQ3 this register indicates the
interrupt cause. The register is cleared when read.
*/
#define FPGA_ISR3 ((UINT16 *) (FPGA_BASE + 0x3E))
#define IS_IP_INT1 BIT1
#define IS_IP_INT0 BIT0
/* Supervision Register 0
*/
#define FPGA_SR0 ((UINT16 *) (FPGA_BASE + 0x40))
#define R50_CLK66_DEV BIT15
#define R50_CLK48_DEV BIT14
#define R50_CLK33_DEV BIT13
#define R50_CLK25_DEV BIT12
#define R48_CLK66_DEV BIT11
#define R48_CLK50_DEV BIT10
#define R48_CLK33_DEV BIT9
#define R48_CLK25_DEV BIT8
#define R33_CLK66_DEV BIT7
#define R33_CLK50_DEV BIT6
#define R33_CLK48_DEV BIT5
#define R33_CLK25_DEV BIT4
#define R25_CLK66_DEV BIT3
#define R25_CLK50_DEV BIT2
#define R25_CLK48_DEV BIT1
#define R25_CLK33_DEV BIT0
/* Supervision Register 1
*/
#define FPGA_SR1 ((UINT16 *) (FPGA_BASE + 0x42))
#define R66_CLK50_DEV BIT3
#define R66_CLK48_DEV BIT2
#define R66_CLK33_DEV BIT1
#define R66_CLK25_DEV BIT0
/* Supervision Register 2
*/
#define FPGA_SR2 ((UINT16 *) (FPGA_BASE + 0x44))
#define DSP_WD_ALARM BIT8
#define P15V_SPEED4_FAIL BIT7
#define P15V_SPEED3_FAIL BIT6
#define P15V_SPEED2_FAIL BIT5
#define P15V_SPEED1_FAIL BIT4
#define M15V_LOW BIT3
#define P15V_LOW BIT2
#define P5V_P3P3V_LOW BIT1
#define CLK25M_ERROR BIT0
/* Timeout time for DSP watchdog (between 0 and 4095 usecs)
*/
#define FPGA_USECS ((UINT16 *) (FPGA_BASE + 0x48))
/* Digital Input Status Register
*/
#define FPGA_DISR ((UINT16 *) (FPGA_BASE + 0x50))
#define DI05 BIT4
#define DI04 BIT3
#define DI03 BIT2
#define DI02 BIT1
#define DI01 BIT0
/* Digital Output Control/Status Register
*/
#define FPGA_DOCSR ((UINT16 *) (FPGA_BASE + 0x52))
#define DO_ENABLE BIT15
#define DO07_FB BIT14
#define DO06_FB BIT13
#define DO05_FB BIT12
#define DO04_FB BIT11
#define DO03_FB BIT10
#define DO02_FB BIT9
#define DO01_FB BIT8
#define DO07 BIT6
#define DO06 BIT5
#define DO05 BIT4
#define DO04 BIT3
#define DO03 BIT2
#define DO02 BIT1
#define DO01 BIT0
/* Digital Input Edge Detect Register
*/
#define FPGA_DIEDR ((UINT16 *) (FPGA_BASE + 0x54))
#define DI05_ED BIT4
#define DI04_ED BIT3
#define DI03_ED BIT2
#define DI02_ED BIT1
#define DI01_ED BIT0
/* ADC 11 configuration register
*/
#define FPGA_ADC11CR ((UINT16 *) (FPGA_BASE + 0x60))
#define ADC_C7 (BIT14 | BIT15)
#define ADC_C6 (BIT12 | BIT13)
#define ADC_C5 (BIT10 | BIT11)
#define ADC_C4 (BIT8 | BIT9)
#define ADC_C3 (BIT6 | BIT7)
#define ADC_C2 (BIT4 | BIT5)
#define ADC_C1 (BIT2 | BIT3)
#define ADC_C0 (BIT0 | BIT1)
/* ADC 12 configuration register
*/
#define FPGA_ADC12CR ((UINT16 *) (FPGA_BASE + 0x62))
/* ADC 13 configuration register
*/
#define FPGA_ADC13CR ((UINT16 *) (FPGA_BASE + 0x64))
/* ADC 14 configuration register
*/
#define FPGA_ADC14CR ((UINT16 *) (FPGA_BASE + 0x66))
/* shortcuts to the available ADCs
*/
#define ADC11 11
#define ADC12 12
#define ADC13 13
#define ADC14 14
/* ADC 11, channels 0-7, data register
bit 15 contains eventual sign bit, bits 14-3 is the raw data, bits 2-0 always zero
*/
#define FPGA_ADC11_0 ((UINT16 *) (FPGA_BASE + 0x70))
#define FPGA_ADC11_1 ((UINT16 *) (FPGA_BASE + 0x72))
#define FPGA_ADC11_2 ((UINT16 *) (FPGA_BASE + 0x74))
#define FPGA_ADC11_3 ((UINT16 *) (FPGA_BASE + 0x76))
#define FPGA_ADC11_4 ((UINT16 *) (FPGA_BASE + 0x78))
#define FPGA_ADC11_5 ((UINT16 *) (FPGA_BASE + 0x7A))
#define FPGA_ADC11_6 ((UINT16 *) (FPGA_BASE + 0x7C))
#define FPGA_ADC11_7 ((UINT16 *) (FPGA_BASE + 0x7E))
/* ADC 12, channels 0-7, data register
bit 15 contains eventual sign bit, bits 14-3 is the raw data, bits 2-0 always zero
*/
#define FPGA_ADC12_0 ((UINT16 *) (FPGA_BASE + 0x80))
#define FPGA_ADC12_1 ((UINT16 *) (FPGA_BASE + 0x82))
#define FPGA_ADC12_2 ((UINT16 *) (FPGA_BASE + 0x84))
#define FPGA_ADC12_3 ((UINT16 *) (FPGA_BASE + 0x86))
#define FPGA_ADC12_4 ((UINT16 *) (FPGA_BASE + 0x88))
#define FPGA_ADC12_5 ((UINT16 *) (FPGA_BASE + 0x8A))
#define FPGA_ADC12_6 ((UINT16 *) (FPGA_BASE + 0x8C))
#define FPGA_ADC12_7 ((UINT16 *) (FPGA_BASE + 0x8E))
/* ADC 13, channels 0-7, data register
bit 15 contains eventual sign bit, bits 14-3 is the raw data, bits 2-0 always zero
*/
#define FPGA_ADC13_0 ((UINT16 *) (FPGA_BASE + 0x90))
#define FPGA_ADC13_1 ((UINT16 *) (FPGA_BASE + 0x92))
#define FPGA_ADC13_2 ((UINT16 *) (FPGA_BASE + 0x94))
#define FPGA_ADC13_3 ((UINT16 *) (FPGA_BASE + 0x96))
#define FPGA_ADC13_4 ((UINT16 *) (FPGA_BASE + 0x98))
#define FPGA_ADC13_5 ((UINT16 *) (FPGA_BASE + 0x9A))
#define FPGA_ADC13_6 ((UINT16 *) (FPGA_BASE + 0x9C))
#define FPGA_ADC13_7 ((UINT16 *) (FPGA_BASE + 0x9E))
/* ADC 14, channels 0-7, data register
bit 15 contains eventual sign bit, bits 14-3 is the raw data, bits 2-0 always zero
*/
#define FPGA_ADC14_0 ((UINT16 *) (FPGA_BASE + 0xA0))
#define FPGA_ADC14_1 ((UINT16 *) (FPGA_BASE + 0xA2))
#define FPGA_ADC14_2 ((UINT16 *) (FPGA_BASE + 0xA4))
#define FPGA_ADC14_3 ((UINT16 *) (FPGA_BASE + 0xA6))
#define FPGA_ADC14_4 ((UINT16 *) (FPGA_BASE + 0xA8))
#define FPGA_ADC14_5 ((UINT16 *) (FPGA_BASE + 0xAA))
#define FPGA_ADC14_6 ((UINT16 *) (FPGA_BASE + 0xAC))
#define FPGA_ADC14_7 ((UINT16 *) (FPGA_BASE + 0xAE))
/* Expansion board configuration register
*/
#define FPGA_EBCR ((UINT16 *) (FPGA_BASE + 0xB0))
/* Free running counter
*/
#define FPGA_FRC ((UINT16 *) (FPGA_BASE + 0xC0))
/* FPGA FW Revision register
*/
#define FPGA_FWREG ((UINT16 *) (FPGA_BASE + 0xF2))
/* --------------------------------------------------------
other definitions
-------------------------------------------------------- */
#define SET 1
#define RESET 2
#endif

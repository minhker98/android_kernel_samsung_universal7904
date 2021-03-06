#ifndef __CMUCAL_NODE_H__
#define __CMUCAL_NODE_H__

#include "../cmucal.h"

/*=================CMUCAL version: LASSEN================================*/

enum clk_id {
	OSCCLK_APM = FIXED_RATE_TYPE,
	OSCCLK_CAM,
	OSCCLK_CMU,
	OSCCLK_CORE,
	OSCCLK_CPUCL0,
	OSCCLK_CPUCL1,
	OSCCLK_CPUCL2,
	OSCCLK_DISPAUD,
	IOCLK_AUDIOCDCLK0,
	IOCLK_AUDIOCDCLK2,
	IOCLK_AUDIOCDCLK3,
	CLK_DEBUG_DECON0,
	TICK_USB,
	OSCCLK_FSYS,
	USB20_0_PHY_CLOCK,
	USB30_PHY_0_RX0CLK,
	USB30_PHY_0_TX0CLKOUT,
	USB30_PHY_1_RX0CLK,
	USB30_PHY_1_TX0CLKOUT,
	OSCCLK_G3D,
	OSCCLK_ISP,
	OSCCLK_MFCMSCL,
	OSCCLK_MIF,
	OSCCLK_MIF1,
	OSCCLK_PERI,
	end_of_fixed_rate,
	num_of_fixed_rate = end_of_fixed_rate - FIXED_RATE_TYPE,

	CLK_MIF_BUSD = FIXED_FACTOR_TYPE,
	CLK_MIF1_BUSD,
	end_of_fixed_factor,
	num_of_fixed_factor = end_of_fixed_factor - FIXED_FACTOR_TYPE,

	PLL_SHARED0 = PLL_TYPE,
	PLL_SHARED1,
	PLL_CPUCL0,
	PLL_CPUCL1,
	PLL_CPUCL2,
	PLL_AUD,
	PLL_USB,
	PLL_G3D,
	PLL_MIF,
	PLL_MIF1,
	end_of_pll,
	num_of_pll = end_of_pll - PLL_TYPE,

	MUX_CLKCMU_MFCMSCL_MSCL = MUX_TYPE,
	MUX_CLKCMU_MFCMSCL_MFC,
	MUX_CLKCMU_DISPAUD_BUS,
	MUX_CLKCMU_FSYS_BUS,
	MUX_CLKCMU_FSYS_MMC_EMBD,
	MUX_CLKCMU_PERI_BUS,
	MUX_CLKCMU_PERI_UART_0,
	MUX_CLKCMU_PERI_UART_1,
	MUX_CLKCMU_PERI_USI2,
	MUX_CLKCMU_PERI_SPI_0,
	MUX_CLKCMU_PERI_SPI_1,
	MUX_CLKCMU_FSYS_MMC_CARD,
	MUX_CLKCMU_CIS_CLK0,
	MUX_CLKCMU_CIS_CLK1,
	MUX_CLKCMU_CIS_CLK2,
	MUX_CLKCMU_PERI_USI0,
	MUX_CLKCMU_PERI_USI1,
	MUX_CMU_CMUREF,
	MUX_CLK_CMU_CMUREF,
	MUX_CLKCMU_APM_BUS,
	MUX_CLKCMU_FSYS_MMC_SDIO,
	MUX_CLKCMU_PERI_UART_2,
	MUX_CLKCMU_FSYS_USB30DRD,
	MUX_CLKCMU_CORE_CCI,
	MUX_CLKCMU_CORE_G3D,
	MUX_CLKCMU_CORE_BUS,
	MUX_CLKCMU_MIF_BUSP,
	MUX_CLKCMU_CAM_BUS,
	MUX_CLKCMU_ISP_BUS,
	MUX_CLKCMU_ISP_GDC,
	MUX_CLKCMU_ISP_VRA,
	MUX_CLKCMU_MIF_SWITCH,
	MUX_CLKCMU_DISPAUD_CPU,
	MUX_CLK_ISP_LOWFREQ,
	MUX_CLK_CORE_GIC,
	MUX_CLK_CPUCL0_PLL,
	MUX_CLK_CPUCL1_PLL,
	MUX_CLK_CPUCL2_PLL,
	MUX_CLK_AUD_CPU,
	MUX_CLK_AUD_UAIF0,
	MUX_CLK_AUD_UAIF2,
	MUX_CLK_AUD_UAIF3,
	MUX_CLK_AUD_CPU_HCH,
	MUX_CLK_AUD_FM,
	MUX_CLK_G3D_BUSD,
	MUX_CLK_MIF_DDRPHY_CLK2X,
	MUX_MIF_CMUREF,
	MUX_CLK_MIF1_DDRPHY_CLK2X,
	MUX_MIF1_CMUREF,
	APM_CMU_CLKOUT0,
	APM_CMU_CLKOUT1,
	CAM_CMU_CLKOUT0,
	CAM_CMU_CLKOUT1,
	CMU_CMU_CLKOUT0,
	CMU_CMU_CLKOUT1,
	CORE_CMU_CLKOUT0,
	CORE_CMU_CLKOUT1,
	CPUCL0_CMU_CLKOUT0,
	CPUCL0_CMU_CLKOUT1,
	CPUCL1_CMU_CLKOUT1,
	CPUCL1_CMU_CLKOUT0,
	CPUCL2_CMU_CLKOUT0,
	CPUCL2_CMU_CLKOUT1,
	DISPAUD_CMU_CLKOUT0,
	DISPAUD_CMU_CLKOUT1,
	FSYS_CMU_CLKOUT0,
	FSYS_CMU_CLKOUT1,
	G3D_CMU_CLKOUT0,
	G3D_CMU_CLKOUT1,
	ISP_CMU_CLKOUT0,
	ISP_CMU_CLKOUT1,
	MFCMSCL_CMU_CLKOUT0,
	MFCMSCL_CMU_CLKOUT1,
	MIF_CMU_CLKOUT0,
	MIF_CMU_CLKOUT1,
	MIF1_CMU_CLKOUT0,
	MIF1_CMU_CLKOUT1,
	PERI_CMU_CLKOUT0,
	PERI_CMU_CLKOUT1,


	MUX_CLKCMU_APM_BUS_USER = ((MASK_OF_ID & PERI_CMU_CLKOUT1) | USER_MUX_TYPE) + 1,
	MUX_CLKCMU_CAM_BUS_USER,
	MUX_CLKCMU_CORE_BUS_USER,
	MUX_CLKCMU_CORE_CCI_USER,
	MUX_CLKCMU_CORE_G3D_USER,
	MUX_CLKCMU_CPUCL0_SWITCH_USER,
	MUX_CLKCMU_CPUCL0_SECJTAG_USER,
	MUX_CLKCMU_CPUCL1_SWITCH_USER,
	MUX_CLKCMU_CPUCL2_SWITCH_USER,
	MUX_CLKCMU_AUD_CPU_USER,
	MUX_CLKCMU_DISPAUD_BUS_USER,
	MUX_CLKCMU_FSYS_BUS_USER,
	MUX_CLKCMU_FSYS_MMC_CARD_USER,
	MUX_CLKCMU_FSYS_MMC_EMBD_USER,
	MUX_CLKCMU_FSYS_MMC_SDIO_USER,
	MUX_CLKCMU_FSYS_USB30DRD_USER,
	MUX_CLKCMU_G3D_SWITCH_USER,
	MUX_CLKCMU_ISP_VRA_USER,
	MUX_CLKCMU_ISP_BUS_USER,
	MUX_CLKCMU_ISP_GDC_USER,
	MUX_CLKCMU_MFCMSCL_MSCL_USER,
	MUX_CLKCMU_MFCMSCL_MFC_USER,
	MUX_CLKCMU_MIF_BUSP_USER,
	MUX_CLKCMU_MIF1_SWITCH_USER,
	MUX_CLKCMU_PERI_BUS_USER,
	MUX_CLKCMU_PERI_UART_0_USER,
	MUX_CLKCMU_PERI_UART_1_USER,
	MUX_CLKCMU_PERI_USI0_USER,
	MUX_CLKCMU_PERI_USI1_USER,
	MUX_CLKCMU_PERI_USI2_USER,
	MUX_CLKCMU_PERI_SPI0_USER,
	MUX_CLKCMU_PERI_SPI1_USER,
	MUX_CLKCMU_PERI_UART_2_USER,
	end_of_mux,
	num_of_mux = (end_of_mux - MUX_TYPE) & MASK_OF_ID,

	DIV_CLK_APM_I2C = DIV_TYPE,
	DIV_CLK_CAM_BUSP,
	CLKCMU_CPUCL1_SWITCH,
	CLKCMU_G3D_SWITCH,
	CLKCMU_ISP_BUS,
	CLKCMU_CAM_BUS,
	CLKCMU_DISPAUD_BUS,
	CLKCMU_FSYS_BUS,
	CLKCMU_CPUCL0_SWITCH,
	CLKCMU_MFCMSCL_MSCL,
	CLKCMU_MFCMSCL_MFC,
	CLKCMU_ISP_GDC,
	AP2CP_SHARED0_PLL_CLK,
	CLKCMU_PERI_BUS,
	CLKCMU_PERI_UART_0,
	CLKCMU_PERI_UART_1,
	CLKCMU_PERI_USI2,
	CLKCMU_PERI_SPI_0,
	CLKCMU_PERI_SPI_1,
	CLKCMU_APM_BUS,
	CLKCMU_FSYS_MMC_CARD,
	CLKCMU_CIS_CLK0,
	CLKCMU_CIS_CLK1,
	CLKCMU_CIS_CLK2,
	CLKCMU_FSYS_MMC_EMBD,
	CLKCMU_PERI_USI0,
	CLKCMU_PERI_USI1,
	AP2CP_SHARED1_PLL_CLK,
	DIV_CLK_CMU_CMUREF,
	CLKCMU_DISPAUD_CPU,
	CLKCMU_ISP_VRA,
	CLKCMU_FSYS_MMC_SDIO,
	CLKCMU_CORE_BUS,
	CLKCMU_PERI_UART_2,
	PLL_SHARED0_DIV3,
	CLKCMU_CPUCL0_SECJTAG,
	PLL_SHARED0_DIV2,
	PLL_SHARED0_DIV4,
	PLL_SHARED1_DIV2,
	PLL_SHARED1_DIV4,
	CLKCMU_CORE_CCI,
	CLKCMU_CPUCL2_SWITCH,
	CLKCMU_FSYS_USB30DRD,
	CLKCMU_CORE_G3D,
	CLKCMU_MIF_BUSP,
	PLL_SHARED0_DIV5,
	PLL_SHARED1_DIV3,
	DIV_CLK_CORE_BUSP,
	DIV_CLK_CPUCL0_PCLK,
	DIV_CLK_CPUCL0_CMUREF,
	DIV_CLK_CPUCL0_ACLK,
	DIV_CLK_CPUCL0_ATCLK,
	DIV_CLK_CPUCL0_CNTCLK,
	DIV_CLK_CPUCL0_PCLKDBG,
	DIV_CLK_CPUCL1_PCLK,
	DIV_CLK_CPUCL1_CMUREF,
	DIV_CLK_CPUCL1_ACLK,
	DIV_CLK_CPUCL1_ATCLK,
	DIV_CLK_CPUCL1_PCLKDBG,
	DIV_CLK_CPUCL1_CNTCLK,
	DIV_CLK_CPUCL2_CPU,
	DIV_CLK_CPUCL2_PCLK,
	DIV_CLK_CPUCL2_CMUREF,
	DIV_CLK_CPUCL2_ACLK,
	DIV_CLK_CPUCL2_ATCLK,
	DIV_CLK_CPUCL2_CNTCLK,
	DIV_CLK_CPUCL2_PCLKDBG,
	DIV_CLK_AUD_BUS,
	DIV_CLK_AUD_PLL,
	DIV_CLK_AUD_CPU_PCLKDBG,
	DIV_CLK_AUD_CPU_ACLK,
	DIV_CLK_AUD_UAIF0,
	DIV_CLK_AUD_AUDIF,
	DIV_CLK_AUD_UAIF2,
	DIV_CLK_AUD_UAIF3,
	DIV_CLK_AUD_FM,
	DIV_CLK_DISPAUD_BUSP,
	DIV_CLK_AUD_FM_SPDY,
	DIV_CLK_G3D_BUSP,
	DIV_CLK_ISP_BUSP,
	DIV_CLK_MFCMSCL_APB,

	DIV_CLK_CPUCL0_CPU = (DIV_CLK_MFCMSCL_APB | CONST_DIV_TYPE) + 1,
	DIV_CLK_CPUCL1_CPU,
	end_of_div,
	num_of_div = (end_of_div - DIV_TYPE) & MASK_OF_ID,

	CLK_BLK_APM_UID_APM_CMU_APM_IPCLKPORT_PCLK = GATE_TYPE,
	GOUT_BLK_APM_UID_APM_IPCLKPORT_ACLK_SYS,
	GOUT_BLK_APM_UID_APM_IPCLKPORT_ACLK_IntMEM,
	GOUT_BLK_APM_UID_WDT_APM_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_LHM_AXI_P_ALIVE_IPCLKPORT_I_CLK,
	GOUT_BLK_APM_UID_LHS_AXI_D_ALIVE_IPCLKPORT_I_CLK,
	GOUT_BLK_APM_UID_MAILBOX_APM2AP_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_MAILBOX_APM2CP_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_MAILBOX_APM2GNSS_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_MAILBOX_APM2WLBT_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_SYSREG_APM_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_RSTnSYNC_CLK_APM_BUS_IPCLKPORT_CLK,
	GOUT_BLK_APM_UID_RSTnSYNC_CLK_APM_BUS_NORET_IPCLKPORT_CLK,
	GOUT_BLK_APM_UID_IP_BATCHER_AP_IPCLKPORT_i_pclk,
	GOUT_BLK_APM_UID_IP_BATCHER_CP_IPCLKPORT_i_pclk,
	GOUT_BLK_APM_UID_MP_APBSEMA_HWACG_2CH_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_SPEEDY_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_APBIF_PMU_ALIVE_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_APBIF_GPIO_ALIVE_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_APM_IPCLKPORT_ACLK_CPU,
	GOUT_BLK_APM_UID_I2C_APM_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_ASYNCAPB_APM_IPCLKPORT_PCLKM,
	GOUT_BLK_APM_UID_ASYNCAPB_APM_IPCLKPORT_PCLKS,
	GOUT_BLK_APM_UID_APBIF_RTC_IPCLKPORT_PCLK,
	GOUT_BLK_APM_UID_APBIF_TOP_RTC_IPCLKPORT_PCLK,
	CLK_BLK_CAM_UID_CAM_CMU_CAM_IPCLKPORT_PCLK,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS0_PCLKM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS0_PCLKS,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS1_PCLKM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS1_PCLKS,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS2_PCLKM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS2_PCLKS,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS3_PCLKM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS3_PCLKS,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS_DMA_PCLKM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_CSIS_DMA_PCLKS,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_3AA0_PCLKM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_3AA0_PCLKS,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_3AA1_PCLKM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_3AA1_PCLKS,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_SMMU_CAM_NS_PCLKM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_SMMU_CAM_NS_PCLKS,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_SMMU_CAM_S_PCLKM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_APB_ASYNC_SMMU_CAM_S_PCLKS,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_XIU_P_CAM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_AXI2APB_CAM0,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_AXI2APB_CAM1,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_CSIS0,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_CSIS1,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_CSIS2,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_CSIS3,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_3AA0,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_3AA1,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_XIU_D_CAM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_PCLK_PPMU_CAM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_PPMU_CAM,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_SMMU_CAM,
	GOUT_BLK_CAM_UID_SYSREG_CAM_IPCLKPORT_PCLK,
	GOUT_BLK_CAM_UID_LHS_ATB_CAMISP_IPCLKPORT_I_CLK,
	GOUT_BLK_CAM_UID_LHM_AXI_P_CAM_IPCLKPORT_I_CLK,
	GOUT_BLK_CAM_UID_LHS_AXI_D_CAM_IPCLKPORT_I_CLK,
	GOUT_BLK_CAM_UID_RSTnSYNC_CLK_CAM_BUSD_IPCLKPORT_CLK,
	GOUT_BLK_CAM_UID_RSTnSYNC_CLK_CAM_BUSP_IPCLKPORT_CLK,
	GOUT_BLK_CAM_UID_is6p20p0_CAM_IPCLKPORT_ACLK_CSIS_DMA,
	GATE_CLKCMU_MFCMSCL_MSCL,
	GATE_CLKCMU_MFCMSCL_MFC,
	GATE_CLKCMU_CPUCL0_SWITCH,
	GATE_CLKCMU_CPUCL1_SWITCH,
	GATE_CLKCMU_G3D_SWITCH,
	GATE_CLKCMU_ISP_BUS,
	GATE_CLKCMU_CAM_BUS,
	GATE_CLKCMU_ISP_GDC,
	GATE_CLKCMU_DISPAUD_BUS,
	GATE_CLKCMU_FSYS_MMC_EMBD,
	GATE_CLKCMU_FSYS_BUS,
	GATE_CLKCMU_MODEM_SHARED0,
	GATE_CLKCMU_PERI_BUS,
	GATE_CLKCMU_PERI_UART_0,
	GATE_CLKCMUC_PERI_UART_1,
	GATE_CLKCMU_PERI_USI2,
	GATE_CLKCMU_PERI_SPI_0,
	GATE_CLKCMU_PERI_SPI_1,
	GATE_CLKCMU_APM_BUS,
	GATE_CLKCMU_FSYS_MMC_CARD,
	GATE_CLKCMU_CIS_CLK0,
	GATE_CLKCMU_CIS_CLK1,
	GATE_CLKCMU_CIS_CLK2,
	GATE_CLKCMU_PERI_USI0,
	GATE_CLKCMU_PERI_USI1,
	GATE_CLKCMU_MODEM_SHARED1,
	GATE_CLKCMU_DISPAUD_VCLK,
	GATE_CLKCMU_ISP_VRA,
	CLKCMU_MIF_SWITCH,
	GATE_CLKCMU_FSYS_MMC_SDIO,
	GATE_CLKCMU_CORE_BUS,
	GATE_CLKCMU_PERI_UART_2,
	GATE_CLKCMU_CPUCL0_SECJTAG,
	GATE_CLKCMU_CORE_CCI,
	GATE_CLKCMU_CPUCL2_SWITCH,
	GATE_CLKCMU_FSYS_USB30DRD,
	GATE_CLKCMU_CORE_G3D,
	GATE_CLKCMU_MIF_BUSP,
	GOUT_BLK_CORE_UID_AD_APB_PDMA0_IPCLKPORT_PCLKS,
	GOUT_BLK_CORE_UID_AD_APB_SPDMA_IPCLKPORT_PCLKS,
	GOUT_BLK_CORE_UID_AD_AXI_GIC_IPCLKPORT_ACLKS,
	GOUT_BLK_CORE_UID_AD_AXI_GIC_IPCLKPORT_ACLKM,
	GOUT_BLK_CORE_UID_ADS_APB_G_CSSYS_IPCLKPORT_PCLKS,
	GOUT_BLK_CORE_UID_AHB_BRIDGE_IPCLKPORT_HCLK,
	GOUT_BLK_CORE_UID_AHB2APB_COREP0_IPCLKPORT_HCLK,
	GOUT_BLK_CORE_UID_AHB2APB_CSSYS_DBG_IPCLKPORT_HCLK,
	GOUT_BLK_CORE_UID_AXI2AHB_CORE_CSSYS_IPCLKPORT_aclk,
	GOUT_BLK_CORE_UID_AXI2AHB_COREP_IPCLKPORT_aclk,
	GOUT_BLK_CORE_UID_AXI2APB_2MB_BUSCP_IPCLKPORT_ACLK,
	GOUT_BLK_CORE_UID_CCI_550_IPCLKPORT_ACLK,
	GOUT_BLK_CORE_UID_GIC400_AIHWACG_IPCLKPORT_CLK,
	GOUT_BLK_CORE_UID_LHM_ACE_D_CPUCL0_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_ACE_D_CPUCL1_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_ABOX_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_CP_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_DPU_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D1_ISP_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_WLBT_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_P_CP_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_D0_MIF_CPU_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_D1_MIF_CPU_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_D0_MIF_NRT_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_D1_MIF_NRT_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_APM_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_CPUCL0_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_CPUCL1_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_DISPAUD_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_FSYS_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_G3D_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_ISP_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_MFCMSCL_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_PERI_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_MAILBOX_ABOX_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_MAILBOX_CP_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_MAILBOX_GNSS_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_MAILBOX_CP_SECURE_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_MAILBOX_WLBT_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_MAILBOX_WLBT_CM4_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_PPCFW_G3D_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_PPMU_ACE_CPUCL0_IPCLKPORT_ACLK,
	GOUT_BLK_CORE_UID_PPMU_ACE_CPUCL0_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_PPMU_ACE_CPUCL1_IPCLKPORT_ACLK,
	GOUT_BLK_CORE_UID_PPMU_ACE_CPUCL1_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_SFR_APBIF_CMU_TOPC_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_SYSREG_CORE_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_TREX_D_CORE_IPCLKPORT_ACLK,
	GOUT_BLK_CORE_UID_TREX_D_CORE_IPCLKPORT_pclk,
	GOUT_BLK_CORE_UID_TREX_P_CORE_IPCLKPORT_ACLK_P_CORE,
	GOUT_BLK_CORE_UID_TREX_P_CORE_IPCLKPORT_CCLK_P_CORE,
	GOUT_BLK_CORE_UID_TREX_P_CORE_IPCLKPORT_PCLK_P_CORE,
	GOUT_BLK_CORE_UID_WRAP_ADC_IF_IPCLKPORT_PCLK_S0,
	GOUT_BLK_CORE_UID_WRAP_ADC_IF_IPCLKPORT_PCLK_S1,
	GOUT_BLK_CORE_UID_RSTnSYNC_CLK_CORE_CCI_OCC_IPCLKPORT_CLK,
	GOUT_BLK_CORE_UID_RSTnSYNC_CLK_CORE_BUSD_IPCLKPORT_CLK,
	GOUT_BLK_CORE_UID_RSTnSYNC_CLK_CORE_BUSP_OCC_IPCLKPORT_CLK,
	GOUT_BLK_CORE_UID_AD_APB_CCI_550_IPCLKPORT_PCLKS,
	GOUT_BLK_CORE_UID_AD_APB_CCI_550_IPCLKPORT_PCLKM,
	GOUT_BLK_CORE_UID_AHB2APB_COREP1_IPCLKPORT_HCLK,
	GOUT_BLK_CORE_UID_AHB2APB_1MB_COREP2_IPCLKPORT_HCLK,
	GOUT_BLK_CORE_UID_LHM_ACE_D_CPUCL2_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_MIF0_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_MIF1_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_PPMU_ACE_CPUCL2_IPCLKPORT_ACLK,
	GOUT_BLK_CORE_UID_PPMU_ACE_CPUCL2_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_RSTnSYNC_CLK_CORE_G3D_OCC_IPCLKPORT_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_CPUCL2_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_ASYNCSFR_WR_DMC_IPCLKPORT_I_PCLK,
	CLK_BLK_CORE_UID_CORE_CMU_CORE_IPCLKPORT_PCLK,
	GOUT_BLK_CORE_UID_PPCFW_G3D_IPCLKPORT_ACLK,
	GOUT_BLK_CORE_UID_RSTnSYNC_CLK_CORE_BUSP_IPCLKPORT_CLK,
	GOUT_BLK_CORE_UID_RSTnSYNC_CLK_CORE_CCI_IPCLKPORT_CLK,
	GOUT_BLK_CORE_UID_RSTnSYNC_CLK_CORE_G3D_IPCLKPORT_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_G3D_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_RSTnSYNC_CLK_CORE_GIC_IPCLKPORT_CLK,
	GOUT_BLK_CORE_UID_AD_APB_PDMA0_IPCLKPORT_PCLKM,
	GOUT_BLK_CORE_UID_AD_APB_SPDMA_IPCLKPORT_PCLKM,
	GOUT_BLK_CORE_UID_AXI_US_A40_32to128_PDMA_IPCLKPORT_aclk,
	GOUT_BLK_CORE_UID_AXI_US_A40_32to128_SDMA_IPCLKPORT_aclk,
	GOUT_BLK_CORE_UID_LHM_AXI_D_APM_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_CSSYS_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_FSYS_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_GNSS_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D0_ISP_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_MFCMSCL_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_PDMA_CORE_IPCLKPORT_ACLK_PDMA0,
	GOUT_BLK_CORE_UID_SPDMA_CORE_IPCLKPORT_ACLK_PDMA1,
	GOUT_BLK_CORE_UID_XIU_D_PDMA_3x1_IPCLKPORT_ACLK,
	GOUT_BLK_CORE_UID_LHM_AXI_D_CAM_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_D0_MIF_RT_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_D1_MIF_RT_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_LHS_AXI_P_CAM_IPCLKPORT_I_CLK,
	GOUT_BLK_CORE_UID_TREX_D_CORE_IPCLKPORT_GCLK,
	GOUT_BLK_CORE_UID_TREX_P_CORE_IPCLKPORT_pclk,
	CLK_BLK_CPUCL0_UID_CPUCL0_CMU_CPUCL0_IPCLKPORT_PCLK,
	GOUT_BLK_CPUCL0_UID_AXI2APB_CPUCL0_IPCLKPORT_ACLK,
	GOUT_BLK_CPUCL0_UID_SYSREG_CPUCL0_IPCLKPORT_PCLK,
	GOUT_BLK_CPUCL0_UID_RSTnSYNC_CLK_CPUCL0_PCLK_IPCLKPORT_CLK,
	GOUT_BLK_CPUCL0_UID_LHM_AXI_P_CPUCL0_IPCLKPORT_I_CLK,
	GOUT_BLK_CPUCL0_UID_LHS_ACE_D_CPUCL0_IPCLKPORT_I_CLK,
	GOUT_BLK_CPUCL0_UID_ADM_APB_P_CSSYS_DBG_IPCLKPORT_PCLKM,
	GOUT_BLK_CPUCL0_UID_CSSYS_DBG_IPCLKPORT_PCLKDBG,
	GOUT_BLK_CPUCL0_UID_LHS_AXI_T_CSSYS_DBG_IPCLKPORT_I_CLK,
	GOUT_BLK_CPUCL0_UID_RSTnSYNC_CLK_CPUCL0_PCLKDBG_IPCLKPORT_CLK,
	GOUT_BLK_CPUCL0_UID_ADS_APB_G_CSSYS_DBG_CLUSTER1_IPCLKPORT_PCLKS,
	GOUT_BLK_CPUCL0_UID_AD_APB_P_DUMP_PC_CPUCL0_IPCLKPORT_PCLKM,
	GOUT_BLK_CPUCL0_UID_AD_APB_P_DUMP_PC_CPUCL0_IPCLKPORT_PCLKS,
	GOUT_BLK_CPUCL0_UID_RSTnSYNC_CLK_CPUCL0_ACLK_IPCLKPORT_CLK,
	GOUT_BLK_CPUCL0_UID_DUMP_PC_CPUCL0_IPCLKPORT_I_PCLK,
	GOUT_BLK_CPUCL0_UID_ADS_AHB_G_SSS_IPCLKPORT_HCLK,
	GOUT_BLK_CPUCL0_UID_RSTnSYNC_CLK_CPUCL_SECJTAG_IPCLKPORT_CLK,
	GOUT_BLK_CPUCL0_UID_AD_APB_P_SECJTAG_CPUCL0_IPCLKPORT_PCLKM,
	GOUT_BLK_CPUCL0_UID_AD_APB_P_SECJTAG_CPUCL0_IPCLKPORT_PCLKS,
	GOUT_BLK_CPUCL0_UID_SECJTAG_IPCLKPORT_i_clk,
	GOUT_BLK_CPUCL0_UID_ADS_APB_G_CSSYS_DBG_CLUSTER2_IPCLKPORT_PCLKS,
	CLK_BLK_CPUCL1_UID_CPUCL1_CMU_CPUCL1_IPCLKPORT_PCLK,
	GOUT_BLK_CPUCL1_UID_LHM_AXI_P_CPUCL1_IPCLKPORT_I_CLK,
	GOUT_BLK_CPUCL1_UID_SYSREG_CPUCL1_IPCLKPORT_PCLK,
	GOUT_BLK_CPUCL1_UID_RSTnSYNC_CLK_CPUCL1_PCLK_IPCLKPORT_CLK,
	GOUT_BLK_CPUCL1_UID_LHS_ACE_D_CPUCL1_IPCLKPORT_I_CLK,
	GOUT_BLK_CPUCL1_UID_AXI2APB_CPUCL1_IPCLKPORT_ACLK,
	GOUT_BLK_CPUCL1_UID_RSTnSYNC_CLK_CPUCL1_ACLK_IPCLKPORT_CLK,
	GOUT_BLK_CPUCL1_UID_RSTnSYNC_CLK_CPUCL1_PCLKDBG_IPCLKPORT_CLK,
	GOUT_BLK_CPUCL1_UID_ADM_APB_G_CPUCL1_IPCLKPORT_PCLKM,
	GOUT_BLK_CPUCL1_UID_AD_APB_P_DUMP_PC_CPUCL1_IPCLKPORT_PCLKM,
	GOUT_BLK_CPUCL1_UID_AD_APB_P_DUMP_PC_CPUCL1_IPCLKPORT_PCLKS,
	GOUT_BLK_CPUCL1_UID_DUMP_PC_CPUCL1_IPCLKPORT_I_PCLK,
	CLK_BLK_CPUCL2_UID_CPUCL2_CMU_CPUCL2_IPCLKPORT_PCLK,
	GOUT_BLK_CPUCL2_UID_LHS_ACE_D_CPUCL2_IPCLKPORT_I_CLK,
	GOUT_BLK_CPUCL2_UID_LHM_AXI_P_CPUCL2_IPCLKPORT_I_CLK,
	GOUT_BLK_CPUCL2_UID_AXI2APB_CPUCL2_IPCLKPORT_ACLK,
	GOUT_BLK_CPUCL2_UID_AD_APB_P_DUMP_PC_CPUCL2_IPCLKPORT_PCLKM,
	GOUT_BLK_CPUCL2_UID_AD_APB_P_DUMP_PC_CPUCL2_IPCLKPORT_PCLKS,
	GOUT_BLK_CPUCL2_UID_ADM_APB_G_CPUCL2_IPCLKPORT_PCLKM,
	GOUT_BLK_CPUCL2_UID_DUMP_PC_CPUCL2_IPCLKPORT_I_PCLK,
	GOUT_BLK_CPUCL2_UID_SYSREG_IPCLKPORT_PCLK,
	GOUT_BLK_CPUCL2_UID_RSTnSYNC_CLK_CPUCL2_ACLK_IPCLKPORT_CLK,
	GOUT_BLK_CPUCL2_UID_RSTnSYNC_CLK_CPUCL2_PCLK_IPCLKPORT_CLK,
	GOUT_BLK_CPUCL2_UID_RSTnSYNC_CLK_CPUCL2_PCLKDBG_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_ABOX_IPCLKPORT_BCLK_UAIF0,
	GOUT_BLK_DISPAUD_UID_ABOX_IPCLKPORT_BCLK_UAIF3,
	GOUT_BLK_DISPAUD_UID_ABOX_IPCLKPORT_CCLK_CA7,
	GOUT_BLK_DISPAUD_UID_ABOX_IPCLKPORT_CCLK_ASB,
	GOUT_BLK_DISPAUD_UID_ABOX_IPCLKPORT_ACLK,
	GOUT_BLK_DISPAUD_UID_AXI_US_32to128_IPCLKPORT_aclk,
	GOUT_BLK_DISPAUD_UID_RSTnSYNC_CLK_AUD_UAIF0_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_RSTnSYNC_CLK_AUD_UAIF2_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_RSTnSYNC_CLK_AUD_UAIF3_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_RSTnSYNC_CLK_AUD_CPU_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_RSTnSYNC_CLK_AUD_PCLKDBG_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_RSTnSYNC_CLK_AUD_BUS_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_PERI_AXI_ASB_IPCLKPORT_ACLKM,
	GOUT_BLK_DISPAUD_UID_PERI_AXI_ASB_IPCLKPORT_PCLK,
	GOUT_BLK_DISPAUD_UID_WDT_ABOXCPU_IPCLKPORT_PCLK,
	GOUT_BLK_DISPAUD_UID_ABOX_IPCLKPORT_BCLK_UAIF2,
	GOUT_BLK_DISPAUD_UID_DFTMUX_DISPAUD_IPCLKPORT_AUD_CODEC_MCLK,
	GOUT_BLK_DISPAUD_UID_PPMU_ABOX_IPCLKPORT_ACLK,
	GOUT_BLK_DISPAUD_UID_PPMU_ABOX_IPCLKPORT_PCLK,
	GOUT_BLK_DISPAUD_UID_SMMU_ABOX_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_AD_APB_DECON0_IPCLKPORT_PCLKS,
	GOUT_BLK_DISPAUD_UID_AD_APB_DECON0_IPCLKPORT_PCLKM,
	GOUT_BLK_DISPAUD_UID_AD_APB_DECON0_SECURE_IPCLKPORT_PCLKS,
	GOUT_BLK_DISPAUD_UID_AD_APB_DECON0_SECURE_IPCLKPORT_PCLKM,
	GOUT_BLK_DISPAUD_UID_AD_APB_DPP_IPCLKPORT_PCLKS,
	GOUT_BLK_DISPAUD_UID_AD_APB_DPP_IPCLKPORT_PCLKM,
	GOUT_BLK_DISPAUD_UID_AD_APB_DPU_DMA_IPCLKPORT_PCLKS,
	GOUT_BLK_DISPAUD_UID_AD_APB_DPU_DMA_IPCLKPORT_PCLKM,
	GOUT_BLK_DISPAUD_UID_AD_APB_DPU_DMA_SECURE_IPCLKPORT_PCLKS,
	GOUT_BLK_DISPAUD_UID_AD_APB_DPU_DMA_SECURE_IPCLKPORT_PCLKM,
	GOUT_BLK_DISPAUD_UID_AD_APB_DSIM0_IPCLKPORT_PCLKS,
	GOUT_BLK_DISPAUD_UID_AXI2APB_DISPAUD_IPCLKPORT_ACLK,
	GOUT_BLK_DISPAUD_UID_DPU_IPCLKPORT_ACLK_DPP,
	GOUT_BLK_DISPAUD_UID_DPU_IPCLKPORT_ACLK_DMA,
	GOUT_BLK_DISPAUD_UID_DPU_IPCLKPORT_ACLK_DECON0,
	GOUT_BLK_DISPAUD_UID_LHS_AXI_D_DPU_IPCLKPORT_I_CLK,
	GOUT_BLK_DISPAUD_UID_PERI_AXI_ASB_IPCLKPORT_ACLKS,
	GOUT_BLK_DISPAUD_UID_RSTnSYNC_CLK_DISPAUD_BUSD_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_RSTnSYNC_CLK_DISPAUD_BUSP_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_PPMU_DPU_IPCLKPORT_ACLK,
	GOUT_BLK_DISPAUD_UID_PPMU_DPU_IPCLKPORT_PCLK,
	GOUT_BLK_DISPAUD_UID_SMMU_DPU_IPCLKPORT_CLK,
	GOUT_BLK_DISPAUD_UID_SYSREG_DISPAUD_IPCLKPORT_PCLK,
	GOUT_BLK_DISPAUD_UID_XIU_P_DISPAUD_IPCLKPORT_ACLK,
	GOUT_BLK_DISPAUD_UID_LHM_AXI_P_DISPAUD_IPCLKPORT_I_CLK,
	GOUT_BLK_DISPAUD_UID_LHS_AXI_D_ABOX_IPCLKPORT_I_CLK,
	GOUT_BLK_DISPAUD_UID_RSTnSYNC_CLK_AUD_CPU_ACLK_IPCLKPORT_CLK,
	CLK_BLK_DISPAUD_UID_DISPAUD_CMU_DISPAUD_IPCLKPORT_PCLK,
	GOUT_BLK_DISPAUD_UID_ABOX_DAP_IPCLKPORT_dapclk,
	GOUT_BLK_DISPAUD_UID_ABOX_IPCLKPORT_BCLK_SPDY,
	GOUT_BLK_DISPAUD_UID_AD_APB_SMMU_DPU_IPCLKPORT_PCLKM,
	GOUT_BLK_DISPAUD_UID_AD_APB_SMMU_DPU_IPCLKPORT_PCLKS,
	GOUT_BLK_DISPAUD_UID_AD_APB_SMMU_DPU_SECURE_IPCLKPORT_PCLKM,
	GOUT_BLK_DISPAUD_UID_AD_APB_SMMU_DPU_SECURE_IPCLKPORT_PCLKS,
	GOUT_BLK_DISPAUD_UID_GPIO_DISPAUD_IPCLKPORT_PCLK,
	CLK_BLK_FSYS_UID_USB20PHY_IPCLKPORT_CLKCORE,
	CLK_BLK_FSYS_UID_FSYS_CMU_FSYS_IPCLKPORT_PCLK,
	GOUT_BLK_FSYS_UID_SSS_IPCLKPORT_i_PCLK,
	GOUT_BLK_FSYS_UID_SSS_IPCLKPORT_i_ACLK,
	GOUT_BLK_FSYS_UID_RTIC_IPCLKPORT_i_ACLK,
	GOUT_BLK_FSYS_UID_RTIC_IPCLKPORT_i_PCLK,
	GOUT_BLK_FSYS_UID_MMC_CARD_IPCLKPORT_I_ACLK,
	GOUT_BLK_FSYS_UID_MMC_CARD_IPCLKPORT_SDCLKIN,
	GOUT_BLK_FSYS_UID_MMC_EMBD_IPCLKPORT_I_ACLK,
	GOUT_BLK_FSYS_UID_MMC_EMBD_IPCLKPORT_SDCLKIN,
	GOUT_BLK_FSYS_UID_USB30DRD_IPCLKPORT_bus_clk_early,
	GOUT_BLK_FSYS_UID_USB30DRD_IPCLKPORT_ACLK_20PHYCTRL,
	GOUT_BLK_FSYS_UID_RSTnSYNC_CLK_FSYS_BUS_IPCLKPORT_CLK,
	GOUT_BLK_FSYS_UID_AXI2AHB_FSYS_IPCLKPORT_aclk,
	GOUT_BLK_FSYS_UID_AHBBR_FSYS_1x4_IPCLKPORT_HCLK,
	GOUT_BLK_FSYS_UID_AHBBR_FSYS_IPCLKPORT_HCLK,
	GOUT_BLK_FSYS_UID_GPIO_FSYS_IPCLKPORT_PCLK,
	GOUT_BLK_FSYS_UID_LHM_AXI_P_FSYS_IPCLKPORT_I_CLK,
	GOUT_BLK_FSYS_UID_LHS_AXI_D_FSYS_IPCLKPORT_I_CLK,
	GOUT_BLK_FSYS_UID_PPMU_FSYS_IPCLKPORT_ACLK,
	GOUT_BLK_FSYS_UID_PPMU_FSYS_IPCLKPORT_PCLK,
	GOUT_BLK_FSYS_UID_SYSREG_FSYS_IPCLKPORT_PCLK,
	GOUT_BLK_FSYS_UID_XIU_D_FSYS_IPCLKPORT_ACLK,
	GOUT_BLK_FSYS_UID_AHB2APB_FSYS_IPCLKPORT_HCLK,
	GOUT_BLK_FSYS_UID_ADM_AHB_SSS_IPCLKPORT_HCLKM,
	GOUT_BLK_FSYS_UID_MMC_SDIO_IPCLKPORT_SDCLKIN,
	GOUT_BLK_FSYS_UID_MMC_SDIO_IPCLKPORT_I_ACLK,
	GOUT_BLK_FSYS_UID_USB30DRD_IPCLKPORT_ref_clk,
	GOUT_BLK_FSYS_UID_US_64to128_FSYS_IPCLKPORT_aclk,
	GOUT_BLK_FSYS_UID_USB30DRD_IPCLKPORT_ACLK_30PHYCTRL_0,
	GOUT_BLK_FSYS_UID_USB30DRD_IPCLKPORT_ACLK_30PHYCTRL_1,
	CLK_BLK_G3D_UID_G3D_CMU_G3D_IPCLKPORT_PCLK,
	GOUT_BLK_G3D_UID_LHS_AXI_G3DSFR_IPCLKPORT_I_CLK,
	GOUT_BLK_G3D_UID_LHM_AXI_P_G3D_IPCLKPORT_I_CLK,
	GOUT_BLK_G3D_UID_SYSREG_G3D_IPCLKPORT_PCLK,
	GOUT_BLK_G3D_UID_XIU_P_G3D_IPCLKPORT_ACLK,
	GOUT_BLK_G3D_UID_RSTnSYNC_CLK_G3D_BUSP_IPCLKPORT_CLK,
	GOUT_BLK_G3D_UID_AXI2APB_G3D_IPCLKPORT_ACLK,
	GOUT_BLK_G3D_UID_RSTnSYNC_CLK_G3D_GPU_IPCLKPORT_CLK,
	GOUT_BLK_G3D_UID_RSTnSYNC_CLK_G3D_BUSD_IPCLKPORT_CLK,
	GOUT_BLK_G3D_UID_LHS_AXI_D_G3D_IPCLKPORT_I_CLK,
	GOUT_BLK_G3D_UID_LHM_AXI_G3DSFR_IPCLKPORT_I_CLK,
	GOUT_BLK_ISP_UID_RSTnSYNC_CLK_ISP_VRA_IPCLKPORT_CLK,
	GOUT_BLK_ISP_UID_RSTnSYNC_CLK_ISP_GDC_IPCLKPORT_CLK,
	GOUT_BLK_ISP_UID_RSTnSYNC_CLK_ISP_BUSP_IPCLKPORT_CLK,
	GOUT_BLK_ISP_UID_SYSREG_ISP_IPCLKPORT_PCLK,
	CLK_BLK_ISP_UID_ISP_CMU_ISP_IPCLKPORT_PCLK,
	GOUT_BLK_ISP_UID_RSTnSYNC_CLK_ISP_BUSD_IPCLKPORT_CLK,
	GOUT_BLK_ISP_UID_LHM_ATB_CAMISP_IPCLKPORT_I_CLK,
	GOUT_BLK_ISP_UID_LHM_AXI_P_ISP_IPCLKPORT_I_CLK,
	GOUT_BLK_ISP_UID_LHS_AXI_D0_ISP_IPCLKPORT_I_CLK,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_ISP_PCLKM,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_ISP_PCLKS,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_MCSC_PCLKM,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_MCSC_PCLKS,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_SMMU_ISP0_NS_PCLKM,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_SMMU_ISP0_NS_PCLKS,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_SMMU_ISP0_S_PCLKM,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_SMMU_ISP0_S_PCLKS,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_SMMU_ISP1_NS_PCLKM,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_SMMU_ISP1_NS_PCLKS,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_SMMU_ISP1_S_PCLKM,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_SMMU_ISP1_S_PCLKS,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_VRA_PCLKM,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_VRA_PCLKS,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_GDC_PCLKM,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_APB_ASYNC_GDC_PCLKS,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_XIU_P_ISP,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_AXI2APB_ISP0,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_AXI2APB_ISP1,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_ISP,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_MCSC,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_VRA,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_GDC,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_XIU_ASYNCS_VRA,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_XIU_ASYNCM_VRA,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_XIU_ASYNCM_GDC,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_XIU_ASYNCS_GDC,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_XIU_D_ISP,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_PPMU_ISP0,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_PCLK_PPMU_ISP0,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_SMMU_ISP0,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_PPMU_ISP1,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_ACLK_SMMU_ISP1,
	GOUT_BLK_ISP_UID_is6p20p0_ISP_IPCLKPORT_PCLK_PPMU_ISP1,
	GOUT_BLK_ISP_UID_LHS_AXI_D1_ISP_IPCLKPORT_I_CLK,
	CLK_BLK_MFCMSCL_UID_MFCMSCL_CMU_MFCMSCL_IPCLKPORT_PCLK,
	GOUT_BLK_MFCMSCL_UID_LHM_AXI_P_MFCMSCL_IPCLKPORT_I_CLK,
	GOUT_BLK_MFCMSCL_UID_ASYNC_MFC_P_IPCLKPORT_PCLKM,
	GOUT_BLK_MFCMSCL_UID_ASYNC_MFC_P_IPCLKPORT_PCLKS,
	GOUT_BLK_MFCMSCL_UID_ASYNC_JPEG_P_IPCLKPORT_PCLKS,
	GOUT_BLK_MFCMSCL_UID_ASYNC_MSCL_P_IPCLKPORT_PCLKM,
	GOUT_BLK_MFCMSCL_UID_ASYNC_MSCL_P_IPCLKPORT_PCLKS,
	GOUT_BLK_MFCMSCL_UID_AXI2APB_MFCMSCL_IPCLKPORT_ACLK,
	GOUT_BLK_MFCMSCL_UID_MFC_IPCLKPORT_Clk,
	GOUT_BLK_MFCMSCL_UID_SYSREG_MFCMSCL_IPCLKPORT_PCLK,
	GOUT_BLK_MFCMSCL_UID_RSTnSYNC_CLK_MFCMSCL_MFC_IPCLKPORT_CLK,
	GOUT_BLK_MFCMSCL_UID_RSTnSYNC_CLK_MFCMSCL_MSCL_IPCLKPORT_CLK,
	GOUT_BLK_MFCMSCL_UID_ASYNC_SMMU_NS_P_IPCLKPORT_PCLKS,
	GOUT_BLK_MFCMSCL_UID_RSTnSYNC_CLK_MFCMSCL_APB_IPCLKPORT_CLK,
	GOUT_BLK_MFCMSCL_UID_ASYNC_G2D_P_IPCLKPORT_PCLKS,
	GOUT_BLK_MFCMSCL_UID_G2D_IPCLKPORT_Clk,
	GOUT_BLK_MFCMSCL_UID_PPMU_MFCMSCL_IPCLKPORT_PCLK,
	GOUT_BLK_MFCMSCL_UID_PPMU_MFCMSCL_IPCLKPORT_ACLK,
	GOUT_BLK_MFCMSCL_UID_SMMU_MFCMSCL_IPCLKPORT_CLK,
	GOUT_BLK_MFCMSCL_UID_XIU_D_MFCMSCL_IPCLKPORT_ACLK,
	GOUT_BLK_MFCMSCL_UID_ASYNC_G2D_P_IPCLKPORT_PCLKM,
	GOUT_BLK_MFCMSCL_UID_ASYNC_JPEG_P_IPCLKPORT_PCLKM,
	GOUT_BLK_MFCMSCL_UID_JPEG_IPCLKPORT_I_FIMP_CLK,
	GOUT_BLK_MFCMSCL_UID_LHS_AXI_D_MFCMSCL_IPCLKPORT_I_CLK,
	GOUT_BLK_MFCMSCL_UID_ASYNC_SMMU_NS_P_IPCLKPORT_PCLKM,
	GOUT_BLK_MFCMSCL_UID_MSCL_IPCLKPORT_ACLK,
	GOUT_BLK_MFCMSCL_UID_ASYNC_SMMU_S_P_IPCLKPORT_PCLKM,
	GOUT_BLK_MFCMSCL_UID_ASYNC_SMMU_S_P_IPCLKPORT_PCLKS,
	GOUT_BLK_MFCMSCL_UID_ASYNC_AXI_IPCLKPORT_ACLKM,
	GOUT_BLK_MFCMSCL_UID_ASYNC_AXI_IPCLKPORT_ACLKS,
	GOUT_BLK_MIF_UID_DMC_IPCLKPORT_ACLK,
	GOUT_BLK_MIF_UID_LHM_AXI_D_MIF_CPU_IPCLKPORT_I_CLK,
	GOUT_BLK_MIF_UID_LHM_AXI_D_MIF_RT_IPCLKPORT_I_CLK,
	GOUT_BLK_MIF_UID_PPMU_DMC_CPU_IPCLKPORT_ACLK,
	GOUT_BLK_MIF_UID_RSTnSYNC_CLK_MIF_BUSD_IPCLKPORT_CLK,
	GOUT_BLK_MIF_UID_QE_DMC_CPU_IPCLKPORT_ACLK,
	CLK_BLK_MIF_UID_MIF_CMU_MIF_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_AXI2APB_SFR_IPCLKPORT_ACLK,
	GOUT_BLK_MIF_UID_DDR_PHY_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_DMC_IPCLKPORT_PCLK_PPMPU,
	GOUT_BLK_MIF_UID_LHM_AXI_P_MIF_IPCLKPORT_I_CLK,
	GOUT_BLK_MIF_UID_PPMU_DMC_CPU_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_QE_DMC_CPU_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_RSTnSYNC_CLK_MIF_BUSP_IPCLKPORT_CLK,
	GOUT_BLK_MIF_UID_SFRAPB_BRIDGE_DDR_PHY_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_SFRAPB_BRIDGE_DMC_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_SFRAPB_BRIDGE_DMC_PPMPU_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_SFRAPB_BRIDGE_DMC_SECURE_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_SYSREG_MIF_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_DMC_IPCLKPORT_PCLK_SECURE,
	GOUT_BLK_MIF_UID_DMC_IPCLKPORT_PCLK,
	GOUT_BLK_MIF_UID_DMC_IPCLKPORT_PCLK_PF,
	GOUT_BLK_MIF_UID_LHM_AXI_D_MIF_NRT_IPCLKPORT_I_CLK,
	CLK_BLK_MIF1_UID_MIF1_CMU_MIF1_IPCLKPORT_PCLK,
	GOUT_BLK_PERI_UID_WDT_CLUSTER0_IPCLKPORT_PCLK,
	GOUT_BLK_PERI_UID_WDT_CLUSTER1_IPCLKPORT_PCLK,
	GOUT_BLK_PERI_UID_MCT_IPCLKPORT_PCLK,
	GOUT_BLK_PERI_UID_SYSREG_PERI_IPCLKPORT_PCLK,
	GOUT_BLK_PERI_UID_BUSIF_TMU_IPCLKPORT_PCLK,
	GOUT_BLK_PERI_UID_OTP_CON_TOP_IPCLKPORT_PCLK,
	GOUT_BLK_PERI_UID_RSTnSYNC_CLK_PERI_BUS_IPCLKPORT_CLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_I2C6_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_I2C0_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_I2C1_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_I2C2_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_I2C3_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_I2C4_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_I2C5_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_PWM_MOTOR_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_SPI0_SPI_EXT_CLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_SPI1_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_SPI0_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_SPI1_SPI_EXT_CLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_UART0_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_UART0_EXT_UCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_UART1_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_UART1_EXT_UCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_HSI2C3_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_HSI2C1_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_HSI2C0_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_USI1_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_USI0_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_HSI2C2_PCLK,
	GOUT_BLK_PERI_UID_SECUCON_IPCLKPORT_PCLK,
	GOUT_BLK_PERI_UID_AXI2AHB_PERI_IPCLKPORT_aclk,
	GOUT_BLK_PERI_UID_BUSP_BR_PERI_IPCLKPORT_HCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_BUSP1_PERIC0_HCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_BUSP1_PERIC1_HCLK,
	CLK_BLK_PERI_UID_PERI_CMU_PERI_IPCLKPORT_PCLK,
	GOUT_BLK_PERI_UID_BUSP1_PERIS0_IPCLKPORT_HCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_GPIO_TOP_PCLK,
	GOUT_BLK_PERI_UID_LHM_AXI_P_PERI_IPCLKPORT_I_CLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_USI0_SCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_USI1_SCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_USI2_SCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_UART2_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_UART2_EXT_UCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_USI2_PCLK,
	GOUT_BLK_PERI_UID_LBLK_PERIC_IPCLKPORT_I2C7_PCLK,
	end_of_gate,
	num_of_gate = end_of_gate - GATE_TYPE,
};

#endif

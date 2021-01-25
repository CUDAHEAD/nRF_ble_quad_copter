#include "mma7660.h"

uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND MPU6050_xout_reg_addr = MMA7660_REG_XOUT;

// Set Active mode.
static uint8_t NRF_TWI_MNGR_BUFFER_LOC_IND default_config[] = { MPU6050_REG_MODE, 1 };

nrf_twi_mngr_transfer_t const MPU6050_init_transfers[MMA7660_INIT_TRANSFER_COUNT] =
{
    NRF_TWI_MNGR_WRITE(MPU6050_ADDR, default_config, sizeof(default_config), 0)
};

/*****************************************************************************
   Lin_Cfg.c
   Generated By:
   Raptor 2023b_1.0.0 (9999_9999)
   Matlab (R2023a) 9.14

   Copyright (c) 2024 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Wed Mar 27 13:31:34 2024
 *****************************************************************************/

#include "Std_Types.h"
#include "SPC58NN_Regs.h"
#include "Lin_Def.h"
#include "Lin.h"
#include "Lin_api.h"
#include "Lin_Cfg.h"
#include "string.h"

/*=====================================================================================================================
   Variable prototype
   ====================================================================================================================*/
/** This data structure store the configuration for a LIN node. */
const tBiosLinNodeConfig bios_Lin_ClustersConfig[BIOS_LIN_TOTAL_CHNL];

/** This data structure point to all schedule table list of different LIN channels */
const tBiosLinSchedTableMap bios_Lin_SchTableMap[BIOS_LIN_TOTAL_CHNL];

/** This data structure point to all frame list of different LIN channels */
const tBiosLinFrameTable const bios_Lin_FrameTables[BIOS_LIN_TOTAL_CHNL];

#define BIOS_LIN_DEFAULT_NUMBER_OF_FLAGS 0
#define RAPTOR_LIN_NO_MASK_ELEMENT     (BIOS_LIN_DEFAULT_NUMBER_OF_FLAGS / BIOS_LIN_NO_FLAG_PER_ELEMENT) + 1

uint32 bios_Lin_GlobalFlagMask[RAPTOR_LIN_NO_MASK_ELEMENT];
const uint16 bios_Lin_NoFlagMaskElement = RAPTOR_LIN_NO_MASK_ELEMENT;
const uint16 bios_Lin_NumberOfFlags = BIOS_LIN_DEFAULT_NUMBER_OF_FLAGS;
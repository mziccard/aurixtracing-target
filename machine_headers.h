#ifndef MACHINE_HEADERS_H_
#define MACHINE_HEADERS_H_

#include <machine/intrinsics.h>
#if defined(__TC29XX__)

#include "tc29xx/IfxCpu_reg.h"
#include "tc29xx/IfxCpu_bf.h"
#include "tc29xx/IfxStm_reg.h"
#include "tc29xx/IfxStm_bf.h"

#elif defined(__TC26XX__)

#include "tc26xx/IfxCpu_reg.h"
#include "tc26xx/IfxCpu_bf.h"
#include "tc26xx/IfxStm_reg.h"
#include "tc26xx/IfxStm_bf.h"

#elif defined(__TC27XX__)
#ifdef TRIBOARD_TC275B

#include "tc27xb/IfxCpu_reg.h"
#include "tc27xb/IfxCpu_bf.h"
#include "tc27xx/IfxStm_reg.h"
#include "tc27xx/IfxStm_bf.h"

#else
#ifdef APPKIT_TC275TU_C

#include "tc27xc/IfxCpu_reg.h"
#include "tc27xc/IfxCpu_bf.h"
#include "tc27xc/IfxStm_reg.h"
#include "tc27xc/IfxStm_bf.h"

#else

#include "tc27xa/IfxCpu_reg.h"
#include "tc27xa/IfxCpu_bf.h"
#include "tc27xa/IfxStm_reg.h"
#include "tc27xa/IfxStm_bf.h"

#endif /* APPKIT_TC275TU_C */
#endif /* TRIBOARD_TC275B */
#endif /* __TC29XX__ */

#endif /* MACHINE_HEADERS_H_ */

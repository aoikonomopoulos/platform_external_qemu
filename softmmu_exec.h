/* Common softmmu definitions and inline routines.  */

/* XXX: find something cleaner.
 * Furthermore, this is false for 64 bits targets
 */
#define ldul_user       ldl_user
#define ldul_kernel     ldl_kernel
#define ldul_hypv       ldl_hypv
#define ldul_executive  ldl_executive
#define ldul_supervisor ldl_supervisor

#include "softmmu_defs.h"

#define ACCESS_TYPE 0
#define MEMSUFFIX MMU_MODE0_SUFFIX
#define DATA_SIZE 1
#include "softmmu_header.h"

#define DATA_SIZE 2
#include "softmmu_header.h"

#define DATA_SIZE 4
#include "softmmu_header.h"

#define DATA_SIZE 8
#include "softmmu_header.h"
#undef ACCESS_TYPE
#undef MEMSUFFIX

#define ACCESS_TYPE 1
#define MEMSUFFIX MMU_MODE1_SUFFIX
#define DATA_SIZE 1
#include "softmmu_header.h"

#define DATA_SIZE 2
#include "softmmu_header.h"

#define DATA_SIZE 4
#include "softmmu_header.h"

#define DATA_SIZE 8
#include "softmmu_header.h"
#undef ACCESS_TYPE
#undef MEMSUFFIX

#if (NB_MMU_MODES >= 3)

#define ACCESS_TYPE 2
#define MEMSUFFIX MMU_MODE2_SUFFIX
#define DATA_SIZE 1
#include "softmmu_header.h"

#define DATA_SIZE 2
#include "softmmu_header.h"

#define DATA_SIZE 4
#include "softmmu_header.h"

#define DATA_SIZE 8
#include "softmmu_header.h"
#undef ACCESS_TYPE
#undef MEMSUFFIX
#endif /* (NB_MMU_MODES >= 3) */

#if (NB_MMU_MODES >= 4)

#define ACCESS_TYPE 3
#define MEMSUFFIX MMU_MODE3_SUFFIX
#define DATA_SIZE 1
#include "softmmu_header.h"

#define DATA_SIZE 2
#include "softmmu_header.h"

#define DATA_SIZE 4
#include "softmmu_header.h"

#define DATA_SIZE 8
#include "softmmu_header.h"
#undef ACCESS_TYPE
#undef MEMSUFFIX
#endif /* (NB_MMU_MODES >= 4) */

#if (NB_MMU_MODES >= 5)

#define ACCESS_TYPE 4
#define MEMSUFFIX MMU_MODE4_SUFFIX
#define DATA_SIZE 1
#include "softmmu_header.h"

#define DATA_SIZE 2
#include "softmmu_header.h"

#define DATA_SIZE 4
#include "softmmu_header.h"

#define DATA_SIZE 8
#include "softmmu_header.h"
#undef ACCESS_TYPE
#undef MEMSUFFIX
#endif /* (NB_MMU_MODES >= 5) */

#if (NB_MMU_MODES >= 6)

#define ACCESS_TYPE 5
#define MEMSUFFIX MMU_MODE5_SUFFIX
#define DATA_SIZE 1
#include "softmmu_header.h"

#define DATA_SIZE 2
#include "softmmu_header.h"

#define DATA_SIZE 4
#include "softmmu_header.h"

#define DATA_SIZE 8
#include "softmmu_header.h"
#undef ACCESS_TYPE
#undef MEMSUFFIX
#endif /* (NB_MMU_MODES >= 6) */

#if (NB_MMU_MODES > 6)
#error "NB_MMU_MODES > 6 is not supported for now"
#endif /* (NB_MMU_MODES > 6) */

/* these access are slower, they must be as rare as possible */
#define ACCESS_TYPE (NB_MMU_MODES)
#define MEMSUFFIX _data
#define DATA_SIZE 1
#include "softmmu_header.h"

#define DATA_SIZE 2
#include "softmmu_header.h"

#define DATA_SIZE 4
#include "softmmu_header.h"

#define DATA_SIZE 8
#include "softmmu_header.h"
#undef ACCESS_TYPE
#undef MEMSUFFIX

#define ldub(p, tag) ldub_data(p, tag)
#define ldsb(p, tag) ldsb_data(p, tag)
#define lduw(p, tag) lduw_data(p, tag)
#define ldsw(p, tag) ldsw_data(p, tag)
#define ldl(p, tag) ldl_data(p, tag)
#define ldq(p, tag) ldq_data(p, tag)

#define stb(p, v, tag) stb_data(p, v, tag)
#define stw(p, v, tag) stw_data(p, v, tag)
#define stl(p, v, tag) stl_data(p, v, tag)
#define stq(p, v, tag) stq_data(p, v, tag)

#define ldub_notaint(p) ldub_data(p, &_argos_dummy_tag)
#define ldsb_notaint(p) ldsb_data(p, &_argos_dummy_tag)
#define lduw_notaint(p) lduw_data(p, &_argos_dummy_tag)
#define ldsw_notaint(p) ldsw_data(p, &_argos_dummy_tag)
#define ldl_notaint(p) ldl_data(p, &_argos_dummy_tag)
#define ldq_notaint(p) ldq_data(p, &_argos_dummy_tag)

#define stb_notaint(p, v) stb_data(p, v, &_argos_dummy_tag)
#define stw_notaint(p, v) stw_data(p, v, &_argos_dummy_tag)
#define stl_notaint(p, v) stl_data(p, v, &_argos_dummy_tag)
#define stq_notaint(p, v) stq_data(p, v, &_argos_dummy_tag)

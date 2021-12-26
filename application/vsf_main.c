#define __VSF_EDA_CLASS_INHERIT__
#define __VSF_HEAP_CLASS_INHERIT__
#include "vsf_cfg.h"

#if VSF_LINUX_CFG_RELATIVE_PATH == ENABLED
#   include "shell/sys/linux/include/unistd.h"
#   include "shell/sys/linux/include/sys/mount.h"
#   include "shell/sys/linux/include/libusb.h"
#else
#   include <unistd.h>
#   include <sys/mount.h>
#   include <libusb.h>
#endif

int vsf_linux_create_fhs(void)
{
    // 0. devfs, busybox, etc
#if VSF_LINUX_USE_DEVFS == ENABLED
    vsf_linux_devfs_init();
#endif
    busybox_install();

    // 1. initialize hardware driver(s)

    // 2. fs

    // 3. install executables

    return 0;
}

// TODO: SDL require that main need argc and argv
int VSF_USER_ENTRY(int argc, char *argv[])
{
    VSF_STREAM_INIT(&VSF_DEBUG_STREAM_RX);
    VSF_STREAM_INIT(&VSF_DEBUG_STREAM_TX);
    vsf_start_trace();
    vsf_trace_info("start linux..." VSF_TRACE_CFG_LINEEND);

    vsf_linux_stdio_stream_t stream = {
        .in     = (vsf_stream_t *)&VSF_DEBUG_STREAM_RX,
        .out    = (vsf_stream_t *)&VSF_DEBUG_STREAM_TX,
        .err    = (vsf_stream_t *)&VSF_DEBUG_STREAM_TX,
    };
    vsf_linux_init(&stream);
    return 0;
}

/* EOF */

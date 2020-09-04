let path = require('path');

let device = "am243x";

const files = {
    common: [
        "hsr_prp_menu.c",
        "hsr_prp_main.c",
        "hsr_prp_soc.c",
        "main.c",
        "hsr_prp_prvmib.c",
        "udp_iperf.c"
    ],
};

/* Relative to where the makefile will be generated
 * Typically at <example_folder>/<BOARD>/<core_os_combo>/<compiler>
 */
const filedirs_evm = {
    common: [
        "..",       /* core_os_combo base */
        "../..",     /* board_base */
        "../../..", /* Example base */
        "../../../..",
        "../../../../common/am243evm",
    ],
};

const filedirs_lp = {
    common: [
        "..",       /* core_os_combo base */
        "../..",     /* board_base */
        "../../..", /* Example base */
        "../../../..",
        "../../../../common/am243lp",
    ],
};

const libdirs_freertos = {
    common: [
        "${MCU_PLUS_SDK_PATH}/source/kernel/freertos/lib",
        "${MCU_PLUS_SDK_PATH}/source/drivers/lib",
        "${MCU_PLUS_SDK_PATH}/source/board/lib",
        "${MCU_PLUS_SDK_PATH}/source/networking/icss_emac/lib",
        "${MCU_PLUS_SDK_PATH}/source/networking//icss_emac/lwipif/lib",
        "${MCU_PLUS_SDK_PATH}/source/networking/icss_timesync/lib",
        "${MCU_PLUS_SDK_PATH}/source/industrial_comms/hsr_prp/icss_fwhal/lib",
        "${MCU_PLUS_SDK_PATH}/source/networking/lwip/lib", /*Stack related*/
    ],
};

const includes_freertos_r5f = {
    common: [
        "${MCU_PLUS_SDK_PATH}/source/kernel/freertos/FreeRTOS-Kernel/include",
        "${MCU_PLUS_SDK_PATH}/source/kernel/freertos/portable/TI_ARM_CLANG/ARM_CR5F",
        "${MCU_PLUS_SDK_PATH}/source/kernel/freertos/config/am243x/r5f",
        "${MCU_PLUS_SDK_PATH}/examples/industrial_comms/hsr_prp_demo",
        //stack related includes
        "${MCU_PLUS_SDK_PATH}/source/networking/lwip/lwip-stack/src/include",
        "${MCU_PLUS_SDK_PATH}/source/networking/icss_emac/lwipif/inc",
        "${MCU_PLUS_SDK_PATH}/source/networking/lwip/lwip-contrib",
        "${MCU_PLUS_SDK_PATH}/source/networking/lwip/lwip-config/am243x",
        "${MCU_PLUS_SDK_PATH}/source/networking/lwip/lwip-port/include",
        "${MCU_PLUS_SDK_PATH}/source/networking/lwip/lwip-port/freertos/include",
    ],
};

const libs_freertos_r5f = {
    common: [
        "freertos.am243x.r5f.ti-arm-clang.${ConfigName}.lib",
        "drivers.am243x.r5f.ti-arm-clang.${ConfigName}.lib",
        "board.am243x.r5f.ti-arm-clang.${ConfigName}.lib",
        "icss_emac.am243x.r5f.ti-arm-clang.${ConfigName}.lib",
        "icss_emac_lwip_if.am243x.r5f.ti-arm-clang.${ConfigName}.lib",
        "icss_timesync.am243x.r5f.ti-arm-clang.${ConfigName}.lib",
        "prp_mii_icss_fwhal.am243x.r5f.ti-arm-clang.${ConfigName}.lib",
        //stack related lib
        "lwip-freertos.am243x.r5f.ti-arm-clang.${ConfigName}.lib",
        "lwip-contrib-freertos.am243x.r5f.ti-arm-clang.${ConfigName}.lib",
    ],
};

const defines_r5f = {
    common: [
        "BUILD_PRP",
        "PTP_TESTING",
    ],
};

const cflags_r5f = {
    common: [
        "-mno-unaligned-access",
    ],
};

const lflags_r5f = {
    common: [
        "--use_memcpy=fast",
        "--use_memset=fast",
    ],
};

const lnkfiles = {
    common: [
        "linker.cmd",
    ]
};

const syscfgfile = "../example.syscfg";

const readmeDoxygenPageTag = "EXAMPLES_INDUSTRIAL_COMMS_HSR_PRP_DEMOS";

const templates_freertos_r5f =
[
    {
        input: ".project/templates/am243x/common/linker_r5f.cmd.xdt",
        output: "linker.cmd",
        options: {
            stackSize: "32768",
            heapSize: "65536",
            codeDataAddr: "70080000",
            codeDataSize: "00140000",
            isIcssPktBufEnable: true,
        },
    },
    {
        input: ".project/templates/am243x/freertos/main_freertos.c.xdt",
        output: "../main.c",
        options: {
            entryFunction: "hsr_prp_main",
        },
    }
];

const buildOptionCombos = [
    { device: device, cpu: "r5fss0-0", cgt: "ti-arm-clang", board: "am243x-evm", os: "freertos"},
    { device: device, cpu: "r5fss0-0", cgt: "ti-arm-clang", board: "am243x-lp",  os: "freertos"},
];

function getComponentProperty() {
    let property = {};

    property.dirPath = path.resolve(__dirname, "..");
    property.type = "executable";
    property.name = "prp_mii_demo";
    property.isInternal = false;
    property.buildOptionCombos = buildOptionCombos;

    return property;
}

function getComponentBuildProperty(buildOption) {
    let build_property = {};

    build_property.files = files;
    if(buildOption.board.match(/am243x-evm*/) )
    {
        build_property.filedirs = filedirs_evm;
    }
    else if(buildOption.board.match(/am243x-lp*/) )
    {
        build_property.filedirs = filedirs_lp;
    }
    build_property.lnkfiles = lnkfiles;
    build_property.syscfgfile = syscfgfile;
    //build_property.readmeDoxygenPageTag = readmeDoxygenPageTag;
    build_property.projecspecFileAction = "link";

    if(buildOption.cpu.match(/r5f*/)) {
        if(buildOption.os.match(/freertos*/) )
        {
            build_property.includes = includes_freertos_r5f;
            build_property.libdirs = libdirs_freertos;
            build_property.libs = libs_freertos_r5f;
            build_property.templates = templates_freertos_r5f;
            build_property.defines = defines_r5f;
            build_property.cflags = cflags_r5f;
            build_property.lflags = lflags_r5f;
        }
    }

    return build_property;
}

module.exports = {
    getComponentProperty,
    getComponentBuildProperty,
};

let path = require('path');

let device = "am62x";

const files = {
    common: [
        "gpio_led_blink.c",
        "main.c",
    ],
};

/* Relative to where the makefile will be generated
 * Typically at <example_folder>/<BOARD>/<core_os_combo>/<compiler>
 */
const filedirs = {
    common: [
        "..",       /* core_os_combo base */
        "../../..", /* Example base */
    ],
};

const libdirs = {
    common: [
        "${MCU_PLUS_SDK_PATH}/source/kernel/nortos/lib",
        "${MCU_PLUS_SDK_PATH}/source/drivers/lib",
        "${MCU_PLUS_SDK_PATH}/source/board/lib",
    ],
};

const libdirs_freertos = {
    common: [
        "${MCU_PLUS_SDK_PATH}/source/kernel/freertos/lib",
        "${MCU_PLUS_SDK_PATH}/source/drivers/lib",
        "${MCU_PLUS_SDK_PATH}/source/board/lib",
    ],
};
const includes_freertos_m4f = {
    common: [
        "${MCU_PLUS_SDK_PATH}/source/kernel/freertos/FreeRTOS-Kernel/include",
        "${MCU_PLUS_SDK_PATH}/source/kernel/freertos/portable/TI_ARM_CLANG/ARM_CM4F",
        "${MCU_PLUS_SDK_PATH}/source/kernel/freertos/config/am62x/m4f",
    ],
};


const libs_nortos_m4f = {
    common: [
        "nortos.am62x.m4f.ti-arm-clang.${ConfigName}.lib",
        "drivers.am62x.m4f.ti-arm-clang.${ConfigName}.lib",
        "board.am62x.m4f.ti-arm-clang.${ConfigName}.lib",
    ],
};

const libs_freertos_m4f = {
    common: [
        "freertos.am62x.m4f.ti-arm-clang.${ConfigName}.lib",
        "drivers.am62x.m4f.ti-arm-clang.${ConfigName}.lib",
        "board.am62x.m4f.ti-arm-clang.${ConfigName}.lib",
    ],
};


const lnkfiles = {
    common: [
        "linker.cmd",
    ]
};

const syscfgfile = "../example.syscfg"

const readmeDoxygenPageTag = "EXAMPLES_DRIVERS_GPIO_LED_BLINK";



const templates_nortos_m4f =
[
    {
        input: ".project/templates/am62x/common/linker_m4f.cmd.xdt",
        output: "linker.cmd",
    },
    {
        input: ".project/templates/am62x/nortos/main_nortos.c.xdt",
        output: "../main.c",
        options: {
            entryFunction: "gpio_led_blink_main",
        },
    }
];

const templates_freertos_m4f =
[
    {
        input: ".project/templates/am62x/common/linker_m4f.cmd.xdt",
        output: "linker.cmd",
    },
    {
        input: ".project/templates/am62x/freertos/main_freertos.c.xdt",
        output: "../main.c",
        options: {
            entryFunction: "gpio_led_blink_main",
        },
    }
];




const buildOptionCombos = [
    { device: "am62x", cpu: "m4fss0-0", cgt: "ti-arm-clang", board: "am62x-sk", os: "nortos"},
    { device: "am62x", cpu: "m4fss0-0", cgt: "ti-arm-clang", board: "am62x-sk", os: "freertos"},
    { device: "am62x", cpu: "m4fss0-0", cgt: "ti-arm-clang", board: "am62x-sk-lp", os: "nortos"},
    { device: "am62x", cpu: "m4fss0-0", cgt: "ti-arm-clang", board: "am62x-sk-lp", os: "freertos"},
];

function getComponentProperty() {
    let property = {};

    property.dirPath = path.resolve(__dirname, "..");
    property.type = "executable";
    property.name = "gpio_led_blink";
    property.isInternal = false;
    property.tirexResourceSubClass = [ "example.gettingstarted" ];
    property.description = "A GPIO LED Blink Example. This example blinks a EVM LED for few seconds."
    property.buildOptionCombos = buildOptionCombos;

    return property;
}

function getComponentBuildProperty(buildOption) {
    let build_property = {};

    build_property.files = files;
    build_property.filedirs = filedirs;
    build_property.libdirs = libdirs;
    build_property.lnkfiles = lnkfiles;
    build_property.syscfgfile = syscfgfile;
    build_property.readmeDoxygenPageTag = readmeDoxygenPageTag;


    if(buildOption.cpu.match(/m4f*/)) {
        if(buildOption.os.match(/freertos*/) )
        {
            build_property.includes = includes_freertos_m4f;
            build_property.libdirs = libdirs_freertos;
            build_property.libs = libs_freertos_m4f;
            build_property.templates = templates_freertos_m4f;
        }
        else
        {
            build_property.libs = libs_nortos_m4f;
            build_property.templates = templates_nortos_m4f;
        }


    }

    return build_property;
}

module.exports = {
    getComponentProperty,
    getComponentBuildProperty,
};

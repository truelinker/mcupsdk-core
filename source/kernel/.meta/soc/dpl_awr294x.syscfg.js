
let common = system.getScript("/common");

const topModules_r5f = [
    "/kernel/dpl/clock",
    "/kernel/dpl/debug_log",
    "/kernel/dpl/mpu_armv7",
    "/kernel/dpl/timer",
];

const topModules_c66 = [
    "/kernel/dpl/cache_c6x",
    "/kernel/dpl/clock",
    "/kernel/dpl/debug_log",
    "/kernel/dpl/timer",
];

/* Max xcache sizes in KB */
const cache_config_c66 = {
    max_l1psize : 32,
    max_l1dsize : 32,
    max_l2size  : 256,
};

function getConfigArr() {
    let cpu = common.getSelfSysCfgCoreName();

    if(cpu.match(/c66*/)) {
        return cache_config_c66;
    }
    return undefined;
}

exports = {
    getTopModules: function() {
        let cpu = common.getSelfSysCfgCoreName();

        if(cpu.match(/r5f*/)) {
            return topModules_r5f;
        }

        if(cpu.match(/c66*/)) {
            return topModules_c66;
        }

        return undefined;
    },
    getConfigArr,
};

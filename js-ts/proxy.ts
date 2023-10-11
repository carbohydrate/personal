enum Mode {
    Quantity = 'quantity',
    Weight = 'weight',
}

const Modes = {
    1: Mode.Quantity,
    2: Mode.Weight,
    3: Mode.Quantity,
};

interface ModeInterface {
    [key: number]: Mode;
}

const createModesProxy = (target: ModeInterface): ModeInterface => {
    const handler = {
        get(target: typeof Modes, prop: PropertyKey) {
            console.log('target: ', target);
            console.log('prop: ', prop);

            if (!Reflect.has(target, prop)) {
                return Mode.Quantity;
            }

            return Reflect.get(target, prop);
        },
    };

    return new Proxy(target, handler);
}

const modesProxy = createModesProxy(Modes);

const testNumber = 4 as number;
console.log('modesProxy: ', modesProxy[testNumber]);

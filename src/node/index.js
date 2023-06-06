// import native addon
const addonCalDev = require('bindings')('caldev');

// expose module API
exports.hello = addonCalDev.greetHello;
exports.calculDev= addonCalDev.calculDev
exports.init= addonCalDev.init
exports.hi= addonCalDev.hi
exports.runSimpleAsyncWorker= addonCalDev.runSimpleAsyncWorker
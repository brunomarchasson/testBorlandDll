console.log('rr')
import  caldevModule from './index.js'
console.log('exports', caldevModule)

console.log('hello', caldevModule.hello('me'))

try{
    console.log('t')
    caldevModule.init('toto')
    console.log('init done !')
    console.log(caldevModule.hi())
    const r = caldevModule.runSimpleAsyncWorker(4).then(res=> console.log('res', `${res}`)).catch(e => console.error(e))
    console.log('rr',)
}catch(e){
    console.log('RRRRR', e)
}
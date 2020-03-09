/* var myModule = require('bindings')('myModule');
var f = new myModule.Calib3D();
console.log(myModule);
 */
var myModule = require('bindings')('myModule');
var f = new myModule.CamFunction();
console.log(myModule);

console.log(f.findCorners());

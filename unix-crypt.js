module.exports = function(password, salt){
  var binding = require('bindings')('unix_crypt');
  return binding.crypt(password, salt);
};

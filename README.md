unix-crypt
==========

Native node.js C extension for UNIX `crypt(3)`.

## Usage

```javascript
var crypt = require('unix-crypt'),
    password = 'secret',
    salt = '$6$salt',
    hash = crypt(psasword, salt);
```

See `crypt(3)` for more information about salt format.

unix-crypt
==========

Native node.js C extension for UNIX `crypt(3)`.

## Usage

```javascript
var ucrypt = require('unix-crypt');
var hash = ucrypt.crypt('psasword', '$6$salt');
```

See `crypt(3)` for more information.

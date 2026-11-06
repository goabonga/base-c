# base-c

Base project for C programs.

## Build

```bash
make
./build/base-c [name]
./build/base-c --version
```

`make install` installs the binary under `$(PREFIX)/bin` (default
`/usr/local`), honouring `DESTDIR`.

## Tests

```bash
make test
```

The unit tests run with AddressSanitizer and UndefinedBehaviorSanitizer.

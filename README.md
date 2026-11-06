# base-c

[![ci](https://github.com/goabonga/base-c/actions/workflows/ci.yml/badge.svg)](https://github.com/goabonga/base-c/actions/workflows/ci.yml)
[![Release](https://img.shields.io/github/v/release/goabonga/base-c)](https://github.com/goabonga/base-c/releases)
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

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

The unit tests run with AddressSanitizer and UndefinedBehaviorSanitizer;
pass `SANITIZE=` to disable them on platforms that reject them.

## Code quality

```bash
make format-check   # clang-format
make lint           # clang-tidy
make format         # apply clang-format
```

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md).

## License

[MIT](LICENSE)

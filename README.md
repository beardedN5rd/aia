# aia
C++ implementation of
[Allen's interval algebra](https://en.wikipedia.org/wiki/Allen's_interval_algebra)

## Usage
It is header only library.

## Dependencies
It requires C++11 and only uses the C++ standard library. For testing boost build and boost test are required.

## Test

* `prepare`, create the test container image
* `run_test`, run the unit tests inside the container

### Requirements
The project uses docker for providing a defined test environment, so `docker` is required, but for testing only.

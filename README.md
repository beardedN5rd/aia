# determined interval logic
This C++ library is meant to describe relations between measured time points and temporal intervals.

It uses concepts mentioned in [Allen's interval algebra](https://en.wikipedia.org/wiki/Allen's_interval_algebra), see the [original paper](http://cse.unl.edu/~choueiry/Documents/Allen-CACM1983.pdf).

In contrast to Allen's intention to work on fuzzy intervals, this library supports determined temporal intervals only.

## Intervals
Intervals are defined as closed intervals described by their endpoints. See the logical implications of this approach in Allen's paper.

## Usage
It is a header only library.

## Dependencies
It requires C++11 and only uses the C++ standard library. For testing boost build and boost test are required.

## Test

* `prepare`, create the test container image
* `run_test`, run the unit tests inside the container

### Requirements
The project uses docker for providing a defined test environment, so `docker` is required, but for testing only.

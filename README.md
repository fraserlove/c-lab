# C Lab

A collection of C programs ranging from a reverse polish calculator to a multi-process pipeline.

## Installation and Usage

1. **Clone the Repository:**
```bash
git clone https://github.com/fraserlove/c-lab.git
cd c-lab
```
2. **Compile and Run a C Program:**

Make sure you have clang and make installed on your system. Run `clang --version` and `make --version` to check you have them installed. Then navigate into a a project directory and run `make`. The programs binary file(s) will be compiled and placed under the programs `build` directory. For example to compile and run `reverse-polish-calculator`:
```
cd reverse-polish-calculator
make
./build/calculator
```
Also note that there are program specific `README.md` files under each programs directory. All included build files can be removed with a simple `make clean`.

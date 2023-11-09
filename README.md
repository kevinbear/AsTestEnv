# AsTestEnv: assignment test environment
### Test environment for homework assignment
If you have a Linux or macOS, this should work perfectly. 
Before you use it, please download the whole project to your computer. Or if you have codespace, you can also run on it.

#### Pre-requisites tools:
+ cmake `cmake /V`
+ make `make -v`
+ git  `git -v` 

  
![ubuntu](https://img.shields.io/badge/os-ubuntu-orange)

![macOS](https://img.shields.io/badge/os-macOS-blue)

![codespace](https://img.shields.io/badge/github-codespace-green)

Use `git clone https://github.com/kevinbear/AsTestEnv.git` to clone all projects to your local.

## AS3: Assignment 3
### Directory structure in AS3
```
├── CMakeLists.txt
├── asset
│   ├── a03.config
│   ├── ciphertext.txt
│   ├── codebook.csv
│   └── plaintext.txt
├── build
│   ├── A03
│   ├── Makefile
├── include
│   ├── A03.h
│   └── defs.h
└── src
    ├── A03.cpp
    └── autograder.cpp
```
### How to use this assignment test environment?
#### 1. Use the `cd`(change directory) command to move the directory assignment that you're working on. 

#### 2. Copy the cpp file content to the corresponding file.
For example, in assignment 3, we have to submit A03.cpp to gradescope, so you can paste your code to A03.cpp or delete it and add your A03.cpp under the `src` folder. 

#### 3. After replacing the cpp files or other files you are working on, use `cd` to move to the `build` directory

#### 4. Delete All contents inside the `build` directory by `rm -rf *`

#### 5. Use `cmake` to produce the Makefile into `build` directory

#### 6. Use `make` to run Makefile to run.

#### 7. If everything goes fine, you will get an executable called A03 in `build` directory.

#### 8. To run A03 with the config file. Use this command `./A03 ../asset/a03.config` in the terminal. And you should see the result. Also, the `asset` directory will generate a file called `ciphertext.txt`.

```
/workspaces/AsTestEnv (main) $ cd AS3
/workspaces/AsTestEnv/AS3 (main) $ cd build/
/workspaces/AsTestEnv/AS3/build (main) $ rm -rf *
/workspaces/AsTestEnv/AS3/build (main) $ cmake -B. -S ..
/workspaces/AsTestEnv/AS3/build (main) $ make
/workspaces/AsTestEnv/AS3/build (main) $ ./A03 ../asset/a03.config
```
#### Note: what file should be put in each directory
asset: directory is for storing files which input or output files. (`a03.config`, `codebook.csv`, `plaintext.txt`)

build: for files or folders that are created by `cmake`; there are a lot of files inside.

include: for header files (`defs.h`, `A03.h`)

src: for all cpp files (`autograder.cpp`, `A03.cpp`)

---

## AS4: Assignment 4
### Directory structure in AS4
```
.
├── CMakeLists.txt
├── Makefile
├── TestCase
│   ├── case1.txt
│   └── case2.txt
├── build
├── include
│   └── CS52Vector.h
└── src
    ├── Vector.cpp
    └── unittest.cpp
```

#### 1. Use the `cd` (change directory) command to move directory assignment that you're working on. 

#### 2. Copy your cpp file content to replace the corresponding one.
For example, in assignment 4, we had to submit CS52Vector.h to Gradescope, so you can paste your code to CS52Vector.h or delete it and add your CS52Vector.h under the `src` folder. 

#### 3. After replacing the cpp files or other files you are working on, use `cd` to move to the `build` directory

#### 4. Delete All contents inside the `build` directory by `rm -rf *`

#### 5. Use `cmake` to produce the Makefile into `build` directory

#### 6. Use `make` to run Makefile to run.

#### 7. If every step goes fine, you will get an executable called A04 in `build` directory.

#### 8. To run A04, use this command `./A04 ../TestCase/case1.txt ../TestCase/case2.txt` in terminal. And you should see the result.

```
/workspaces/AsTestEnv (main) $ cd AS4
/workspaces/AsTestEnv/AS3 (main) $ cd build/
/workspaces/AsTestEnv/AS3/build (main) $ rm -rf *
/workspaces/AsTestEnv/AS3/build (main) $ cmake -B. -S ..
/workspaces/AsTestEnv/AS3/build (main) $ make
/workspaces/AsTestEnv/AS3/build (main) $ ./A04 ../TestCase/case1.txt ../TestCase/case2.txt
```
